#include <ADC.h>
#include <RCC.h>


void start_conversion(ADC_TypeDef *ADCx){
	ADCx->CR |= ADC_CR_ADSTART;
}

void poll_end_of_conversion(ADC_TypeDef *ADCx){
	while( !(ADCx->ISR & ADC_ISR_EOC) );
}

void disable_deep_pwd(ADC_TypeDef *ADCx){
	ADCx->CR &= ~ADC_CR_DEEPPWD;
}
void enable_deep_pwd(ADC_TypeDef *ADCx){
	ADCx->CR |= ADC_CR_DEEPPWD;
}
void disable_adc_voltage_regulator(ADC_TypeDef *ADCx){
	ADCx->CR &= ~ADC_CR_ADVREGEN;
}
void enable_adc_voltage_regulator(ADC_TypeDef *ADCx){
	ADCx->CR |= ADC_CR_ADVREGEN;
}
void enable_adc(ADC_TypeDef* ADCx){
	//clear the ADRDY bit by writing 1 to it
	ADCx->ISR |= ADC_ISR_ADRDY;
	//set ADEN in CR
	ADCx->CR |= ADC_CR_ADEN;
	//wait for ADRDY to be set again
	while( !(ADCx->ISR & ADC_ISR_ADRDY) ); 
}

void disable_adc(ADC_TypeDef* ADCx){
	//wait for ADC to finish all conversions
	while( (ADCx->CR & ADC_CR_ADSTART) ); 
	//set ADDIS
	ADCx->CR |= ADC_CR_ADDIS;
	//wait till disabling finishes
	while( (ADCx->CR & ADC_CR_ADDIS) ); 
}

void set_conversions(uint8_t numOfConversions){

}

void set_regular_channels_sequence(adc_channel_conf_t* channels, uint8_t numOfChannels){

}

void set_channels_sampling_time(adc_channel_conf_t* channels, uint8_t numOfChannels){

}


void readChannels(adc_channel_conf_t *channels, uint8_t numOfChannels){

}

uint32_t analogRead(ADC_TypeDef* ADCx, uint8_t channelNumber){
	//one conversion
	ADCx->SQR1 = 0;

	ADCx->SQR1 |= channelNumber << ADC_SQR1_SQ1_Pos;

	start_conversion(ADCx);

	poll_end_of_conversion(ADCx);

	return ADCx->DR;
}



void ADCInit(ADCx_init_t *init_struct){
	//select clock source for the ADC
	//mandatory to select one because by default no clock supplied to ADC even if enabled on AHB2 bus
	RCC_ADC_CLK_SYS_SEL();
	//now enable clock
	RCC_ADC_CLK_ENABLE();
	//disable deep down power mode
	disable_deep_pwd(init_struct->instance);
	//enable adc voltage regulator
	enable_adc_voltage_regulator(init_struct->instance);
	//average wake up time is 20us for the voltage regulator
	//(since clock is 80mhz) and we want to wait for 50us we need to count 4000
	for(int i = 0; i < 4000; i++);			//delay 50us  



	RCC_GPIOA_CLK_ENABLE();

	//finally enable the adc
	enable_adc(init_struct->instance);
}