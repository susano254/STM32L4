#ifndef 	MPU_H
#define 	MPU_H

#include <stm32l432kc.h>

#define MPU 		0x68
#define MAG 		0x0C

#define ACC_FACT	16384.0f	
#define GYRO_FACT	131.0f	
#define MAG_FACT	6.6667f
#define CAL_FACT	1000

typedef struct {
	uint8_t calibrated;

	float acc[3];
	float accError[3];

	float gyro[3];
	float gyroError[3];

	float mag[3];
	float magASA[3];
	float magError[3];
	float magScale[3];

	float angles[3];
} MPU_t;


#ifdef __cplusplus
extern "C" {
#endif
	MPU_t* getMpu();
	void mpu_init();
	void readAcc();
	void readGyro();
	void readMag();
	void printValues();
	void calibrate();
	void calculateAngles(float dt);
#ifdef __cplusplus
}
#endif

#endif