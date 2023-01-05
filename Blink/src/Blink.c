#include <stm32l432kc.h>

RCC_TypeDef *RCC = (RCC_TypeDef*) 0x40021000;
GPIO_TypeDef *GPIOA = (GPIO_TypeDef*) 0x48000000;

void main(){
	//enable clock for GPIOA
	RCC->AHB2ENR |= (1 << 0);
	//write 01 in MODER register
	GPIOA->MODER &= ~(1 << 1);
	GPIOA->MODER |= (1 << 0);
	while(1){
		//delay for a while
		for(uint32_t i = 0; i < 90000; i++);
		//write ODR0 to 1
		GPIOA->ODR ^= (1 << 0);
	}
}
