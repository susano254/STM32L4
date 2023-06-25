#include <MPU.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
#include <string.h>
#include <Core.h>

using namespace global;

int main(){
	MPU_t mpu;
	float dt = 0.0f;

	System.Init();
	Systick.Init();
	Serial.begin(115200);
	mpu.Init();
	mpu.calibrate();
	// mpu.calibrateAcc();
	// while(1);
	Mahony mahony(2.5, 0.0f);
	Madgwick madgwick(0.1);
	
	while(1){
		mpu.readAcc();
		mpu.readGyro();
		mpu.readMag();
		dt = Systick.getDeltaT();
		// mpu.calculateAngles(dt);
		// mpu.angles = mahony.update(mpu.acc, mpu.gyro, dt);
		mpu.angles = madgwick.update(mpu.acc, mpu.gyro, dt);
		mpu.printValues();
		// mpu.printAngles();
	}

	return 0;
}