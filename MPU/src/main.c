#include <MPU.h>
#include <RCC.h>
#include <USART.h>
#include <math.h>
#include <string.h>

I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;

void Systick_init(uint32_t reload){
	//init systick
	SysTick->LOAD = reload;
	SysTick->VAL = 0;
	SysTick->CTRL |= 1 << 0;
}

float getDeltaT(){
	float dt;
	dt = 0xffffff - SysTick->VAL;
	dt *= 0.0000001;
	SysTick->VAL = 0;

	return dt;
}

int main(){
	float dt = 0.0f;

	SystemInit();
	USART2Init(115200, HSI16);
	Systick_init(0xffffff);
	mpu_init();
	MPU_t mpu = *getMpu();
	
	while(1){
		readAcc();
		readGyro();
		readMag();
		dt = getDeltaT();
		calculateAngles(dt);
		printValues();
		
		// float yaw = (float) atan2(mpu.mag[1], mpu.mag[0]);
		// yaw = (yaw/M_PI)*180;
		// printFloat(yaw);
		// printStrln("");
	}

	return 0;
}