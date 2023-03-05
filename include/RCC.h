#ifndef RCC_H
#define RCC_H

#include <stm32l432kc.h>

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_MSION_Pos                     (0U)
#define RCC_CR_MSION_Msk                     (0x1UL << RCC_CR_MSION_Pos)       /*!< 0x00000001 */
#define RCC_CR_MSION                         RCC_CR_MSION_Msk                  /*!< Internal Multi Speed oscillator (MSI) clock enable */
#define RCC_CR_MSIRDY_Pos                    (1U)
#define RCC_CR_MSIRDY_Msk                    (0x1UL << RCC_CR_MSIRDY_Pos)      /*!< 0x00000002 */
#define RCC_CR_MSIRDY                        RCC_CR_MSIRDY_Msk                 /*!< Internal Multi Speed oscillator (MSI) clock ready flag */
#define RCC_CR_MSIPLLEN_Pos                  (2U)
#define RCC_CR_MSIPLLEN_Msk                  (0x1UL << RCC_CR_MSIPLLEN_Pos)    /*!< 0x00000004 */
#define RCC_CR_MSIPLLEN                      RCC_CR_MSIPLLEN_Msk               /*!< Internal Multi Speed oscillator (MSI) PLL enable */
#define RCC_CR_MSIRGSEL_Pos                  (3U)
#define RCC_CR_MSIRGSEL_Msk                  (0x1UL << RCC_CR_MSIRGSEL_Pos)    /*!< 0x00000008 */
#define RCC_CR_MSIRGSEL                      RCC_CR_MSIRGSEL_Msk               /*!< Internal Multi Speed oscillator (MSI) range selection */

/*!< MSIRANGE configuration : 12 frequency ranges available */
#define RCC_CR_MSIRANGE_Pos                  (4U)
#define RCC_CR_MSIRANGE_Msk                  (0xFUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000F0 */
#define RCC_CR_MSIRANGE                      RCC_CR_MSIRANGE_Msk               /*!< Internal Multi Speed oscillator (MSI) clock Range */
#define RCC_CR_MSIRANGE_0                    (0x0UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000000 */
#define RCC_CR_MSIRANGE_1                    (0x1UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000010 */
#define RCC_CR_MSIRANGE_2                    (0x2UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000020 */
#define RCC_CR_MSIRANGE_3                    (0x3UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000030 */
#define RCC_CR_MSIRANGE_4                    (0x4UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000040 */
#define RCC_CR_MSIRANGE_5                    (0x5UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000050 */
#define RCC_CR_MSIRANGE_6                    (0x6UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000060 */
#define RCC_CR_MSIRANGE_7                    (0x7UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000070 */
#define RCC_CR_MSIRANGE_8                    (0x8UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000080 */
#define RCC_CR_MSIRANGE_9                    (0x9UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000090 */
#define RCC_CR_MSIRANGE_10                   (0xAUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000A0 */
#define RCC_CR_MSIRANGE_11                   (0xBUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000B0 */

#define RCC_CR_HSION_Pos                     (8U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)       /*!< 0x00000100 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                  (9U)
#define RCC_CR_HSIKERON_Msk                  (0x1UL << RCC_CR_HSIKERON_Pos)    /*!< 0x00000200 */
#define RCC_CR_HSIKERON                      RCC_CR_HSIKERON_Msk               /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                    (10U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)      /*!< 0x00000400 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed oscillator (HSI16) clock ready flag */
#define RCC_CR_HSIASFS_Pos                   (11U)
#define RCC_CR_HSIASFS_Msk                   (0x1UL << RCC_CR_HSIASFS_Pos)     /*!< 0x00000800 */
#define RCC_CR_HSIASFS                       RCC_CR_HSIASFS_Msk                /*!< HSI16 Automatic Start from Stop */

#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)       /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)      /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_HSEBYP_Pos                    (18U)
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)      /*!< 0x00040000 */
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk                 /*!< External High Speed oscillator (HSE) clock bypass */
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)       /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< HSE Clock Security System enable */

#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)       /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< System PLL clock enable */
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)      /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< System PLL clock ready */
#define RCC_CR_PLLSAI1ON_Pos                 (26U)
#define RCC_CR_PLLSAI1ON_Msk                 (0x1UL << RCC_CR_PLLSAI1ON_Pos)   /*!< 0x04000000 */
#define RCC_CR_PLLSAI1ON                     RCC_CR_PLLSAI1ON_Msk              /*!< SAI1 PLL enable */
#define RCC_CR_PLLSAI1RDY_Pos                (27U)
#define RCC_CR_PLLSAI1RDY_Msk                (0x1UL << RCC_CR_PLLSAI1RDY_Pos)  /*!< 0x08000000 */
#define RCC_CR_PLLSAI1RDY                    RCC_CR_PLLSAI1RDY_Msk             /*!< SAI1 PLL ready */

/********************  Bit definition for RCC_ICSCR register  ***************/
/*!< MSICAL configuration */
#define RCC_ICSCR_MSICAL_Pos                 (0U)
#define RCC_ICSCR_MSICAL_Msk                 (0xFFUL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x000000FF */
#define RCC_ICSCR_MSICAL                     RCC_ICSCR_MSICAL_Msk              /*!< MSICAL[7:0] bits */
#define RCC_ICSCR_MSICAL_0                   (0x01UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000001 */
#define RCC_ICSCR_MSICAL_1                   (0x02UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000002 */
#define RCC_ICSCR_MSICAL_2                   (0x04UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000004 */
#define RCC_ICSCR_MSICAL_3                   (0x08UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000008 */
#define RCC_ICSCR_MSICAL_4                   (0x10UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000010 */
#define RCC_ICSCR_MSICAL_5                   (0x20UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000020 */
#define RCC_ICSCR_MSICAL_6                   (0x40UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000040 */
#define RCC_ICSCR_MSICAL_7                   (0x80UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000080 */

/*!< MSITRIM configuration */
#define RCC_ICSCR_MSITRIM_Pos                (8U)
#define RCC_ICSCR_MSITRIM_Msk                (0xFFUL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x0000FF00 */
#define RCC_ICSCR_MSITRIM                    RCC_ICSCR_MSITRIM_Msk             /*!< MSITRIM[7:0] bits */
#define RCC_ICSCR_MSITRIM_0                  (0x01UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000100 */
#define RCC_ICSCR_MSITRIM_1                  (0x02UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000200 */
#define RCC_ICSCR_MSITRIM_2                  (0x04UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000400 */
#define RCC_ICSCR_MSITRIM_3                  (0x08UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000800 */
#define RCC_ICSCR_MSITRIM_4                  (0x10UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00001000 */
#define RCC_ICSCR_MSITRIM_5                  (0x20UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00002000 */
#define RCC_ICSCR_MSITRIM_6                  (0x40UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00004000 */
#define RCC_ICSCR_MSITRIM_7                  (0x80UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00008000 */

/*!< HSICAL configuration */
#define RCC_ICSCR_HSICAL_Pos                 (16U)
#define RCC_ICSCR_HSICAL_Msk                 (0xFFUL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00FF0000 */
#define RCC_ICSCR_HSICAL                     RCC_ICSCR_HSICAL_Msk              /*!< HSICAL[7:0] bits */
#define RCC_ICSCR_HSICAL_0                   (0x01UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00010000 */
#define RCC_ICSCR_HSICAL_1                   (0x02UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00020000 */
#define RCC_ICSCR_HSICAL_2                   (0x04UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00040000 */
#define RCC_ICSCR_HSICAL_3                   (0x08UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00080000 */
#define RCC_ICSCR_HSICAL_4                   (0x10UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00100000 */
#define RCC_ICSCR_HSICAL_5                   (0x20UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00200000 */
#define RCC_ICSCR_HSICAL_6                   (0x40UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00400000 */
#define RCC_ICSCR_HSICAL_7                   (0x80UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00800000 */

/*!< HSITRIM configuration */
#define RCC_ICSCR_HSITRIM_Pos                (24U)
#define RCC_ICSCR_HSITRIM_Msk                (0x1FUL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x1F000000 */
#define RCC_ICSCR_HSITRIM                    RCC_ICSCR_HSITRIM_Msk             /*!< HSITRIM[4:0] bits */
#define RCC_ICSCR_HSITRIM_0                  (0x01UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x01000000 */
#define RCC_ICSCR_HSITRIM_1                  (0x02UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x02000000 */
#define RCC_ICSCR_HSITRIM_2                  (0x04UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x04000000 */
#define RCC_ICSCR_HSITRIM_3                  (0x08UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x08000000 */
#define RCC_ICSCR_HSITRIM_4                  (0x10UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x10000000 */

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)        /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)        /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)        /*!< 0x00000002 */

#define RCC_CFGR_SW_MSI                      (0x00000000UL)                    /*!< MSI oscillator selection as system clock */
#define RCC_CFGR_SW_HSI                      (0x00000001UL)                    /*!< HSI16 oscillator selection as system clock */
#define RCC_CFGR_SW_HSE                      (0x00000002UL)                    /*!< HSE oscillator selection as system clock */
#define RCC_CFGR_SW_PLL                      (0x00000003UL)                    /*!< PLL selection as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)       /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000008 */

#define RCC_CFGR_SWS_MSI                     (0x00000000UL)                    /*!< MSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSI                     (0x00000004UL)                    /*!< HSI16 oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                     (0x00000008UL)                    /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                     (0x0000000CUL)                    /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)      /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                   (0x00000000UL)                    /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                   (0x00000080UL)                    /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                   (0x00000090UL)                    /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                   (0x000000A0UL)                    /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                  (0x000000B0UL)                    /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                  (0x000000C0UL)                    /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                 (0x000000D0UL)                    /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                 (0x000000E0UL)                    /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                 (0x000000F0UL)                    /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1                  (0x00000000UL)                    /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                  (0x00000400UL)                    /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                  (0x00000500UL)                    /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                  (0x00000600UL)                    /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                 (0x00000700UL)                    /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1                  (0x00000000UL)                    /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                  (0x00002000UL)                    /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                  (0x00002800UL)                    /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                  (0x00003000UL)                    /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                 (0x00003800UL)                    /*!< HCLK divided by 16 */

