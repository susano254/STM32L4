#include <USART.h>
#include <GPIO.h>
#include <RCC.h>

I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;

void main(){
	//init USART2  and Use HSI 16 for the clock
	SystemInit();

	USART2Init(115200, HSI16);
	USART_EnableInterrupt(USART2,  5);

	while (1) {
		printFloat(-0.0178);
		printStrln("");
	}
}