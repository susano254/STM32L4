#include <stm32l432kc.h>

int stringIndex = 0;
char message[100];

void NVIC_ClearPending(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ICPR[reg] |= (1 << bitNumber);
}

void NVIC_EnableInterrupt(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ISER[reg] |= 1 <<  bitNumber;
}

#define RXNE 5
#define RXNEIE RXNE

void USART2Init(int baudRate, const uint8_t CLOCK){
	//configure the pins
	//enable clock for GPIOA
	GPIOInit('A');
	//PA2, PA15 alternate function mode
	setToAF(GPIOA, 2);
	setToAF(GPIOA, 15);
	//set pin2 to AF7	
	setAFR(GPIOA, 2, 7);
	//set pin15 to AF3
	setAFR(GPIOA, 15, 3);

	//Enable HSI clock
	HSI16Enable();

	//enable clock
	RCC->APB1ENR1 |= (1 << 17);
	//select sysclk for the peripheral clock
	RCC->CCIPR &= ~(3 << 2);
	RCC->CCIPR |= (CLOCK << 2);

	//write the baudrate 
	baudRate = 16000000/baudRate;
	USART2->BRR = baudRate;

	//disable Ovverrun
	USART2->CR3 |= (1 << 12);

	//enable peripheral
	//TE and RE set 
	USART2->CR1 |= (3 << 2);

	//UE (USART enable) set
	USART2->CR1 |= (1 << 0);

	//wait for both TE and RE acknowledge by the hardware 
	int TR_EACK = (3 << 21);
	while (!(USART2->ISR & TR_EACK));
}

void USART2SendByte(uint8_t value){
	uint8_t TXE = 1 << 7;
	//wait until TXE is set
	while ( !(USART2->ISR & TXE) );

	*(volatile uint8_t*)&USART2->TDR = value;
}

void USART2Send(uint8_t *value, uint16_t size){
	uint8_t TC = 3 << 6;

	for(int i = 0; i < size; i++)
		USART2SendByte(value[i]);
	
	//wait until TC is set
	while ( !(USART2->ISR & TC) );
}

void printStrln(uint8_t *value, uint16_t size){
	USART2Send(value, size);
	USART2SendByte('\n');
}

void USART_EnableInterrupt(USART_TypeDef *USARTx, uint8_t interrupt){
	if(interrupt < 4 || interrupt > 8) return;

	//first enable interrupt for the USART handler
	NVIC_EnableInterrupt(USART2_IRQn);
	//enable RXNEIE
	USARTx->CR1 |= 1 << interrupt;
}


void USART2_IRQHandler(){
	uint8_t value = *(volatile uint8_t*)&USART2->RDR;
	message[stringIndex++] = value;
	if(value == '\n' || value == '\r' || value == '\0'){
		//reset the string index
		USART2Send(message, stringIndex);
		stringIndex = 0;
	}
	NVIC_ClearPending(USART2_IRQn);
}