#define RCC_CFGR_STOPWUCK_Pos                (15U)
#define RCC_CFGR_STOPWUCK_Msk                (0x1UL << RCC_CFGR_STOPWUCK_Pos)  /*!< 0x00008000 */
#define RCC_CFGR_STOPWUCK                    RCC_CFGR_STOPWUCK_Msk             /*!< Wake Up from stop and CSS backup clock selection */

/*!< MCOSEL configuration */
#define RCC_CFGR_MCOSEL_Pos                  (24U)
#define RCC_CFGR_MCOSEL_Msk                  (0xFUL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x0F000000 */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCOSEL_Msk               /*!< MCOSEL [3:0] bits (Clock output selection) */
#define RCC_CFGR_MCOSEL_0                    (0x1UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                    (0x2UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                    (0x4UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x04000000 */
#define RCC_CFGR_MCOSEL_3                    (0x8UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x08000000 */

#define RCC_CFGR_MCOPRE_Pos                  (28U)
#define RCC_CFGR_MCOPRE_Msk                  (0x7UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                      RCC_CFGR_MCOPRE_Msk               /*!< MCO prescaler */
#define RCC_CFGR_MCOPRE_0                    (0x1UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                    (0x2UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                    (0x4UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x40000000 */

#define RCC_CFGR_MCOPRE_DIV1                 (0x00000000UL)                    /*!< MCO is divided by 1 */
#define RCC_CFGR_MCOPRE_DIV2                 (0x10000000UL)                    /*!< MCO is divided by 2 */
#define RCC_CFGR_MCOPRE_DIV4                 (0x20000000UL)                    /*!< MCO is divided by 4 */
#define RCC_CFGR_MCOPRE_DIV8                 (0x30000000UL)                    /*!< MCO is divided by 8 */
#define RCC_CFGR_MCOPRE_DIV16                (0x40000000UL)                    /*!< MCO is divided by 16 */

/* Legacy aliases */
#define RCC_CFGR_MCO_PRE                     RCC_CFGR_MCOPRE
#define RCC_CFGR_MCO_PRE_1                   RCC_CFGR_MCOPRE_DIV1
#define RCC_CFGR_MCO_PRE_2                   RCC_CFGR_MCOPRE_DIV2
#define RCC_CFGR_MCO_PRE_4                   RCC_CFGR_MCOPRE_DIV4
#define RCC_CFGR_MCO_PRE_8                   RCC_CFGR_MCOPRE_DIV8
#define RCC_CFGR_MCO_PRE_16                  RCC_CFGR_MCOPRE_DIV16

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC_Pos               (0U)
#define RCC_PLLCFGR_PLLSRC_Msk               (0x3UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC                   RCC_PLLCFGR_PLLSRC_Msk

#define RCC_PLLCFGR_PLLSRC_MSI_Pos           (0U)
#define RCC_PLLCFGR_PLLSRC_MSI_Msk           (0x1UL << RCC_PLLCFGR_PLLSRC_MSI_Pos) /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC_MSI               RCC_PLLCFGR_PLLSRC_MSI_Msk        /*!< MSI oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSI_Pos           (1U)
#define RCC_PLLCFGR_PLLSRC_HSI_Msk           (0x1UL << RCC_PLLCFGR_PLLSRC_HSI_Pos) /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLSRC_HSI               RCC_PLLCFGR_PLLSRC_HSI_Msk        /*!< HSI16 oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSE_Pos           (0U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk           (0x3UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC_HSE               RCC_PLLCFGR_PLLSRC_HSE_Msk        /*!< HSE oscillator source clock selected */

#define RCC_PLLCFGR_PLLM_Pos                 (4U)
#define RCC_PLLCFGR_PLLM_Msk                 (0x7UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000070 */
#define RCC_PLLCFGR_PLLM                     RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0                   (0x1UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_1                   (0x2UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_2                   (0x4UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLM_DIV1                (0U)
#define RCC_PLLCFGR_PLLM_DIV2                (1U)
#define RCC_PLLCFGR_PLLM_DIV3                (2U)
#define RCC_PLLCFGR_PLLM_DIV4                (3U)
#define RCC_PLLCFGR_PLLM_DIV5                (4U)
#define RCC_PLLCFGR_PLLM_DIV6                (5U)
#define RCC_PLLCFGR_PLLM_DIV7                (6U)
#define RCC_PLLCFGR_PLLM_DIV8                (7U)

#define RCC_PLLCFGR_PLLN_Pos                 (8U)
#define RCC_PLLCFGR_PLLN_Msk                 (0x7FUL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00007F00 */
#define RCC_PLLCFGR_PLLN                     RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0                   (0x01UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_1                   (0x02UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_2                   (0x04UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_3                   (0x08UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_4                   (0x10UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_5                   (0x20UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_6                   (0x40UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLPEN_Pos               (16U)
#define RCC_PLLCFGR_PLLPEN_Msk               (0x1UL << RCC_PLLCFGR_PLLPEN_Pos) /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLPEN                   RCC_PLLCFGR_PLLPEN_Msk
#define RCC_PLLCFGR_PLLP_Pos                 (17U)
#define RCC_PLLCFGR_PLLP_Msk                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)   /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLP                     RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLQEN_Pos               (20U)
#define RCC_PLLCFGR_PLLQEN_Msk               (0x1UL << RCC_PLLCFGR_PLLQEN_Pos) /*!< 0x00100000 */
#define RCC_PLLCFGR_PLLQEN                   RCC_PLLCFGR_PLLQEN_Msk

#define RCC_PLLCFGR_PLLQ_Pos                 (21U)
#define RCC_PLLCFGR_PLLQ_Msk                 (0x3UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00600000 */
#define RCC_PLLCFGR_PLLQ                     RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0                   (0x1UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00200000 */
#define RCC_PLLCFGR_PLLQ_1                   (0x2UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00400000 */

#define RCC_PLLCFGR_PLLREN_Pos               (24U)
#define RCC_PLLCFGR_PLLREN_Msk               (0x1UL << RCC_PLLCFGR_PLLREN_Pos) /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLREN                   RCC_PLLCFGR_PLLREN_Msk
#define RCC_PLLCFGR_PLLR_Pos                 (25U)
#define RCC_PLLCFGR_PLLR_Msk                 (0x3UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x06000000 */
#define RCC_PLLCFGR_PLLR                     RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0                   (0x1UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLR_1                   (0x2UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLR_DIV2                (0U)
#define RCC_PLLCFGR_PLLR_DIV4                (1U)
#define RCC_PLLCFGR_PLLR_DIV6                (2U)
#define RCC_PLLCFGR_PLLR_DIV8                (3U)

#define RCC_PLLCFGR_PLLPDIV_Pos              (27U)
#define RCC_PLLCFGR_PLLPDIV_Msk              (0x1FUL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0xF8000000 */
#define RCC_PLLCFGR_PLLPDIV                  RCC_PLLCFGR_PLLPDIV_Msk
#define RCC_PLLCFGR_PLLPDIV_0                (0x01UL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0x08000000 */
#define RCC_PLLCFGR_PLLPDIV_1                (0x02UL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0x10000000 */
#define RCC_PLLCFGR_PLLPDIV_2                (0x04UL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0x20000000 */
#define RCC_PLLCFGR_PLLPDIV_3                (0x08UL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0x40000000 */
#define RCC_PLLCFGR_PLLPDIV_4                (0x10UL << RCC_PLLCFGR_PLLPDIV_Pos) /*!< 0x80000000 */

/********************  Bit definition for RCC_PLLSAI1CFGR register  ************/
#define RCC_PLLSAI1CFGR_PLLSAI1N_Pos         (8U)
#define RCC_PLLSAI1CFGR_PLLSAI1N_Msk         (0x7FUL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00007F00 */
#define RCC_PLLSAI1CFGR_PLLSAI1N             RCC_PLLSAI1CFGR_PLLSAI1N_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1N_0           (0x01UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000100 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_1           (0x02UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000200 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_2           (0x04UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000400 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_3           (0x08UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000800 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_4           (0x10UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00001000 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_5           (0x20UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00002000 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_6           (0x40UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00004000 */

#define RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos       (16U)
#define RCC_PLLSAI1CFGR_PLLSAI1PEN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos) /*!< 0x00010000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PEN           RCC_PLLSAI1CFGR_PLLSAI1PEN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1P_Pos         (17U)
#define RCC_PLLSAI1CFGR_PLLSAI1P_Msk         (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1P_Pos) /*!< 0x00020000 */
#define RCC_PLLSAI1CFGR_PLLSAI1P             RCC_PLLSAI1CFGR_PLLSAI1P_Msk

#define RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos       (20U)
#define RCC_PLLSAI1CFGR_PLLSAI1QEN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos) /*!< 0x00100000 */
#define RCC_PLLSAI1CFGR_PLLSAI1QEN           RCC_PLLSAI1CFGR_PLLSAI1QEN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1Q_Pos         (21U)
#define RCC_PLLSAI1CFGR_PLLSAI1Q_Msk         (0x3UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00600000 */
#define RCC_PLLSAI1CFGR_PLLSAI1Q             RCC_PLLSAI1CFGR_PLLSAI1Q_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1Q_0           (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00200000 */
#define RCC_PLLSAI1CFGR_PLLSAI1Q_1           (0x2UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00400000 */

