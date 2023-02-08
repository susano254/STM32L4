#include <GPIO.h>
#include <RCC.h>
#include <I2C.h>
#include <USART.h>



void I2CInit(I2C_Handle_t* handle){
	//enable clock 
	if(handle->instance == I2C1){
		//select clock
		RCC_I2C1_CLK_SEL(HSI16);
		//enable peripheral clock
		RCC_I2C1_CLK_ENABLE();
	} else {
		//select clock
		RCC_I2C3_CLK_SEL(HSI16);
		//enable peripheral clock
		RCC_I2C3_CLK_ENABLE();

	}

	//disable peripheral before going further
	i2c_disable_peripheral(handle->instance);
	//set prescaler to 3
	handle->instance->TIMINGR |= (3 << I2C_REG_TIMINGR_PRESC);
	//set SCLL to 199 or 0xc7 (199+1)*250ns = 5 us needed for standard 100khz mode)
	handle->instance->TIMINGR |= (0x13 << I2C_REG_TIMINGR_SCLL);
	//set SCLH to 15 or 0xf  (195+1)*250 = 4 us needed for standard 100khz mode)
	handle->instance->TIMINGR |= (0xf << I2C_REG_TIMINGR_SCLH);
	//set SDADEL to 2 or 0x2  (2)*250 = 500 ns needed for standard 100khz mode)
	handle->instance->TIMINGR |= (0x2 << I2C_REG_TIMINGR_SDADEL);
	//set SCLDEL to 4 or 0x4  (4+1)*250 = 1250 ns needed for standard 100khz mode)
	handle->instance->TIMINGR |= (0x4 << I2C_REG_TIMINGR_SCLDEL);
	//finally enable peripheral
	i2c_enable_peripheral(handle->instance);
	//wait for a while till the device wakes
	for(int i = 0; i < 2000; i++);
}

void i2c_master_tx(I2C_Handle_t *handle, uint8_t slave_address, uint8_t regAddr, uint8_t *buffer, uint32_t size){
	int i;
	//populate the handler
	handle->buffer = buffer;
	handle->bufferSize = size;
	handle->state = I2C_STATE_BUSYTX;

	//reset the cr2 register first 
	handle->instance->CR2 = 0;
	//write the address of the slave device in sadd
	handle->instance->CR2 |= (slave_address << I2C_REG_CR2_SADD7);



	//write the NBytes to be transmitted
	//first clear the old value
	handle->instance->CR2 &= ~(0xff << I2C_REG_CR2_NBYTES);
	//write the NBytes to be transmitted
	handle->instance->CR2 |= (handle->bufferSize+1 << I2C_REG_CR2_NBYTES);
	//write the direction to be write
	handle->instance->CR2 &= ~I2C_REG_CR2_RD_WRN;
	//generate a start condition
	i2c_start_gen(handle->instance);

	//first write  regAddr
	//wait for the TXE flag 
	while(!(handle->instance->ISR & I2C_REG_ISR_TXE));
	//write the data in TXDR to be sent
	handle->instance->TXDR = regAddr;
	//wait for the ACK
	while(!(handle->instance->ISR & I2C_REG_ISR_TXIS));
	//then write data to it 
	for(i = 0; i < size; i++){
		//wait till the TX register is empty
		while(!(handle->instance->ISR & I2C_REG_ISR_TXE));
		//put the data to be transmitted
		handle->instance->TXDR = buffer[i];
		//TXIS flag is not set on the last byte (i.e. after NBYTES sent) and the TC flag will gets set instead 
		if(i != size-1)
			//wait for the ACK
			while(!(handle->instance->ISR & I2C_REG_ISR_TXIS));
	}
	//wait for TC flag to be set 
	while(!(handle->instance->ISR & I2C_REG_ISR_TC));
	//generate the stop condition and terminate communication
	i2c_stop_gen(handle->instance);
}

