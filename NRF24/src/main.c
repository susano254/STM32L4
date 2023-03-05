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
	uint8_t led1, led2, led3, led4;
	led1 = D0;
	led2 = D1;
	led3 = D2;
	led4 = D3;
	SystemInit();
	USART2Init(115200, HSI16);
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();


	int8_t buffer[100] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};
	NRF24Init(CE_PIN, CSN_PIN);
	NRF24RxMode(buffer, 0);

	gpio_pin_conf_t led;
	led.mode = GPIO_PIN_OUTPUT_MODE;
	led.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	led.pupd = GPIO_PIN_PUPD_NO_PUPD;
	led.speed = GPIO_PIN_OSPEED_LOW;
	led.alternate_function = -1;
	//init  the output pins
	led.pin = led1;
	gpio_init(GPIOA, &led);
	led.pin = led2;
	gpio_init(GPIOA, &led);
	led.pin = led3;
	gpio_init(GPIOA, &led);
	led.pin = led4;
	gpio_init(GPIOB, &led);

	char read[8];
	for(int i = 0; i < 7; i++){
		read[i] = NRF24ReadReg(i);
	}

	uint8_t status = 0xff;
	receive(buffer);
	while(1){
		gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOB, led4, GPIO_OUTPUT_LOW);

		status = NRF24ReadReg(STATUS);
		if(isDataAvailable(0)){
			receive(buffer);
			printData(buffer);
		}

		if(buffer[1] > 30)
			gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_HIGH);
		if(buffer[0] < -30)
			gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_HIGH);
		if(buffer[0] > 30)
			gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_HIGH);
		if(buffer[1] < -30)
			gpio_write_pin(GPIOB, led4, GPIO_OUTPUT_HIGH);
		// else {
		// 	printStrln("No data found");
		// }
	}

  return 0;
}

void printData(int8_t *buffer){
	printInt(buffer[0]);
	printStr(",\t");
	printInt(buffer[1]);
	printStr(",\t");
	printInt(buffer[2]);
	printStr(",\t");
	printInt(buffer[3]);
	printStr(",\t");
	printInt(buffer[4]);
	printStr(",\t");
	printInt(buffer[5]);
	printStr("\n");
}