#define RCC_PLLSAI1CFGR_PLLSAI1REN_Pos       (24U)
#define RCC_PLLSAI1CFGR_PLLSAI1REN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1REN_Pos) /*!< 0x01000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1REN           RCC_PLLSAI1CFGR_PLLSAI1REN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1R_Pos         (25U)
#define RCC_PLLSAI1CFGR_PLLSAI1R_Msk         (0x3UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x06000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1R             RCC_PLLSAI1CFGR_PLLSAI1R_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1R_0           (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x02000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1R_1           (0x2UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x04000000 */

#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos      (27U)
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_Msk      (0x1FUL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0xF8000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV          RCC_PLLSAI1CFGR_PLLSAI1PDIV_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_0        (0x01UL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0x08000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_1        (0x02UL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0x10000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_2        (0x04UL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0x20000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_3        (0x08UL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0x40000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_4        (0x10UL << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos) /*!< 0x80000000 */

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSIRDYIE_Pos                (0U)
#define RCC_CIER_LSIRDYIE_Msk                (0x1UL << RCC_CIER_LSIRDYIE_Pos)  /*!< 0x00000001 */
#define RCC_CIER_LSIRDYIE                    RCC_CIER_LSIRDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos                (1U)
#define RCC_CIER_LSERDYIE_Msk                (0x1UL << RCC_CIER_LSERDYIE_Pos)  /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                    RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_MSIRDYIE_Pos                (2U)
#define RCC_CIER_MSIRDYIE_Msk                (0x1UL << RCC_CIER_MSIRDYIE_Pos)  /*!< 0x00000004 */
#define RCC_CIER_MSIRDYIE                    RCC_CIER_MSIRDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos                (3U)
#define RCC_CIER_HSIRDYIE_Msk                (0x1UL << RCC_CIER_HSIRDYIE_Pos)  /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                    RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos                (4U)
#define RCC_CIER_HSERDYIE_Msk                (0x1UL << RCC_CIER_HSERDYIE_Pos)  /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                    RCC_CIER_HSERDYIE_Msk
#define RCC_CIER_PLLRDYIE_Pos                (5U)
#define RCC_CIER_PLLRDYIE_Msk                (0x1UL << RCC_CIER_PLLRDYIE_Pos)  /*!< 0x00000020 */
#define RCC_CIER_PLLRDYIE                    RCC_CIER_PLLRDYIE_Msk
#define RCC_CIER_PLLSAI1RDYIE_Pos            (6U)
#define RCC_CIER_PLLSAI1RDYIE_Msk            (0x1UL << RCC_CIER_PLLSAI1RDYIE_Pos) /*!< 0x00000040 */
#define RCC_CIER_PLLSAI1RDYIE                RCC_CIER_PLLSAI1RDYIE_Msk
#define RCC_CIER_LSECSSIE_Pos                (9U)
#define RCC_CIER_LSECSSIE_Msk                (0x1UL << RCC_CIER_LSECSSIE_Pos)  /*!< 0x00000200 */
#define RCC_CIER_LSECSSIE                    RCC_CIER_LSECSSIE_Msk
#define RCC_CIER_HSI48RDYIE_Pos              (10U)
#define RCC_CIER_HSI48RDYIE_Msk              (0x1UL << RCC_CIER_HSI48RDYIE_Pos) /*!< 0x00000400 */
#define RCC_CIER_HSI48RDYIE                  RCC_CIER_HSI48RDYIE_Msk

/********************  Bit definition for RCC_CIFR register  ******************/
#define RCC_CIFR_LSIRDYF_Pos                 (0U)
#define RCC_CIFR_LSIRDYF_Msk                 (0x1UL << RCC_CIFR_LSIRDYF_Pos)   /*!< 0x00000001 */
#define RCC_CIFR_LSIRDYF                     RCC_CIFR_LSIRDYF_Msk
#define RCC_CIFR_LSERDYF_Pos                 (1U)
#define RCC_CIFR_LSERDYF_Msk                 (0x1UL << RCC_CIFR_LSERDYF_Pos)   /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                     RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_MSIRDYF_Pos                 (2U)
#define RCC_CIFR_MSIRDYF_Msk                 (0x1UL << RCC_CIFR_MSIRDYF_Pos)   /*!< 0x00000004 */
#define RCC_CIFR_MSIRDYF                     RCC_CIFR_MSIRDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos                 (3U)
#define RCC_CIFR_HSIRDYF_Msk                 (0x1UL << RCC_CIFR_HSIRDYF_Pos)   /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                     RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos                 (4U)
#define RCC_CIFR_HSERDYF_Msk                 (0x1UL << RCC_CIFR_HSERDYF_Pos)   /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                     RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_PLLRDYF_Pos                 (5U)
#define RCC_CIFR_PLLRDYF_Msk                 (0x1UL << RCC_CIFR_PLLRDYF_Pos)   /*!< 0x00000020 */
#define RCC_CIFR_PLLRDYF                     RCC_CIFR_PLLRDYF_Msk
#define RCC_CIFR_PLLSAI1RDYF_Pos             (6U)
#define RCC_CIFR_PLLSAI1RDYF_Msk             (0x1UL << RCC_CIFR_PLLSAI1RDYF_Pos) /*!< 0x00000040 */
#define RCC_CIFR_PLLSAI1RDYF                 RCC_CIFR_PLLSAI1RDYF_Msk
#define RCC_CIFR_CSSF_Pos                    (8U)
#define RCC_CIFR_CSSF_Msk                    (0x1UL << RCC_CIFR_CSSF_Pos)      /*!< 0x00000100 */
#define RCC_CIFR_CSSF                        RCC_CIFR_CSSF_Msk
#define RCC_CIFR_LSECSSF_Pos                 (9U)
#define RCC_CIFR_LSECSSF_Msk                 (0x1UL << RCC_CIFR_LSECSSF_Pos)   /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                     RCC_CIFR_LSECSSF_Msk
#define RCC_CIFR_HSI48RDYF_Pos               (10U)
#define RCC_CIFR_HSI48RDYF_Msk               (0x1UL << RCC_CIFR_HSI48RDYF_Pos) /*!< 0x00000400 */
#define RCC_CIFR_HSI48RDYF                   RCC_CIFR_HSI48RDYF_Msk

/********************  Bit definition for RCC_CICR register  ******************/
#define RCC_CICR_LSIRDYC_Pos                 (0U)
#define RCC_CICR_LSIRDYC_Msk                 (0x1UL << RCC_CICR_LSIRDYC_Pos)   /*!< 0x00000001 */
#define RCC_CICR_LSIRDYC                     RCC_CICR_LSIRDYC_Msk
#define RCC_CICR_LSERDYC_Pos                 (1U)
#define RCC_CICR_LSERDYC_Msk                 (0x1UL << RCC_CICR_LSERDYC_Pos)   /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                     RCC_CICR_LSERDYC_Msk
#define RCC_CICR_MSIRDYC_Pos                 (2U)
#define RCC_CICR_MSIRDYC_Msk                 (0x1UL << RCC_CICR_MSIRDYC_Pos)   /*!< 0x00000004 */
#define RCC_CICR_MSIRDYC                     RCC_CICR_MSIRDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                 (3U)
#define RCC_CICR_HSIRDYC_Msk                 (0x1UL << RCC_CICR_HSIRDYC_Pos)   /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                     RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos                 (4U)
#define RCC_CICR_HSERDYC_Msk                 (0x1UL << RCC_CICR_HSERDYC_Pos)   /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                     RCC_CICR_HSERDYC_Msk
#define RCC_CICR_PLLRDYC_Pos                 (5U)
#define RCC_CICR_PLLRDYC_Msk                 (0x1UL << RCC_CICR_PLLRDYC_Pos)   /*!< 0x00000020 */
#define RCC_CICR_PLLRDYC                     RCC_CICR_PLLRDYC_Msk
#define RCC_CICR_PLLSAI1RDYC_Pos             (6U)
#define RCC_CICR_PLLSAI1RDYC_Msk             (0x1UL << RCC_CICR_PLLSAI1RDYC_Pos) /*!< 0x00000040 */
#define RCC_CICR_PLLSAI1RDYC                 RCC_CICR_PLLSAI1RDYC_Msk
#define RCC_CICR_CSSC_Pos                    (8U)
#define RCC_CICR_CSSC_Msk                    (0x1UL << RCC_CICR_CSSC_Pos)      /*!< 0x00000100 */
#define RCC_CICR_CSSC                        RCC_CICR_CSSC_Msk
#define RCC_CICR_LSECSSC_Pos                 (9U)
#define RCC_CICR_LSECSSC_Msk                 (0x1UL << RCC_CICR_LSECSSC_Pos)   /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                     RCC_CICR_LSECSSC_Msk
#define RCC_CICR_HSI48RDYC_Pos               (10U)
#define RCC_CICR_HSI48RDYC_Msk               (0x1UL << RCC_CICR_HSI48RDYC_Pos) /*!< 0x00000400 */
#define RCC_CICR_HSI48RDYC                   RCC_CICR_HSI48RDYC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_DMA1RST_Pos             (0U)
#define RCC_AHB1RSTR_DMA1RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_DMA1RST                 RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMA2RST_Pos             (1U)
#define RCC_AHB1RSTR_DMA2RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos) /*!< 0x00000002 */
#define RCC_AHB1RSTR_DMA2RST                 RCC_AHB1RSTR_DMA2RST_Msk
#define RCC_AHB1RSTR_FLASHRST_Pos            (8U)
#define RCC_AHB1RSTR_FLASHRST_Msk            (0x1UL << RCC_AHB1RSTR_FLASHRST_Pos) /*!< 0x00000100 */
#define RCC_AHB1RSTR_FLASHRST                RCC_AHB1RSTR_FLASHRST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos              (12U)
#define RCC_AHB1RSTR_CRCRST_Msk              (0x1UL << RCC_AHB1RSTR_CRCRST_Pos) /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                  RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_TSCRST_Pos              (16U)
#define RCC_AHB1RSTR_TSCRST_Msk              (0x1UL << RCC_AHB1RSTR_TSCRST_Pos) /*!< 0x00010000 */
#define RCC_AHB1RSTR_TSCRST                  RCC_AHB1RSTR_TSCRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_GPIOARST_Pos            (0U)
#define RCC_AHB2RSTR_GPIOARST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB2RSTR_GPIOARST                RCC_AHB2RSTR_GPIOARST_Msk
#define RCC_AHB2RSTR_GPIOBRST_Pos            (1U)
#define RCC_AHB2RSTR_GPIOBRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB2RSTR_GPIOBRST                RCC_AHB2RSTR_GPIOBRST_Msk
#define RCC_AHB2RSTR_GPIOCRST_Pos            (2U)
#define RCC_AHB2RSTR_GPIOCRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB2RSTR_GPIOCRST                RCC_AHB2RSTR_GPIOCRST_Msk
#define RCC_AHB2RSTR_GPIOHRST_Pos            (7U)
#define RCC_AHB2RSTR_GPIOHRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_GPIOHRST                RCC_AHB2RSTR_GPIOHRST_Msk
#define RCC_AHB2RSTR_ADCRST_Pos              (13U)
#define RCC_AHB2RSTR_ADCRST_Msk              (0x1UL << RCC_AHB2RSTR_ADCRST_Pos) /*!< 0x00002000 */
#define RCC_AHB2RSTR_ADCRST                  RCC_AHB2RSTR_ADCRST_Msk
#define RCC_AHB2RSTR_RNGRST_Pos              (18U)
#define RCC_AHB2RSTR_RNGRST_Msk              (0x1UL << RCC_AHB2RSTR_RNGRST_Pos) /*!< 0x00040000 */
#define RCC_AHB2RSTR_RNGRST                  RCC_AHB2RSTR_RNGRST_Msk

/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_QSPIRST_Pos             (8U)
#define RCC_AHB3RSTR_QSPIRST_Msk             (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos) /*!< 0x00000100 */
#define RCC_AHB3RSTR_QSPIRST                 RCC_AHB3RSTR_QSPIRST_Msk

/********************  Bit definition for RCC_APB1RSTR1 register  **************/
#define RCC_APB1RSTR1_TIM2RST_Pos            (0U)
#define RCC_APB1RSTR1_TIM2RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR1_TIM2RST                RCC_APB1RSTR1_TIM2RST_Msk
#define RCC_APB1RSTR1_TIM6RST_Pos            (4U)
#define RCC_APB1RSTR1_TIM6RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM6RST_Pos) /*!< 0x00000010 */
#define RCC_APB1RSTR1_TIM6RST                RCC_APB1RSTR1_TIM6RST_Msk
#define RCC_APB1RSTR1_TIM7RST_Pos            (5U)
#define RCC_APB1RSTR1_TIM7RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM7RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR1_TIM7RST                RCC_APB1RSTR1_TIM7RST_Msk
#define RCC_APB1RSTR1_SPI3RST_Pos            (15U)
#define RCC_APB1RSTR1_SPI3RST_Msk            (0x1UL << RCC_APB1RSTR1_SPI3RST_Pos) /*!< 0x00008000 */
#define RCC_APB1RSTR1_SPI3RST                RCC_APB1RSTR1_SPI3RST_Msk
#define RCC_APB1RSTR1_USART2RST_Pos          (17U)
#define RCC_APB1RSTR1_USART2RST_Msk          (0x1UL << RCC_APB1RSTR1_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR1_USART2RST              RCC_APB1RSTR1_USART2RST_Msk
#define RCC_APB1RSTR1_I2C1RST_Pos            (21U)
#define RCC_APB1RSTR1_I2C1RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR1_I2C1RST                RCC_APB1RSTR1_I2C1RST_Msk
#define RCC_APB1RSTR1_I2C3RST_Pos            (23U)
#define RCC_APB1RSTR1_I2C3RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C3RST_Pos) /*!< 0x00800000 */
#define RCC_APB1RSTR1_I2C3RST                RCC_APB1RSTR1_I2C3RST_Msk
#define RCC_APB1RSTR1_CRSRST_Pos             (24U)
#define RCC_APB1RSTR1_CRSRST_Msk             (0x1UL << RCC_APB1RSTR1_CRSRST_Pos) /*!< 0x01000000 */
#define RCC_APB1RSTR1_CRSRST                 RCC_APB1RSTR1_CRSRST_Msk
#define RCC_APB1RSTR1_CAN1RST_Pos            (25U)
#define RCC_APB1RSTR1_CAN1RST_Msk            (0x1UL << RCC_APB1RSTR1_CAN1RST_Pos) /*!< 0x02000000 */
#define RCC_APB1RSTR1_CAN1RST                RCC_APB1RSTR1_CAN1RST_Msk
#define RCC_APB1RSTR1_USBFSRST_Pos           (26U)
#define RCC_APB1RSTR1_USBFSRST_Msk           (0x1UL << RCC_APB1RSTR1_USBFSRST_Pos) /*!< 0x04000000 */
#define RCC_APB1RSTR1_USBFSRST               RCC_APB1RSTR1_USBFSRST_Msk
#define RCC_APB1RSTR1_PWRRST_Pos             (28U)
#define RCC_APB1RSTR1_PWRRST_Msk             (0x1UL << RCC_APB1RSTR1_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR1_PWRRST                 RCC_APB1RSTR1_PWRRST_Msk
#define RCC_APB1RSTR1_DAC1RST_Pos            (29U)
#define RCC_APB1RSTR1_DAC1RST_Msk            (0x1UL << RCC_APB1RSTR1_DAC1RST_Pos) /*!< 0x20000000 */
#define RCC_APB1RSTR1_DAC1RST                RCC_APB1RSTR1_DAC1RST_Msk
#define RCC_APB1RSTR1_OPAMPRST_Pos           (30U)
#define RCC_APB1RSTR1_OPAMPRST_Msk           (0x1UL << RCC_APB1RSTR1_OPAMPRST_Pos) /*!< 0x40000000 */
#define RCC_APB1RSTR1_OPAMPRST               RCC_APB1RSTR1_OPAMPRST_Msk
#define RCC_APB1RSTR1_LPTIM1RST_Pos          (31U)
#define RCC_APB1RSTR1_LPTIM1RST_Msk          (0x1UL << RCC_APB1RSTR1_LPTIM1RST_Pos) /*!< 0x80000000 */
#define RCC_APB1RSTR1_LPTIM1RST              RCC_APB1RSTR1_LPTIM1RST_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1RSTR2_LPUART1RST_Pos         (0U)
#define RCC_APB1RSTR2_LPUART1RST_Msk         (0x1UL << RCC_APB1RSTR2_LPUART1RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR2_LPUART1RST             RCC_APB1RSTR2_LPUART1RST_Msk
#define RCC_APB1RSTR2_SWPMI1RST_Pos          (2U)
#define RCC_APB1RSTR2_SWPMI1RST_Msk          (0x1UL << RCC_APB1RSTR2_SWPMI1RST_Pos) /*!< 0x00000004 */
#define RCC_APB1RSTR2_SWPMI1RST              RCC_APB1RSTR2_SWPMI1RST_Msk
#define RCC_APB1RSTR2_LPTIM2RST_Pos          (5U)
#define RCC_APB1RSTR2_LPTIM2RST_Msk          (0x1UL << RCC_APB1RSTR2_LPTIM2RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR2_LPTIM2RST              RCC_APB1RSTR2_LPTIM2RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_SYSCFGRST_Pos           (0U)
#define RCC_APB2RSTR_SYSCFGRST_Msk           (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_SYSCFGRST               RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_TIM1RST_Pos             (11U)
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos           (14U)
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_TIM15RST_Pos            (16U)
#define RCC_APB2RSTR_TIM15RST_Msk            (0x1UL << RCC_APB2RSTR_TIM15RST_Pos) /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM15RST                RCC_APB2RSTR_TIM15RST_Msk
#define RCC_APB2RSTR_TIM16RST_Pos            (17U)
#define RCC_APB2RSTR_TIM16RST_Msk            (0x1UL << RCC_APB2RSTR_TIM16RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM16RST                RCC_APB2RSTR_TIM16RST_Msk
#define RCC_APB2RSTR_SAI1RST_Pos             (21U)
#define RCC_APB2RSTR_SAI1RST_Msk             (0x1UL << RCC_APB2RSTR_SAI1RST_Pos) /*!< 0x00200000 */
#define RCC_APB2RSTR_SAI1RST                 RCC_APB2RSTR_SAI1RST_Msk

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_DMA1EN_Pos               (0U)
#define RCC_AHB1ENR_DMA1EN_Msk               (0x1UL << RCC_AHB1ENR_DMA1EN_Pos) /*!< 0x00000001 */
#define RCC_AHB1ENR_DMA1EN                   RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMA2EN_Pos               (1U)
#define RCC_AHB1ENR_DMA2EN_Msk               (0x1UL << RCC_AHB1ENR_DMA2EN_Pos) /*!< 0x00000002 */
#define RCC_AHB1ENR_DMA2EN                   RCC_AHB1ENR_DMA2EN_Msk
#define RCC_AHB1ENR_FLASHEN_Pos              (8U)
#define RCC_AHB1ENR_FLASHEN_Msk              (0x1UL << RCC_AHB1ENR_FLASHEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1ENR_FLASHEN                  RCC_AHB1ENR_FLASHEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos                (12U)
#define RCC_AHB1ENR_CRCEN_Msk                (0x1UL << RCC_AHB1ENR_CRCEN_Pos)  /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                    RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_TSCEN_Pos                (16U)
#define RCC_AHB1ENR_TSCEN_Msk                (0x1UL << RCC_AHB1ENR_TSCEN_Pos)  /*!< 0x00010000 */
#define RCC_AHB1ENR_TSCEN                    RCC_AHB1ENR_TSCEN_Msk

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_GPIOAEN_Pos              (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                  RCC_AHB2ENR_GPIOAEN_Msk
#define RCC_AHB2ENR_GPIOBEN_Pos              (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOBEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2ENR_GPIOBEN                  RCC_AHB2ENR_GPIOBEN_Msk
#define RCC_AHB2ENR_GPIOCEN_Pos              (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOCEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2ENR_GPIOCEN                  RCC_AHB2ENR_GPIOCEN_Msk
#define RCC_AHB2ENR_GPIOHEN_Pos              (7U)
#define RCC_AHB2ENR_GPIOHEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOHEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2ENR_GPIOHEN                  RCC_AHB2ENR_GPIOHEN_Msk
#define RCC_AHB2ENR_ADCEN_Pos                (13U)
#define RCC_AHB2ENR_ADCEN_Msk                (0x1UL << RCC_AHB2ENR_ADCEN_Pos)  /*!< 0x00002000 */
#define RCC_AHB2ENR_ADCEN                    RCC_AHB2ENR_ADCEN_Msk
#define RCC_AHB2ENR_RNGEN_Pos                (18U)
#define RCC_AHB2ENR_RNGEN_Msk                (0x1UL << RCC_AHB2ENR_RNGEN_Pos)  /*!< 0x00040000 */
#define RCC_AHB2ENR_RNGEN                    RCC_AHB2ENR_RNGEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_QSPIEN_Pos               (8U)
#define RCC_AHB3ENR_QSPIEN_Msk               (0x1UL << RCC_AHB3ENR_QSPIEN_Pos) /*!< 0x00000100 */
#define RCC_AHB3ENR_QSPIEN                   RCC_AHB3ENR_QSPIEN_Msk

/********************  Bit definition for RCC_APB1ENR1 register  ***************/
#define RCC_APB1ENR1_TIM2EN_Pos              (0U)
#define RCC_APB1ENR1_TIM2EN_Msk              (0x1UL << RCC_APB1ENR1_TIM2EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                  RCC_APB1ENR1_TIM2EN_Msk
#define RCC_APB1ENR1_TIM6EN_Pos              (4U)
#define RCC_APB1ENR1_TIM6EN_Msk              (0x1UL << RCC_APB1ENR1_TIM6EN_Pos) /*!< 0x00000010 */
#define RCC_APB1ENR1_TIM6EN                  RCC_APB1ENR1_TIM6EN_Msk
#define RCC_APB1ENR1_TIM7EN_Pos              (5U)
#define RCC_APB1ENR1_TIM7EN_Msk              (0x1UL << RCC_APB1ENR1_TIM7EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR1_TIM7EN                  RCC_APB1ENR1_TIM7EN_Msk
#define RCC_APB1ENR1_RTCAPBEN_Pos            (10U)
#define RCC_APB1ENR1_RTCAPBEN_Msk            (0x1UL << RCC_APB1ENR1_RTCAPBEN_Pos) /*!< 0x00000400 */
#define RCC_APB1ENR1_RTCAPBEN                RCC_APB1ENR1_RTCAPBEN_Msk
#define RCC_APB1ENR1_WWDGEN_Pos              (11U)
#define RCC_APB1ENR1_WWDGEN_Msk              (0x1UL << RCC_APB1ENR1_WWDGEN_Pos) /*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                  RCC_APB1ENR1_WWDGEN_Msk
#define RCC_APB1ENR1_SPI3EN_Pos              (15U)
#define RCC_APB1ENR1_SPI3EN_Msk              (0x1UL << RCC_APB1ENR1_SPI3EN_Pos) /*!< 0x00008000 */
#define RCC_APB1ENR1_SPI3EN                  RCC_APB1ENR1_SPI3EN_Msk
#define RCC_APB1ENR1_USART2EN_Pos            (17U)
#define RCC_APB1ENR1_USART2EN_Msk            (0x1UL << RCC_APB1ENR1_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR1_USART2EN                RCC_APB1ENR1_USART2EN_Msk
#define RCC_APB1ENR1_I2C1EN_Pos              (21U)
#define RCC_APB1ENR1_I2C1EN_Msk              (0x1UL << RCC_APB1ENR1_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_APB1ENR1_I2C1EN                  RCC_APB1ENR1_I2C1EN_Msk
#define RCC_APB1ENR1_I2C3EN_Pos              (23U)
#define RCC_APB1ENR1_I2C3EN_Msk              (0x1UL << RCC_APB1ENR1_I2C3EN_Pos) /*!< 0x00800000 */
#define RCC_APB1ENR1_I2C3EN                  RCC_APB1ENR1_I2C3EN_Msk
#define RCC_APB1ENR1_CRSEN_Pos               (24U)
#define RCC_APB1ENR1_CRSEN_Msk               (0x1UL << RCC_APB1ENR1_CRSEN_Pos) /*!< 0x01000000 */
#define RCC_APB1ENR1_CRSEN                   RCC_APB1ENR1_CRSEN_Msk
#define RCC_APB1ENR1_CAN1EN_Pos              (25U)
#define RCC_APB1ENR1_CAN1EN_Msk              (0x1UL << RCC_APB1ENR1_CAN1EN_Pos) /*!< 0x02000000 */
#define RCC_APB1ENR1_CAN1EN                  RCC_APB1ENR1_CAN1EN_Msk
#define RCC_APB1ENR1_USBFSEN_Pos             (26U)
#define RCC_APB1ENR1_USBFSEN_Msk             (0x1UL << RCC_APB1ENR1_USBFSEN_Pos) /*!< 0x04000000 */
#define RCC_APB1ENR1_USBFSEN                 RCC_APB1ENR1_USBFSEN_Msk
#define RCC_APB1ENR1_PWREN_Pos               (28U)
#define RCC_APB1ENR1_PWREN_Msk               (0x1UL << RCC_APB1ENR1_PWREN_Pos) /*!< 0x10000000 */
#define RCC_APB1ENR1_PWREN                   RCC_APB1ENR1_PWREN_Msk
#define RCC_APB1ENR1_DAC1EN_Pos              (29U)
#define RCC_APB1ENR1_DAC1EN_Msk              (0x1UL << RCC_APB1ENR1_DAC1EN_Pos) /*!< 0x20000000 */
#define RCC_APB1ENR1_DAC1EN                  RCC_APB1ENR1_DAC1EN_Msk
#define RCC_APB1ENR1_OPAMPEN_Pos             (30U)
#define RCC_APB1ENR1_OPAMPEN_Msk             (0x1UL << RCC_APB1ENR1_OPAMPEN_Pos) /*!< 0x40000000 */
#define RCC_APB1ENR1_OPAMPEN                 RCC_APB1ENR1_OPAMPEN_Msk
#define RCC_APB1ENR1_LPTIM1EN_Pos            (31U)
#define RCC_APB1ENR1_LPTIM1EN_Msk            (0x1UL << RCC_APB1ENR1_LPTIM1EN_Pos) /*!< 0x80000000 */
#define RCC_APB1ENR1_LPTIM1EN                RCC_APB1ENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1ENR2_LPUART1EN_Pos           (0U)
#define RCC_APB1ENR2_LPUART1EN_Msk           (0x1UL << RCC_APB1ENR2_LPUART1EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR2_LPUART1EN               RCC_APB1ENR2_LPUART1EN_Msk
#define RCC_APB1ENR2_SWPMI1EN_Pos            (2U)
#define RCC_APB1ENR2_SWPMI1EN_Msk            (0x1UL << RCC_APB1ENR2_SWPMI1EN_Pos) /*!< 0x00000004 */
#define RCC_APB1ENR2_SWPMI1EN                RCC_APB1ENR2_SWPMI1EN_Msk
#define RCC_APB1ENR2_LPTIM2EN_Pos            (5U)
#define RCC_APB1ENR2_LPTIM2EN_Msk            (0x1UL << RCC_APB1ENR2_LPTIM2EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR2_LPTIM2EN                RCC_APB1ENR2_LPTIM2EN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_SYSCFGEN_Pos             (0U)
#define RCC_APB2ENR_SYSCFGEN_Msk             (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos) /*!< 0x00000001 */
#define RCC_APB2ENR_SYSCFGEN                 RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_FWEN_Pos                 (7U)
#define RCC_APB2ENR_FWEN_Msk                 (0x1UL << RCC_APB2ENR_FWEN_Pos)   /*!< 0x00000080 */
#define RCC_APB2ENR_FWEN                     RCC_APB2ENR_FWEN_Msk
#define RCC_APB2ENR_TIM1EN_Pos               (11U)
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos) /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos               (12U)
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos) /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos             (14U)
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_TIM15EN_Pos              (16U)
#define RCC_APB2ENR_TIM15EN_Msk              (0x1UL << RCC_APB2ENR_TIM15EN_Pos) /*!< 0x00010000 */
#define RCC_APB2ENR_TIM15EN                  RCC_APB2ENR_TIM15EN_Msk
#define RCC_APB2ENR_TIM16EN_Pos              (17U)
#define RCC_APB2ENR_TIM16EN_Msk              (0x1UL << RCC_APB2ENR_TIM16EN_Pos) /*!< 0x00020000 */
#define RCC_APB2ENR_TIM16EN                  RCC_APB2ENR_TIM16EN_Msk
#define RCC_APB2ENR_SAI1EN_Pos               (21U)
#define RCC_APB2ENR_SAI1EN_Msk               (0x1UL << RCC_APB2ENR_SAI1EN_Pos) /*!< 0x00200000 */
#define RCC_APB2ENR_SAI1EN                   RCC_APB2ENR_SAI1EN_Msk

/********************  Bit definition for RCC_AHB1SMENR register  ***************/
#define RCC_AHB1SMENR_DMA1SMEN_Pos           (0U)
#define RCC_AHB1SMENR_DMA1SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA1SMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1SMENR_DMA1SMEN               RCC_AHB1SMENR_DMA1SMEN_Msk
#define RCC_AHB1SMENR_DMA2SMEN_Pos           (1U)
#define RCC_AHB1SMENR_DMA2SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA2SMEN_Pos) /*!< 0x00000002 */
#define RCC_AHB1SMENR_DMA2SMEN               RCC_AHB1SMENR_DMA2SMEN_Msk
#define RCC_AHB1SMENR_FLASHSMEN_Pos          (8U)
#define RCC_AHB1SMENR_FLASHSMEN_Msk          (0x1UL << RCC_AHB1SMENR_FLASHSMEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1SMENR_FLASHSMEN              RCC_AHB1SMENR_FLASHSMEN_Msk
#define RCC_AHB1SMENR_SRAM1SMEN_Pos          (9U)
#define RCC_AHB1SMENR_SRAM1SMEN_Msk          (0x1UL << RCC_AHB1SMENR_SRAM1SMEN_Pos) /*!< 0x00000200 */
#define RCC_AHB1SMENR_SRAM1SMEN              RCC_AHB1SMENR_SRAM1SMEN_Msk
#define RCC_AHB1SMENR_CRCSMEN_Pos            (12U)
#define RCC_AHB1SMENR_CRCSMEN_Msk            (0x1UL << RCC_AHB1SMENR_CRCSMEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1SMENR_CRCSMEN                RCC_AHB1SMENR_CRCSMEN_Msk
#define RCC_AHB1SMENR_TSCSMEN_Pos            (16U)
#define RCC_AHB1SMENR_TSCSMEN_Msk            (0x1UL << RCC_AHB1SMENR_TSCSMEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1SMENR_TSCSMEN                RCC_AHB1SMENR_TSCSMEN_Msk

/********************  Bit definition for RCC_AHB2SMENR register  *************/
#define RCC_AHB2SMENR_GPIOASMEN_Pos          (0U)
#define RCC_AHB2SMENR_GPIOASMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOASMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2SMENR_GPIOASMEN              RCC_AHB2SMENR_GPIOASMEN_Msk
#define RCC_AHB2SMENR_GPIOBSMEN_Pos          (1U)
#define RCC_AHB2SMENR_GPIOBSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOBSMEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2SMENR_GPIOBSMEN              RCC_AHB2SMENR_GPIOBSMEN_Msk
#define RCC_AHB2SMENR_GPIOCSMEN_Pos          (2U)
#define RCC_AHB2SMENR_GPIOCSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOCSMEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2SMENR_GPIOCSMEN              RCC_AHB2SMENR_GPIOCSMEN_Msk
#define RCC_AHB2SMENR_GPIOHSMEN_Pos          (7U)
#define RCC_AHB2SMENR_GPIOHSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOHSMEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2SMENR_GPIOHSMEN              RCC_AHB2SMENR_GPIOHSMEN_Msk
#define RCC_AHB2SMENR_SRAM2SMEN_Pos          (9U)
#define RCC_AHB2SMENR_SRAM2SMEN_Msk          (0x1UL << RCC_AHB2SMENR_SRAM2SMEN_Pos) /*!< 0x00000200 */
#define RCC_AHB2SMENR_SRAM2SMEN              RCC_AHB2SMENR_SRAM2SMEN_Msk
#define RCC_AHB2SMENR_ADCSMEN_Pos            (13U)
#define RCC_AHB2SMENR_ADCSMEN_Msk            (0x1UL << RCC_AHB2SMENR_ADCSMEN_Pos) /*!< 0x00002000 */
#define RCC_AHB2SMENR_ADCSMEN                RCC_AHB2SMENR_ADCSMEN_Msk
#define RCC_AHB2SMENR_RNGSMEN_Pos            (18U)
#define RCC_AHB2SMENR_RNGSMEN_Msk            (0x1UL << RCC_AHB2SMENR_RNGSMEN_Pos) /*!< 0x00040000 */
#define RCC_AHB2SMENR_RNGSMEN                RCC_AHB2SMENR_RNGSMEN_Msk

/********************  Bit definition for RCC_AHB3SMENR register  *************/
#define RCC_AHB3SMENR_QSPISMEN_Pos           (8U)
#define RCC_AHB3SMENR_QSPISMEN_Msk           (0x1UL << RCC_AHB3SMENR_QSPISMEN_Pos) /*!< 0x00000100 */
#define RCC_AHB3SMENR_QSPISMEN               RCC_AHB3SMENR_QSPISMEN_Msk

/********************  Bit definition for RCC_APB1SMENR1 register  *************/
#define RCC_APB1SMENR1_TIM2SMEN_Pos          (0U)
#define RCC_APB1SMENR1_TIM2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM2SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR1_TIM2SMEN              RCC_APB1SMENR1_TIM2SMEN_Msk
#define RCC_APB1SMENR1_TIM6SMEN_Pos          (4U)
#define RCC_APB1SMENR1_TIM6SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM6SMEN_Pos) /*!< 0x00000010 */
#define RCC_APB1SMENR1_TIM6SMEN              RCC_APB1SMENR1_TIM6SMEN_Msk
#define RCC_APB1SMENR1_TIM7SMEN_Pos          (5U)
#define RCC_APB1SMENR1_TIM7SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM7SMEN_Pos) /*!< 0x00000020 */
#define RCC_APB1SMENR1_TIM7SMEN              RCC_APB1SMENR1_TIM7SMEN_Msk
#define RCC_APB1SMENR1_RTCAPBSMEN_Pos        (10U)
#define RCC_APB1SMENR1_RTCAPBSMEN_Msk        (0x1UL << RCC_APB1SMENR1_RTCAPBSMEN_Pos) /*!< 0x00000400 */
#define RCC_APB1SMENR1_RTCAPBSMEN            RCC_APB1SMENR1_RTCAPBSMEN_Msk
#define RCC_APB1SMENR1_WWDGSMEN_Pos          (11U)
#define RCC_APB1SMENR1_WWDGSMEN_Msk          (0x1UL << RCC_APB1SMENR1_WWDGSMEN_Pos) /*!< 0x00000800 */
#define RCC_APB1SMENR1_WWDGSMEN              RCC_APB1SMENR1_WWDGSMEN_Msk
#define RCC_APB1SMENR1_SPI3SMEN_Pos          (15U)
#define RCC_APB1SMENR1_SPI3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_SPI3SMEN_Pos) /*!< 0x00008000 */
#define RCC_APB1SMENR1_SPI3SMEN              RCC_APB1SMENR1_SPI3SMEN_Msk
#define RCC_APB1SMENR1_USART2SMEN_Pos        (17U)
#define RCC_APB1SMENR1_USART2SMEN_Msk        (0x1UL << RCC_APB1SMENR1_USART2SMEN_Pos) /*!< 0x00020000 */
#define RCC_APB1SMENR1_USART2SMEN            RCC_APB1SMENR1_USART2SMEN_Msk
#define RCC_APB1SMENR1_I2C1SMEN_Pos          (21U)
#define RCC_APB1SMENR1_I2C1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C1SMEN_Pos) /*!< 0x00200000 */
#define RCC_APB1SMENR1_I2C1SMEN              RCC_APB1SMENR1_I2C1SMEN_Msk
#define RCC_APB1SMENR1_I2C3SMEN_Pos          (23U)
#define RCC_APB1SMENR1_I2C3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C3SMEN_Pos) /*!< 0x00800000 */
#define RCC_APB1SMENR1_I2C3SMEN              RCC_APB1SMENR1_I2C3SMEN_Msk
#define RCC_APB1SMENR1_CRSSMEN_Pos           (24U)
#define RCC_APB1SMENR1_CRSSMEN_Msk           (0x1UL << RCC_APB1SMENR1_CRSSMEN_Pos) /*!< 0x01000000 */
#define RCC_APB1SMENR1_CRSSMEN               RCC_APB1SMENR1_CRSSMEN_Msk
#define RCC_APB1SMENR1_CAN1SMEN_Pos          (25U)
#define RCC_APB1SMENR1_CAN1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_CAN1SMEN_Pos) /*!< 0x02000000 */
#define RCC_APB1SMENR1_CAN1SMEN              RCC_APB1SMENR1_CAN1SMEN_Msk
#define RCC_APB1SMENR1_USBFSSMEN_Pos         (26U)
#define RCC_APB1SMENR1_USBFSSMEN_Msk         (0x1UL << RCC_APB1SMENR1_USBFSSMEN_Pos) /*!< 0x04000000 */
#define RCC_APB1SMENR1_USBFSSMEN             RCC_APB1SMENR1_USBFSSMEN_Msk
#define RCC_APB1SMENR1_PWRSMEN_Pos           (28U)
#define RCC_APB1SMENR1_PWRSMEN_Msk           (0x1UL << RCC_APB1SMENR1_PWRSMEN_Pos) /*!< 0x10000000 */
#define RCC_APB1SMENR1_PWRSMEN               RCC_APB1SMENR1_PWRSMEN_Msk
#define RCC_APB1SMENR1_DAC1SMEN_Pos          (29U)
#define RCC_APB1SMENR1_DAC1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_DAC1SMEN_Pos) /*!< 0x20000000 */
#define RCC_APB1SMENR1_DAC1SMEN              RCC_APB1SMENR1_DAC1SMEN_Msk
#define RCC_APB1SMENR1_OPAMPSMEN_Pos         (30U)
#define RCC_APB1SMENR1_OPAMPSMEN_Msk         (0x1UL << RCC_APB1SMENR1_OPAMPSMEN_Pos) /*!< 0x40000000 */
#define RCC_APB1SMENR1_OPAMPSMEN             RCC_APB1SMENR1_OPAMPSMEN_Msk
#define RCC_APB1SMENR1_LPTIM1SMEN_Pos        (31U)
#define RCC_APB1SMENR1_LPTIM1SMEN_Msk        (0x1UL << RCC_APB1SMENR1_LPTIM1SMEN_Pos) /*!< 0x80000000 */
#define RCC_APB1SMENR1_LPTIM1SMEN            RCC_APB1SMENR1_LPTIM1SMEN_Msk

/********************  Bit definition for RCC_APB1SMENR2 register  *************/
#define RCC_APB1SMENR2_LPUART1SMEN_Pos       (0U)
#define RCC_APB1SMENR2_LPUART1SMEN_Msk       (0x1UL << RCC_APB1SMENR2_LPUART1SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR2_LPUART1SMEN           RCC_APB1SMENR2_LPUART1SMEN_Msk
#define RCC_APB1SMENR2_SWPMI1SMEN_Pos        (2U)
#define RCC_APB1SMENR2_SWPMI1SMEN_Msk        (0x1UL << RCC_APB1SMENR2_SWPMI1SMEN_Pos) /*!< 0x00000004 */
#define RCC_APB1SMENR2_SWPMI1SMEN            RCC_APB1SMENR2_SWPMI1SMEN_Msk
#define RCC_APB1SMENR2_LPTIM2SMEN_Pos        (5U)
#define RCC_APB1SMENR2_LPTIM2SMEN_Msk        (0x1UL << RCC_APB1SMENR2_LPTIM2SMEN_Pos) /*!< 0x00000020 */
#define RCC_APB1SMENR2_LPTIM2SMEN            RCC_APB1SMENR2_LPTIM2SMEN_Msk

/********************  Bit definition for RCC_APB2SMENR register  *************/
#define RCC_APB2SMENR_SYSCFGSMEN_Pos         (0U)
#define RCC_APB2SMENR_SYSCFGSMEN_Msk         (0x1UL << RCC_APB2SMENR_SYSCFGSMEN_Pos) /*!< 0x00000001 */
#define RCC_APB2SMENR_SYSCFGSMEN             RCC_APB2SMENR_SYSCFGSMEN_Msk
#define RCC_APB2SMENR_TIM1SMEN_Pos           (11U)
#define RCC_APB2SMENR_TIM1SMEN_Msk           (0x1UL << RCC_APB2SMENR_TIM1SMEN_Pos) /*!< 0x00000800 */
#define RCC_APB2SMENR_TIM1SMEN               RCC_APB2SMENR_TIM1SMEN_Msk
#define RCC_APB2SMENR_SPI1SMEN_Pos           (12U)
#define RCC_APB2SMENR_SPI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SPI1SMEN_Pos) /*!< 0x00001000 */
#define RCC_APB2SMENR_SPI1SMEN               RCC_APB2SMENR_SPI1SMEN_Msk
#define RCC_APB2SMENR_USART1SMEN_Pos         (14U)
#define RCC_APB2SMENR_USART1SMEN_Msk         (0x1UL << RCC_APB2SMENR_USART1SMEN_Pos) /*!< 0x00004000 */
#define RCC_APB2SMENR_USART1SMEN             RCC_APB2SMENR_USART1SMEN_Msk
#define RCC_APB2SMENR_TIM15SMEN_Pos          (16U)
#define RCC_APB2SMENR_TIM15SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM15SMEN_Pos) /*!< 0x00010000 */
#define RCC_APB2SMENR_TIM15SMEN              RCC_APB2SMENR_TIM15SMEN_Msk
#define RCC_APB2SMENR_TIM16SMEN_Pos          (17U)
#define RCC_APB2SMENR_TIM16SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM16SMEN_Pos) /*!< 0x00020000 */
#define RCC_APB2SMENR_TIM16SMEN              RCC_APB2SMENR_TIM16SMEN_Msk
#define RCC_APB2SMENR_SAI1SMEN_Pos           (21U)
#define RCC_APB2SMENR_SAI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SAI1SMEN_Pos) /*!< 0x00200000 */
#define RCC_APB2SMENR_SAI1SMEN               RCC_APB2SMENR_SAI1SMEN_Msk

/********************  Bit definition for RCC_CCIPR register  ******************/
#define RCC_CCIPR_USART1SEL_Pos              (0U)
#define RCC_CCIPR_USART1SEL_Msk              (0x3UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000003 */
#define RCC_CCIPR_USART1SEL                  RCC_CCIPR_USART1SEL_Msk
#define RCC_CCIPR_USART1SEL_0                (0x1UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000001 */
#define RCC_CCIPR_USART1SEL_1                (0x2UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000002 */

#define RCC_CCIPR_USART2SEL_Pos              (2U)
#define RCC_CCIPR_USART2SEL_Msk              (0x3UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x0000000C */
#define RCC_CCIPR_USART2SEL                  RCC_CCIPR_USART2SEL_Msk
#define RCC_CCIPR_USART2SEL_0                (0x1UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x00000004 */
#define RCC_CCIPR_USART2SEL_1                (0x2UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x00000008 */

#define RCC_CCIPR_LPUART1SEL_Pos             (10U)
#define RCC_CCIPR_LPUART1SEL_Msk             (0x3UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000C00 */
#define RCC_CCIPR_LPUART1SEL                 RCC_CCIPR_LPUART1SEL_Msk
#define RCC_CCIPR_LPUART1SEL_0               (0x1UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000400 */
#define RCC_CCIPR_LPUART1SEL_1               (0x2UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000800 */

#define RCC_CCIPR_I2C1SEL_Pos                (12U)
#define RCC_CCIPR_I2C1SEL_Msk                (0x3UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00003000 */
#define RCC_CCIPR_I2C1SEL                    RCC_CCIPR_I2C1SEL_Msk
#define RCC_CCIPR_I2C1SEL_0                  (0x1UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00001000 */
#define RCC_CCIPR_I2C1SEL_1                  (0x2UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00002000 */

#define RCC_CCIPR_I2C3SEL_Pos                (16U)
#define RCC_CCIPR_I2C3SEL_Msk                (0x3UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00030000 */
#define RCC_CCIPR_I2C3SEL                    RCC_CCIPR_I2C3SEL_Msk
#define RCC_CCIPR_I2C3SEL_0                  (0x1UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00010000 */
#define RCC_CCIPR_I2C3SEL_1                  (0x2UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00020000 */

#define RCC_CCIPR_LPTIM1SEL_Pos              (18U)
#define RCC_CCIPR_LPTIM1SEL_Msk              (0x3UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM1SEL                  RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0                (0x1UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x00040000 */
#define RCC_CCIPR_LPTIM1SEL_1                (0x2UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x00080000 */

#define RCC_CCIPR_LPTIM2SEL_Pos              (20U)
#define RCC_CCIPR_LPTIM2SEL_Msk              (0x3UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00300000 */
#define RCC_CCIPR_LPTIM2SEL                  RCC_CCIPR_LPTIM2SEL_Msk
#define RCC_CCIPR_LPTIM2SEL_0                (0x1UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00100000 */
#define RCC_CCIPR_LPTIM2SEL_1                (0x2UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00200000 */

#define RCC_CCIPR_SAI1SEL_Pos                (22U)
#define RCC_CCIPR_SAI1SEL_Msk                (0x3UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00C00000 */
#define RCC_CCIPR_SAI1SEL                    RCC_CCIPR_SAI1SEL_Msk
#define RCC_CCIPR_SAI1SEL_0                  (0x1UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00400000 */
#define RCC_CCIPR_SAI1SEL_1                  (0x2UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00800000 */

#define RCC_CCIPR_CLK48SEL_Pos               (26U)
#define RCC_CCIPR_CLK48SEL_Msk               (0x3UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x0C000000 */
#define RCC_CCIPR_CLK48SEL                   RCC_CCIPR_CLK48SEL_Msk
#define RCC_CCIPR_CLK48SEL_0                 (0x1UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x04000000 */
#define RCC_CCIPR_CLK48SEL_1                 (0x2UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x08000000 */

#define RCC_CCIPR_ADCSEL_Pos                 (28U)
#define RCC_CCIPR_ADCSEL_Msk                 (0x3UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x30000000 */
#define RCC_CCIPR_ADCSEL                     RCC_CCIPR_ADCSEL_Msk
#define RCC_CCIPR_ADCSEL_0                   (0x1UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x10000000 */
#define RCC_CCIPR_ADCSEL_1                   (0x2UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x20000000 */

#define RCC_CCIPR_SWPMI1SEL_Pos              (30U)
#define RCC_CCIPR_SWPMI1SEL_Msk              (0x1UL << RCC_CCIPR_SWPMI1SEL_Pos) /*!< 0x40000000 */
#define RCC_CCIPR_SWPMI1SEL                  RCC_CCIPR_SWPMI1SEL_Msk

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                   (0U)
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)     /*!< 0x00000001 */
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                  (1U)
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)    /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                  (2U)
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)    /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEDRV_Pos                  (3U)
#define RCC_BDCR_LSEDRV_Msk                  (0x3UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                      RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                    (0x1UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                    (0x2UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000010 */

#define RCC_BDCR_LSECSSON_Pos                (5U)
#define RCC_BDCR_LSECSSON_Msk                (0x1UL << RCC_BDCR_LSECSSON_Pos)  /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON                    RCC_BDCR_LSECSSON_Msk
#define RCC_BDCR_LSECSSD_Pos                 (6U)
#define RCC_BDCR_LSECSSD_Msk                 (0x1UL << RCC_BDCR_LSECSSD_Pos)   /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                     RCC_BDCR_LSECSSD_Msk

#define RCC_BDCR_RTCSEL_Pos                  (8U)
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                   (15U)
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)     /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                   (16U)
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)     /*!< 0x00010000 */
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk
#define RCC_BDCR_LSCOEN_Pos                  (24U)
#define RCC_BDCR_LSCOEN_Msk                  (0x1UL << RCC_BDCR_LSCOEN_Pos)    /*!< 0x01000000 */
#define RCC_BDCR_LSCOEN                      RCC_BDCR_LSCOEN_Msk
#define RCC_BDCR_LSCOSEL_Pos                 (25U)
#define RCC_BDCR_LSCOSEL_Msk                 (0x1UL << RCC_BDCR_LSCOSEL_Pos)   /*!< 0x02000000 */
#define RCC_BDCR_LSCOSEL                     RCC_BDCR_LSCOSEL_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                    (0U)
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)      /*!< 0x00000001 */
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                   (1U)
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)     /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk

