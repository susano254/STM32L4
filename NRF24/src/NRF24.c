#include <stm32l432kc.h>
#include <RCC.h>
#include <GPIO.h>
#include <USART.h>
#include <SPI.h>
#include <NRF24.h>

//CE pin of NRF24 = PB4
//CSN pin of NRF24 = PB5
#define CE_PIN 		4
#define CSN_PIN 	5


void CS_Select(){
  GPIOB->ODR &= ~(1 << CSN_PIN);
}
void CS_UnSelect(){
  GPIOB->ODR |= (1 << CSN_PIN);
}
void CE_Disable(){
  GPIOB->ODR &= ~(1 << CE_PIN);
}
void CE_Enable(){
  GPIOB->ODR |= (1 << CE_PIN);
}

void NRF24WriteReg(uint8_t reg, uint8_t data){
  uint8_t cmd;

  cmd = reg | W_REGISTER;
  CS_Select();

  SPITransfer(cmd);
  SPITransfer(data);

  //wait for the BSY flag
  while( (SPI1->SR & (1 << 7)) );

  //delay a bit before releasing 
  for(int i = 0; i < 10; i++);
  CS_UnSelect();
}

uint8_t NRF24ReadReg(uint8_t reg){
  uint8_t rx;
  uint8_t dummy = 0;

  CS_Select();

  rx = SPITransfer(reg);
  rx = SPITransfer(dummy);

  //wait for the BSY flag
  while( (SPI1->SR & (1 << 7)) );

  //delay a bit before releasing 
  for(int i = 0; i < 10; i++);
  CS_UnSelect();

  return rx;
}
void NRF24Init(uint8_t CE, uint8_t CSN){
	uint8_t prescaler = 0b000;

	SPIInit(prescaler);

	//configure other pins used by the NRF24
	GPIOInit('B');
	//set PB4 and PB5 to output
	setToOuputMode(GPIOB, CE);
	setToOuputMode(GPIOB, CSN);
  CS_UnSelect();
  CE_Disable();

}

void transmit(uint8_t *data, int size){
  CS_Select();

  SPITransfer(W_TX_PAYLOAD);
  for(int i = 0; i < size; i++)
    SPITransfer(data[i]);

  //optional delay
  CS_UnSelect();

  //optional delay
  uint8_t status = NRF24ReadReg(0x17);
  if( (status & (1 << 4)) && !(status & (1 << 3)) ){
    sendCmd(FLUSH_TX);
    //Serial.println("Data on Air");
  }
  else{
    printStrln("Data transmission failed");
  }
}
void sendCmd(uint8_t cmd){
  uint8_t rx;

  CS_Select();
  SPITransfer(cmd);
  CS_UnSelect();
}

int main(){
	CE_Enable();
	NRF24Init(CE_PIN, CSN_PIN);
	CE_Disable();

	while(1){

	}

  return 0;
}
