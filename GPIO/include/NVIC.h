#include <stm32l432kc.h>

#ifndef 	NVIC_H
#define 	NVIC_H

void NVIC_EnableInterrupt(uint8_t);
void NVIC_ClearPending(uint8_t);

void NVIC_ClearPending(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ICPR[reg] |= (1 << bitNumber);
}

void NVIC_EnableInterrupt(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ISER[reg] |= 1 <<  bitNumber;
}

#endif