#define RCC_CSR_MSISRANGE_Pos                (8U)
#define RCC_CSR_MSISRANGE_Msk                (0xFUL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000F00 */
#define RCC_CSR_MSISRANGE                    RCC_CSR_MSISRANGE_Msk
#define RCC_CSR_MSISRANGE_1                  (0x4UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000400 */
#define RCC_CSR_MSISRANGE_2                  (0x5UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000500 */
#define RCC_CSR_MSISRANGE_4                  (0x6UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000600 */
#define RCC_CSR_MSISRANGE_8                  (0x7UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000700 */

#define RCC_CSR_RMVF_Pos                     (23U)
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)       /*!< 0x00800000 */
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk
#define RCC_CSR_FWRSTF_Pos                   (24U)
#define RCC_CSR_FWRSTF_Msk                   (0x1UL << RCC_CSR_FWRSTF_Pos)     /*!< 0x01000000 */
#define RCC_CSR_FWRSTF                       RCC_CSR_FWRSTF_Msk
#define RCC_CSR_OBLRSTF_Pos                  (25U)
#define RCC_CSR_OBLRSTF_Msk                  (0x1UL << RCC_CSR_OBLRSTF_Pos)    /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                      RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                  (26U)
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)    /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk
#define RCC_CSR_BORRSTF_Pos                  (27U)
#define RCC_CSR_BORRSTF_Msk                  (0x1UL << RCC_CSR_BORRSTF_Pos)    /*!< 0x08000000 */
#define RCC_CSR_BORRSTF                      RCC_CSR_BORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                  (28U)
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)    /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                 (29U)
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)   /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                 (30U)
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)   /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                 (31U)
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)   /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk

