#include <TIMER.h>
#include <RCC.h>
#include <USART.h>
#include <NVIC.h>
#include <GPIO.h>
#include <ADC.h>

I2C_TypeDef *I2C1_Base = I2C1;
RCC_TypeDef *RCC_Base = RCC;
GPIO_TypeDef *GPIOA_Base = GPIOA;
GPIO_TypeDef *GPIOB_Base = GPIOB;
GPIO_TypeDef *GPIOC_Base = GPIOC;
USART_TypeDef *USART2_Base = USART2;
SPI_TypeDef *SPI1_Base = SPI1;
NVIC_Type* NVIC_Base = NVIC;
TIM_TypeDef* TIM2_Base = TIM2;

int main(){
	SystemInit();
	USART2Init(115200, HSI16);
	RCC_GPIOA_CLK_ENABLE();
	gpio_pin_conf_t led1;
	led1.pin = PA0;
	led1.mode = GPIO_PIN_ALT_FUN_MODE;
	led1.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	led1.pupd = GPIO_PIN_PUPD_NO_PUPD;
	led1.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	led1.alternate_function = 1;
	gpio_init(GPIOA, &led1);
	
		
	TIMx_init_t tim2_init;
	tim2_init.instance = TIM2;
	tim2_init.direction = TIM_DIR_UPCOUNT;
	tim2_init.preload = TIM_CR1_ARPE;
	tim2_init.prescaler = 0;
	tim2_init.auto_reload = 1600000;
	//tim2_init.auto_reload = 4000;

	channel_conf_t ch1;
	ch1.no = 1;
	ch1.io = CHANNEL_IO_OUTPUT;
	ch1.polarity = CHANNEL_POLARITY_HIGH;
	ch1.capture_preload_enable = 0;
	ch1.mode = OCxM_PWM_1;
	ch1.capture_compare = 50;

	ADCx_init_t init_struct;
	init_struct.instance = ADC1;
	init_struct.numOfConversions = 1;
	ADCInit(&init_struct);

	RCC_TIM2_CLK_ENABLE();
	TIMx_init(&tim2_init);
	NVIC_EnableInterrupt(TIM2_IRQn);
	channel_init(TIM2, &ch1);
	TIM2->DIER |= TIM_DIER_CC1IE;
	TIM2->EGR |= TIM_EGR_UG;
	
	while(1);


}
void TIM2_IRQHandler(){
	uint16_t data;

	ADC1->CR |= ADC_CR_ADSTART;
	while( !(ADC1->ISR & ADC_ISR_EOC) );
	data = ADC1->DR;
	// printInt(data);
	// printStrln("");
	uint32_t temp = 36.63 * ADC1->DR + 45000;
	//uint32_t temp = ADC1->DR; 
	// printInt(temp);
	// printStrln("");
	for(int i = 0; i < 100; i++);
	TIM2->CCR1 =  temp;


	NVIC_ClearPending(TIM2_IRQn);
	TIM2->SR &= ~TIM_SR_CC1IF;
}