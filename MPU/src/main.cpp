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
	Madgwick madgwick(0.5f);
	ZeroVelocityUpdate gyroFilter(5, Vector3(3.0f, 3.0f, 3.0f));

	uint32_t millis = 0;
	uint32_t micros = 0;
	while(1){
		mpu.readAcc();
		mpu.readGyro();
		mpu.readMag();
		
		mpu.printGyro();
		// float dt_1 = Systick.getDeltaT(millis);
		// millis = Systick.millis;

		// dt = System.getDeltaT(micros);
		// micros = System.getMicros();

		// mpu.calculateAngles(dt);
		// mpu.angles = mahony.update(mpu.acc, mpu.gyro, dt);
		// mpu.angles = madgwick.update(mpu.acc, mpu.gyro, dt);

		// mpu.gyro = gyroFilter.update(mpu.gyro);
		// mpu.q = madgwick.MadgwickQuaternionUpdate(mpu.acc, mpu.gyro, mpu.mag, dt); 
		// mpu.printQuaternion();

		// mpu.printAcc();
		// mpu.printAccG();
		// mpu.printVelocity();
		// mpu.printPosition();
		// mpu.printAngles();
		// mpu.printValues();
	}

	return 0;
}