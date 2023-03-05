#include <ADC.h>
#include <RCC.h>
#include <USART.h>
#include <GPIO.h>


I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type *NVIC_Base = NVIC;
TIM_TypeDef *TIM2_Base = TIM2;
ADC_TypeDef *ADC1_Base = ADC1;


int main(){
	uint16_t data;
	uint8_t led1, led2, led3, led4;
	led1 = PA0;
	led2 = PA1;
	led3 = PA3;
	led4 = PA4;
	gpio_pin_conf_t led;
	ADCx_init_t init_struct;
	init_struct.instance = ADC1;
	init_struct.numOfConversions = 1;
	led.mode = GPIO_PIN_OUTPUT_MODE;
	led.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	led.pupd = GPIO_PIN_PUPD_NO_PUPD;
	led.speed = GPIO_PIN_OSPEED_LOW;
	led.alternate_function = -1;

	SystemInit();
	USART2Init(115200, HSI16);
	ADCInit(&init_struct);

	RCC_GPIOA_CLK_ENABLE();
	//init  the output pins
	led.pin = led1;
	gpio_init(GPIOA, &led);
	led.pin = led2;
	gpio_init(GPIOA, &led);
	led.pin = led3;
	gpio_init(GPIOA, &led);
	led.pin = led4;
	gpio_init(GPIOA, &led);

	while(1){
		ADC1->CR |= ADC_CR_ADSTART;
		while( !(ADC1->ISR & ADC_ISR_EOC) );
		data = ADC1->DR;
		printInt(data);
		printStrln("");

		gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_LOW);
		gpio_write_pin(GPIOA, led4, GPIO_OUTPUT_LOW);
		if(data > 500)
			gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_HIGH);
		if(data > 1500)
			gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_HIGH);
		if(data > 2500)
			gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_HIGH);
		if(data > 3500)
			gpio_write_pin(GPIOA, led4, GPIO_OUTPUT_HIGH);
	}
}