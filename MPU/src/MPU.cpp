#include <I2C.h>
#include <MPU.h>
#include <GPIO.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
//#include <Madgwick.h>
#include <Core.h>
#include <AML/AML.h>
#include <string>
#include <vector>


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
		readGyro();

		gyroError.data[0] += gyro.data[0];
		gyroError.data[1] += gyro.data[1];
		gyroError.data[2] += gyro.data[2];
	}

	gyroError.data[0] = gyroError.data[0]/CAL_FACT;
	gyroError.data[1] = gyroError.data[1]/CAL_FACT;
	gyroError.data[2] = gyroError.data[2]/CAL_FACT;

	//accError.data[0] = 0.0003*acc.data[0] + 0.172;
	//accError.data[1] = 0.0003*acc.data[1] + 0.172;
	//accError.data[2] = 0.0003*acc.data[2] + 0.172;

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

void MPU_t::calibrateAcc() {
	float offset;
	float x_sum = 0;
	float y_sum = 0;
	float x_squared_sum = 0;
	float xy_sum = 0;

	Serial.printStrln("Hold sensor up z-axis up right");
	for(int i = 0; i < CAL_FACT; i++){
		readAcc();

		offset = acc.data[2] - 1;
		x_sum += 1;
		y_sum += offset;
		x_squared_sum += 1;
		xy_sum += 1 * offset;

	}
	Serial.printStrln("Hold sensor down z-axis upside down");
	for(int i = 0; i < CAL_FACT; i++){
		readAcc();

		offset = acc.data[2] + 1;
		x_sum += -1;
		y_sum += offset;
		x_squared_sum += 1;
		xy_sum += -1 * offset;
	}
	Serial.printStrln("Hold sensor side z-axis his side facing down");
	for(int i = 0; i < CAL_FACT; i++){
		readAcc();

		offset = acc.data[2];
		// x_sum += 0;
		y_sum += offset;
		// x_squared_sum += 0;
		// xy_sum += 0 * offset;
	}

	float n = 3*CAL_FACT;
	float m = (n*xy_sum - x_sum*y_sum)/(n*x_squared_sum - x_sum*x_sum);
	float b = (y_sum - m*x_sum)/n;
	Serial.printStr("m = ");
	Serial.printFloat(m);
	Serial.printStr(",\tb = ");
	Serial.printFloat(b);
	Serial.printStrln("");
	Serial.printStrln("done");
}
void MPU_t::readAcc() {
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MPU, 0x3B, buffer, 6);

	acc.data[0] = ((int16_t) ((buffer[0] << 8) | buffer[1]))  / ACC_FACT;
	acc.data[1] = ((int16_t) ((buffer[2] << 8) | buffer[3]))  / ACC_FACT;
	acc.data[2] = ((int16_t) ((buffer[4] << 8) | buffer[5]))  / ACC_FACT;

	if(calibrated){
		// accError.data[0] = ;
		// accError.data[1] = ;
		// accError.data[2] = -0.018*acc.data[2] + 0.102;
		accError.data[2] = 0.0003*acc.data[2] + 0.172;
		acc.data[0] -= accError.data[0];
		acc.data[1] -= accError.data[1];
		acc.data[2] -= accError.data[2];

	}

	static Vector3 filteredAcc;
	filteredAcc = 0.9*filteredAcc + 0.1*acc;
	acc = filteredAcc;

	// normalize(acc);
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
	// angles.data[2] += gz*dt;
}

void MPU_t::printValues(){
	string s;
	s.append(Serial.floatToStr(acc.data[0]));
	s.append("\t");
	s.append(Serial.floatToStr(acc.data[1]));
	s.append("\t");
	s.append(Serial.floatToStr(acc.data[2]));
	s.append("\t");
	s.append(Serial.floatToStr(gyro.data[0]));
	s.append("\t");
	s.append(Serial.floatToStr(gyro.data[1]));
	s.append("\t");
	s.append(Serial.floatToStr(gyro.data[2]));
	s.append("\t");
	s.append(Serial.floatToStr(mag.data[0]));
	s.append("\t");
	s.append(Serial.floatToStr(mag.data[1]));
	s.append("\t");
	s.append(Serial.floatToStr(mag.data[2]));
	s.append("\t");
	s.append(Serial.floatToStr(angles.data[0]));
	s.append("\t");
	s.append(Serial.floatToStr(angles.data[1]));
	s.append("\t");
	s.append(Serial.floatToStr(angles.data[2]));
	Serial.printStrln((char*) s.c_str());

	// Serial.printFloat(acc.data[0]);
	// // Serial.printStr("\t");
	// Serial.sendByte('\t');
	// Serial.printFloat(acc.data[1]);
	// // Serial.printStr("\t");
	// Serial.sendByte('\t');
	// Serial.printFloat(acc.data[2]);
	// // Serial.printStr("\t");
	// Serial.sendByte('\t');
	// // Serial.sendByte(',');
	// Serial.printFloat(gyro.data[0]);
	// Serial.sendByte('\t');
	// // Serial.printStr("\t");
	// // Serial.sendByte(',');
	// Serial.printFloat(gyro.data[1]);
	// Serial.sendByte('\t');
	// // Serial.printStr("\t");
	// // Serial.sendByte(',');
	// Serial.printFloat(gyro.data[2]);
	// // Serial.sendByte('\n');
	// // Serial.printStr(",\t\t\t");
	// Serial.sendByte('\t');
	// // Serial.printStr("\t");
	// Serial.printFloat(mag.data[0]);
	// Serial.sendByte('\t');
	// // Serial.printStr("\t");
	// Serial.printFloat(mag.data[1]);
	// Serial.sendByte('\t');
	// // Serial.printStr("\t");
	// Serial.printFloat(mag.data[2]);
	// Serial.sendByte('\n');
}

