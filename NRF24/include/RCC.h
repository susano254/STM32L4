#include <stm32l432kc.h>

void HSI16Enable(){
	int HSION = 1 << 8;
	int HSIRDY = 1 << 10;

	//enable HSION
	RCC->CR |= HSION;
	//wait until ready
	while(RCC->CR & HSIRDY);
}

void SystemInit(){
	return;
}
