#include <RCC.h>


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
	//Enable HSI clock
	RCC_HSI16_CLK_ENABLE();
	//enable fpu 
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  

	return;
}