#include <RCC.h>
#include <FLASH.h>
#include <Core.h>
#include <USART.h>

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
	SysTick->VAL = 0;
	SysTick->CTRL |= 3 << 0;
}

float Systick_t::getDeltaT(float last_micros){
	float dt;
	dt = micros - last_micros;
	dt *= 0.000001f;

	return dt;
}

float Systick_t::getMicros(){
	return Systick.micros;
}

float Systick_t::getDeltaT(){
	float dt;
	dt = 0xffffff - SysTick->VAL;
	dt *= 0.0000001f;
	SysTick->VAL = 0;

	return dt;
}
extern "C" {
	void SysTick_Handler(){
		Systick.micros++;
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

	return;
}
