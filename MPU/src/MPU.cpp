#include <I2C.h>
#include <MPU.h>
#include <GPIO.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
#include <Madgwick.h>
#include <Core.h>
#include <AML/AML.h>


using namespace AML;
using namespace global;

I2C_Handle_t i2c_handle;
// MPU_t mpu;

#define toDeg(x)	((x*180.0f)/M_PI)
#define toRad(x)	((x*M_PI)/180.0f)
// madgwick_t *madgwick;


void MPU_t::Init(){
	// madgwick = getMadgwick();
	// MadgwickInit(0.5, 0.2);
	//configure pins 
	gpio_pin_conf_t pinA9, pinA10;
	pinA9.pin = PA9;
	pinA10.pin = PA10;
	//set mode
	pinA9.mode = GPIO_PIN_ALT_FUN_MODE;
	pinA10.mode = GPIO_PIN_ALT_FUN_MODE;
	//output type
	pinA9.op_type = GPIO_PIN_OP_TYPE_OPEN_DRAIN;
	pinA10.op_type = GPIO_PIN_OP_TYPE_OPEN_DRAIN;
	////set pullups for pin 9 and 10
	pinA9.pupd = GPIO_PIN_PUPD_NO_PUPD;
	pinA10.pupd = GPIO_PIN_PUPD_NO_PUPD;
	//set speed
	pinA9.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	pinA10.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	//set alternate function
	pinA9.alternate_function = 4;
	pinA10.alternate_function = 4;

	//enable clock for GPIOA
	RCC_GPIOA_CLK_ENABLE();
	gpio_init(GPIOA, &pinA9);
	gpio_init(GPIOA, &pinA10);

	i2c_handle.instance = I2C1;
 	I2CInit(&i2c_handle);


	Serial.printStrln("Starting Init sequence of MPU");
	uint8_t buffer[6];

	//init sequence
	buffer[0] = 0x80;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	Serial.printStrln("first succesful transmit");
	for(int i = 0; i < 800000; i++);

	buffer[0] = 0x00;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	for(int i = 0; i < 800000; i++);

	buffer[0] = 0x01;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	for(int i = 0; i < 1600000; i++);

	//set gyro range to maximum of 2000 degrees/second
	buffer[0] = (3 << 3);
	i2c_master_tx(&i2c_handle, MPU, 0x1B, buffer, 1);

	//set acc range to be 4g
	buffer[0] = (1 << 3);
	i2c_master_tx(&i2c_handle, MPU, 0x1C, buffer, 1);

	//enable bypass multiplexer to access magnetometer and bmp
	buffer[0] = 0x02;
	i2c_master_tx(&i2c_handle, MPU, 0x37, buffer, 1);
	for(int i = 0; i < 800000; i++);


	/*************Init the MAG************************/
	// //just for test to see if it reads the device id correctly
	// i2c_master_rx(&i2c_handle, MAG, 0x00, buffer, 1);
	buffer[0] = 0x1f;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);

	i2c_master_rx(&i2c_handle, MAG, 0x10, buffer, 3);
	magASA.data[0] = ((buffer[0] - 128)/256.0f) + 1.0f;
	magASA.data[1] = ((buffer[1] - 128)/256.0f) + 1.0f;
	magASA.data[2] = ((buffer[2] - 128)/256.0f) + 1.0f;

	buffer[0] = 0x00;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);

	buffer[0] = 0x16;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);
}

