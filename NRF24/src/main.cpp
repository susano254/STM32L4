#include <NRF24.h>
#include <USART.h>
#include <Core.h>
#include <RCC.h>

using namespace global;

int main(){
	uint8_t reg;
	NRF24 nrf;

	System.Init();
	Serial.begin(115200);
	nrf.init(CE_PIN, CSN_PIN);
	nrf.setRxMode(nrf.defaultAddr, 0);

	char read[8];
	for(int i = 0; i < 7; i++){
		read[i] = nrf.readReg(i);
	}

	uint8_t status = 0xff;
	nrf.receive();
	while(1){

		status = nrf.readReg(STATUS);
		if(nrf.isDataAvailable(0)){
			nrf.receive();
			nrf.printData();
		}

		// else {
		// 	printStrln("No data found");
		// }
	}

  return 0;
}
