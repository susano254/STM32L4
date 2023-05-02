#ifndef 	USART_H
#define 	USART_H

#include <stm32l432kc.h>
#include <string>

using namespace std;


#define HAL_USART_ERROR_NONE		((uint32_t) 0x00)	//No Error
#define HAL_USART_ERROR_PE			((uint32_t) 0x01)	//Parity Error
#define HAL_USART_ERROR_NE			((uint32_t) 0x02)	//Noise error
#define HAL_USART_ERROR_FE			((uint32_t) 0x04)	//frame error
#define HAL_USART_ERROR_ORE			((uint32_t) 0x08)	//Overrun error
#define HAL_USART_ERROR_DMA			((uint32_t) 0x10)	//DMA transfer error

#define WL_7		0x07
#define	WL_8		0x08
#define	WL_9		0x09

//typedef enum {
//	STOP_BITS_HALF 		= 0x00,
//	STOP_BITS_ONE 		= 0x01,
//	STOP_BITS_TWO 		= 0x02,
//	STOP_BITS_ONE_HALF 	= 0x12,
//} stop_bits_t;

#define USART_OVERSAMPLING_16		0x00
#define USART_OVERSAMPLING_8		0x01

#define USART_STOP_BITS_HALF		0x00
#define USART_STOP_BITS_ONE			0x01
#define USART_STOP_BITS_TWO			0x02
#define USART_STOP_BITS_ONE_HALF	0x03

//CR1 register 
#define USART_REG_CR1_UE			((uint32_t) (1 << 0))
#define USART_REG_CR1_UESM			((uint32_t) (1 << 1))
#define USART_REG_CR1_RE			((uint32_t) (1 << 2))
#define USART_REG_CR1_TE			((uint32_t) (1 << 3))
#define USART_REG_CR1_IDLEIE		((uint32_t) (1 << 4))
#define USART_REG_CR1_RXNEIE		((uint32_t) (1 << 5))
#define USART_REG_CR1_TCIE			((uint32_t) (1 << 6))
#define USART_REG_CR1_TXEIE			((uint32_t) (1 << 7))
#define USART_REG_CR1_PEIE			((uint32_t) (1 << 8))
#define USART_REG_CR1_PS			((uint32_t) (1 << 9))
#define USART_REG_CR1_PCE			((uint32_t) (1 << 10))
#define USART_REG_CR1_WAKE			((uint32_t) (1 << 11))
#define USART_REG_CR1_M0			((uint32_t) (1 << 12))
#define USART_REG_CR1_MME			((uint32_t) (1 << 13))
#define USART_REG_CR1_CMIE			((uint32_t) (1 << 14))
#define USART_REG_CR1_OVER8			((uint32_t) (1 << 15))
#define USART_REG_CR1_DEDT_4		((uint32_t) (16))
#define USART_REG_CR1_DEAT_4		((uint32_t) (21))
#define USART_REG_CR1_RTOIE			((uint32_t) (1 << 26))
#define USART_REG_CR1_EOBIE			((uint32_t) (1 << 27))
#define USART_REG_CR1_M1			((uint32_t) (1 << 28))


//CR2 register 
#define USART_REG_CR2_CPHA			((uint32_t) (1 << 9))
#define USART_REG_CR2_CPOL			((uint32_t) (1 << 10))
#define USART_REG_CR2_CLKEN			((uint32_t) (1 << 11))
#define USART_REG_CR2_STOP_BITS		((uint32_t) (12))
#define USART_REG_CR2_SWAP			((uint32_t) (1 << 15))
#define USART_REG_CR2_RXINV			((uint32_t) (1 << 16))
#define USART_REG_CR2_TXINV			((uint32_t) (1 << 17))
#define USART_REG_CR2_DATAINV		((uint32_t) (1 << 18))
#define USART_REG_CR2_MSBFIRST		((uint32_t) (1 << 19))
#define USART_REG_CR2_ABREN			((uint32_t) (1 << 20))

//CR3 register 
#define USART_REG_CR3_EIE			((uint32_t) (1 << 0))
#define USART_REG_CR3_DMAR			((uint32_t) (1 << 6))
#define USART_REG_CR3_DMAT			((uint32_t) (1 << 7))
#define USART_REG_CR3_OVRDIS		((uint32_t) (1 << 12))


