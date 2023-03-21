#ifndef 	SPI_H
#define 	SPI_H

#include <stm32l432kc.h>

#define FRXTH	(1 << 12);
#define BR 		3
#define MSTR	(1 << 2)
#define SSM 	(1 << 9)
#define SSI 	(1 << 8)
#define SPE 	(1 << 6)

#ifdef __cplusplus
extern "C" {
#endif                                      
	void SPIInit(uint8_t);
	uint8_t SPITransfer(uint8_t);
#ifdef __cplusplus
}
#endif                                      

#endif