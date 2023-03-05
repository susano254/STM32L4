#include <ADC.h>
#include <RCC.h>


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

	//one conversion
	init_struct->instance->SQR1 &= ~ADC_SQR1_L;
	init_struct->instance->SQR1 |= init_struct->numOfConversions - 1;
	//first and only channel to be channel 15
	init_struct->instance->SQR1 |= 15 << ADC_SQR1_SQ1_Pos;

	// //set number of conversions for the adc
	// set_conversions(init_struct->numOfConversions);
	// //set channels sequence
	// set_regular_channels_sequence(init_struct->channels, init_struct->numOfChannels);
	// //set channels sampling time
	// set_channels_sampling_time(init_struct->channels, init_struct->numOfChannels);
	//finally enable the adc
	enable_adc(init_struct->instance);
}