/********************  Bit definition for RCC_CRRCR register  *****************/
#define RCC_CRRCR_HSI48ON_Pos                (0U)
#define RCC_CRRCR_HSI48ON_Msk                (0x1UL << RCC_CRRCR_HSI48ON_Pos)  /*!< 0x00000001 */
#define RCC_CRRCR_HSI48ON                    RCC_CRRCR_HSI48ON_Msk
#define RCC_CRRCR_HSI48RDY_Pos               (1U)
#define RCC_CRRCR_HSI48RDY_Msk               (0x1UL << RCC_CRRCR_HSI48RDY_Pos) /*!< 0x00000002 */
#define RCC_CRRCR_HSI48RDY                   RCC_CRRCR_HSI48RDY_Msk

/*!< HSI48CAL configuration */
#define RCC_CRRCR_HSI48CAL_Pos               (7U)
#define RCC_CRRCR_HSI48CAL_Msk               (0x1FFUL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x0000FF80 */
#define RCC_CRRCR_HSI48CAL                   RCC_CRRCR_HSI48CAL_Msk             /*!< HSI48CAL[8:0] bits */
#define RCC_CRRCR_HSI48CAL_0                 (0x001UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00000080 */
#define RCC_CRRCR_HSI48CAL_1                 (0x002UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00000100 */
#define RCC_CRRCR_HSI48CAL_2                 (0x004UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00000200 */
#define RCC_CRRCR_HSI48CAL_3                 (0x008UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00000400 */
#define RCC_CRRCR_HSI48CAL_4                 (0x010UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00000800 */
#define RCC_CRRCR_HSI48CAL_5                 (0x020UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00001000 */
#define RCC_CRRCR_HSI48CAL_6                 (0x040UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00002000 */
#define RCC_CRRCR_HSI48CAL_7                 (0x080UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00004000 */
#define RCC_CRRCR_HSI48CAL_8                 (0x100UL << RCC_CRRCR_HSI48CAL_Pos) /*!< 0x00008000 */



