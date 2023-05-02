#include <RCC.h>
#include <FLASH.h>


namespace global {
	I2C_TypeDef *I2C1_Base = I2C1;
	RCC_TypeDef *RCC_Base = RCC;
	GPIO_TypeDef *GPIOA_Base = GPIOA;
	GPIO_TypeDef *GPIOB_Base = GPIOB;
	GPIO_TypeDef *GPIOC_Base = GPIOC;
	USART_TypeDef *USART2_Base = USART2;
	SPI_TypeDef *SPI1_Base = SPI1;
	NVIC_Type* NVIC_Base = NVIC;
	FLASH_TypeDef* FLASH_Base = FLASH;
}
// sets the msi range
uint8_t RCC_SET_MSI_RANGE(msi_range_t range)
{
	if (range > MSI_48MHZ)
		return 0;
	RCC->CR &= ~RCC_CR_MSIRANGE_Msk;
	RCC->CR |= (range << RCC_CR_MSIRANGE_Pos);
	return 1;
}

void RCC_I2C3_CLK_SEL(preipheral_clocks_t clock)
{
	RCC->CCIPR &= ~RCC_CCIPR_I2C3SEL_Msk;
	RCC->CCIPR |= (clock << RCC_CCIPR_I2C3SEL_Pos);
}
void RCC_I2C1_CLK_SEL(preipheral_clocks_t clock)
{
	RCC->CCIPR &= ~RCC_CCIPR_I2C1SEL_Msk;
	RCC->CCIPR |= (clock << RCC_CCIPR_I2C1SEL_Pos);
}

void RCC_HSI16_CLK_ENABLE()
{
	RCC->CR |= RCC_CR_HSION;
	while (!(RCC->CR & RCC_CR_HSIRDY))
		;
}

// pll helpers
void RCC_PLL_CLK_ENABLE()
{
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));
}
void RCC_SET_PLL_SRC(uint32_t pllSrc)
{
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC_Msk;

	if (pllSrc == RCC_PLLCFGR_PLLSRC_MSI)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_MSI;
	else if (pllSrc == RCC_PLLCFGR_PLLSRC_HSI)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI;
	else if (pllSrc == RCC_PLLCFGR_PLLSRC_HSE)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	else
		RCC->PLLCFGR |= 0x00 << RCC_PLLCFGR_PLLSRC_Pos;
}

void RCC_SET_PLLM_DIV(uint32_t pllM)
{
	if (pllM >= RCC_PLLCFGR_PLLM_DIV1 && pllM <= RCC_PLLCFGR_PLLM_DIV8)
	{
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM_Msk;
		RCC->PLLCFGR |= (pllM << RCC_PLLCFGR_PLLM_Pos);
	}
}
void RCC_SET_PLLN_MUL(uint32_t pllN)
{
	if (pllN >= 8 && pllN <= 86)
	{
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN_Msk;
		RCC->PLLCFGR |= (pllN << RCC_PLLCFGR_PLLN_Pos);
	}
}
void RCC_SET_PLLR_DIV(uint32_t pllR)
{
	if (pllR >= RCC_PLLCFGR_PLLR_DIV2 && pllR <= RCC_PLLCFGR_PLLR_DIV8)
	{
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLR_Msk;
		RCC->PLLCFGR |= (pllR << RCC_PLLCFGR_PLLR_Pos);
	}
}

// set sysclk mux
uint8_t RCC_SET_SYSCLK(uint32_t sysClock)
{
	if (sysClock > RCC_CFGR_SW_PLL | sysClock < RCC_CFGR_SW_MSI)
		return 0;
	RCC->CFGR &= ~RCC_CFGR_SW_Msk;
	RCC->CFGR |= sysClock;
	while (((RCC->CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_Pos) != sysClock)
		;
	return 1;
}

void RCC_SET_AHB_PRESCALER(uint32_t prescaler) {
	RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
	RCC->CFGR |= prescaler;
}

void RCC_SET_APB1_PRESCALER(uint32_t prescaler) {
	RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
	RCC->CFGR |= prescaler;
}

void RCC_SET_APB2_PRESCALER(uint32_t prescaler) {
	RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
	RCC->CFGR |= prescaler;
}

void SystemInit() {
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