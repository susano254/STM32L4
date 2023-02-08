#include <NRF24.h>
#include <USART.h>
#include <RCC.h>


I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;

int main(){
	uint8_t reg;
	SystemInit();
	USART2Init(115200, HSI16);
	NRF24Init(CE_PIN, CSN_PIN);

	reg = NRF24ReadReg(0x00);
	reg = NRF24ReadReg(0x01);
	reg = NRF24ReadReg(0x02);
	reg = NRF24ReadReg(0x03);
	reg = NRF24ReadReg(0x04);
	reg = NRF24ReadReg(0x05);
	reg = NRF24ReadReg(0x06);
	reg = NRF24ReadReg(0x10);
	while(1){
		printInt(reg);
		printStrln("");
	}

  return 0;
}