#define RCC_PLLR_ENABLE()       (RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN)

/****************************AHB1 BUS Clocks****************************/
#define RCC_DMA1_CLK_ENABLE()	  (RCC->AHB1ENR |= (1 << 0))
#define RCC_DMA2_CLK_ENABLE()	  (RCC->AHB1ENR |= (1 << 1))
#define RCC_FLASH_CLK_ENABLE()	(RCC->AHB1ENR |= (1 << 8))
#define RCC_CRC_CLK_ENABLE()	  (RCC->AHB1ENR |= (1 << 12))
#define RCC_TSC_CLK_ENABLE()	  (RCC->AHB1ENR |= (1 << 16))

/****************************AHB2 BUS Clocks****************************/
#define RCC_GPIOA_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 0))
#define RCC_GPIOB_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 1))
#define RCC_GPIOC_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 2))
#define RCC_GPIOD_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 3))
#define RCC_GPIOE_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 4))
#define RCC_GPIOH_CLK_ENABLE()	(RCC->AHB2ENR |= (1 << 5))
#define RCC_ADC_CLK_ENABLE()	  (RCC->AHB2ENR |= (1 << 13))
#define RCC_RNG_CLK_ENABLE()	  (RCC->AHB2ENR |= (1 << 18))

/****************************APB1 BUS Clocks****************************/
#define RCC_I2C1_CLK_ENABLE()	  (RCC->APB1ENR1 |= (1 << 21))
#define RCC_I2C3_CLK_ENABLE()	  (RCC->APB1ENR1 |= (1 << 23))
#define RCC_USART2_CLK_ENABLE() (RCC->APB1ENR1 |= (1 << 17))
#define RCC_TIM2_CLK_ENABLE()	  (RCC->APB1ENR1 |= (1 << 0))


