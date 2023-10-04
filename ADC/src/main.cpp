#include <ADC.h>
#include <RCC.h>
#include <USART.h>
#include <GPIO.h>
#include <Core.h>



using namespace global;

int main(){
	System.Init();
	Serial.begin(115200);

	uint16_t data;
	ADCx_init_t init_struct;
	init_struct.instance = ADC1;


	ADCInit(&init_struct);

	while(1){
		// ADC1->CR |= ADC_CR_ADSTART;
		// while( !(ADC1->ISR & ADC_ISR_EOC) );
		// data = ADC1->DR;
		uint32_t ch5, ch6;
		ch5 = analogRead(ADC1, 5);
		ch6 = analogRead(ADC1, 6);
		Serial.printInt(ch5);
		Serial.printStr(", ");
		Serial.printInt(ch6);
		Serial.printStrln("");

		// gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_LOW);
		// gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_LOW);
		// gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_LOW);
		// gpio_write_pin(GPIOA, led4, GPIO_OUTPUT_LOW);
		// if(data > 500)
		// 	gpio_write_pin(GPIOA, led1, GPIO_OUTPUT_HIGH);
		// if(data > 1500)
		// 	gpio_write_pin(GPIOA, led2, GPIO_OUTPUT_HIGH);
		// if(data > 2500)
		// 	gpio_write_pin(GPIOA, led3, GPIO_OUTPUT_HIGH);
		// if(data > 3500)
		// 	gpio_write_pin(GPIOA, led4, GPIO_OUTPUT_HIGH);
	}
}