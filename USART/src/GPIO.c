#include <GPIO.h>



uint8_t gpio_read_pin(GPIO_TypeDef *GPIOx, uint8_t pin){
	return ((GPIOx->IDR & (1 << pin)) ? 1 : 0);
}
void gpio_write_pin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
	if(value) 	GPIOx->ODR |=  (1 << pin) ;
	else 		GPIOx->ODR &= ~(1 << pin);
}
void gpio_set_alt_func(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t alt_fun){
	uint8_t baseBit = (pin * 4) % 32;
	uint8_t reg = pin < 8 ? 0 : 1;

	GPIOx->AFR[reg] &= ~(0b1111 << baseBit);
	GPIOx->AFR[reg] |= (alt_fun << baseBit);
}
static void gpio_configure_pin_mode(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t mode){
	GPIOx->MODER &= ~(3 << (pin * 2));
	GPIOx->MODER |= (mode << (pin * 2));
}
static void gpio_configure_pin_otype(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t op_type){
	GPIOx->OTYPER &= ~(1 << pin);
	GPIOx->OTYPER |= (op_type << pin);
}
static void gpio_configure_pin_ospeed(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t ospeed){
	GPIOx->OSPEEDR &= ~(3 << (pin * 2));
	GPIOx->OSPEEDR |= (ospeed << (pin * 2));
}
static void gpio_configure_pin_pupd(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t pupd){
	GPIOx->PUPDR &= ~(3 << (pin * 2));
	GPIOx->PUPDR |= (pupd << (pin * 2));
}

void gpio_init(GPIO_TypeDef* GPIOx, gpio_pin_conf_t* pin_conf){
	//first configure the mode
	gpio_configure_pin_mode(GPIOx, pin_conf->pin, pin_conf->mode);
	//configure the output type
	gpio_configure_pin_otype(GPIOx, pin_conf->pin, pin_conf->op_type);
	//configure the ospeed
	gpio_configure_pin_ospeed(GPIOx, pin_conf->pin, pin_conf->speed);
	//configure the alternate function
	if(pin_conf->alternate_function != -1)
		gpio_set_alt_func(GPIOx, pin_conf->pin, pin_conf->alternate_function);
}