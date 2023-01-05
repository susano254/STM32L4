#include <stm32l432kc.h>

#ifndef RCC_H
#define RCC_H

/****************************AHB1 BUS Clocks****************************/
#define RCC_DMA1_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 0))
#define RCC_DMA2_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 1))
#define RCC_FLASH_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 8))
#define RCC_CRC_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 12))
#define RCC_TSC_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 16))

/****************************AHB2 BUS Clocks****************************/
#define RCC_GPIOA_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 0))
#define RCC_GPIOB_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 1))
#define RCC_GPIOC_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 2))
#define RCC_GPIOD_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 3))
#define RCC_GPIOE_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 4))
#define RCC_GPIOH_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 5))
#define RCC_ADC_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 13))
#define RCC_RNG_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 18))

/****************************APB1 BUS Clocks****************************/
#define RCC_I2C1_CLK_ENABLE()	(RCC->APB1ENR1 |= (1 << 21))
#define RCC_I2C3_CLK_ENABLE()	(RCC->APB1ENR1 |= (1 << 23))
#define RCC_USART2_CLK_ENABLE()	(RCC->APB1ENR1 |= (1 << 17))
#define RCC_TIM2_CLK_ENABLE()	(RCC->APB1ENR1 |= (1 << 0))


/****************************APB2 BUS Clocks****************************/
#define RCC_TIM1_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 11))
#define RCC_SPI1_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 12))
#define RCC_USART1_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 14))
#define RCC_TIM15_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 16))
#define RCC_TIM16_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 17))

#define RCC_REG_CCIPR_I2C1SEL	((uint32_t) 12)
#define RCC_REG_CCIPR_I2C3SEL	((uint32_t) 16)
typedef enum {
  PCLK = 0b00,
  SYSCLK = 0b01,
  HSI16 = 0b10,
  LSE = 0b11
} clocks_t;



void RCC_I2C3_CLK_SEL(clocks_t clock){
	RCC->CCIPR &= ~(0b11 << RCC_REG_CCIPR_I2C3SEL);
	RCC->CCIPR |= (clock << RCC_REG_CCIPR_I2C3SEL);
 }
void RCC_I2C1_CLK_SEL(clocks_t clock){
	RCC->CCIPR &= ~(0b11 << RCC_REG_CCIPR_I2C1SEL);
	RCC->CCIPR |= (clock << RCC_REG_CCIPR_I2C1SEL);
 }

void RCC_HSI16_CLK_ENABLE(){
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

#endif