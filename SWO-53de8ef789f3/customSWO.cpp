#include "stm32l4xx_hal.h"
#include "core_cm4.h"

/* ITM register addresses */
#define ITM_BASE_ADDR           (0xE0000000UL)
#define ITM_STIM0_ADDR          (*(volatile uint32_t *)(ITM_BASE_ADDR + 0x0000UL))

/* TPIU register addresses */
#define TPIU_BASE_ADDR          (0xE0040000UL)
#define TPIU_ACPR_ADDR          (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x010UL))
#define TPIU_SPPR_ADDR          (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x00F0UL))
#define TPIU_FFCR_ADDR          (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x304UL))
#define TPIU_DEVID_ADDR         (*(volatile uint32_t *)(TPIU_BASE_ADDR + 0x0FCUL))

/* Core debug registers */
#define CoreDebug_DEMCR         (*(volatile uint32_t *)(0xE000EDFCUL))

/* SCS register addresses */
#define SCS_DEMCR               (*(volatile uint32_t *)(0xE000EDFCUL))

/* UART settings */
#define UART_BAUDRATE           115200
#define UART_TX_PORT            GPIOA
#define UART_TX_PIN             GPIO_PIN_9

/* ITM output settings */
#define ITM_PORT                0
#define ITM_PRIORITY            1

/**
  * @brief Initializes the ITM and TPIU for printf output
  * @retval None
  */
void itm_init(void)
{
    /* Enable trace subsystem (we'll use ITM and TPIU) */
    SCS_DEMCR |= SCS_DEMCR_TRCENA;

    /* Configure TPIU baud rate */
    TPIU_ACPR_ADDR = (HAL_RCC_GetHCLKFreq() / (UART_BAUDRATE * 16)) - 1;

    /* Configure TPIU protocol */
    TPIU_SPPR_ADDR = 0x00000002;

    /* Enable asynchronous trace */
    TPIU_FFCR_ADDR |= 0x00000100;

    /* Enable ITM and ITM output */
    CoreDebug_DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    CoreDebug_DEMCR |= CoreDebug_DEMCR_MON_EN_Msk;
    ITM_TCR |= ITM_TCR_ITMENA_Msk;
    ITM_TCR |= ITM_TCR_TSENA_Msk;

    /* Configure ITM port */
    ITM_TER |= (1 << ITM_PORT);
    ITM_TPR = ITM_PRIORITY << 16;

    /* Redirect printf to ITM */
    ITM_STIM0_ADDR = 0x55AA55AA;
}

int main(void)
{
    /* Initialize ITM for printf output */
    itm_init();

    /* Send a string through ITM channel */
    printf("Hello, ITM!\n");

    while (1)
    {
        /* Main program loop */
    }
}