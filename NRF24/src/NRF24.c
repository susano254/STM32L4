#include <stm32l432kc.h>
#include <RCC.h>
#include <GPIO.h>
#include <USART.h>
#include <SPI.h>
#include <NRF24.h>

void CS_Select(){
  GPIOB->ODR &= ~(1 << CSN_PIN);
  for(int i = 0; i < 10; i++);
}
void CS_UnSelect(){
  GPIOB->ODR |= (1 << CSN_PIN);
}
void CE_Disable(){
  GPIOB->ODR &= ~(1 << CE_PIN);
}
void CE_Enable(){
  GPIOB->ODR |= (1 << CE_PIN);
  for(int i = 0; i < 10; i++);
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
  for(int i = 0; i < 100; i++);
  CS_UnSelect();
}
void NRF24WriteMultiReg(uint8_t reg, uint8_t *data, uint8_t size){
  uint8_t cmd;

  cmd = reg | W_REGISTER;
  CS_Select();

  SPITransfer(cmd);
  for(int i = 0; i < size; i++)
    SPITransfer(data[i]);
  
  //wait for the BSY flag
  while( (SPI1->SR & (1 << 7)) );

  //delay a bit before releasing 
  for(int i = 0; i < 100; i++);
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
  //for(int i = 0; i < 100; i++);
  CS_UnSelect();

  return rx;
}

void NRF24ReadMultiReg(uint8_t reg, uint8_t *data, uint8_t size){
  uint8_t rx;
  uint8_t dummy = 0;

  CS_Select();

  rx = SPITransfer(reg);
  for(int i = 0; i < size; i++)
    data[i] = SPITransfer(dummy);

  //wait for the BSY flag
  while( (SPI1->SR & (1 << 7)) );

  //delay a bit before releasing 
  for(int i = 0; i < 100; i++);
  CS_UnSelect();

}

void NRF24Init(uint8_t CE, uint8_t CSN){
	uint8_t prescaler = 0b010;

	SPIInit(prescaler);

	//configure other pins used by the NRF24
	//set PB4 and PB5 to output
  gpio_pin_conf_t ce_pin, cs_pin;
  ce_pin.pin = CE_PIN;
  cs_pin.pin = CSN_PIN;
  
  ce_pin.mode = GPIO_PIN_OUTPUT_MODE;
  cs_pin.mode = GPIO_PIN_OUTPUT_MODE;

  ce_pin.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
  cs_pin.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;

  ce_pin.speed = GPIO_PIN_OSPEED_HIGH;
  cs_pin.speed = GPIO_PIN_OSPEED_HIGH;

  RCC_GPIOB_CLK_ENABLE();
	gpio_init(GPIOB, &ce_pin);
	gpio_init(GPIOB, &cs_pin);

  CE_Disable();

  //power off the device
  NRF24WriteReg(CONFIG, PWR_OFF);
  //disable auto acknowledgement
  NRF24WriteReg(EN_AA, 0x00);
  //disable all receive pipes for now (no addresses are active for reception)
  NRF24WriteReg(EN_RXADDR, 0x00);
  //set the address width for both TX, RX
  NRF24WriteReg(SETUP_AW, 0x03);
  //disable auto retransmit because it needs auto acknowledge (and we disabled it in EN_AA above)
  NRF24WriteReg(SETUP_RETR, 0x00);
  //set the channel number to be used for transmission (both transmitter and receiver need to use the same channel because it also sets the frequency offset from the base frequency of 2.4GHZ)
  //set 0 for now (needs to be reconfigured in the TX and RX mode functions)
  NRF24WriteReg(RF_CH, 0x00);
  //set the Air data rate to be 2 Mbps and power to maximum
  NRF24WriteReg(RF_SETUP, 0x0f);
  
  CE_Enable();
}

void transmit(uint8_t *data, int size){
  CS_Select();

  SPITransfer(W_TX_PAYLOAD);
  for(int i = 0; i < size; i++)
    SPITransfer(data[i]);

  //optional delay
  CS_UnSelect();

  //optional delay
  
  uint8_t status = NRF24ReadReg(FIFO_STATUS);
  //check bits 2, 3 to be zeros and TXE set (2,3 are reserved but are zeros when the device operating and 1 when the device poewr off)
  if( (status & (1 << 4)) && !(status & (1 << 3)) ){
    sendCmd(FLUSH_TX);
    printStrln("Data on air");
  }
  else{
    printStrln("Data transmission failed");
  }
}

void receive(uint8_t *data){
  NRF24ReadMultiReg(R_RX_PAYLOAD, data, 32);
  //delay(10);
  for(int i = 0; i < 100; i++);
  sendCmd(FLUSH_RX);
}
void sendCmd(uint8_t cmd){
  uint8_t rx;

  CS_Select();
  SPITransfer(cmd);
  CS_UnSelect();
}


void NRF24TxMode(uint8_t *addr, uint8_t channel){
  uint8_t buffer[100];

  //chip disable (TX, RX)
  CE_Disable();

  //power off from the config register to disable chip
  NRF24WriteReg(CONFIG, PWR_OFF);

  //write the channel you want to use in register 5
  NRF24WriteReg(RF_CH, channel);

  //write the addr you want to communicate with (length is 5 bytes by default)
  NRF24WriteMultiReg(TX_ADDR, addr, 5);

  //readMultiReg(0x10, buffer, 5);
  //for(int i = 0; i < 5; i++){
  //  if(buffer[i] != addr[i])
  //    Serial.println("TX_ADDR not written correctly!!");
  //}

  //power up the device with tx mode enable
  NRF24WriteReg(CONFIG, PWR_UP & ~PRIM_RX);

  //activate chip enable for (Tx mode)
  CE_Enable();
}

void NRF24RxMode(uint8_t *addr, uint8_t channel){
  //chip disable for (TX, RX)
  CE_Disable();

  //power off the device from the config before modifying anything
  NRF24WriteReg(CONFIG, PWR_OFF);

  //write the channel in register 5
  NRF24WriteReg(RF_CH, channel);

  //enable data pipe n (mostly data pipe 0 write 0x01)
  NRF24WriteReg(EN_RXADDR, ENAA_P0);

  //write the addr of the receive pipe (mostly data pipe 0 in 0x0a)
  NRF24WriteMultiReg(RX_ADDR_P0, addr, 5);

  //write the length for the data pipe used (mostly data pipe 0 to be 32)
  NRF24WriteReg(RX_PW_P0, 32);

  //power up the device again in rx mode
  NRF24WriteReg(CONFIG, PWR_UP|PRIM_RX);

  //enable the chip pin
  CE_Enable();
}

uint8_t isDataAvailable(uint8_t pipeNum){
  uint8_t status, rxNum;

  //read the status register
  status = NRF24ReadReg(CONFIG);
  status = NRF24ReadReg(STATUS);

  //check RX_DR bit in status register
  if(status & RX_DR){
    //get the data pipe number that is full
    rxNum = status & (0b111 << RX_P_NO);
    //finally return 1 if it's the same number as the one quiried for
    if(rxNum == pipeNum){
      //clear the RX_DR bit
      NRF24WriteReg(STATUS, status);
      return 1;
    }
  }
  if(status == 0) 
    sendCmd(FLUSH_RX);
  return 0;
}