/****************************APB2 BUS Clocks****************************/
#define RCC_TIM1_CLK_ENABLE()	  (RCC->APB2ENR |= (1 << 11))
#define RCC_SPI1_CLK_ENABLE()	  (RCC->APB2ENR |= (1 << 12))
#define RCC_USART1_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 14))
#define RCC_TIM15_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 16))
#define RCC_TIM16_CLK_ENABLE()	(RCC->APB2ENR |= (1 << 17))
//#define RCC_HSI16_CLK_ENABLE()  (RCC->CR |= RCC_CR_HSION; while(RCC->CR & RCC_CR_HSIRDY);)

#define RCC_GET_SYSCLK_SRC() ((RCC->CFGR & (0b11 << RCC_CFGR_SWS_Pos)) >> RCC_CFGR_SWS_Pos)

//typedef enum {
//  MCO_SEL_NO_CLOCK  = 0b0000,
//  MCO_SEL_SYSCLK    = 0b0001,
//  MCO_SEL_MSI       = 0b0010,
//  MCO_SEL_HSI16     = 0b0011,
//  MCO_SEL_HSE       = 0b0100,
//  MCO_SEL_PLL       = 0b0101,
//  MCO_SEL_LSI       = 0b0110,
//  MCO_SEL_LSE       = 0b0111,
//  MCO_SEL_HSI48     = 0b1000
//} mco_clocks_t;
//
//
//typedef enum {
//  HCLK_DIV_1    = 0b000,
//  HCLK_DIV_2    = 0b100,
//  HCLK_DIV_4    = 0b101,
//  HCLK_DIV_8    = 0b110,
//  HCLK_DIV_16   = 0b111
//} ppre_div_t;
//
//typedef enum {
//  SW_MSI      = 0b00,
//  SW_HSI16    = 0b01,
//  SW_HSE      = 0b10,
//  SW_PLL      = 0b11
//} system_clock_t;

