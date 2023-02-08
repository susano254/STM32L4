#ifndef 	NVIC_H
#define 	NVIC_H

#include <stm32l432kc.h>

void NVIC_EnableInterrupt(uint8_t);
void NVIC_ClearPending(uint8_t);

#endif