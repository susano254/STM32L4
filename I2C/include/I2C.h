#include <stm32l432kc.h>

#ifndef 	I2C_H
#define 	I2C_H

/********************CR1 Register Bit definitions***********************/
#define I2C_REG_CR1_PE 			((uint32_t) 1 << 0)
#define I2C_REG_CR1_TXIE 		((uint32_t) 1 << 1)
#define I2C_REG_CR1_RXIE 		((uint32_t) 1 << 2)
#define I2C_REG_CR1_ADDRIE 		((uint32_t) 1 << 3)
#define I2C_REG_CR1_NACKIE 		((uint32_t) 1 << 4)
#define I2C_REG_CR1_STOPIE		((uint32_t) 1 << 5)
#define I2C_REG_CR1_TCIE		((uint32_t) 1 << 6)
#define I2C_REG_CR1_ERRIE		((uint32_t) 1 << 7)
#define I2C_REG_CR1_DNF			((uint32_t) 0b1111 << 8)
#define I2C_REG_CR1_ANFOFF		((uint32_t) 1 << 12)
#define I2C_REG_CR1_TXDMAEN		((uint32_t) 1 << 14)
#define I2C_REG_CR1_RXDMAEN		((uint32_t) 1 << 15)
#define I2C_REG_CR1_NOSTRETCH	((uint32_t) 1 << 17)
                                            
/********************CR2 Register Bit definitions***********************/
#define I2C_REG_CR2_SADD7		((uint32_t) 1)
#define I2C_REG_CR2_RD_WRN 		((uint32_t) 1 << 10)
#define I2C_REG_CR2_ADD10 		((uint32_t) 1 << 11)
#define I2C_REG_CR2_HEAD10R		((uint32_t) 1 << 12)
#define I2C_REG_CR2_START 		((uint32_t) 1 << 13)
#define I2C_REG_CR2_STOP 		((uint32_t) 1 << 14)
#define I2C_REG_CR2_NACK 		((uint32_t) 1 << 15)
#define I2C_REG_CR2_NBYTES		((uint32_t) 16)
#define I2C_REG_CR2_RELOAD 		((uint32_t) 1 << 24)
#define I2C_REG_CR2_AUTOEND		((uint32_t) 1 << 25)
#define I2C_REG_CR2_PECBYTE 	((uint32_t) 1 << 26)

/********************TIMINGR Register Bit definitions***********************/
#define I2C_REG_TIMINGR_SCLL 	((uint32_t)  0)
#define I2C_REG_TIMINGR_SCLH 	((uint32_t)  8)
#define I2C_REG_TIMINGR_SDADEL 	((uint32_t) 16)
#define I2C_REG_TIMINGR_SCLDEL 	((uint32_t) 20)
#define I2C_REG_TIMINGR_PRESC 	((uint32_t) 28)

/********************ISR Register Bit definitions***********************/
#define I2C_REG_ISR_TXE 		((uint32_t) 1 << 0)
#define I2C_REG_ISR_TXIS 		((uint32_t) 1 << 1)
#define I2C_REG_ISR_RXNE 		((uint32_t) 1 << 2)
#define I2C_REG_ISR_ADDR 		((uint32_t) 1 << 3)
#define I2C_REG_ISR_NACKF 		((uint32_t) 1 << 4)
#define I2C_REG_ISR_STOPF 		((uint32_t) 1 << 5)
#define I2C_REG_ISR_TC 			((uint32_t) 1 << 6)
#define I2C_REG_ISR_TCR 		((uint32_t) 1 << 7)
#define I2C_REG_ISR_BERR 		((uint32_t) 1 << 8)
#define I2C_REG_ISR_ARLO 		((uint32_t) 1 << 9)
#define I2C_REG_ISR_OVR 		((uint32_t) 1 << 10)
#define I2C_REG_ISR_PECERR 		((uint32_t) 1 << 11)
#define I2C_REG_ISR_TIMEOUT 	((uint32_t) 1 << 12)
#define I2C_REG_ISR_ALERT 		((uint32_t) 1 << 13)
#define I2C_REG_ISR_BUSY 		((uint32_t) 1 << 15)
#define I2C_REG_ISR_DIR 		((uint32_t) 1 << 16)
#define I2C_REG_ISR_ADDCODE 	((uint32_t) 0b1111111 << 17)

/**********************more values*********************/
#define I2C_ADDRMODE_7BIT		((uint32_t) 7)
#define I2C_ADDRMODE_10BIT		((uint32_t) 10)

typedef enum {
	I2C_STATE_RESET	 = 0x00, 
	I2C_STATE_READY = 0x01, 
	I2C_STATE_BUSY = 0x02, 
	I2C_STATE_BUSYTX = 0x03, 
	I2C_STATE_BUSYRX = 0x04, 
	I2C_STATE_ERROR = 0x05 
} i2c_state_t;

typedef struct {
	uint32_t clockSpeed; 			//clock frequency
	uint32_t AddressingMode;		//7bit or 10 bits
	uint32_t NoStretechMode;		//clock stretching enable or disable
	uint32_t ack_enable;			//clock stretching enable or disable
} I2C_Init_t;

typedef struct {
	I2C_TypeDef		*instance;			//i2c instance used
	uint8_t			*buffer;			//transfer buffer
	uint32_t 		bufferSize;
	I2C_Init_t		init;				//init struct parameters
	i2c_state_t 	state;
	//void 			(*pI2CInit)();
} I2C_Handle_t;

void i2c_set_addressing_mode(I2C_TypeDef*, uint32_t);
void i2c_manage_clock_stretch(I2C_TypeDef*, uint32_t);
void i2c_disable_peripheral(I2C_TypeDef*);
void i2c_enable_peripheral(I2C_TypeDef*);
void i2c_stop_gen(I2C_TypeDef*);
void i2c_start_gen(I2C_TypeDef*);
void i2c_master_rx(I2C_Handle_t *, uint8_t, uint8_t *, uint32_t);
void i2c_master_tx(I2C_Handle_t *, uint8_t, uint8_t *, uint32_t);
void I2CInit(I2C_Handle_t*);

#endif                                      