void MPU_t::printAngles(){
	string s;
	s.append(Serial.floatToStr(angles.data[0]));
	s.append("\t");
	s.append(Serial.floatToStr(angles.data[1]));
	s.append("\t");
	s.append(Serial.floatToStr(angles.data[2]));
	Serial.printStrln((char*) s.c_str());
	// // Serial.printFloat(angles.data[0]);
	// // Serial.sendByte(',');
	// Serial.printStr(",\t");
	// Serial.printFloat(angles.data[1]);
	// // Serial.sendByte(',');
	// Serial.printStr(",\t");
	// Serial.printFloat(angles.data[2]);
	// Serial.sendByte('\n');
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

EulerAngles Mahony::update(Vector3 &acc, Vector3 &gyro_degrees, float dt) {
	Vector3 gyro = gyro_degrees * (M_PI/180.0f);

	//computre the estimated gravity vector from the quaternion
	float data[] = {2*(q.q1*q.q3 - q.q0*q.q2), 2*(q.q0*q.q1 + q.q2*q.q3), 1 - 2*q.q1*q.q1 - 2*q.q2*q.q2};
	Vector3 v(data);

	normalize(acc);
	//get the incremental error by cross product between measured and estimated
	Vector3 delta_error = cross(acc, v);

	//compute the whole orientation error
	error = error + delta_error * dt;
	gyro = gyro + kp*delta_error + ki*error;


	//feed back gyro degrees for next iteration
	gyro_degrees = gyro * (180.0f/M_PI);

	Quaternion qdot = quatKinematicsRates_BodyRates(q, gyro);
	q = integrateQuat(q, qdot, dt);

	EulerAngles angles = quat2EulerAngles(q);
	//convert to degrees back
	angles.phi *= (180.0f/M_PI);
	angles.theta *= (180.0f/M_PI);
	angles.psi *= (180.0f/M_PI);

	return angles;
}

EulerAngles Madgwick::update(Vector3 &acc, Vector3 &gyro_degrees, float dt) {
	// convert gyro degrees measurements to rads
	Vector3 gyro = gyro_degrees * (M_PI/180.0f);
	// normalize acc
	normalize(acc);

	//computre the estimated gravity vector from the quaternion
	float data[] = {2*(q.q1*q.q3 - q.q0*q.q2), 2*(q.q0*q.q1 + q.q2*q.q3), 1 - 2*q.q1*q.q1 - 2*q.q2*q.q2};
	Vector3 v(data);

	Vector3 F_g = v - acc;

	//define the jacobian
	float J_g[3][4] = { 
		{-2*q.q2, 2*q.q3, -2*q.q0, 2*q.q1},
		{2*q.q1, 2*q.q0, 2*q.q3, 2*q.q2},
		{	0  , -4*q.q1, -4*q.q2,	0  }
	};

	//define gradient to be the jacobian * costfunction
	Quaternion gradient;
 	// now computer the gradient gradient = J_g'*F_g (J_g' means transpose)
    gradient.q0 = J_g[0][0] * F_g.data[0] + J_g[1][0] * F_g.data[1] + J_g[2][0] * F_g.data[2];
    gradient.q1 = J_g[0][1] * F_g.data[0] + J_g[1][1] * F_g.data[1] + J_g[2][1] * F_g.data[2];
    gradient.q2 = J_g[0][2] * F_g.data[0] + J_g[1][2] * F_g.data[1] + J_g[2][2] * F_g.data[2];
    gradient.q3 = J_g[0][3] * F_g.data[0] + J_g[1][3] * F_g.data[1] + J_g[2][3] * F_g.data[2];
	normalise(gradient);

	// get the direction to be the normalized gradient * beta
	// the direction needs to be opposite to the gradient in grad descent so its negative
	Quaternion q_delta = -beta*gradient;

	//get gyro increment orientation
	Quaternion qw_dot = quatKinematicsRates_BodyRates(q, gyro);

	//Fuse the measurments from both the acc and gyro to obtain the estimated attitude 
	Quaternion qdot = qw_dot + q_delta;

	q = integrateQuat(q, qdot, dt);

	EulerAngles angles = quat2EulerAngles(q);
	//convert to degrees back
	angles.phi *= (180.0f/M_PI);
	angles.theta *= (180.0f/M_PI);
	angles.psi *= (180.0f/M_PI);

	return angles;
}
