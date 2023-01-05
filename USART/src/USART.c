#include <stm32l432kc.h>
#include <RCC.h>
#include <GPIO.h>
#include <USART.h>

void main(){
	//init USART2  and Use HSI 16 for the clock
	USART2Init(115200, HSI16);
	USART_EnableInterrupt(USART2,  RXNEIE);

	while (1) {}
}
