#ifndef 	MPU_H
#define 	MPU_H

#include <stm32l432kc.h>
#include <AML/AML.h>

#define MPU 		0x68
#define MAG 		0x0C


//#define ACC_FACT	16384.0f	
//#define ACC_FACT	8192.0f	
#define ACC_FACT	4096.0f	
//#define ACC_FACT	2048.0f	

//#define GYRO_FACT	131.0f	
//#define GYRO_FACT	65.5f	
//#define GYRO_FACT	32.8f	
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
	void calibrate();
	void calibrateAcc();
	void calibrateGyro();
	void calibrateMag();
	void calculateAngles(float dt);

	//prints
	void printValues();
	void printErrors();
	void printAcc();
	void printGyro();
	void printMag();
	void printAngles();

	private:
		void calibrateAccAxis(uint8_t axis_id);
		void calibrateAccX();
		void calibrateAccY();
		void calibrateAccZ();
};


struct Madgwick {
	float beta;
	Quaternion q, offset_q;
	EulerAngles offset_angles;
	Vector3 error;

	Madgwick() : beta(0.1f), q(1, 0, 0, 0), offset_q(1, 0, 0, 0), error(0.0f) {}
	Madgwick(float beta) : beta(beta), q(1, 0, 0, 0), offset_q(1, 0, 0, 0), error(0.0f) {}
	EulerAngles update(Vector3 &acc, Vector3 &gyro, float dt);
	EulerAngles update(Vector3 &acc, Vector3 &gyro, Vector3 &mag, float dt);
	EulerAngles MadgwickQuaternionUpdate(Vector3 &acc, Vector3 &gyro_degrees, Vector3 &mag, float deltat, bool withOffset);
	void printQuaternion();
};

struct Mahony {
	float kp, ki;
	Quaternion q;
	Vector3 error;

	Mahony() : kp(0.0f), ki(0.0f), q(1, 0, 0, 0), error(0.0f) {}
	Mahony(float kp, float ki) : kp(kp), ki(ki), q(1, 0, 0, 0), error(0.0f) {}
	EulerAngles update(Vector3 &acc, Vector3 &gyro, float dt);
	EulerAngles update(Vector3 &acc, Vector3 &gyro, Vector3 &mag, float dt);
	void printQuaternion();
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