void MPU_t::calibrate(){
	Serial.printStrln("Calibrating....");
	for(int i = 0; i < CAL_FACT; i++){
		readAcc();
		readGyro();

		accError.data[0] += acc.data[0];
		accError.data[1] += acc.data[1];
		accError.data[2] += acc.data[2] - 1;

		gyroError.data[0] += gyro.data[0];
		gyroError.data[1] += gyro.data[1];
		gyroError.data[2] += gyro.data[2];
	}
	accError.data[0] = accError.data[0]/CAL_FACT;
	accError.data[1] = accError.data[1]/CAL_FACT;
	accError.data[2] = accError.data[2]/CAL_FACT;

	gyroError.data[0] = gyroError.data[0]/CAL_FACT;
	gyroError.data[1] = gyroError.data[1]/CAL_FACT;
	gyroError.data[2] = gyroError.data[2]/CAL_FACT;

	magError.data[0] = (40.785 + -45.477)/2.0f;
	magError.data[1] = (67.953 + -1.434)/2.0f;
	magError.data[2] = (76.485 + -4.509)/2.0f;

	magScale.data[0] = (40.785 - -45.477)/2.0f;
	magScale.data[1] = (67.953 - -1.434)/2.0f;
	magScale.data[2] = (76.485 - -4.509)/2.0f;
	float avg = (magScale.data[0] + magScale.data[1] + magScale.data[2])/3.0f;
	magScale.data[0] = avg/magScale.data[0];
	magScale.data[1] = avg/magScale.data[1];
	magScale.data[2] = avg/magScale.data[2];

	calibrated = true;
}
void MPU_t::readAcc(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MPU, 0x3B, buffer, 6);

	acc.data[0] = ((int16_t) ((buffer[0] << 8) | buffer[1]))  / ACC_FACT;
	acc.data[1] = ((int16_t) ((buffer[2] << 8) | buffer[3]))  / ACC_FACT;
	acc.data[2] = ((int16_t) ((buffer[4] << 8) | buffer[5]))  / ACC_FACT;

	if(calibrated){
		acc.data[0] -= accError.data[0];
		acc.data[1] -= accError.data[1];
		acc.data[2] -= accError.data[2];

	}

	static Vector3 filteredAcc;
	filteredAcc = 0.9*filteredAcc + 0.1*acc;
	acc = filteredAcc;

	normalize(acc);

}

void MPU_t::readGyro(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MPU, 0x43, buffer, 6);

	gyro.data[0] = ((int16_t) ((buffer[0] << 8) | buffer[1])) / GYRO_FACT;
	gyro.data[1] = ((int16_t) ((buffer[2] << 8) | buffer[3])) / GYRO_FACT;
	gyro.data[2] = ((int16_t) ((buffer[4] << 8) | buffer[5])) / GYRO_FACT;

	if(calibrated){
		gyro.data[0] -= gyroError.data[0];
		gyro.data[1] -= gyroError.data[1];
		gyro.data[2] -= gyroError.data[2];
	}
}

void MPU_t::readMag(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MAG, 0x02, buffer, 1);
	uint8_t st1 = buffer[0];

	if( !(st1 & (1 << 0)) ) return;
	i2c_master_rx(&i2c_handle, MAG, 0x03, buffer, 7);

	mag.data[0] = ((int16_t) ((buffer[1] << 8) | buffer[0]) / MAG_FACT); //* mpu.magASA[0];
	mag.data[1] = ((int16_t) ((buffer[3] << 8) | buffer[2]) / MAG_FACT); //* mpu.magASA[1];
	mag.data[2] = ((int16_t) ((buffer[5] << 8) | buffer[4]) / MAG_FACT); //* mpu.magASA[2];

	//change axis to align with the acc and gyro
	float temp = mag.data[0];
	mag.data[0] = mag.data[1];
	mag.data[1] = temp;
	mag.data[2] = -mag.data[2];

	uint8_t st2 = buffer[6];
	if(st2 & (1 << 3))
		Serial.printStrln("Error magnetometer overflow");

	if(calibrated){
		mag.data[0] = (mag.data[0] - magError.data[0]) * magScale.data[0];
		mag.data[1] = (mag.data[1] - magError.data[1]) * magScale.data[1];
		mag.data[2] = (mag.data[2] - magError.data[2]) * magScale.data[2];
	}
}

