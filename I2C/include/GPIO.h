#include <stm32l432kc.h>

#ifndef 	GPIO_H
#define 	GPIO_H

void GPIOInit(char);
void setToInputMode(GPIO_TypeDef*, uint8_t);
void setToOuputMode(GPIO_TypeDef*, uint8_t);
void setToAF(GPIO_TypeDef*, uint8_t);
void setToAnalogMode(GPIO_TypeDef*, uint8_t);
void setAFR(GPIO_TypeDef*, uint8_t, uint8_t);


void GPIOInit(char x){
	switch (x) {
	case 'A':
		//enable clock for GPIOA
		RCC->AHB2ENR |= (1 << 0);
		break;
	case 'B':
		//enable clock for GPIOA
		RCC->AHB2ENR |= (1 << 1);
		break;
	case 'C':
		//enable clock for GPIOA
		RCC->AHB2ENR |= (1 << 2);
		break;
	}
}

void setToInputMode(GPIO_TypeDef* GPIOX, uint8_t pinNumber){
	uint8_t baseBit = pinNumber * 2;
	GPIOX->MODER &= ~(1 << baseBit++);
	GPIOX->MODER &= ~(1 << baseBit);
}
void setToOuputMode(GPIO_TypeDef* GPIOX, uint8_t pinNumber){
	uint8_t baseBit = pinNumber * 2;
	GPIOX->MODER |= (1 << baseBit++);
	GPIOX->MODER &= ~(1 << baseBit);
}
void setToAF(GPIO_TypeDef* GPIOX, uint8_t pinNumber){
	uint8_t baseBit = pinNumber * 2;
	GPIOX->MODER &= ~(1 << baseBit++);
	GPIOX->MODER |= (1 << baseBit);
}
void setToAnalogMode(GPIO_TypeDef* GPIOX, uint8_t pinNumber){
	uint8_t baseBit = pinNumber * 2;
	GPIOX->MODER |= (1 << baseBit++);
	GPIOX->MODER |= (1 << baseBit);
}
void setAFR(GPIO_TypeDef* GPIOX, uint8_t pinNumber, uint8_t mode){
	uint8_t baseBit = (pinNumber * 4) % 32;
	uint8_t reg = pinNumber < 8 ? 0 : 1;

	GPIOX->AFR[reg] &= ~(0b1111 << baseBit);
	GPIOX->AFR[reg] |= (mode << baseBit);
}

#endif