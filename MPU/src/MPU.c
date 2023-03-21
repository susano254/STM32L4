#include <I2C.h>
#include <MPU.h>
#include <GPIO.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
#include <Madgwick.h>


I2C_Handle_t i2c_handle;
MPU_t mpu;

#define toDeg(x)	((x*180.0f)/M_PI)
#define toRad(x)	((x*M_PI)/180.0f)
// madgwick_t *madgwick;


void mpu_init(){
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


	printStrln("Starting Init sequence of MPU");
	uint8_t buffer[6];

	buffer[0] = 0x80;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	buffer[0] = 0x00;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	buffer[0] = 0x01;
	i2c_master_tx(&i2c_handle, MPU, 0x6B, buffer, 1);
	for(int i = 0; i < 16000000; i++);

	buffer[0] = 0x02;
	i2c_master_tx(&i2c_handle, MPU, 0x37, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	// //just for test to see if it reads the device id correctly
	// i2c_master_rx(&i2c_handle, MAG, 0x00, buffer, 1);
	buffer[0] = 0x1f;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	i2c_master_rx(&i2c_handle, MAG, 0x10, buffer, 3);
	mpu.magASA[0] = ((buffer[0] - 128)/256.0f) + 1.0f;
	mpu.magASA[1] = ((buffer[1] - 128)/256.0f) + 1.0f;
	mpu.magASA[2] = ((buffer[2] - 128)/256.0f) + 1.0f;

	buffer[0] = 0x00;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	buffer[0] = 0x16;
	i2c_master_tx(&i2c_handle, MAG, 0x0A, buffer, 1);
	for(int i = 0; i < 8000000; i++);

	calibrate();
}

MPU_t* getMpu(){
	return &mpu;
}

void calibrate(){
	printStrln("Calibrating....");
	for(int i = 0; i < CAL_FACT; i++){
		readAcc();
		readGyro();

		mpu.accError[0] += mpu.acc[0];
		mpu.accError[1] += mpu.acc[1];
		mpu.accError[2] += mpu.acc[2] - 1;

		mpu.gyroError[0] += mpu.gyro[0];
		mpu.gyroError[1] += mpu.gyro[1];
		mpu.gyroError[2] += mpu.gyro[2];
	}
	mpu.accError[0] = mpu.accError[0]/CAL_FACT;
	mpu.accError[1] = mpu.accError[1]/CAL_FACT;
	mpu.accError[2] = mpu.accError[2]/CAL_FACT;

	mpu.gyroError[0] = mpu.gyroError[0]/CAL_FACT;
	mpu.gyroError[1] = mpu.gyroError[1]/CAL_FACT;
	mpu.gyroError[2] = mpu.gyroError[2]/CAL_FACT;

	mpu.magError[0] = (40.785 + -45.477)/2.0f;
	mpu.magError[1] = (67.953 + -1.434)/2.0f;
	mpu.magError[2] = (76.485 + -4.509)/2.0f;

	mpu.magScale[0] = (40.785 - -45.477)/2.0f;
	mpu.magScale[1] = (67.953 - -1.434)/2.0f;
	mpu.magScale[2] = (76.485 - -4.509)/2.0f;
	float avg = (mpu.magScale[0] + mpu.magScale[1] + mpu.magScale[2])/3.0f;
	mpu.magScale[0] = avg/mpu.magScale[0];
	mpu.magScale[1] = avg/mpu.magScale[1];
	mpu.magScale[2] = avg/mpu.magScale[2];

	mpu.calibrated = 1;
}
void readAcc(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MPU, 0x3B, buffer, 6);

	mpu.acc[0] = ((int16_t) ((buffer[0] << 8) | buffer[1]))  / ACC_FACT;
	mpu.acc[1] = ((int16_t) ((buffer[2] << 8) | buffer[3]))  / ACC_FACT;
	mpu.acc[2] = ((int16_t) ((buffer[4] << 8) | buffer[5]))  / ACC_FACT;

	if(mpu.calibrated){
		mpu.acc[0] -= mpu.accError[0];
		mpu.acc[1] -= mpu.accError[1];
		mpu.acc[2] -= mpu.accError[2];
	}
}
void readGyro(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MPU, 0x43, buffer, 6);

	mpu.gyro[0] = ((int16_t) ((buffer[0] << 8) | buffer[1])) / GYRO_FACT;
	mpu.gyro[1] = ((int16_t) ((buffer[2] << 8) | buffer[3])) / GYRO_FACT;
	mpu.gyro[2] = ((int16_t) ((buffer[4] << 8) | buffer[5])) / GYRO_FACT;

	if(mpu.calibrated){
		mpu.gyro[0] -= mpu.gyroError[0];
		mpu.gyro[1] -= mpu.gyroError[1];
		mpu.gyro[2] -= mpu.gyroError[2];
	}
}