void MPU_t::calculateAngles(float dt){
	float accRoll, accPitch, magYaw;
	float roll, pitch, yaw;
	roll = angles.data[0];
	pitch = angles.data[1];
	yaw = angles.data[2];

	float ax, ay, az;
	float gx, gy, gz;
	float mx, my, mz;
	ax = acc.data[0];
	ay = acc.data[1];
	az = acc.data[2];

	gx = gyro.data[0];
	gy = gyro.data[1];
	gz = gyro.data[2];

	mx = mag.data[0];
	my = mag.data[1];
	mz = mag.data[2];

	accRoll = atan2f(ay, sqrtf(ax*ax + az*az));
	accRoll = toDeg(accRoll);
	roll = 0.96*(roll + gx*dt) + 0.04*accRoll;
	float radRoll = toRad(roll);

	//accPitch = atan2(-ax, ay*sinf(radRoll) + az*cosf(radRoll) );
	accPitch = atan2f(-ax, sqrtf(ay*ay + az*az));
	accPitch = toDeg(accPitch);
	pitch = 0.96*(pitch + gy*dt) + 0.04*accPitch;
	float radPitch = toRad(pitch);

	magYaw = atan2f(mz*sinf(radRoll) - my*cosf(radRoll), mx*cosf(radPitch) + my*sinf(radPitch)*sinf(radRoll) + mz*sinf(radPitch)*cosf(radRoll));
	magYaw = toDeg(magYaw);

	if(magYaw > 175 || magYaw < -175)
		yaw = magYaw;
	else
		yaw = 0.96*(yaw + gz*dt) + 0.04*magYaw;

	angles.data[0] = roll;
	angles.data[1] = pitch;
	angles.data[2] = yaw;
	// mpu.angles.data[2] += gz*dt;
}

void MPU_t::printValues(){
	Serial.printFloat(acc.data[0]);
	Serial.printStr("\t");
	// Serial.sendByte(',');
	Serial.printFloat(acc.data[1]);
	Serial.printStr("\t");
	// Serial.sendByte(',');
	Serial.printFloat(acc.data[2]);
	Serial.printStr("\t");
	// Serial.sendByte(',');
	Serial.printStr("\t\t\t");
	Serial.printFloat(gyro.data[0]);
	Serial.printStr("\t");
	// Serial.sendByte(',');
	Serial.printFloat(gyro.data[1]);
	Serial.printStr("\t");
	// Serial.sendByte(',');
	Serial.printFloat(gyro.data[2]);
	// Serial.sendByte('\n');
	// Serial.printStr(",\t\t\t");
	Serial.printStr("\t\t\t");
	Serial.printFloat(mag.data[0]);
	Serial.printStr("\t");
	Serial.printFloat(mag.data[1]);
	Serial.printStr("\t");
	Serial.printFloat(mag.data[2]);
	Serial.sendByte('\n');
}

void MPU_t::printAngles(){
	Serial.printFloat(angles.data[0]);
	// Serial.sendByte(',');
	Serial.printStr(",\t");
	Serial.printFloat(angles.data[1]);
	// Serial.sendByte(',');
	Serial.printStr(",\t");
	Serial.printFloat(angles.data[2]);
	Serial.sendByte('\n');
}

void MPU_t::printErrors() {
	Serial.printFloat(accError.data[0]);
	Serial.printStr(",\t");
	Serial.printFloat(accError.data[1]);
	Serial.printStr(",\t");
	Serial.printFloat(accError.data[2]);
	Serial.printStr(",\t\t");
	Serial.printFloat(gyroError.data[0]);
	Serial.printStr(",\t");
	Serial.printFloat(gyroError.data[1]);
	Serial.printStr(",\t");
	Serial.printFloat(gyroError.data[2]);
	Serial.sendByte('\n');
}

EulerAngles Mahony::update(Vector3 &acc, Vector3 &gyro, float dt) {
	//computre the estimated gravity vector from the quaternion
	float data[] = {2*(q.q1*q.q3 - q.q0*q.q2), 2*(q.q0*q.q1 + q.q2*q.q3), q.q0*q.q0 - q.q1*q.q1 - q.q2*q.q2 + q.q3*q.q3};
	Vector3 v(data);

	//get the incremental error by cross product between measured and estimated
	Vector3 delta_error = cross(acc, v);

	//compute the whole orientation error
	error = error + delta_error * dt;
	gyro = gyro + kp*delta_error + ki*error;

	Quaternion qdot = quatKinematicsRates_BodyRates(q, gyro);

	q = integrateQuat(q, qdot, dt);
	return quat2EulerAngles(q);
}
