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

	char buffer[100] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};
	NRF24Init(CE_PIN, CSN_PIN);
	NRF24RxMode(buffer, 0);

	char read[8];
	for(int i = 0; i < 7; i++){
		read[i] = NRF24ReadReg(i);
	}

	uint8_t status = 0xff;
	receive(buffer);
	while(1){
		status = NRF24ReadReg(STATUS);
		if(isDataAvailable(0)){
			printStrln("Data found");
			receive(buffer);
			printStrln(buffer);
		}
		//else {
		//	printStrln("No data found");
		//}
	}

  return 0;
}