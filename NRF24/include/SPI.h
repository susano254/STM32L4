#include <stm32l432kc.h>

#ifndef 	SPI_H
#define 	SPI_H

#define FRXTH	(1 << 12);
#define SPI1EN	(1 << 12);
#define BR 		3
#define MSTR	2
#define SSM 	9
#define SSI 	8
#define SPE 	6

void SPIInit(uint8_t);
uint8_t SPITransfer(uint8_t);

void SPIInit(uint8_t prescaler){
	//enable clock for GPIOA
	GPIOInit('A');

	//PA5, PA6, PA7 alternate function mode
	setToAF(GPIOA, 5);
	setToAF(GPIOA, 6);
	setToAF(GPIOA, 7);

	//set pin5,6,7 to AF7	
	setAFR(GPIOA, 5, 5);
	setAFR(GPIOA, 6, 5);
	setAFR(GPIOA, 7, 5);


	//enable clock for the peripheral
	RCC->APB2ENR |= SPI1EN;
	//set baudrate
	SPI1->CR1 |= (prescaler << BR);
	//set SSM and SSI
	SPI1->CR1 |= (1 << SSM);
	SPI1->CR1 |= (1 << SSI);
	//set to master mode
	SPI1->CR1 |= (1 << MSTR);
	//set RXNE to be generated on 8 bits
	SPI1->CR2 |= FRXTH;

	//finally enable SPI
	SPI1->CR1 |= (1 << SPE);
}

uint8_t SPITransfer(uint8_t data){
  uint8_t rx;

  //wait for the TXE flag
  while( !(SPI1->SR & (1 << 1)) );

  //force 8-bit data write
  *(volatile uint8_t *)&SPI1->DR = data;

  //wait for the RXNE flag
  while( !(SPI1->SR & (1 << 0)) );

  //force 8-bit data access
  rx = *(volatile uint8_t*) &SPI1->DR;

  return rx;
}

#endif