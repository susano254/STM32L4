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
	// Systick.Init();
	
	while(1){
		mpu.readAcc();
		mpu.readGyro();
		mpu.readMag();
		dt = Systick.getDeltaT();
		mpu.calculateAngles(dt);
		mpu.printValues();
		// mpu.printAngles();
	}

	return 0;
}