#include <TIMER.h>

void TIMER::enable_channel(TIM_TypeDef *TIMx, channel_conf_t * ch){
	if(ch->no == 1)
		TIMx->CCER |= TIM_CCER_CC1E;
	else if(ch->no == 2)
		TIMx->CCER |= TIM_CCER_CC2E;
	else if(ch->no == 3)
		TIMx->CCER |= TIM_CCER_CC3E;
	else if(ch->no == 4)
		TIMx->CCER |= TIM_CCER_CC4E;
}

void TIMER::set_polarity(TIM_TypeDef *TIMx, channel_conf_t *ch){
	if(ch->no == 1)
		!ch->polarity ? (TIMx->CCER &= ~TIM_CCER_CC1P) : (TIMx->CCER |= TIM_CCER_CC1P);

	else if(ch->no == 2)
		!ch->polarity ? (TIMx->CCER &= ~TIM_CCER_CC2P) : (TIMx->CCER |= TIM_CCER_CC2P);

	else if(ch->no == 3)
		!ch->polarity ? (TIMx->CCER &= ~TIM_CCER_CC3P) : (TIMx->CCER |= TIM_CCER_CC3P);

	else if(ch->no == 4)
		!ch->polarity ? (TIMx->CCER &= ~TIM_CCER_CC4P) : (TIMx->CCER |= TIM_CCER_CC4P);
}

void TIMER::set_ch_io(TIM_TypeDef *TIMx, channel_conf_t *ch){
	if(ch->no == 1)
		TIMx->CCMR1 |= (ch->io << TIM_CCMR1_CC1S_Pos);
	else if(ch->no == 2)
		TIMx->CCMR1 |= (ch->io << TIM_CCMR1_CC2S_Pos);
	else if(ch->no == 3)
		TIMx->CCMR2 |= (ch->io << TIM_CCMR2_CC3S_Pos);
	else if(ch->no == 4)
		TIMx->CCMR2 |= (ch->io << TIM_CCMR2_CC4S_Pos);
}

void TIMER::set_preaload_enable(TIM_TypeDef *TIMx, channel_conf_t *ch){
	if(ch->no == 1)
		ch->capture_preload_enable ? (TIMx->CCMR1 |= TIM_CCMR1_OC1PE) : (TIMx->CCMR1 &= ~TIM_CCMR1_OC1PE); 

	else if(ch->no == 2)
		ch->capture_preload_enable ? (TIMx->CCMR1 |= TIM_CCMR1_OC2PE) : (TIMx->CCMR1 &= ~TIM_CCMR1_OC2PE); 

	else if(ch->no == 3)
		ch->capture_preload_enable ? (TIMx->CCMR2 |= TIM_CCMR2_OC3PE) : (TIMx->CCMR2 &= ~TIM_CCMR2_OC3PE); 

	else if(ch->no == 4)
		ch->capture_preload_enable ? (TIMx->CCMR2 |= TIM_CCMR2_OC4PE) : (TIMx->CCMR2 &= ~TIM_CCMR2_OC4PE); 
}
void TIMER::set_ch_mode(TIM_TypeDef *TIMx, channel_conf_t *ch){
	uint32_t lower_3_bits = 0b111 & ch->mode;
	uint32_t upper_bit = (0b1000 & ch->mode) >> 3;

	if(ch->no == 1){
		TIMx->CCMR1 |= (lower_3_bits << TIM_CCMR1_OC1M_Pos);
		TIMx->CCMR1 |= (upper_bit << TIM_CCMR1_OC1M_3);
	}
	else if(ch->no == 2){
		TIMx->CCMR1 |= (lower_3_bits << TIM_CCMR1_OC2M_Pos);
		TIMx->CCMR1 |= (upper_bit << TIM_CCMR1_OC2M_3);
	}
	else if(ch->no == 3){
		TIMx->CCMR2 |= (lower_3_bits << TIM_CCMR2_OC3M_Pos);
		TIMx->CCMR2 |= (upper_bit << TIM_CCMR2_OC3M_3);
	}
	else if(ch->no == 4){
		TIMx->CCMR2 |= (lower_3_bits << TIM_CCMR2_OC4M_Pos);
		TIMx->CCMR2 |= (upper_bit << TIM_CCMR2_OC4M_3);
	}
}
void TIMER::set_capture_compare(TIM_TypeDef *TIMx, channel_conf_t *ch){
	switch (ch->no) {
		case 1:
			TIMx->CCR1 = ch->capture_compare;
			break;
		case 2:
			TIMx->CCR2 = ch->capture_compare;
			break;
		case 3:
			TIMx->CCR3 = ch->capture_compare;
			break;
		case 4:
			TIMx->CCR4 = ch->capture_compare;
			break;
		
		default:
			break;
	}
	// if(ch->no == 1)
	// 	TIMx->CCR1 = ch->capture_compare;

	// else if(ch->no == 2)
	// 	TIMx->CCR2 = ch->capture_compare;

	// else if(ch->no == 3)
	// 	TIMx->CCR3 = ch->capture_compare;

	// else if(ch->no == 4)
	// 	TIMx->CCR4 = ch->capture_compare;
}

void TIMER::init(TIMx_init_t *init_struct){
	this->init_struct.instance = init_struct->instance;
	this->init_struct.direction = init_struct->direction;
	this->init_struct.preload = init_struct->preload;
	this->init_struct.prescaler = init_struct->prescaler;
	this->init_struct.auto_reload = init_struct->auto_reload;
	//set preload enable or  not for the auto reload register
	if(init_struct->preload)
		init_struct->instance->CR1 |= TIM_CR1_ARPE;
	else
		init_struct->instance->CR1 &= ~TIM_CR1_ARPE;

	//set direction (counter counts up or down)
	if(init_struct->direction == TIM_DIR_DOWNCOUNT)
		init_struct->instance->CR1 |=  TIM_CR1_DIR;
	else
		init_struct->instance->CR1 &= ~TIM_CR1_DIR;

	//load the prescaler register
	init_struct->instance->PSC = init_struct->prescaler;
	//load the auto realod register
	init_struct->instance->ARR = init_struct->auto_reload;

	//finally enable the counter
	init_struct->instance->CR1 |= TIM_CR1_CEN;

	//if its an advanced timer you need to explicitly enable the output
	if(init_struct->instance == TIM1){
		init_struct->instance->BDTR |= TIM_BDTR_MOE;
	}
}

void TIMER::channel_init(TIM_TypeDef *TIMx, channel_conf_t *ch){
	//enable the channel CCER
	enable_channel(TIMx, ch);

	//capture preload enable or disable
	set_preaload_enable(TIMx, ch);

	//set polarity CCER
	set_polarity(TIMx, ch);

	//set input output CCxS CCMRx
	set_ch_io(TIMx, ch);

	//set the mode OCxM CCMRx
	set_ch_mode(TIMx, ch);
	
	//set capture compare if output
	if(ch->io == CHANNEL_IO_OUTPUT)
		set_capture_compare(TIMx, ch);
	
	this->channels.push_back(ch);
}

namespace global {
	TIM_TypeDef *TIM2_Base = TIM2;
};