void readMag(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, MAG, 0x02, buffer, 1);
	uint8_t st1 = buffer[0];

	if( !(st1 & (1 << 0)) ) return;
	i2c_master_rx(&i2c_handle, MAG, 0x03, buffer, 7);

	mpu.mag[0] = ((int16_t) ((buffer[1] << 8) | buffer[0]) / MAG_FACT); //* mpu.magASA[0];
	mpu.mag[1] = ((int16_t) ((buffer[3] << 8) | buffer[2]) / MAG_FACT); //* mpu.magASA[1];
	mpu.mag[2] = ((int16_t) ((buffer[5] << 8) | buffer[4]) / MAG_FACT); //* mpu.magASA[2];

	//change axis to align with the acc and gyro
	float temp = mpu.mag[0];
	mpu.mag[0] = mpu.mag[1];
	mpu.mag[1] = temp;
	mpu.mag[2] = -mpu.mag[2];

	uint8_t st2 = buffer[6];
	if(st2 & (1 << 3))
		printStrln("Error magnetometer overflow");

	if(mpu.calibrated){
		mpu.mag[0] = (mpu.mag[0] * mpu.magScale[0]) - mpu.magError[0];
		mpu.mag[1] = (mpu.mag[1] * mpu.magScale[1]) - mpu.magError[1];
		mpu.mag[2] = (mpu.mag[2] * mpu.magScale[2]) - mpu.magError[2];
	}
}

void calculateAngles(float dt){
	float accRoll, accPitch, magYaw;
	float roll, pitch, yaw;
	roll = mpu.angles[0];
	pitch = mpu.angles[1];
	yaw = mpu.angles[2];

	float ax, ay, az;
	float gx, gy, gz;
	float mx, my, mz;
	ax = mpu.acc[0];
	ay = mpu.acc[1];
	az = mpu.acc[2];

	gx = mpu.gyro[0];
	gy = mpu.gyro[1];
	gz = mpu.gyro[2];

	mx = mpu.mag[0];
	my = mpu.mag[1];
	mz = mpu.mag[2];

	// madgwick->dt = dt;

	accRoll = atan2(ay, sqrt(ax*ax + az*az));
	accRoll = toDeg(accRoll);
	roll = 0.96*(roll + gx*dt) + 0.04*accRoll;
	float radRoll = toRad(roll);

	//accPitch = atan2(-ax, ay*sinf(radRoll) + az*cosf(radRoll) );
	accPitch = atan2(-ax, sqrt(ay*ay + az*az));
	accPitch = toDeg(accPitch);
	pitch = 0.96*(pitch + gy*dt) + 0.04*accPitch;
	float radPitch = toRad(pitch);

	magYaw = atan2(mz*sinf(radRoll) - my*cosf(radRoll), mx*cosf(radPitch) + my*sinf(radPitch)*sinf(radRoll) + mz*sinf(radPitch)*cosf(radRoll));
	magYaw = toDeg(magYaw);

	if(magYaw > 175 || magYaw < -175)
		yaw = magYaw;
	else
		yaw = 0.96*(yaw + gz*dt) + 0.04*magYaw;

	mpu.angles[0] = roll;
	mpu.angles[1] = pitch;
	mpu.angles[2] = yaw;
	// mpu.angles[2] += gz*dt;
}

void printValues(){
	// printFloat(mpu.acc[0]);
	// USART2SendByte(',');
	// printFloat(mpu.acc[1]);
	// USART2SendByte(',');
	// printFloat(mpu.acc[2]);
	// USART2SendByte(',');
	// printStr("\t\t\t");
	// printFloat(mpu.gyro[0]);
	// printStr(",\t");
	// // USART2SendByte(',');
	// printFloat(mpu.gyro[1]);
	// printStr(",\t");
	// // USART2SendByte(',');
	// printFloat(mpu.gyro[2]);
	// printStr(",\t\t\t");
	// USART2SendByte(',');
	// printStr("\t\t\t");
	// printFloat(mpu.mag[0]);
	// USART2SendByte(',');
	// printFloat(mpu.mag[1]);
	// USART2SendByte(',');
	// printFloat(mpu.mag[2]);
	printFloat(mpu.angles[0]);
	printStr(",\t");
	printFloat(mpu.angles[1]);
	printStr(",\t");
	printFloat(mpu.angles[2]);
	USART2SendByte('\n');
}