#include <RCC.h>
#include <FLASH.h>
#include <Core.h>
#include <USART.h>

TIM_TypeDef *TIM6_Base = TIM6;
DWT_Type *DWT_Base = DWT;
SCB_Type *SCB_Base = SCB;
CoreDebug_Type *CoreDebug_Base = CoreDebug;

namespace global {
	NVIC_t Nvic;
	Systick_t Systick;
	System_t System;
}

using namespace global;

void NVIC_t::clearPending(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ICPR[reg] |= (1 << bitNumber);
}

void NVIC_t::enableInterrupt(uint8_t interruptNumber){
	uint8_t reg = interruptNumber/32;
	uint8_t bitNumber = interruptNumber%32;

	NVIC->ISER[reg] |= 1 <<  bitNumber;
}


void Systick_t::Init(uint32_t reload){
	this->reload = reload;
	//init systick
	SysTick->LOAD = reload;
	SysTick->VAL = reload;
	
	
	SysTick->CTRL |= 7 << 0;
}

float Systick_t::getDeltaT(float prev_millis){
	float dt;
	dt = (millis - prev_millis) * 0.001f + (reload - SysTick->VAL)*1.0f/80000000.0f;

	return dt;
}

float Systick_t::getMillis(){
	return Systick.millis;
}

extern "C" {
	void SysTick_Handler(){
		Systick.millis++;
	}
}

void System_t::Init() {
	// Enable HSI clock
	RCC_HSI16_CLK_ENABLE();
	// enable fpu
	SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));

	// select src of the pll
	RCC_SET_PLL_SRC(RCC_PLLCFGR_PLLSRC_MSI);

	// select pllM div
	RCC_SET_PLLM_DIV(RCC_PLLCFGR_PLLM_DIV1);

	// select pllN div
	RCC_SET_PLLN_MUL(40);

	// select pllR div
	RCC_SET_PLLR_DIV(RCC_PLLCFGR_PLLR_DIV2);

	// enable pll
	RCC_PLL_CLK_ENABLE();

	// enable the R output
	RCC_PLLR_ENABLE();

	// change flash latency
	FLASH_SET_LATENCY(FLASH_ACR_LATENCY_4WS);

	// select pll as sysclk
	RCC_SET_SYSCLK(RCC_CFGR_SW_PLL);

	// configure AHB bus prescaler
	RCC_SET_AHB_PRESCALER(RCC_CFGR_HPRE_DIV1);

	// configure APB1 bus prescaler
	RCC_SET_APB1_PRESCALER(RCC_CFGR_PPRE1_DIV1);

	// configure APB2 bus prescaler
	RCC_SET_APB2_PRESCALER(RCC_CFGR_PPRE2_DIV1);

	enable_cyclic_counter();

	return;
}

void System_t::enable_tracing_unit(){
    CoreDebug->DEMCR  |= CoreDebug_DEMCR_TRCENA_Msk;
}

void System_t::reset_cyclic_counter(){
    DWT->CYCCNT  = 0; // reset the counter
	disable_cyclic_counter();
}

void System_t::enable_cyclic_counter(){
	enable_tracing_unit();
    DWT->CTRL |= 1 ; // enable the counter
}

void System_t::disable_cyclic_counter(){
    DWT->CTRL |= 0 ; // disable the counter    
}
uint32_t System_t::getMicros() {
	return get_CYCCNT_Cycles()/80;
}

float System_t::getDeltaT(uint32_t prev_micros) {
	float dt;
	uint32_t cur_micros = getMicros();
	if(cur_micros > prev_micros)
		dt = (cur_micros - prev_micros)*0.000001f;
	else if (cur_micros < prev_micros)
		dt = (cur_micros + (uint32_t)((0xffffffff/80) - prev_micros))*0.000001f;
	return dt;
}
void System_t::delay_us(uint32_t us) {
	uint32_t start_us = getMicros();
	while(getMicros()-start_us < us);
}

unsigned int System_t::get_CYCCNT_Cycles(){
    return DWT->CYCCNT;
}