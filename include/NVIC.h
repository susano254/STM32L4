#ifndef 	NVIC_H
#define 	NVIC_H

#include <stm32l432kc.h>

#ifdef __cplusplus
extern "C" {
#endif                                      
	void NVIC_EnableInterrupt(uint8_t);
	void NVIC_ClearPending(uint8_t);
#ifdef __cplusplus
}
#endif                                      

#endif