void i2c_master_rx(I2C_Handle_t *handle, uint8_t slave_address, uint8_t regAddr, uint8_t *buffer, uint32_t size){
	int i;
	//populate the handler
	handle->buffer = buffer;
	handle->bufferSize = size;
	handle->state = I2C_STATE_BUSYTX;

	//reseet the cr2 register first 
	handle->instance->CR2 = 0;
	//write the address of the slave device in sadd
	handle->instance->CR2 |= (slave_address << I2C_REG_CR2_SADD7);

	//first write the reg addr then restart and read

	//first write 
	//write the NBytes to be transmitted
	handle->instance->CR2 |= (1 << I2C_REG_CR2_NBYTES);
	//write the direction to be a write
	handle->instance->CR2 &= ~I2C_REG_CR2_RD_WRN;
	//generate the start condition
	i2c_start_gen(handle->instance);
	//wait for the TXE flag 
	while(!(handle->instance->ISR & I2C_REG_ISR_TXE));
	//write the data in TXDR to be sent
	handle->instance->TXDR = regAddr;
	//wait for the TC
	while(!(handle->instance->ISR & I2C_REG_ISR_TC));

	//then read
	//write the NBytes to be transmitted
	//first clear the old value
	handle->instance->CR2 &= ~(0xff << I2C_REG_CR2_NBYTES);
	handle->instance->CR2 |= (handle->bufferSize << I2C_REG_CR2_NBYTES);
	//write the direction to be a write
	handle->instance->CR2 |= I2C_REG_CR2_RD_WRN;
	//generate a start condition again
	i2c_start_gen(handle->instance);
	for(i = 0; i < size; i++){
		//wait until the RX register is filled (not empty)
		while(!(handle->instance->ISR & I2C_REG_ISR_RXNE));
		//read  the data
		buffer[i] = handle->instance->RXDR;
	}
	//wait for TC flag to be set 
	while(!(handle->instance->ISR & I2C_REG_ISR_TC));
	//finally generate the stop condition and terminate communication
	i2c_stop_gen(handle->instance);
}

void i2c_start_gen(I2C_TypeDef* I2Cx){
	//generate the start condition 
	I2Cx->CR2 |= I2C_REG_CR2_START;
	//wait for success
	while (I2Cx->CR2 & I2C_REG_CR2_START);
}
void i2c_stop_gen(I2C_TypeDef* I2Cx){
	//generate the start condition 
	I2Cx->CR2 |= I2C_REG_CR2_STOP;
	//wait for success
	while (I2Cx->CR2 & I2C_REG_CR2_STOP);
	//clear the stop flag 
	I2Cx->ICR |= I2C_REG_ICR_STOPCF;
}

void i2c_enable_peripheral(I2C_TypeDef* I2Cx){
	I2Cx->CR1 |= I2C_REG_CR1_PE;
}
void i2c_disable_peripheral(I2C_TypeDef* I2Cx){
	I2Cx->CR1 &= ~I2C_REG_CR1_PE;
}

void i2c_manage_clock_stretch(I2C_TypeDef* I2Cx, uint32_t no_stretch){
	if(no_stretch)
		I2Cx->CR1 |= I2C_REG_CR1_NOSTRETCH;
	else
		I2Cx->CR1 &= ~I2C_REG_CR1_NOSTRETCH;
}
void i2c_set_addressing_mode(I2C_TypeDef* I2Cx, uint32_t addressing_mode){
	if(addressing_mode == I2C_ADDRMODE_7BIT)
		I2Cx->CR2 &= ~I2C_REG_CR2_ADD10;
	else
		I2Cx->CR2 |= I2C_REG_CR2_ADD10;
}

void i2c_write_reg(I2C_TypeDef* I2Cx, uint8_t reg){
	//write the NBytes to be transmitted
	I2Cx->CR2 |= (1 << I2C_REG_CR2_NBYTES);
	//write the direction to be a write
	I2Cx->CR2 &= ~I2C_REG_CR2_RD_WRN;
	//generate the start condition
	i2c_start_gen(I2Cx);
	//wait for the TXE flag 
	while(!(I2Cx->ISR & I2C_REG_ISR_TXE));
	//write the data in TXDR to be sent
	I2Cx->TXDR = reg;
	//wait for the ACK
	while(!(I2Cx->ISR & I2C_REG_ISR_TXIS));
	//wait for the TC
	while(!(I2Cx->ISR & I2C_REG_ISR_TC));
}