typedef enum {
  MSI_100KHZ    = RCC_CR_MSIRANGE_0,
  MSI_200KHZ    = RCC_CR_MSIRANGE_1,
  MSI_400KHZ    = RCC_CR_MSIRANGE_2,
  MSI_800KHZ    = RCC_CR_MSIRANGE_3,
  MSI_1MHZ      = RCC_CR_MSIRANGE_4,
  MSI_2MHZ      = RCC_CR_MSIRANGE_5,
  MSI_4MHZ      = RCC_CR_MSIRANGE_6,
  MSI_8MHZ      = RCC_CR_MSIRANGE_7,
  MSI_16MHZ     = RCC_CR_MSIRANGE_8,
  MSI_24MHZ     = RCC_CR_MSIRANGE_9,
  MSI_32MHZ     = RCC_CR_MSIRANGE_10,
  MSI_48MHZ     = RCC_CR_MSIRANGE_11
} msi_range_t;

typedef enum {
  PCLK = 0b00,
  SYSCLK = 0b01,
  HSI16 = 0b10,
  LSE = 0b11
} preipheral_clocks_t;

uint8_t RCC_SET_SYSCLK(uint32_t sysClock);
uint8_t RCC_SET_MSI_RANGE(msi_range_t range);
void RCC_I2C3_CLK_SEL(preipheral_clocks_t clock);
void RCC_I2C1_CLK_SEL(preipheral_clocks_t clock);
void RCC_HSI16_CLK_ENABLE();
void SystemInit();

#endif