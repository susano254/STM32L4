#ifndef 	MPU_H
#define 	MPU_H

#include <stm32l432kc.h>
#include <AML/AML.h>

#define MPU 		0x68
#define MAG 		0x0C

#define ACC_FACT	8192.0f	
#define GYRO_FACT	16.4f	
#define MAG_FACT	6.6667f
#define CAL_FACT	1000

using namespace AML;

struct MPU_t {
	bool calibrated = true;

	Vector3 acc;
	Vector3 accError;

	Vector3 gyro;
	Vector3 gyroError;

	Vector3 mag;
	Vector3 magASA;
	Vector3 magError;
	Vector3 magScale;

	EulerAngles angles;
	// union {
	// 	Vector3 angles;
	// 	struct {
	// 		float roll, pitch, yaw;
	// 	};
		
	// };
	
	MPU_t(){

	}

	void Init();
	void readAcc();
	void readGyro();
	void readMag();
	void printValues();
	void printErrors();
	void printAngles();
	void calibrate();
	void calibrateAcc();
	void calibrateGyro();
	void calibrateMag();
	void calculateAngles(float dt);
};


struct Madgwick {
	float beta;
	Quaternion q;
	Vector3 error;

	Madgwick() : beta(0.1f), q(1, 0, 0, 0), error(0.0f) {}
	Madgwick(float beta) : beta(beta), q(1, 0, 0, 0), error(0.0f) {}
	EulerAngles update(Vector3 &acc, Vector3 &gyro, float dt);
};
struct Mahony {
	float kp, ki;
	Quaternion q;
	Vector3 error;

	Mahony() : kp(0.0f), ki(0.0f), q(1, 0, 0, 0), error(0.0f) {}
	Mahony(float kp, float ki) : kp(kp), ki(ki), q(1, 0, 0, 0), error(0.0f) {}
	EulerAngles update(Vector3 &acc, Vector3 &gyro, float dt);
};

// #ifdef __cplusplus
// extern "C" {
// #endif
// 	MPU_t* getMpu();
// 	void mpu_init();
// 	void readAcc();
// 	void readGyro();
// 	void readMag();
// 	void printValues();
// 	void calibrate();
// 	void calculateAngles(float dt);
// #ifdef __cplusplus
// }
// #endif

#endif