typedef enum {
	HAL_USART_STATE_RESET 		= 0x00,
	HAL_USART_STATE_READY 		= 0x01,
	HAL_USART_STATE_BUSY 		= 0x02,
	HAL_USART_STATE_BUSY_TX 	= 0x12,
	HAL_USART_STATE_BUSY_RX 	= 0x22,
	HAL_USART_STATE_BUSY_TX_RX 	= 0x32
} hal_usart_state_t;

typedef struct {
	uint32_t baudRate;
	uint32_t wordLength;
	uint32_t stopBits;
	uint32_t parity;
	uint32_t mode;
	uint32_t oversampling;
} usart_init_t;

typedef void (tx_callback_t)(void *ptr);
typedef void (rx_callback_t)(void *ptr);

typedef struct {
	USART_TypeDef		*instance;
	usart_init_t		init;
	uint8_t				*pTxBuffer;
	uint16_t			txSize;
	uint16_t			txCount;
	uint8_t				*pRxBuffer;
	uint16_t			rxSize;
	uint16_t			rxCount;
	hal_usart_state_t	tx_state;
	hal_usart_state_t	rx_state;
	uint32_t			errorCode;
	tx_callback_t		*tx_callback;
	rx_callback_t		*rx_callback;
} usart_handle_t;


struct VirtualPort {
	int stringIndex = 0;
	string buffer;
	bool RXNE = false;

	void begin(int baudRate);
	void sendByte(uint8_t byte);
	void send(uint8_t *pData, uint16_t size);
	void printStrln(char *str);
	void printStr(char *str);
	int length(char *str);
	void intToStr(int num, char *str);
	void floatToStr(float num, char *str);
	void printInt(int num);
	void printFloat(float num);
	bool isAvailable();
	string recieve();
};

void USART_EnableInterrupt(USART_TypeDef * USARTx, uint8_t interruptNumber);

struct USARTx {
	void hal_usart_init(usart_handle_t *handle);
	void hal_usart_tx(usart_handle_t *handle, uint8_t *buffer, uint32_t len);
	void hal_usart_rx(usart_handle_t *handle, uint8_t *buffer, uint32_t len);
	void hal_usart_handle_interrupt(usart_handle_t *handle);

	private:

	void hal_usart_enable(USART_TypeDef *USARTx);
	void hal_usart_disable(USART_TypeDef *USARTx);
	void hal_usart_tx_enable(USART_TypeDef *USARTx);
	void hal_usart_tx_disable(USART_TypeDef *USARTx);
	void hal_usart_rx_enable(USART_TypeDef *USARTx);
	void hal_usart_rx_disable(USART_TypeDef *USARTx);
	void hal_usart_error_interrupt_enable(USART_TypeDef *USARTx);
	void hal_usart_error_interrupt_disable(USART_TypeDef *USARTx);
	void hal_usart_configure_world_length(USART_TypeDef *USARTx, uint8_t worldLength);
	void hal_usart_configure_stop_bits(USART_TypeDef *USARTx, uint8_t nstop);
	void hal_usart_configure_over_sampling(USART_TypeDef *USARTx, uint8_t over8);
};


namespace global {
	extern VirtualPort Serial;
}

// #ifdef __cplusplus
// extern "C" {
// #endif
// 	void hal_usart_init(usart_handle_t *handle);
// 	void hal_usart_tx(usart_handle_t *handle, uint8_t *buffer, uint32_t len);
// 	void hal_usart_rx(usart_handle_t *handle, uint8_t *buffer, uint32_t len);
// 	void hal_usart_handle_interrupt(usart_handle_t *handle);

// 	void USART2Init(int baudRate, const uint8_t clock);
// 	void USART_EnableInterrupt(USART_TypeDef * USARTx, uint8_t interruptNumber);
// 	void USART2SendByte(uint8_t byte);
// 	void USART2Send(uint8_t *pData, uint16_t size);
// 	void printStrln(char *str);
// 	void printStr(char *str);
// 	int length(char *str);
// 	void intToStr(int num, char *str);
// 	void floatToStr(float num, char *str);
// 	void printInt(int num);
// 	void printFloat(float num);
// #ifdef __cplusplus
// }
// #endif


#endif