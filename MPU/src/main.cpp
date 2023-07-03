#include <MPU.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
#include <string.h>
#include <Core.h>

#define M_PIf ((float) M_PI)
using namespace global;

int main(){
	MPU_t mpu;
	float dt = 0.0f;

	System.Init();
	Systick.Init();
	Serial.begin(115200);
	mpu.Init();
	mpu.calibrate();

	//mpu.calibrateAcc();
	//while(1);

	Mahony mahony(2.5, 0.0f);
	Madgwick madgwick(1.5);

	uint32_t micros = 0;

	//for(int i = 0; i < 5; i++){
	//	mpu.readAcc();
	//	mpu.readGyro();
	//	mpu.readMag();
	//	
	//	dt = Systick.getDeltaT(micros);
	//	micros = Systick.getMicros();

	//	madgwick.MadgwickQuaternionUpdate(mpu.acc, mpu.gyro, mpu.mag, dt, false);
	//	madgwick.offset_q = inverse(madgwick.q);
	//	madgwick.offset_angles = quat2EulerAngles(madgwick.offset_q);
	//	madgwick.offset_angles.phi *= (180.0f/M_PIf);
	//	madgwick.offset_angles.theta *= (180.0f/M_PIf);
	//	madgwick.offset_angles.psi *= (180.0f/M_PIf);
	//}

	while(1){
		mpu.readAcc();
		mpu.readGyro();
		mpu.readMag();
		
		dt = Systick.getDeltaT(micros);
		micros = Systick.getMicros();

		// mpu.calculateAngles(dt);
		// mpu.angles = mahony.update(mpu.acc, mpu.gyro, dt);
		// mpu.angles = madgwick.update(mpu.acc, mpu.gyro, dt);
		mpu.angles = madgwick.MadgwickQuaternionUpdate(mpu.acc, mpu.gyro, mpu.mag, dt, false); 

		madgwick.printQuaternion();
		// mpu.printAngles();
		// mpu.printValues();
	}

	return 0;
}