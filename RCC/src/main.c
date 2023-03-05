#include <RCC.h>
#include <GPIO.h>


I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;
FLASH_TypeDef* FLASH_Base = FLASH;

int main(){
	SystemInit();
	gpio_pin_conf_t led;
	led.pin = D3;
	led.mode = GPIO_PIN_OUTPUT_MODE;
	led.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	led.pupd = GPIO_PIN_PUPD_NO_PUPD;
	led.speed = GPIO_PIN_OSPEED_LOW;
	led.alternate_function = -1;

	RCC_GPIOB_CLK_ENABLE();
	gpio_init(GPIOB, &led);


	uint8_t state = 1;
	while(1){
		for(int i = 0; i < 8000000; i++);
		gpio_write_pin(GPIOB, led.pin, state);
		state = !state;
	}

}