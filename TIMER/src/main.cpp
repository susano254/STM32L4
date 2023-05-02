#include <TIMER.h>
#include <RCC.h>
#include <USART.h>
#include <Core.h>
#include <GPIO.h>
#include <ADC.h>

using namespace global;

// TIM_TypeDef *TIM1_Base = TIM1;
int value = 0;

int main(){
	System.Init();
	Serial.begin(115200);
	RCC_GPIOA_CLK_ENABLE();
	gpio_pin_conf_t led1;
	led1.pin = PA8;
	led1.mode = GPIO_PIN_ALT_FUN_MODE;
	led1.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	led1.pupd = GPIO_PIN_PUPD_NO_PUPD;
	led1.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	led1.alternate_function = 1;
	gpio_init(GPIOA, &led1);
	
		
	TIMER tim1;
	TIMx_init_t tim1_init;
	tim1_init.instance = TIM1;
	tim1_init.direction = TIM_DIR_UPCOUNT;
	tim1_init.preload = TIM_CR1_ARPE;
	tim1_init.prescaler = 1600-1;
	tim1_init.auto_reload = 1000;
	// TIMER tim2;
	// TIMx_init_t tim2_init;
	// tim2_init.instance = TIM2;
	// tim2_init.direction = TIM_DIR_UPCOUNT;
	// tim2_init.preload = TIM_CR1_ARPE;
	// tim2_init.prescaler = 0;
	// tim2_init.auto_reload = 1600000;
	//tim2_init.auto_reload = 4000;

	channel_conf_t ch1;
	ch1.no = 1;
	ch1.io = CHANNEL_IO_OUTPUT;
	ch1.polarity = CHANNEL_POLARITY_HIGH;
	ch1.capture_preload_enable = 0;
	ch1.mode = OCxM_PWM_1;
	ch1.capture_compare = 50;

	// ADCx_init_t init_struct;
	// init_struct.instance = ADC1;
	// init_struct.numOfConversions = 1;
	// ADCInit(&init_struct);

	// RCC_TIM2_CLK_ENABLE();
	RCC_TIM1_CLK_ENABLE();
	tim1.init(&tim1_init);
	// tim1_init.instance->BDTR |= TIM_BDTR_MOE;
	// Nvic.enableInterrupt(TIM1_CC_IRQn);
	tim1.channel_init(TIM1, &ch1);
	// TIM1->DIER |= TIM_DIER_CC1IE;
	TIM1->EGR |= TIM_EGR_UG;
	
	while(1){
		for(int i = 0; i < 1000; i++){
			TIM1->CCR1 = i;
			for(int x = 0; x < 2000; x++);
		}
		for(int i = 1000; i > 0; i--){
			TIM1->CCR1 = i;
			for(int x = 0; x < 2000; x++);
		}
	}


}

extern "C" {

void TIM6_DAC_IRQHandler(){
	Nvic.clearPending(TIM2_IRQn);
	TIM6->SR &= ~TIM_SR_UIF;
}


}