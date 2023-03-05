#include <I2C.h>
#include <GPIO.h>
#include <RCC.h>
#include <USART.h>

I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;

void readAcc();
void readGyro();
void printValues();

I2C_Handle_t i2c_handle;

#define MPU 0x68

float acc[3];
float gyro[3];

int main(){
	SystemInit();
	USART2Init(115200, HSI16);
	//configure pins 
	gpio_pin_conf_t pinA9, pinA10;
	pinA9.pin = PA9;
	pinA10.pin = PA10;
	//set mode
	pinA9.mode = GPIO_PIN_ALT_FUN_MODE;
	pinA10.mode = GPIO_PIN_ALT_FUN_MODE;
	//output type
	pinA9.op_type = GPIO_PIN_OP_TYPE_OPEN_DRAIN;
	pinA10.op_type = GPIO_PIN_OP_TYPE_OPEN_DRAIN;
	////set pullups for pin 9 and 10
	pinA9.pupd = GPIO_PIN_PUPD_NO_PUPD;
	pinA10.pupd = GPIO_PIN_PUPD_NO_PUPD;
	//set speed
	pinA9.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	pinA10.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	//set alternate function
	pinA9.alternate_function = 4;
	pinA10.alternate_function = 4;

	//enable clock for GPIOA
	RCC_GPIOA_CLK_ENABLE();
	gpio_init(GPIOA, &pinA9);
	gpio_init(GPIOA, &pinA10);
	int8_t buffer[6];
	i2c_handle.instance = I2C1;
 	I2CInit(&i2c_handle);

	buffer[0] = 0x80;

	i2c_master_rx(&i2c_handle, 0x68, 0x75, buffer, 1);

	buffer[0] = 0x80;
	i2c_master_tx(&i2c_handle, 0x68, 0x6B, buffer, 1);
	buffer[0] = 0x00;
	i2c_master_tx(&i2c_handle, 0x68, 0x6B, buffer, 1);
	buffer[0] = 0x01;
	i2c_master_tx(&i2c_handle, 0x68, 0x6B, buffer, 1);

	while(1){
		readAcc();
		readGyro();
		printValues();
	}

	return 0;
}

void readAcc(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, 0x68, 0x3B, buffer, 6);

	acc[0] = ((int16_t) ((buffer[0] << 8) | buffer[1]))  / 16384.0f;
	acc[1] = ((int16_t) ((buffer[2] << 8) | buffer[3]))  / 16384.0f;
	acc[2] = ((int16_t) ((buffer[4] << 8) | buffer[5]))  / 16384.0f;
}
void readGyro(){
	uint8_t buffer[6];
	i2c_master_rx(&i2c_handle, 0x68, 0x43, buffer, 6);

	gyro[0] = ((int16_t) ((buffer[0] << 8) | buffer[1])) / 131.0f;
	gyro[1] = ((int16_t) ((buffer[2] << 8) | buffer[3])) / 131.0f;
	gyro[2] = ((int16_t) ((buffer[4] << 8) | buffer[5])) / 131.0f;
}

void printValues(){
	printFloat(acc[0]);
	printStr(",\t\t");
	printFloat(acc[1]);
	printStr(",\t\t");
	printFloat(acc[2]);
	printStr(",\t\t\t\t");
	printFloat(gyro[0]);
	printStr(",\t\t");
	printFloat(gyro[1]);
	printStr(",\t\t");
	printFloat(gyro[2]);
	printStrln("");
}