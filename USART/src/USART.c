#include <USART.h>
#include <GPIO.h>
#include <RCC.h>
#include <NVIC.h>
#include <string.h>

int stringIndex = 0;
uint8_t message[100];

#define PRECISION 3
#define PREC_RADIX 1000



void hal_usart_enable(USART_TypeDef *USARTx){
	USARTx->CR1 |= USART_REG_CR1_UE;
}
void hal_usart_disable(USART_TypeDef *USARTx){
	USARTx->CR1 &= ~USART_REG_CR1_UE;
}

void hal_usart_tx_enable(USART_TypeDef *USARTx){
	USARTx->CR1 |= USART_REG_CR1_TE;
}
void hal_usart_tx_disable(USART_TypeDef *USARTx){
	USARTx->CR1 &= ~USART_REG_CR1_TE;
}

void hal_usart_rx_enable(USART_TypeDef *USARTx){
	USARTx->CR1 |= USART_REG_CR1_RE;
}
void hal_usart_rx_disable(USART_TypeDef *USARTx){
	USARTx->CR1 &= ~USART_REG_CR1_RE;
}

void hal_usart_error_interrupt_enable(USART_TypeDef *USARTx){
	USARTx->CR3 |= USART_REG_CR3_EIE;
}
void hal_usart_error_interrupt_disable(USART_TypeDef *USARTx){
	USARTx->CR3 &= ~USART_REG_CR3_EIE;
}

void hal_usart_configure_world_length(USART_TypeDef *USARTx, uint8_t worldLength){
	if(worldLength == WL_9){
		USARTx->CR1 |=  USART_REG_CR1_M0;
		USARTx->CR1 &= ~USART_REG_CR1_M1;
	}
	else if(worldLength == WL_7){
		USARTx->CR1 &= ~USART_REG_CR1_M0;
		USARTx->CR1 |=  USART_REG_CR1_M1;
	}
	else {
		USARTx->CR1 &= ~USART_REG_CR1_M0;
		USARTx->CR1 &= ~USART_REG_CR1_M1;
	}
}


void hal_usart_configure_stop_bits(USART_TypeDef *USARTx, uint8_t nstop){
	USARTx->CR2 &= ~(0x11 << USART_REG_CR2_STOP_BITS);

	if(nstop == USART_STOP_BITS_HALF)
		USARTx->CR2 |=  (0x01 << USART_REG_CR2_STOP_BITS);
	else if(nstop == USART_STOP_BITS_TWO)
		USARTx->CR2 |=  (0x02 << USART_REG_CR2_STOP_BITS);
	else if(nstop == USART_STOP_BITS_ONE_HALF)
		USARTx->CR2 |=  (0x03 << USART_REG_CR2_STOP_BITS);
	else 
		USARTx->CR2 |=  (0x00 << USART_REG_CR2_STOP_BITS);
}

void hal_usart_configure_over_sampling(USART_TypeDef *USARTx, uint8_t over8){
	if(over8 == USART_OVERSAMPLING_8)
		USARTx->CR1 |=  USART_REG_CR1_OVER8;
	else 
		USARTx->CR1 &= ~USART_REG_CR1_OVER8;
}

void hal_usart_init(usart_handle_t *handle){
	//configure world length

	//configure number of stop bits

	//configure oversampling 

	//set baudrate

	//enable TX block

	//enable RX block

	//enable peripheral


	//set state 
	handle->tx_state = HAL_USART_STATE_READY;
	handle->rx_state = HAL_USART_STATE_READY;
	handle->errorCode = HAL_USART_ERROR_NONE;

}

void USART2Init(int baudRate, const uint8_t CLOCK){
	//configure the pins
	gpio_pin_conf_t pinA2, pinA15;
	pinA2.pin = PA2;
	pinA15.pin = PA15;
	//PA2, PA15 alternate function mode
	pinA2.mode = GPIO_PIN_ALT_FUN_MODE;
	pinA15.mode = GPIO_PIN_ALT_FUN_MODE;
	pinA2.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	pinA15.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	pinA2.pupd = GPIO_PIN_PUPD_NO_PUPD;
	pinA15.pupd = GPIO_PIN_PUPD_NO_PUPD;
	pinA2.speed = GPIO_PIN_OSPEED_HIGH;
	pinA15.speed = GPIO_PIN_OSPEED_HIGH;
	pinA2.alternate_function = 7; 			 //set pin2 to AF7	
	pinA15.alternate_function = 3;			 //set pin15 to AF3

	//enable clock for GPIOA
	RCC_GPIOA_CLK_ENABLE();
	gpio_init(GPIOA, &pinA2);
	gpio_init(GPIOA, &pinA15);
	
	//enable clock
	RCC_USART2_CLK_ENABLE();
	//select clock for the peripheral clock
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

void floatToStr(float num, char *str){
	char intStr[10], floatStr[10];
	int integerPart, floatPart;
	uint8_t negative = 0;

	//initialize integer part to the type casted value (will remove what is after the decimal point)
	integerPart = num;
	//multiply the value by 10^3 and modulus to get the first 3 values after the decimal point
	floatPart = (int) (num * 1000.0f) % 1000;
	//if negative 
	if(num < 0){
		negative = 1;
		integerPart = -integerPart;
		floatPart = -floatPart;
	}

	//convert both numbers
	intToStr(integerPart, intStr);
	intToStr(floatPart, floatStr);

	int floatLen = length(floatStr);
	if(floatLen < 3){
		char temp[3] = {0, 0, 0};
		int diff = 3 - floatLen;

		for(int i = 0; i < diff; i++)
			strcat(temp, "0");
		strcat(temp, floatStr);
		strcpy(floatStr, temp);
	}

	//finally combine them
	if(negative){
		char temp[20] = "-";
		strcat(temp, intStr);
		strcpy(intStr, temp);
	}
	strcat(intStr, ".");
	strcpy(str, intStr);
	strcat(str, floatStr);
}
void printFloat(float num){
	char str[30];
	floatToStr(num, str);
	printStr(str);
}
void printInt(int num){
	char str[30];
	intToStr(num, str);
	printStr(str);
}
void intToStr(int num, char *pStr){
	int mod, i;
	char str[20];
	uint8_t negative = 0;

	if(num < 0){ 
		negative = 1;
		num = -num;
	}
	

	if(num == 0) { 
		strcpy(pStr, "0");
		return;
	}

	for(i = 0; num != 0; i++){
		mod = num % 10;
		str[i] = mod + '0';
		num /= 10;
	}
	str[i] = '\0';
	for(int n = 0, m = i - 1; n < m; n++, m--){
		char temp = str[n];
		str[n] = str[m];
		str[m] = temp;
	}

	if(negative){
		strcpy(pStr,"-");
		strcat(pStr, str);
	}
	else {
		strcpy(pStr, str);
	}
}

void printStrln(char *value){
	//add one to for the null byte at the end
	int size = length(value)+1;
	USART2Send((uint8_t *)value, size);
	USART2SendByte('\n');
}

void printStr(char *value){
	//add one to for the null byte at the end
	int size = length(value)+1;
	USART2Send((uint8_t *)value, size);
}
int length(char *str){
	char c = str[0];
	int len = 0;

	while (c != '\0') {
		len++;
		c = str[len];
	}

	return len;
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
