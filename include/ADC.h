#include <stm32l432kc.h> 

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32L4 serie)
 */
/* Note: No specific macro feature on this device */

/********************  Bit definition for ADC_ISR register  *******************/
#define ADC_ISR_ADRDY_Pos              (0U)
#define ADC_ISR_ADRDY_Msk              (0x1UL << ADC_ISR_ADRDY_Pos)            /*!< 0x00000001 */
#define ADC_ISR_ADRDY                  ADC_ISR_ADRDY_Msk                       /*!< ADC ready flag */
#define ADC_ISR_EOSMP_Pos              (1U)
#define ADC_ISR_EOSMP_Msk              (0x1UL << ADC_ISR_EOSMP_Pos)            /*!< 0x00000002 */
#define ADC_ISR_EOSMP                  ADC_ISR_EOSMP_Msk                       /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos                (2U)
#define ADC_ISR_EOC_Msk                (0x1UL << ADC_ISR_EOC_Pos)              /*!< 0x00000004 */
#define ADC_ISR_EOC                    ADC_ISR_EOC_Msk                         /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos                (3U)
#define ADC_ISR_EOS_Msk                (0x1UL << ADC_ISR_EOS_Pos)              /*!< 0x00000008 */
#define ADC_ISR_EOS                    ADC_ISR_EOS_Msk                         /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos                (4U)
#define ADC_ISR_OVR_Msk                (0x1UL << ADC_ISR_OVR_Pos)              /*!< 0x00000010 */
#define ADC_ISR_OVR                    ADC_ISR_OVR_Msk                         /*!< ADC group regular overrun flag */
#define ADC_ISR_JEOC_Pos               (5U)
#define ADC_ISR_JEOC_Msk               (0x1UL << ADC_ISR_JEOC_Pos)             /*!< 0x00000020 */
#define ADC_ISR_JEOC                   ADC_ISR_JEOC_Msk                        /*!< ADC group injected end of unitary conversion flag */
#define ADC_ISR_JEOS_Pos               (6U)
#define ADC_ISR_JEOS_Msk               (0x1UL << ADC_ISR_JEOS_Pos)             /*!< 0x00000040 */
#define ADC_ISR_JEOS                   ADC_ISR_JEOS_Msk                        /*!< ADC group injected end of sequence conversions flag */
#define ADC_ISR_AWD1_Pos               (7U)
#define ADC_ISR_AWD1_Msk               (0x1UL << ADC_ISR_AWD1_Pos)             /*!< 0x00000080 */
#define ADC_ISR_AWD1                   ADC_ISR_AWD1_Msk                        /*!< ADC analog watchdog 1 flag */
#define ADC_ISR_AWD2_Pos               (8U)
#define ADC_ISR_AWD2_Msk               (0x1UL << ADC_ISR_AWD2_Pos)             /*!< 0x00000100 */
#define ADC_ISR_AWD2                   ADC_ISR_AWD2_Msk                        /*!< ADC analog watchdog 2 flag */
#define ADC_ISR_AWD3_Pos               (9U)
#define ADC_ISR_AWD3_Msk               (0x1UL << ADC_ISR_AWD3_Pos)             /*!< 0x00000200 */
#define ADC_ISR_AWD3                   ADC_ISR_AWD3_Msk                        /*!< ADC analog watchdog 3 flag */
#define ADC_ISR_JQOVF_Pos              (10U)
#define ADC_ISR_JQOVF_Msk              (0x1UL << ADC_ISR_JQOVF_Pos)            /*!< 0x00000400 */
#define ADC_ISR_JQOVF                  ADC_ISR_JQOVF_Msk                       /*!< ADC group injected contexts queue overflow flag */

/********************  Bit definition for ADC_IER register  *******************/
#define ADC_IER_ADRDYIE_Pos            (0U)
#define ADC_IER_ADRDYIE_Msk            (0x1UL << ADC_IER_ADRDYIE_Pos)          /*!< 0x00000001 */
#define ADC_IER_ADRDYIE                ADC_IER_ADRDYIE_Msk                     /*!< ADC ready interrupt */
#define ADC_IER_EOSMPIE_Pos            (1U)
#define ADC_IER_EOSMPIE_Msk            (0x1UL << ADC_IER_EOSMPIE_Pos)          /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                ADC_IER_EOSMPIE_Msk                     /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos              (2U)
#define ADC_IER_EOCIE_Msk              (0x1UL << ADC_IER_EOCIE_Pos)            /*!< 0x00000004 */
#define ADC_IER_EOCIE                  ADC_IER_EOCIE_Msk                       /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos              (3U)
#define ADC_IER_EOSIE_Msk              (0x1UL << ADC_IER_EOSIE_Pos)            /*!< 0x00000008 */
#define ADC_IER_EOSIE                  ADC_IER_EOSIE_Msk                       /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos              (4U)
#define ADC_IER_OVRIE_Msk              (0x1UL << ADC_IER_OVRIE_Pos)            /*!< 0x00000010 */
#define ADC_IER_OVRIE                  ADC_IER_OVRIE_Msk                       /*!< ADC group regular overrun interrupt */
#define ADC_IER_JEOCIE_Pos             (5U)
#define ADC_IER_JEOCIE_Msk             (0x1UL << ADC_IER_JEOCIE_Pos)           /*!< 0x00000020 */
#define ADC_IER_JEOCIE                 ADC_IER_JEOCIE_Msk                      /*!< ADC group injected end of unitary conversion interrupt */
#define ADC_IER_JEOSIE_Pos             (6U)
#define ADC_IER_JEOSIE_Msk             (0x1UL << ADC_IER_JEOSIE_Pos)           /*!< 0x00000040 */
#define ADC_IER_JEOSIE                 ADC_IER_JEOSIE_Msk                      /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_IER_AWD1IE_Pos             (7U)
#define ADC_IER_AWD1IE_Msk             (0x1UL << ADC_IER_AWD1IE_Pos)           /*!< 0x00000080 */
#define ADC_IER_AWD1IE                 ADC_IER_AWD1IE_Msk                      /*!< ADC analog watchdog 1 interrupt */
#define ADC_IER_AWD2IE_Pos             (8U)
#define ADC_IER_AWD2IE_Msk             (0x1UL << ADC_IER_AWD2IE_Pos)           /*!< 0x00000100 */
#define ADC_IER_AWD2IE                 ADC_IER_AWD2IE_Msk                      /*!< ADC analog watchdog 2 interrupt */
#define ADC_IER_AWD3IE_Pos             (9U)
#define ADC_IER_AWD3IE_Msk             (0x1UL << ADC_IER_AWD3IE_Pos)           /*!< 0x00000200 */
#define ADC_IER_AWD3IE                 ADC_IER_AWD3IE_Msk                      /*!< ADC analog watchdog 3 interrupt */
#define ADC_IER_JQOVFIE_Pos            (10U)
#define ADC_IER_JQOVFIE_Msk            (0x1UL << ADC_IER_JQOVFIE_Pos)          /*!< 0x00000400 */
#define ADC_IER_JQOVFIE                ADC_IER_JQOVFIE_Msk                     /*!< ADC group injected contexts queue overflow interrupt */

/* Legacy defines */
#define ADC_IER_ADRDY           (ADC_IER_ADRDYIE)
#define ADC_IER_EOSMP           (ADC_IER_EOSMPIE)
#define ADC_IER_EOC             (ADC_IER_EOCIE)
#define ADC_IER_EOS             (ADC_IER_EOSIE)
#define ADC_IER_OVR             (ADC_IER_OVRIE)
#define ADC_IER_JEOC            (ADC_IER_JEOCIE)
#define ADC_IER_JEOS            (ADC_IER_JEOSIE)
#define ADC_IER_AWD1            (ADC_IER_AWD1IE)
#define ADC_IER_AWD2            (ADC_IER_AWD2IE)
#define ADC_IER_AWD3            (ADC_IER_AWD3IE)
#define ADC_IER_JQOVF           (ADC_IER_JQOVFIE)

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos                (0U)
#define ADC_CR_ADEN_Msk                (0x1UL << ADC_CR_ADEN_Pos)              /*!< 0x00000001 */
#define ADC_CR_ADEN                    ADC_CR_ADEN_Msk                         /*!< ADC enable */
#define ADC_CR_ADDIS_Pos               (1U)
#define ADC_CR_ADDIS_Msk               (0x1UL << ADC_CR_ADDIS_Pos)             /*!< 0x00000002 */
#define ADC_CR_ADDIS                   ADC_CR_ADDIS_Msk                        /*!< ADC disable */
#define ADC_CR_ADSTART_Pos             (2U)
#define ADC_CR_ADSTART_Msk             (0x1UL << ADC_CR_ADSTART_Pos)           /*!< 0x00000004 */
#define ADC_CR_ADSTART                 ADC_CR_ADSTART_Msk                      /*!< ADC group regular conversion start */
#define ADC_CR_JADSTART_Pos            (3U)
#define ADC_CR_JADSTART_Msk            (0x1UL << ADC_CR_JADSTART_Pos)          /*!< 0x00000008 */
#define ADC_CR_JADSTART                ADC_CR_JADSTART_Msk                     /*!< ADC group injected conversion start */
#define ADC_CR_ADSTP_Pos               (4U)
#define ADC_CR_ADSTP_Msk               (0x1UL << ADC_CR_ADSTP_Pos)             /*!< 0x00000010 */
#define ADC_CR_ADSTP                   ADC_CR_ADSTP_Msk                        /*!< ADC group regular conversion stop */
#define ADC_CR_JADSTP_Pos              (5U)
#define ADC_CR_JADSTP_Msk              (0x1UL << ADC_CR_JADSTP_Pos)            /*!< 0x00000020 */
#define ADC_CR_JADSTP                  ADC_CR_JADSTP_Msk                       /*!< ADC group injected conversion stop */
#define ADC_CR_ADVREGEN_Pos            (28U)
#define ADC_CR_ADVREGEN_Msk            (0x1UL << ADC_CR_ADVREGEN_Pos)          /*!< 0x10000000 */
#define ADC_CR_ADVREGEN                ADC_CR_ADVREGEN_Msk                     /*!< ADC voltage regulator enable */
#define ADC_CR_DEEPPWD_Pos             (29U)
#define ADC_CR_DEEPPWD_Msk             (0x1UL << ADC_CR_DEEPPWD_Pos)           /*!< 0x20000000 */
#define ADC_CR_DEEPPWD                 ADC_CR_DEEPPWD_Msk                      /*!< ADC deep power down enable */
#define ADC_CR_ADCALDIF_Pos            (30U)
#define ADC_CR_ADCALDIF_Msk            (0x1UL << ADC_CR_ADCALDIF_Pos)          /*!< 0x40000000 */
#define ADC_CR_ADCALDIF                ADC_CR_ADCALDIF_Msk                     /*!< ADC differential mode for calibration */
#define ADC_CR_ADCAL_Pos               (31U)
#define ADC_CR_ADCAL_Msk               (0x1UL << ADC_CR_ADCAL_Pos)             /*!< 0x80000000 */
#define ADC_CR_ADCAL                   ADC_CR_ADCAL_Msk                        /*!< ADC calibration */

/********************  Bit definition for ADC_CFGR register  ******************/
#define ADC_CFGR_DMAEN_Pos             (0U)
#define ADC_CFGR_DMAEN_Msk             (0x1UL << ADC_CFGR_DMAEN_Pos)           /*!< 0x00000001 */
#define ADC_CFGR_DMAEN                 ADC_CFGR_DMAEN_Msk                      /*!< ADC DMA transfer enable */
#define ADC_CFGR_DMACFG_Pos            (1U)
#define ADC_CFGR_DMACFG_Msk            (0x1UL << ADC_CFGR_DMACFG_Pos)          /*!< 0x00000002 */
#define ADC_CFGR_DMACFG                ADC_CFGR_DMACFG_Msk                     /*!< ADC DMA transfer configuration */

#define ADC_CFGR_RES_Pos               (3U)
#define ADC_CFGR_RES_Msk               (0x3UL << ADC_CFGR_RES_Pos)             /*!< 0x00000018 */
#define ADC_CFGR_RES                   ADC_CFGR_RES_Msk                        /*!< ADC data resolution */
#define ADC_CFGR_RES_0                 (0x1UL << ADC_CFGR_RES_Pos)             /*!< 0x00000008 */
#define ADC_CFGR_RES_1                 (0x2UL << ADC_CFGR_RES_Pos)             /*!< 0x00000010 */

#define ADC_CFGR_ALIGN_Pos             (5U)
#define ADC_CFGR_ALIGN_Msk             (0x1UL << ADC_CFGR_ALIGN_Pos)           /*!< 0x00000020 */
#define ADC_CFGR_ALIGN                 ADC_CFGR_ALIGN_Msk                      /*!< ADC data alignment */

#define ADC_CFGR_EXTSEL_Pos            (6U)
#define ADC_CFGR_EXTSEL_Msk            (0xFUL << ADC_CFGR_EXTSEL_Pos)          /*!< 0x000003C0 */
#define ADC_CFGR_EXTSEL                ADC_CFGR_EXTSEL_Msk                     /*!< ADC group regular external trigger source */
#define ADC_CFGR_EXTSEL_0              (0x1UL << ADC_CFGR_EXTSEL_Pos)          /*!< 0x00000040 */
#define ADC_CFGR_EXTSEL_1              (0x2UL << ADC_CFGR_EXTSEL_Pos)          /*!< 0x00000080 */
#define ADC_CFGR_EXTSEL_2              (0x4UL << ADC_CFGR_EXTSEL_Pos)          /*!< 0x00000100 */
#define ADC_CFGR_EXTSEL_3              (0x8UL << ADC_CFGR_EXTSEL_Pos)          /*!< 0x00000200 */

#define ADC_CFGR_EXTEN_Pos             (10U)
#define ADC_CFGR_EXTEN_Msk             (0x3UL << ADC_CFGR_EXTEN_Pos)           /*!< 0x00000C00 */
#define ADC_CFGR_EXTEN                 ADC_CFGR_EXTEN_Msk                      /*!< ADC group regular external trigger polarity */
#define ADC_CFGR_EXTEN_0               (0x1UL << ADC_CFGR_EXTEN_Pos)           /*!< 0x00000400 */
#define ADC_CFGR_EXTEN_1               (0x2UL << ADC_CFGR_EXTEN_Pos)           /*!< 0x00000800 */

#define ADC_CFGR_OVRMOD_Pos            (12U)
#define ADC_CFGR_OVRMOD_Msk            (0x1UL << ADC_CFGR_OVRMOD_Pos)          /*!< 0x00001000 */
#define ADC_CFGR_OVRMOD                ADC_CFGR_OVRMOD_Msk                     /*!< ADC group regular overrun configuration */
#define ADC_CFGR_CONT_Pos              (13U)
#define ADC_CFGR_CONT_Msk              (0x1UL << ADC_CFGR_CONT_Pos)            /*!< 0x00002000 */
#define ADC_CFGR_CONT                  ADC_CFGR_CONT_Msk                       /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR_AUTDLY_Pos            (14U)
#define ADC_CFGR_AUTDLY_Msk            (0x1UL << ADC_CFGR_AUTDLY_Pos)          /*!< 0x00004000 */
#define ADC_CFGR_AUTDLY                ADC_CFGR_AUTDLY_Msk                     /*!< ADC low power auto wait */

#define ADC_CFGR_DISCEN_Pos            (16U)
#define ADC_CFGR_DISCEN_Msk            (0x1UL << ADC_CFGR_DISCEN_Pos)          /*!< 0x00010000 */
#define ADC_CFGR_DISCEN                ADC_CFGR_DISCEN_Msk                     /*!< ADC group regular sequencer discontinuous mode */

#define ADC_CFGR_DISCNUM_Pos           (17U)
#define ADC_CFGR_DISCNUM_Msk           (0x7UL << ADC_CFGR_DISCNUM_Pos)         /*!< 0x000E0000 */
#define ADC_CFGR_DISCNUM               ADC_CFGR_DISCNUM_Msk                    /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CFGR_DISCNUM_0             (0x1UL << ADC_CFGR_DISCNUM_Pos)         /*!< 0x00020000 */
#define ADC_CFGR_DISCNUM_1             (0x2UL << ADC_CFGR_DISCNUM_Pos)         /*!< 0x00040000 */
#define ADC_CFGR_DISCNUM_2             (0x4UL << ADC_CFGR_DISCNUM_Pos)         /*!< 0x00080000 */

#define ADC_CFGR_JDISCEN_Pos           (20U)
#define ADC_CFGR_JDISCEN_Msk           (0x1UL << ADC_CFGR_JDISCEN_Pos)         /*!< 0x00100000 */
#define ADC_CFGR_JDISCEN               ADC_CFGR_JDISCEN_Msk                    /*!< ADC group injected sequencer discontinuous mode */
#define ADC_CFGR_JQM_Pos               (21U)
#define ADC_CFGR_JQM_Msk               (0x1UL << ADC_CFGR_JQM_Pos)             /*!< 0x00200000 */
#define ADC_CFGR_JQM                   ADC_CFGR_JQM_Msk                        /*!< ADC group injected contexts queue mode */
#define ADC_CFGR_AWD1SGL_Pos           (22U)
#define ADC_CFGR_AWD1SGL_Msk           (0x1UL << ADC_CFGR_AWD1SGL_Pos)         /*!< 0x00400000 */
#define ADC_CFGR_AWD1SGL               ADC_CFGR_AWD1SGL_Msk                    /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR_AWD1EN_Pos            (23U)
#define ADC_CFGR_AWD1EN_Msk            (0x1UL << ADC_CFGR_AWD1EN_Pos)          /*!< 0x00800000 */
#define ADC_CFGR_AWD1EN                ADC_CFGR_AWD1EN_Msk                     /*!< ADC analog watchdog 1 enable on scope ADC group regular */
#define ADC_CFGR_JAWD1EN_Pos           (24U)
#define ADC_CFGR_JAWD1EN_Msk           (0x1UL << ADC_CFGR_JAWD1EN_Pos)         /*!< 0x01000000 */
#define ADC_CFGR_JAWD1EN               ADC_CFGR_JAWD1EN_Msk                    /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CFGR_JAUTO_Pos             (25U)
#define ADC_CFGR_JAUTO_Msk             (0x1UL << ADC_CFGR_JAUTO_Pos)           /*!< 0x02000000 */
#define ADC_CFGR_JAUTO                 ADC_CFGR_JAUTO_Msk                      /*!< ADC group injected automatic trigger mode */

#define ADC_CFGR_AWD1CH_Pos            (26U)
#define ADC_CFGR_AWD1CH_Msk            (0x1FUL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x7C000000 */
#define ADC_CFGR_AWD1CH                ADC_CFGR_AWD1CH_Msk                     /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR_AWD1CH_0              (0x01UL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x04000000 */
#define ADC_CFGR_AWD1CH_1              (0x02UL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x08000000 */
#define ADC_CFGR_AWD1CH_2              (0x04UL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x10000000 */
#define ADC_CFGR_AWD1CH_3              (0x08UL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x20000000 */
#define ADC_CFGR_AWD1CH_4              (0x10UL << ADC_CFGR_AWD1CH_Pos)         /*!< 0x40000000 */

#define ADC_CFGR_JQDIS_Pos             (31U)
#define ADC_CFGR_JQDIS_Msk             (0x1UL << ADC_CFGR_JQDIS_Pos)           /*!< 0x80000000 */
#define ADC_CFGR_JQDIS                 ADC_CFGR_JQDIS_Msk                      /*!< ADC group injected contexts queue disable */

/********************  Bit definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_ROVSE_Pos            (0U)
#define ADC_CFGR2_ROVSE_Msk            (0x1UL << ADC_CFGR2_ROVSE_Pos)          /*!< 0x00000001 */
#define ADC_CFGR2_ROVSE                ADC_CFGR2_ROVSE_Msk                     /*!< ADC oversampler enable on scope ADC group regular */
#define ADC_CFGR2_JOVSE_Pos            (1U)
#define ADC_CFGR2_JOVSE_Msk            (0x1UL << ADC_CFGR2_JOVSE_Pos)          /*!< 0x00000002 */
#define ADC_CFGR2_JOVSE                ADC_CFGR2_JOVSE_Msk                     /*!< ADC oversampler enable on scope ADC group injected */

#define ADC_CFGR2_OVSR_Pos             (2U)
#define ADC_CFGR2_OVSR_Msk             (0x7UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x0000001C */
#define ADC_CFGR2_OVSR                 ADC_CFGR2_OVSR_Msk                      /*!< ADC oversampling ratio */
#define ADC_CFGR2_OVSR_0               (0x1UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000004 */
#define ADC_CFGR2_OVSR_1               (0x2UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000008 */
#define ADC_CFGR2_OVSR_2               (0x4UL << ADC_CFGR2_OVSR_Pos)           /*!< 0x00000010 */

#define ADC_CFGR2_OVSS_Pos             (5U)
#define ADC_CFGR2_OVSS_Msk             (0xFUL << ADC_CFGR2_OVSS_Pos)           /*!< 0x000001E0 */
#define ADC_CFGR2_OVSS                 ADC_CFGR2_OVSS_Msk                      /*!< ADC oversampling shift */
#define ADC_CFGR2_OVSS_0               (0x1UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000020 */
#define ADC_CFGR2_OVSS_1               (0x2UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000040 */
#define ADC_CFGR2_OVSS_2               (0x4UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000080 */
#define ADC_CFGR2_OVSS_3               (0x8UL << ADC_CFGR2_OVSS_Pos)           /*!< 0x00000100 */

#define ADC_CFGR2_TROVS_Pos            (9U)
#define ADC_CFGR2_TROVS_Msk            (0x1UL << ADC_CFGR2_TROVS_Pos)          /*!< 0x00000200 */
#define ADC_CFGR2_TROVS                ADC_CFGR2_TROVS_Msk                     /*!< ADC oversampling discontinuous mode (triggered mode) for ADC group regular */
#define ADC_CFGR2_ROVSM_Pos            (10U)
#define ADC_CFGR2_ROVSM_Msk            (0x1UL << ADC_CFGR2_ROVSM_Pos)          /*!< 0x00000400 */
#define ADC_CFGR2_ROVSM                ADC_CFGR2_ROVSM_Msk                     /*!< ADC oversampling mode managing interlaced conversions of ADC group regular and group injected */

/********************  Bit definition for ADC_SMPR1 register  *****************/
#define ADC_SMPR1_SMP0_Pos             (0U)
#define ADC_SMPR1_SMP0_Msk             (0x7UL << ADC_SMPR1_SMP0_Pos)           /*!< 0x00000007 */
#define ADC_SMPR1_SMP0                 ADC_SMPR1_SMP0_Msk                      /*!< ADC channel 0 sampling time selection  */
#define ADC_SMPR1_SMP0_0               (0x1UL << ADC_SMPR1_SMP0_Pos)           /*!< 0x00000001 */
#define ADC_SMPR1_SMP0_1               (0x2UL << ADC_SMPR1_SMP0_Pos)           /*!< 0x00000002 */
#define ADC_SMPR1_SMP0_2               (0x4UL << ADC_SMPR1_SMP0_Pos)           /*!< 0x00000004 */

#define ADC_SMPR1_SMP1_Pos             (3U)
#define ADC_SMPR1_SMP1_Msk             (0x7UL << ADC_SMPR1_SMP1_Pos)           /*!< 0x00000038 */
#define ADC_SMPR1_SMP1                 ADC_SMPR1_SMP1_Msk                      /*!< ADC channel 1 sampling time selection  */
#define ADC_SMPR1_SMP1_0               (0x1UL << ADC_SMPR1_SMP1_Pos)           /*!< 0x00000008 */
#define ADC_SMPR1_SMP1_1               (0x2UL << ADC_SMPR1_SMP1_Pos)           /*!< 0x00000010 */
#define ADC_SMPR1_SMP1_2               (0x4UL << ADC_SMPR1_SMP1_Pos)           /*!< 0x00000020 */

#define ADC_SMPR1_SMP2_Pos             (6U)
#define ADC_SMPR1_SMP2_Msk             (0x7UL << ADC_SMPR1_SMP2_Pos)           /*!< 0x000001C0 */
#define ADC_SMPR1_SMP2                 ADC_SMPR1_SMP2_Msk                      /*!< ADC channel 2 sampling time selection  */
#define ADC_SMPR1_SMP2_0               (0x1UL << ADC_SMPR1_SMP2_Pos)           /*!< 0x00000040 */
#define ADC_SMPR1_SMP2_1               (0x2UL << ADC_SMPR1_SMP2_Pos)           /*!< 0x00000080 */
#define ADC_SMPR1_SMP2_2               (0x4UL << ADC_SMPR1_SMP2_Pos)           /*!< 0x00000100 */

#define ADC_SMPR1_SMP3_Pos             (9U)
#define ADC_SMPR1_SMP3_Msk             (0x7UL << ADC_SMPR1_SMP3_Pos)           /*!< 0x00000E00 */
#define ADC_SMPR1_SMP3                 ADC_SMPR1_SMP3_Msk                      /*!< ADC channel 3 sampling time selection  */
#define ADC_SMPR1_SMP3_0               (0x1UL << ADC_SMPR1_SMP3_Pos)           /*!< 0x00000200 */
#define ADC_SMPR1_SMP3_1               (0x2UL << ADC_SMPR1_SMP3_Pos)           /*!< 0x00000400 */
#define ADC_SMPR1_SMP3_2               (0x4UL << ADC_SMPR1_SMP3_Pos)           /*!< 0x00000800 */

#define ADC_SMPR1_SMP4_Pos             (12U)
#define ADC_SMPR1_SMP4_Msk             (0x7UL << ADC_SMPR1_SMP4_Pos)           /*!< 0x00007000 */
#define ADC_SMPR1_SMP4                 ADC_SMPR1_SMP4_Msk                      /*!< ADC channel 4 sampling time selection  */
#define ADC_SMPR1_SMP4_0               (0x1UL << ADC_SMPR1_SMP4_Pos)           /*!< 0x00001000 */
#define ADC_SMPR1_SMP4_1               (0x2UL << ADC_SMPR1_SMP4_Pos)           /*!< 0x00002000 */
#define ADC_SMPR1_SMP4_2               (0x4UL << ADC_SMPR1_SMP4_Pos)           /*!< 0x00004000 */

#define ADC_SMPR1_SMP5_Pos             (15U)
#define ADC_SMPR1_SMP5_Msk             (0x7UL << ADC_SMPR1_SMP5_Pos)           /*!< 0x00038000 */
#define ADC_SMPR1_SMP5                 ADC_SMPR1_SMP5_Msk                      /*!< ADC channel 5 sampling time selection  */
#define ADC_SMPR1_SMP5_0               (0x1UL << ADC_SMPR1_SMP5_Pos)           /*!< 0x00008000 */
#define ADC_SMPR1_SMP5_1               (0x2UL << ADC_SMPR1_SMP5_Pos)           /*!< 0x00010000 */
#define ADC_SMPR1_SMP5_2               (0x4UL << ADC_SMPR1_SMP5_Pos)           /*!< 0x00020000 */

#define ADC_SMPR1_SMP6_Pos             (18U)
#define ADC_SMPR1_SMP6_Msk             (0x7UL << ADC_SMPR1_SMP6_Pos)           /*!< 0x001C0000 */
#define ADC_SMPR1_SMP6                 ADC_SMPR1_SMP6_Msk                      /*!< ADC channel 6 sampling time selection  */
#define ADC_SMPR1_SMP6_0               (0x1UL << ADC_SMPR1_SMP6_Pos)           /*!< 0x00040000 */
#define ADC_SMPR1_SMP6_1               (0x2UL << ADC_SMPR1_SMP6_Pos)           /*!< 0x00080000 */
#define ADC_SMPR1_SMP6_2               (0x4UL << ADC_SMPR1_SMP6_Pos)           /*!< 0x00100000 */

#define ADC_SMPR1_SMP7_Pos             (21U)
#define ADC_SMPR1_SMP7_Msk             (0x7UL << ADC_SMPR1_SMP7_Pos)           /*!< 0x00E00000 */
#define ADC_SMPR1_SMP7                 ADC_SMPR1_SMP7_Msk                      /*!< ADC channel 7 sampling time selection  */
#define ADC_SMPR1_SMP7_0               (0x1UL << ADC_SMPR1_SMP7_Pos)           /*!< 0x00200000 */
#define ADC_SMPR1_SMP7_1               (0x2UL << ADC_SMPR1_SMP7_Pos)           /*!< 0x00400000 */
#define ADC_SMPR1_SMP7_2               (0x4UL << ADC_SMPR1_SMP7_Pos)           /*!< 0x00800000 */

#define ADC_SMPR1_SMP8_Pos             (24U)
#define ADC_SMPR1_SMP8_Msk             (0x7UL << ADC_SMPR1_SMP8_Pos)           /*!< 0x07000000 */
#define ADC_SMPR1_SMP8                 ADC_SMPR1_SMP8_Msk                      /*!< ADC channel 8 sampling time selection  */
#define ADC_SMPR1_SMP8_0               (0x1UL << ADC_SMPR1_SMP8_Pos)           /*!< 0x01000000 */
#define ADC_SMPR1_SMP8_1               (0x2UL << ADC_SMPR1_SMP8_Pos)           /*!< 0x02000000 */
#define ADC_SMPR1_SMP8_2               (0x4UL << ADC_SMPR1_SMP8_Pos)           /*!< 0x04000000 */

#define ADC_SMPR1_SMP9_Pos             (27U)
#define ADC_SMPR1_SMP9_Msk             (0x7UL << ADC_SMPR1_SMP9_Pos)           /*!< 0x38000000 */
#define ADC_SMPR1_SMP9                 ADC_SMPR1_SMP9_Msk                      /*!< ADC channel 9 sampling time selection  */
#define ADC_SMPR1_SMP9_0               (0x1UL << ADC_SMPR1_SMP9_Pos)           /*!< 0x08000000 */
#define ADC_SMPR1_SMP9_1               (0x2UL << ADC_SMPR1_SMP9_Pos)           /*!< 0x10000000 */
#define ADC_SMPR1_SMP9_2               (0x4UL << ADC_SMPR1_SMP9_Pos)           /*!< 0x20000000 */

/********************  Bit definition for ADC_SMPR2 register  *****************/
#define ADC_SMPR2_SMP10_Pos            (0U)
#define ADC_SMPR2_SMP10_Msk            (0x7UL << ADC_SMPR2_SMP10_Pos)          /*!< 0x00000007 */
#define ADC_SMPR2_SMP10                ADC_SMPR2_SMP10_Msk                     /*!< ADC channel 10 sampling time selection  */
#define ADC_SMPR2_SMP10_0              (0x1UL << ADC_SMPR2_SMP10_Pos)          /*!< 0x00000001 */
#define ADC_SMPR2_SMP10_1              (0x2UL << ADC_SMPR2_SMP10_Pos)          /*!< 0x00000002 */
#define ADC_SMPR2_SMP10_2              (0x4UL << ADC_SMPR2_SMP10_Pos)          /*!< 0x00000004 */

#define ADC_SMPR2_SMP11_Pos            (3U)
#define ADC_SMPR2_SMP11_Msk            (0x7UL << ADC_SMPR2_SMP11_Pos)          /*!< 0x00000038 */
#define ADC_SMPR2_SMP11                ADC_SMPR2_SMP11_Msk                     /*!< ADC channel 11 sampling time selection  */
#define ADC_SMPR2_SMP11_0              (0x1UL << ADC_SMPR2_SMP11_Pos)          /*!< 0x00000008 */
#define ADC_SMPR2_SMP11_1              (0x2UL << ADC_SMPR2_SMP11_Pos)          /*!< 0x00000010 */
#define ADC_SMPR2_SMP11_2              (0x4UL << ADC_SMPR2_SMP11_Pos)          /*!< 0x00000020 */

#define ADC_SMPR2_SMP12_Pos            (6U)
#define ADC_SMPR2_SMP12_Msk            (0x7UL << ADC_SMPR2_SMP12_Pos)          /*!< 0x000001C0 */
#define ADC_SMPR2_SMP12                ADC_SMPR2_SMP12_Msk                     /*!< ADC channel 12 sampling time selection  */
#define ADC_SMPR2_SMP12_0              (0x1UL << ADC_SMPR2_SMP12_Pos)          /*!< 0x00000040 */
#define ADC_SMPR2_SMP12_1              (0x2UL << ADC_SMPR2_SMP12_Pos)          /*!< 0x00000080 */
#define ADC_SMPR2_SMP12_2              (0x4UL << ADC_SMPR2_SMP12_Pos)          /*!< 0x00000100 */

#define ADC_SMPR2_SMP13_Pos            (9U)
#define ADC_SMPR2_SMP13_Msk            (0x7UL << ADC_SMPR2_SMP13_Pos)          /*!< 0x00000E00 */
#define ADC_SMPR2_SMP13                ADC_SMPR2_SMP13_Msk                     /*!< ADC channel 13 sampling time selection  */
#define ADC_SMPR2_SMP13_0              (0x1UL << ADC_SMPR2_SMP13_Pos)          /*!< 0x00000200 */
#define ADC_SMPR2_SMP13_1              (0x2UL << ADC_SMPR2_SMP13_Pos)          /*!< 0x00000400 */
#define ADC_SMPR2_SMP13_2              (0x4UL << ADC_SMPR2_SMP13_Pos)          /*!< 0x00000800 */

#define ADC_SMPR2_SMP14_Pos            (12U)
#define ADC_SMPR2_SMP14_Msk            (0x7UL << ADC_SMPR2_SMP14_Pos)          /*!< 0x00007000 */
#define ADC_SMPR2_SMP14                ADC_SMPR2_SMP14_Msk                     /*!< ADC channel 14 sampling time selection  */
#define ADC_SMPR2_SMP14_0              (0x1UL << ADC_SMPR2_SMP14_Pos)          /*!< 0x00001000 */
#define ADC_SMPR2_SMP14_1              (0x2UL << ADC_SMPR2_SMP14_Pos)          /*!< 0x00002000 */
#define ADC_SMPR2_SMP14_2              (0x4UL << ADC_SMPR2_SMP14_Pos)          /*!< 0x00004000 */

#define ADC_SMPR2_SMP15_Pos            (15U)
#define ADC_SMPR2_SMP15_Msk            (0x7UL << ADC_SMPR2_SMP15_Pos)          /*!< 0x00038000 */
#define ADC_SMPR2_SMP15                ADC_SMPR2_SMP15_Msk                     /*!< ADC channel 15 sampling time selection  */
#define ADC_SMPR2_SMP15_0              (0x1UL << ADC_SMPR2_SMP15_Pos)          /*!< 0x00008000 */
#define ADC_SMPR2_SMP15_1              (0x2UL << ADC_SMPR2_SMP15_Pos)          /*!< 0x00010000 */
#define ADC_SMPR2_SMP15_2              (0x4UL << ADC_SMPR2_SMP15_Pos)          /*!< 0x00020000 */

#define ADC_SMPR2_SMP16_Pos            (18U)
#define ADC_SMPR2_SMP16_Msk            (0x7UL << ADC_SMPR2_SMP16_Pos)          /*!< 0x001C0000 */
#define ADC_SMPR2_SMP16                ADC_SMPR2_SMP16_Msk                     /*!< ADC channel 16 sampling time selection  */
#define ADC_SMPR2_SMP16_0              (0x1UL << ADC_SMPR2_SMP16_Pos)          /*!< 0x00040000 */
#define ADC_SMPR2_SMP16_1              (0x2UL << ADC_SMPR2_SMP16_Pos)          /*!< 0x00080000 */
#define ADC_SMPR2_SMP16_2              (0x4UL << ADC_SMPR2_SMP16_Pos)          /*!< 0x00100000 */

#define ADC_SMPR2_SMP17_Pos            (21U)
#define ADC_SMPR2_SMP17_Msk            (0x7UL << ADC_SMPR2_SMP17_Pos)          /*!< 0x00E00000 */
#define ADC_SMPR2_SMP17                ADC_SMPR2_SMP17_Msk                     /*!< ADC channel 17 sampling time selection  */
#define ADC_SMPR2_SMP17_0              (0x1UL << ADC_SMPR2_SMP17_Pos)          /*!< 0x00200000 */
#define ADC_SMPR2_SMP17_1              (0x2UL << ADC_SMPR2_SMP17_Pos)          /*!< 0x00400000 */
#define ADC_SMPR2_SMP17_2              (0x4UL << ADC_SMPR2_SMP17_Pos)          /*!< 0x00800000 */

#define ADC_SMPR2_SMP18_Pos            (24U)
#define ADC_SMPR2_SMP18_Msk            (0x7UL << ADC_SMPR2_SMP18_Pos)          /*!< 0x07000000 */
#define ADC_SMPR2_SMP18                ADC_SMPR2_SMP18_Msk                     /*!< ADC channel 18 sampling time selection  */
#define ADC_SMPR2_SMP18_0              (0x1UL << ADC_SMPR2_SMP18_Pos)          /*!< 0x01000000 */
#define ADC_SMPR2_SMP18_1              (0x2UL << ADC_SMPR2_SMP18_Pos)          /*!< 0x02000000 */
#define ADC_SMPR2_SMP18_2              (0x4UL << ADC_SMPR2_SMP18_Pos)          /*!< 0x04000000 */

/********************  Bit definition for ADC_TR1 register  *******************/
#define ADC_TR1_LT1_Pos                (0U)
#define ADC_TR1_LT1_Msk                (0xFFFUL << ADC_TR1_LT1_Pos)            /*!< 0x00000FFF */
#define ADC_TR1_LT1                    ADC_TR1_LT1_Msk                         /*!< ADC analog watchdog 1 threshold low */
#define ADC_TR1_LT1_0                  (0x001UL << ADC_TR1_LT1_Pos)            /*!< 0x00000001 */
#define ADC_TR1_LT1_1                  (0x002UL << ADC_TR1_LT1_Pos)            /*!< 0x00000002 */
#define ADC_TR1_LT1_2                  (0x004UL << ADC_TR1_LT1_Pos)            /*!< 0x00000004 */
#define ADC_TR1_LT1_3                  (0x008UL << ADC_TR1_LT1_Pos)            /*!< 0x00000008 */
#define ADC_TR1_LT1_4                  (0x010UL << ADC_TR1_LT1_Pos)            /*!< 0x00000010 */
#define ADC_TR1_LT1_5                  (0x020UL << ADC_TR1_LT1_Pos)            /*!< 0x00000020 */
#define ADC_TR1_LT1_6                  (0x040UL << ADC_TR1_LT1_Pos)            /*!< 0x00000040 */
#define ADC_TR1_LT1_7                  (0x080UL << ADC_TR1_LT1_Pos)            /*!< 0x00000080 */
#define ADC_TR1_LT1_8                  (0x100UL << ADC_TR1_LT1_Pos)            /*!< 0x00000100 */
#define ADC_TR1_LT1_9                  (0x200UL << ADC_TR1_LT1_Pos)            /*!< 0x00000200 */
#define ADC_TR1_LT1_10                 (0x400UL << ADC_TR1_LT1_Pos)            /*!< 0x00000400 */
#define ADC_TR1_LT1_11                 (0x800UL << ADC_TR1_LT1_Pos)            /*!< 0x00000800 */

#define ADC_TR1_HT1_Pos                (16U)
#define ADC_TR1_HT1_Msk                (0xFFFUL << ADC_TR1_HT1_Pos)            /*!< 0x0FFF0000 */
#define ADC_TR1_HT1                    ADC_TR1_HT1_Msk                         /*!< ADC Analog watchdog 1 threshold high */
#define ADC_TR1_HT1_0                  (0x001UL << ADC_TR1_HT1_Pos)            /*!< 0x00010000 */
#define ADC_TR1_HT1_1                  (0x002UL << ADC_TR1_HT1_Pos)            /*!< 0x00020000 */
#define ADC_TR1_HT1_2                  (0x004UL << ADC_TR1_HT1_Pos)            /*!< 0x00040000 */
#define ADC_TR1_HT1_3                  (0x008UL << ADC_TR1_HT1_Pos)            /*!< 0x00080000 */
#define ADC_TR1_HT1_4                  (0x010UL << ADC_TR1_HT1_Pos)            /*!< 0x00100000 */
#define ADC_TR1_HT1_5                  (0x020UL << ADC_TR1_HT1_Pos)            /*!< 0x00200000 */
#define ADC_TR1_HT1_6                  (0x040UL << ADC_TR1_HT1_Pos)            /*!< 0x00400000 */
#define ADC_TR1_HT1_7                  (0x080UL << ADC_TR1_HT1_Pos)            /*!< 0x00800000 */
#define ADC_TR1_HT1_8                  (0x100UL << ADC_TR1_HT1_Pos)            /*!< 0x01000000 */
#define ADC_TR1_HT1_9                  (0x200UL << ADC_TR1_HT1_Pos)            /*!< 0x02000000 */
#define ADC_TR1_HT1_10                 (0x400UL << ADC_TR1_HT1_Pos)            /*!< 0x04000000 */
#define ADC_TR1_HT1_11                 (0x800UL << ADC_TR1_HT1_Pos)            /*!< 0x08000000 */

/********************  Bit definition for ADC_TR2 register  *******************/
#define ADC_TR2_LT2_Pos                (0U)
#define ADC_TR2_LT2_Msk                (0xFFUL << ADC_TR2_LT2_Pos)             /*!< 0x000000FF */
#define ADC_TR2_LT2                    ADC_TR2_LT2_Msk                         /*!< ADC analog watchdog 2 threshold low */
#define ADC_TR2_LT2_0                  (0x01UL << ADC_TR2_LT2_Pos)             /*!< 0x00000001 */
#define ADC_TR2_LT2_1                  (0x02UL << ADC_TR2_LT2_Pos)             /*!< 0x00000002 */
#define ADC_TR2_LT2_2                  (0x04UL << ADC_TR2_LT2_Pos)             /*!< 0x00000004 */
#define ADC_TR2_LT2_3                  (0x08UL << ADC_TR2_LT2_Pos)             /*!< 0x00000008 */
#define ADC_TR2_LT2_4                  (0x10UL << ADC_TR2_LT2_Pos)             /*!< 0x00000010 */
#define ADC_TR2_LT2_5                  (0x20UL << ADC_TR2_LT2_Pos)             /*!< 0x00000020 */
#define ADC_TR2_LT2_6                  (0x40UL << ADC_TR2_LT2_Pos)             /*!< 0x00000040 */
#define ADC_TR2_LT2_7                  (0x80UL << ADC_TR2_LT2_Pos)             /*!< 0x00000080 */

#define ADC_TR2_HT2_Pos                (16U)
#define ADC_TR2_HT2_Msk                (0xFFUL << ADC_TR2_HT2_Pos)             /*!< 0x00FF0000 */
#define ADC_TR2_HT2                    ADC_TR2_HT2_Msk                         /*!< ADC analog watchdog 2 threshold high */
#define ADC_TR2_HT2_0                  (0x01UL << ADC_TR2_HT2_Pos)             /*!< 0x00010000 */
#define ADC_TR2_HT2_1                  (0x02UL << ADC_TR2_HT2_Pos)             /*!< 0x00020000 */
#define ADC_TR2_HT2_2                  (0x04UL << ADC_TR2_HT2_Pos)             /*!< 0x00040000 */
#define ADC_TR2_HT2_3                  (0x08UL << ADC_TR2_HT2_Pos)             /*!< 0x00080000 */
#define ADC_TR2_HT2_4                  (0x10UL << ADC_TR2_HT2_Pos)             /*!< 0x00100000 */
#define ADC_TR2_HT2_5                  (0x20UL << ADC_TR2_HT2_Pos)             /*!< 0x00200000 */
#define ADC_TR2_HT2_6                  (0x40UL << ADC_TR2_HT2_Pos)             /*!< 0x00400000 */
#define ADC_TR2_HT2_7                  (0x80UL << ADC_TR2_HT2_Pos)             /*!< 0x00800000 */

/********************  Bit definition for ADC_TR3 register  *******************/
#define ADC_TR3_LT3_Pos                (0U)
#define ADC_TR3_LT3_Msk                (0xFFUL << ADC_TR3_LT3_Pos)             /*!< 0x000000FF */
#define ADC_TR3_LT3                    ADC_TR3_LT3_Msk                         /*!< ADC analog watchdog 3 threshold low */
#define ADC_TR3_LT3_0                  (0x01UL << ADC_TR3_LT3_Pos)             /*!< 0x00000001 */
#define ADC_TR3_LT3_1                  (0x02UL << ADC_TR3_LT3_Pos)             /*!< 0x00000002 */
#define ADC_TR3_LT3_2                  (0x04UL << ADC_TR3_LT3_Pos)             /*!< 0x00000004 */
#define ADC_TR3_LT3_3                  (0x08UL << ADC_TR3_LT3_Pos)             /*!< 0x00000008 */
#define ADC_TR3_LT3_4                  (0x10UL << ADC_TR3_LT3_Pos)             /*!< 0x00000010 */
#define ADC_TR3_LT3_5                  (0x20UL << ADC_TR3_LT3_Pos)             /*!< 0x00000020 */
#define ADC_TR3_LT3_6                  (0x40UL << ADC_TR3_LT3_Pos)             /*!< 0x00000040 */
#define ADC_TR3_LT3_7                  (0x80UL << ADC_TR3_LT3_Pos)             /*!< 0x00000080 */

#define ADC_TR3_HT3_Pos                (16U)
#define ADC_TR3_HT3_Msk                (0xFFUL << ADC_TR3_HT3_Pos)             /*!< 0x00FF0000 */
#define ADC_TR3_HT3                    ADC_TR3_HT3_Msk                         /*!< ADC analog watchdog 3 threshold high */
#define ADC_TR3_HT3_0                  (0x01UL << ADC_TR3_HT3_Pos)             /*!< 0x00010000 */
#define ADC_TR3_HT3_1                  (0x02UL << ADC_TR3_HT3_Pos)             /*!< 0x00020000 */
#define ADC_TR3_HT3_2                  (0x04UL << ADC_TR3_HT3_Pos)             /*!< 0x00040000 */
#define ADC_TR3_HT3_3                  (0x08UL << ADC_TR3_HT3_Pos)             /*!< 0x00080000 */
#define ADC_TR3_HT3_4                  (0x10UL << ADC_TR3_HT3_Pos)             /*!< 0x00100000 */
#define ADC_TR3_HT3_5                  (0x20UL << ADC_TR3_HT3_Pos)             /*!< 0x00200000 */
#define ADC_TR3_HT3_6                  (0x40UL << ADC_TR3_HT3_Pos)             /*!< 0x00400000 */
#define ADC_TR3_HT3_7                  (0x80UL << ADC_TR3_HT3_Pos)             /*!< 0x00800000 */

/********************  Bit definition for ADC_SQR1 register  ******************/
#define ADC_SQR1_L_Pos                 (0U)
#define ADC_SQR1_L_Msk                 (0xFUL << ADC_SQR1_L_Pos)               /*!< 0x0000000F */
#define ADC_SQR1_L                     ADC_SQR1_L_Msk                          /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_L_0                   (0x1UL << ADC_SQR1_L_Pos)               /*!< 0x00000001 */
#define ADC_SQR1_L_1                   (0x2UL << ADC_SQR1_L_Pos)               /*!< 0x00000002 */
#define ADC_SQR1_L_2                   (0x4UL << ADC_SQR1_L_Pos)               /*!< 0x00000004 */
#define ADC_SQR1_L_3                   (0x8UL << ADC_SQR1_L_Pos)               /*!< 0x00000008 */

#define ADC_SQR1_SQ1_Pos               (6U)
#define ADC_SQR1_SQ1_Msk               (0x1FUL << ADC_SQR1_SQ1_Pos)            /*!< 0x000007C0 */
#define ADC_SQR1_SQ1                   ADC_SQR1_SQ1_Msk                        /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR1_SQ1_0                 (0x01UL << ADC_SQR1_SQ1_Pos)            /*!< 0x00000040 */
#define ADC_SQR1_SQ1_1                 (0x02UL << ADC_SQR1_SQ1_Pos)            /*!< 0x00000080 */
#define ADC_SQR1_SQ1_2                 (0x04UL << ADC_SQR1_SQ1_Pos)            /*!< 0x00000100 */
#define ADC_SQR1_SQ1_3                 (0x08UL << ADC_SQR1_SQ1_Pos)            /*!< 0x00000200 */
#define ADC_SQR1_SQ1_4                 (0x10UL << ADC_SQR1_SQ1_Pos)            /*!< 0x00000400 */

#define ADC_SQR1_SQ2_Pos               (12U)
#define ADC_SQR1_SQ2_Msk               (0x1FUL << ADC_SQR1_SQ2_Pos)            /*!< 0x0001F000 */
#define ADC_SQR1_SQ2                   ADC_SQR1_SQ2_Msk                        /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR1_SQ2_0                 (0x01UL << ADC_SQR1_SQ2_Pos)            /*!< 0x00001000 */
#define ADC_SQR1_SQ2_1                 (0x02UL << ADC_SQR1_SQ2_Pos)            /*!< 0x00002000 */
#define ADC_SQR1_SQ2_2                 (0x04UL << ADC_SQR1_SQ2_Pos)            /*!< 0x00004000 */
#define ADC_SQR1_SQ2_3                 (0x08UL << ADC_SQR1_SQ2_Pos)            /*!< 0x00008000 */
#define ADC_SQR1_SQ2_4                 (0x10UL << ADC_SQR1_SQ2_Pos)            /*!< 0x00010000 */

#define ADC_SQR1_SQ3_Pos               (18U)
#define ADC_SQR1_SQ3_Msk               (0x1FUL << ADC_SQR1_SQ3_Pos)            /*!< 0x007C0000 */
#define ADC_SQR1_SQ3                   ADC_SQR1_SQ3_Msk                        /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR1_SQ3_0                 (0x01UL << ADC_SQR1_SQ3_Pos)            /*!< 0x00040000 */
#define ADC_SQR1_SQ3_1                 (0x02UL << ADC_SQR1_SQ3_Pos)            /*!< 0x00080000 */
#define ADC_SQR1_SQ3_2                 (0x04UL << ADC_SQR1_SQ3_Pos)            /*!< 0x00100000 */
#define ADC_SQR1_SQ3_3                 (0x08UL << ADC_SQR1_SQ3_Pos)            /*!< 0x00200000 */
#define ADC_SQR1_SQ3_4                 (0x10UL << ADC_SQR1_SQ3_Pos)            /*!< 0x00400000 */

#define ADC_SQR1_SQ4_Pos               (24U)
#define ADC_SQR1_SQ4_Msk               (0x1FUL << ADC_SQR1_SQ4_Pos)            /*!< 0x1F000000 */
#define ADC_SQR1_SQ4                   ADC_SQR1_SQ4_Msk                        /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR1_SQ4_0                 (0x01UL << ADC_SQR1_SQ4_Pos)            /*!< 0x01000000 */
#define ADC_SQR1_SQ4_1                 (0x02UL << ADC_SQR1_SQ4_Pos)            /*!< 0x02000000 */
#define ADC_SQR1_SQ4_2                 (0x04UL << ADC_SQR1_SQ4_Pos)            /*!< 0x04000000 */
#define ADC_SQR1_SQ4_3                 (0x08UL << ADC_SQR1_SQ4_Pos)            /*!< 0x08000000 */
#define ADC_SQR1_SQ4_4                 (0x10UL << ADC_SQR1_SQ4_Pos)            /*!< 0x10000000 */

/********************  Bit definition for ADC_SQR2 register  ******************/
#define ADC_SQR2_SQ5_Pos               (0U)
#define ADC_SQR2_SQ5_Msk               (0x1FUL << ADC_SQR2_SQ5_Pos)            /*!< 0x0000001F */
#define ADC_SQR2_SQ5                   ADC_SQR2_SQ5_Msk                        /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR2_SQ5_0                 (0x01UL << ADC_SQR2_SQ5_Pos)            /*!< 0x00000001 */
#define ADC_SQR2_SQ5_1                 (0x02UL << ADC_SQR2_SQ5_Pos)            /*!< 0x00000002 */
#define ADC_SQR2_SQ5_2                 (0x04UL << ADC_SQR2_SQ5_Pos)            /*!< 0x00000004 */
#define ADC_SQR2_SQ5_3                 (0x08UL << ADC_SQR2_SQ5_Pos)            /*!< 0x00000008 */
#define ADC_SQR2_SQ5_4                 (0x10UL << ADC_SQR2_SQ5_Pos)            /*!< 0x00000010 */

#define ADC_SQR2_SQ6_Pos               (6U)
#define ADC_SQR2_SQ6_Msk               (0x1FUL << ADC_SQR2_SQ6_Pos)            /*!< 0x000007C0 */
#define ADC_SQR2_SQ6                   ADC_SQR2_SQ6_Msk                        /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR2_SQ6_0                 (0x01UL << ADC_SQR2_SQ6_Pos)            /*!< 0x00000040 */
#define ADC_SQR2_SQ6_1                 (0x02UL << ADC_SQR2_SQ6_Pos)            /*!< 0x00000080 */
#define ADC_SQR2_SQ6_2                 (0x04UL << ADC_SQR2_SQ6_Pos)            /*!< 0x00000100 */
#define ADC_SQR2_SQ6_3                 (0x08UL << ADC_SQR2_SQ6_Pos)            /*!< 0x00000200 */
#define ADC_SQR2_SQ6_4                 (0x10UL << ADC_SQR2_SQ6_Pos)            /*!< 0x00000400 */

#define ADC_SQR2_SQ7_Pos               (12U)
#define ADC_SQR2_SQ7_Msk               (0x1FUL << ADC_SQR2_SQ7_Pos)            /*!< 0x0001F000 */
#define ADC_SQR2_SQ7                   ADC_SQR2_SQ7_Msk                        /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR2_SQ7_0                 (0x01UL << ADC_SQR2_SQ7_Pos)            /*!< 0x00001000 */
#define ADC_SQR2_SQ7_1                 (0x02UL << ADC_SQR2_SQ7_Pos)            /*!< 0x00002000 */
#define ADC_SQR2_SQ7_2                 (0x04UL << ADC_SQR2_SQ7_Pos)            /*!< 0x00004000 */
#define ADC_SQR2_SQ7_3                 (0x08UL << ADC_SQR2_SQ7_Pos)            /*!< 0x00008000 */
#define ADC_SQR2_SQ7_4                 (0x10UL << ADC_SQR2_SQ7_Pos)            /*!< 0x00010000 */

#define ADC_SQR2_SQ8_Pos               (18U)
#define ADC_SQR2_SQ8_Msk               (0x1FUL << ADC_SQR2_SQ8_Pos)            /*!< 0x007C0000 */
#define ADC_SQR2_SQ8                   ADC_SQR2_SQ8_Msk                        /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0                 (0x01UL << ADC_SQR2_SQ8_Pos)            /*!< 0x00040000 */
#define ADC_SQR2_SQ8_1                 (0x02UL << ADC_SQR2_SQ8_Pos)            /*!< 0x00080000 */
#define ADC_SQR2_SQ8_2                 (0x04UL << ADC_SQR2_SQ8_Pos)            /*!< 0x00100000 */
#define ADC_SQR2_SQ8_3                 (0x08UL << ADC_SQR2_SQ8_Pos)            /*!< 0x00200000 */
#define ADC_SQR2_SQ8_4                 (0x10UL << ADC_SQR2_SQ8_Pos)            /*!< 0x00400000 */

#define ADC_SQR2_SQ9_Pos               (24U)
#define ADC_SQR2_SQ9_Msk               (0x1FUL << ADC_SQR2_SQ9_Pos)            /*!< 0x1F000000 */
#define ADC_SQR2_SQ9                   ADC_SQR2_SQ9_Msk                        /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0                 (0x01UL << ADC_SQR2_SQ9_Pos)            /*!< 0x01000000 */
#define ADC_SQR2_SQ9_1                 (0x02UL << ADC_SQR2_SQ9_Pos)            /*!< 0x02000000 */
#define ADC_SQR2_SQ9_2                 (0x04UL << ADC_SQR2_SQ9_Pos)            /*!< 0x04000000 */
#define ADC_SQR2_SQ9_3                 (0x08UL << ADC_SQR2_SQ9_Pos)            /*!< 0x08000000 */
#define ADC_SQR2_SQ9_4                 (0x10UL << ADC_SQR2_SQ9_Pos)            /*!< 0x10000000 */

/********************  Bit definition for ADC_SQR3 register  ******************/
#define ADC_SQR3_SQ10_Pos              (0U)
#define ADC_SQR3_SQ10_Msk              (0x1FUL << ADC_SQR3_SQ10_Pos)           /*!< 0x0000001F */
#define ADC_SQR3_SQ10                  ADC_SQR3_SQ10_Msk                       /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR3_SQ10_0                (0x01UL << ADC_SQR3_SQ10_Pos)           /*!< 0x00000001 */
#define ADC_SQR3_SQ10_1                (0x02UL << ADC_SQR3_SQ10_Pos)           /*!< 0x00000002 */
#define ADC_SQR3_SQ10_2                (0x04UL << ADC_SQR3_SQ10_Pos)           /*!< 0x00000004 */
#define ADC_SQR3_SQ10_3                (0x08UL << ADC_SQR3_SQ10_Pos)           /*!< 0x00000008 */
#define ADC_SQR3_SQ10_4                (0x10UL << ADC_SQR3_SQ10_Pos)           /*!< 0x00000010 */

#define ADC_SQR3_SQ11_Pos              (6U)
#define ADC_SQR3_SQ11_Msk              (0x1FUL << ADC_SQR3_SQ11_Pos)           /*!< 0x000007C0 */
#define ADC_SQR3_SQ11                  ADC_SQR3_SQ11_Msk                       /*!< ADC group regular sequencer rank 11 */
#define ADC_SQR3_SQ11_0                (0x01UL << ADC_SQR3_SQ11_Pos)           /*!< 0x00000040 */
#define ADC_SQR3_SQ11_1                (0x02UL << ADC_SQR3_SQ11_Pos)           /*!< 0x00000080 */
#define ADC_SQR3_SQ11_2                (0x04UL << ADC_SQR3_SQ11_Pos)           /*!< 0x00000100 */
#define ADC_SQR3_SQ11_3                (0x08UL << ADC_SQR3_SQ11_Pos)           /*!< 0x00000200 */
#define ADC_SQR3_SQ11_4                (0x10UL << ADC_SQR3_SQ11_Pos)           /*!< 0x00000400 */

#define ADC_SQR3_SQ12_Pos              (12U)
#define ADC_SQR3_SQ12_Msk              (0x1FUL << ADC_SQR3_SQ12_Pos)           /*!< 0x0001F000 */
#define ADC_SQR3_SQ12                  ADC_SQR3_SQ12_Msk                       /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR3_SQ12_0                (0x01UL << ADC_SQR3_SQ12_Pos)           /*!< 0x00001000 */
#define ADC_SQR3_SQ12_1                (0x02UL << ADC_SQR3_SQ12_Pos)           /*!< 0x00002000 */
#define ADC_SQR3_SQ12_2                (0x04UL << ADC_SQR3_SQ12_Pos)           /*!< 0x00004000 */
#define ADC_SQR3_SQ12_3                (0x08UL << ADC_SQR3_SQ12_Pos)           /*!< 0x00008000 */
#define ADC_SQR3_SQ12_4                (0x10UL << ADC_SQR3_SQ12_Pos)           /*!< 0x00010000 */

#define ADC_SQR3_SQ13_Pos              (18U)
#define ADC_SQR3_SQ13_Msk              (0x1FUL << ADC_SQR3_SQ13_Pos)           /*!< 0x007C0000 */
#define ADC_SQR3_SQ13                  ADC_SQR3_SQ13_Msk                       /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR3_SQ13_0                (0x01UL << ADC_SQR3_SQ13_Pos)           /*!< 0x00040000 */
#define ADC_SQR3_SQ13_1                (0x02UL << ADC_SQR3_SQ13_Pos)           /*!< 0x00080000 */
#define ADC_SQR3_SQ13_2                (0x04UL << ADC_SQR3_SQ13_Pos)           /*!< 0x00100000 */
#define ADC_SQR3_SQ13_3                (0x08UL << ADC_SQR3_SQ13_Pos)           /*!< 0x00200000 */
#define ADC_SQR3_SQ13_4                (0x10UL << ADC_SQR3_SQ13_Pos)           /*!< 0x00400000 */

#define ADC_SQR3_SQ14_Pos              (24U)
#define ADC_SQR3_SQ14_Msk              (0x1FUL << ADC_SQR3_SQ14_Pos)           /*!< 0x1F000000 */
#define ADC_SQR3_SQ14                  ADC_SQR3_SQ14_Msk                       /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR3_SQ14_0                (0x01UL << ADC_SQR3_SQ14_Pos)           /*!< 0x01000000 */
#define ADC_SQR3_SQ14_1                (0x02UL << ADC_SQR3_SQ14_Pos)           /*!< 0x02000000 */
#define ADC_SQR3_SQ14_2                (0x04UL << ADC_SQR3_SQ14_Pos)           /*!< 0x04000000 */
#define ADC_SQR3_SQ14_3                (0x08UL << ADC_SQR3_SQ14_Pos)           /*!< 0x08000000 */
#define ADC_SQR3_SQ14_4                (0x10UL << ADC_SQR3_SQ14_Pos)           /*!< 0x10000000 */

/********************  Bit definition for ADC_SQR4 register  ******************/
#define ADC_SQR4_SQ15_Pos              (0U)
#define ADC_SQR4_SQ15_Msk              (0x1FUL << ADC_SQR4_SQ15_Pos)           /*!< 0x0000001F */
#define ADC_SQR4_SQ15                  ADC_SQR4_SQ15_Msk                       /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR4_SQ15_0                (0x01UL << ADC_SQR4_SQ15_Pos)           /*!< 0x00000001 */
#define ADC_SQR4_SQ15_1                (0x02UL << ADC_SQR4_SQ15_Pos)           /*!< 0x00000002 */
#define ADC_SQR4_SQ15_2                (0x04UL << ADC_SQR4_SQ15_Pos)           /*!< 0x00000004 */
#define ADC_SQR4_SQ15_3                (0x08UL << ADC_SQR4_SQ15_Pos)           /*!< 0x00000008 */
#define ADC_SQR4_SQ15_4                (0x10UL << ADC_SQR4_SQ15_Pos)           /*!< 0x00000010 */

#define ADC_SQR4_SQ16_Pos              (6U)
#define ADC_SQR4_SQ16_Msk              (0x1FUL << ADC_SQR4_SQ16_Pos)           /*!< 0x000007C0 */
#define ADC_SQR4_SQ16                  ADC_SQR4_SQ16_Msk                       /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR4_SQ16_0                (0x01UL << ADC_SQR4_SQ16_Pos)           /*!< 0x00000040 */
#define ADC_SQR4_SQ16_1                (0x02UL << ADC_SQR4_SQ16_Pos)           /*!< 0x00000080 */
#define ADC_SQR4_SQ16_2                (0x04UL << ADC_SQR4_SQ16_Pos)           /*!< 0x00000100 */
#define ADC_SQR4_SQ16_3                (0x08UL << ADC_SQR4_SQ16_Pos)           /*!< 0x00000200 */
#define ADC_SQR4_SQ16_4                (0x10UL << ADC_SQR4_SQ16_Pos)           /*!< 0x00000400 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_RDATA_Pos               (0U)
#define ADC_DR_RDATA_Msk               (0xFFFFUL << ADC_DR_RDATA_Pos)          /*!< 0x0000FFFF */
#define ADC_DR_RDATA                   ADC_DR_RDATA_Msk                        /*!< ADC group regular conversion data */
#define ADC_DR_RDATA_0                 (0x0001UL << ADC_DR_RDATA_Pos)          /*!< 0x00000001 */
#define ADC_DR_RDATA_1                 (0x0002UL << ADC_DR_RDATA_Pos)          /*!< 0x00000002 */
#define ADC_DR_RDATA_2                 (0x0004UL << ADC_DR_RDATA_Pos)          /*!< 0x00000004 */
#define ADC_DR_RDATA_3                 (0x0008UL << ADC_DR_RDATA_Pos)          /*!< 0x00000008 */
#define ADC_DR_RDATA_4                 (0x0010UL << ADC_DR_RDATA_Pos)          /*!< 0x00000010 */
#define ADC_DR_RDATA_5                 (0x0020UL << ADC_DR_RDATA_Pos)          /*!< 0x00000020 */
#define ADC_DR_RDATA_6                 (0x0040UL << ADC_DR_RDATA_Pos)          /*!< 0x00000040 */
#define ADC_DR_RDATA_7                 (0x0080UL << ADC_DR_RDATA_Pos)          /*!< 0x00000080 */
#define ADC_DR_RDATA_8                 (0x0100UL << ADC_DR_RDATA_Pos)          /*!< 0x00000100 */
#define ADC_DR_RDATA_9                 (0x0200UL << ADC_DR_RDATA_Pos)          /*!< 0x00000200 */
#define ADC_DR_RDATA_10                (0x0400UL << ADC_DR_RDATA_Pos)          /*!< 0x00000400 */
#define ADC_DR_RDATA_11                (0x0800UL << ADC_DR_RDATA_Pos)          /*!< 0x00000800 */
#define ADC_DR_RDATA_12                (0x1000UL << ADC_DR_RDATA_Pos)          /*!< 0x00001000 */
#define ADC_DR_RDATA_13                (0x2000UL << ADC_DR_RDATA_Pos)          /*!< 0x00002000 */
#define ADC_DR_RDATA_14                (0x4000UL << ADC_DR_RDATA_Pos)          /*!< 0x00004000 */
#define ADC_DR_RDATA_15                (0x8000UL << ADC_DR_RDATA_Pos)          /*!< 0x00008000 */

/********************  Bit definition for ADC_JSQR register  ******************/
#define ADC_JSQR_JL_Pos                (0U)
#define ADC_JSQR_JL_Msk                (0x3UL << ADC_JSQR_JL_Pos)              /*!< 0x00000003 */
#define ADC_JSQR_JL                    ADC_JSQR_JL_Msk                         /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0                  (0x1UL << ADC_JSQR_JL_Pos)              /*!< 0x00000001 */
#define ADC_JSQR_JL_1                  (0x2UL << ADC_JSQR_JL_Pos)              /*!< 0x00000002 */

#define ADC_JSQR_JEXTSEL_Pos           (2U)
#define ADC_JSQR_JEXTSEL_Msk           (0xFUL << ADC_JSQR_JEXTSEL_Pos)         /*!< 0x0000003C */
#define ADC_JSQR_JEXTSEL               ADC_JSQR_JEXTSEL_Msk                    /*!< ADC group injected external trigger source */
#define ADC_JSQR_JEXTSEL_0             (0x1UL << ADC_JSQR_JEXTSEL_Pos)         /*!< 0x00000004 */
#define ADC_JSQR_JEXTSEL_1             (0x2UL << ADC_JSQR_JEXTSEL_Pos)         /*!< 0x00000008 */
#define ADC_JSQR_JEXTSEL_2             (0x4UL << ADC_JSQR_JEXTSEL_Pos)         /*!< 0x00000010 */
#define ADC_JSQR_JEXTSEL_3             (0x8UL << ADC_JSQR_JEXTSEL_Pos)         /*!< 0x00000020 */

#define ADC_JSQR_JEXTEN_Pos            (6U)
#define ADC_JSQR_JEXTEN_Msk            (0x3UL << ADC_JSQR_JEXTEN_Pos)          /*!< 0x000000C0 */
#define ADC_JSQR_JEXTEN                ADC_JSQR_JEXTEN_Msk                     /*!< ADC group injected external trigger polarity */
#define ADC_JSQR_JEXTEN_0              (0x1UL << ADC_JSQR_JEXTEN_Pos)          /*!< 0x00000040 */
#define ADC_JSQR_JEXTEN_1              (0x2UL << ADC_JSQR_JEXTEN_Pos)          /*!< 0x00000080 */

#define ADC_JSQR_JSQ1_Pos              (8U)
#define ADC_JSQR_JSQ1_Msk              (0x1FUL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00001F00 */
#define ADC_JSQR_JSQ1                  ADC_JSQR_JSQ1_Msk                       /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0                (0x01UL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00000100 */
#define ADC_JSQR_JSQ1_1                (0x02UL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00000200 */
#define ADC_JSQR_JSQ1_2                (0x04UL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00000400 */
#define ADC_JSQR_JSQ1_3                (0x08UL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00000800 */
#define ADC_JSQR_JSQ1_4                (0x10UL << ADC_JSQR_JSQ1_Pos)           /*!< 0x00001000 */

#define ADC_JSQR_JSQ2_Pos              (14U)
#define ADC_JSQR_JSQ2_Msk              (0x1FUL << ADC_JSQR_JSQ2_Pos)           /*!< 0x0007C000 */
#define ADC_JSQR_JSQ2                  ADC_JSQR_JSQ2_Msk                       /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0                (0x01UL << ADC_JSQR_JSQ2_Pos)           /*!< 0x00004000 */
#define ADC_JSQR_JSQ2_1                (0x02UL << ADC_JSQR_JSQ2_Pos)           /*!< 0x00008000 */
#define ADC_JSQR_JSQ2_2                (0x04UL << ADC_JSQR_JSQ2_Pos)           /*!< 0x00010000 */
#define ADC_JSQR_JSQ2_3                (0x08UL << ADC_JSQR_JSQ2_Pos)           /*!< 0x00020000 */
#define ADC_JSQR_JSQ2_4                (0x10UL << ADC_JSQR_JSQ2_Pos)           /*!< 0x00040000 */

#define ADC_JSQR_JSQ3_Pos              (20U)
#define ADC_JSQR_JSQ3_Msk              (0x1FUL << ADC_JSQR_JSQ3_Pos)           /*!< 0x01F00000 */
#define ADC_JSQR_JSQ3                  ADC_JSQR_JSQ3_Msk                       /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0                (0x01UL << ADC_JSQR_JSQ3_Pos)           /*!< 0x00100000 */
#define ADC_JSQR_JSQ3_1                (0x02UL << ADC_JSQR_JSQ3_Pos)           /*!< 0x00200000 */
#define ADC_JSQR_JSQ3_2                (0x04UL << ADC_JSQR_JSQ3_Pos)           /*!< 0x00400000 */
#define ADC_JSQR_JSQ3_3                (0x08UL << ADC_JSQR_JSQ3_Pos)           /*!< 0x00800000 */
#define ADC_JSQR_JSQ3_4                (0x10UL << ADC_JSQR_JSQ3_Pos)           /*!< 0x01000000 */

#define ADC_JSQR_JSQ4_Pos              (26U)
#define ADC_JSQR_JSQ4_Msk              (0x1FUL << ADC_JSQR_JSQ4_Pos)           /*!< 0x7C000000 */
#define ADC_JSQR_JSQ4                  ADC_JSQR_JSQ4_Msk                       /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0                (0x01UL << ADC_JSQR_JSQ4_Pos)           /*!< 0x04000000 */
#define ADC_JSQR_JSQ4_1                (0x02UL << ADC_JSQR_JSQ4_Pos)           /*!< 0x08000000 */
#define ADC_JSQR_JSQ4_2                (0x04UL << ADC_JSQR_JSQ4_Pos)           /*!< 0x10000000 */
#define ADC_JSQR_JSQ4_3                (0x08UL << ADC_JSQR_JSQ4_Pos)           /*!< 0x20000000 */
#define ADC_JSQR_JSQ4_4                (0x10UL << ADC_JSQR_JSQ4_Pos)           /*!< 0x40000000 */

/********************  Bit definition for ADC_OFR1 register  ******************/
#define ADC_OFR1_OFFSET1_Pos           (0U)
#define ADC_OFR1_OFFSET1_Msk           (0xFFFUL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000FFF */
#define ADC_OFR1_OFFSET1               ADC_OFR1_OFFSET1_Msk                    /*!< ADC offset number 1 offset level */
#define ADC_OFR1_OFFSET1_0             (0x001UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000001 */
#define ADC_OFR1_OFFSET1_1             (0x002UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000002 */
#define ADC_OFR1_OFFSET1_2             (0x004UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000004 */
#define ADC_OFR1_OFFSET1_3             (0x008UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000008 */
#define ADC_OFR1_OFFSET1_4             (0x010UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000010 */
#define ADC_OFR1_OFFSET1_5             (0x020UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000020 */
#define ADC_OFR1_OFFSET1_6             (0x040UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000040 */
#define ADC_OFR1_OFFSET1_7             (0x080UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000080 */
#define ADC_OFR1_OFFSET1_8             (0x100UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000100 */
#define ADC_OFR1_OFFSET1_9             (0x200UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000200 */
#define ADC_OFR1_OFFSET1_10            (0x400UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000400 */
#define ADC_OFR1_OFFSET1_11            (0x800UL << ADC_OFR1_OFFSET1_Pos)       /*!< 0x00000800 */

#define ADC_OFR1_OFFSET1_CH_Pos        (26U)
#define ADC_OFR1_OFFSET1_CH_Msk        (0x1FUL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x7C000000 */
#define ADC_OFR1_OFFSET1_CH            ADC_OFR1_OFFSET1_CH_Msk                 /*!< ADC offset number 1 channel selection */
#define ADC_OFR1_OFFSET1_CH_0          (0x01UL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x04000000 */
#define ADC_OFR1_OFFSET1_CH_1          (0x02UL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x08000000 */
#define ADC_OFR1_OFFSET1_CH_2          (0x04UL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x10000000 */
#define ADC_OFR1_OFFSET1_CH_3          (0x08UL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x20000000 */
#define ADC_OFR1_OFFSET1_CH_4          (0x10UL << ADC_OFR1_OFFSET1_CH_Pos)     /*!< 0x40000000 */

#define ADC_OFR1_OFFSET1_EN_Pos        (31U)
#define ADC_OFR1_OFFSET1_EN_Msk        (0x1UL << ADC_OFR1_OFFSET1_EN_Pos)      /*!< 0x80000000 */
#define ADC_OFR1_OFFSET1_EN            ADC_OFR1_OFFSET1_EN_Msk                 /*!< ADC offset number 1 enable */

/********************  Bit definition for ADC_OFR2 register  ******************/
#define ADC_OFR2_OFFSET2_Pos           (0U)
#define ADC_OFR2_OFFSET2_Msk           (0xFFFUL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000FFF */
#define ADC_OFR2_OFFSET2               ADC_OFR2_OFFSET2_Msk                    /*!< ADC offset number 2 offset level */
#define ADC_OFR2_OFFSET2_0             (0x001UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000001 */
#define ADC_OFR2_OFFSET2_1             (0x002UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000002 */
#define ADC_OFR2_OFFSET2_2             (0x004UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000004 */
#define ADC_OFR2_OFFSET2_3             (0x008UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000008 */
#define ADC_OFR2_OFFSET2_4             (0x010UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000010 */
#define ADC_OFR2_OFFSET2_5             (0x020UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000020 */
#define ADC_OFR2_OFFSET2_6             (0x040UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000040 */
#define ADC_OFR2_OFFSET2_7             (0x080UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000080 */
#define ADC_OFR2_OFFSET2_8             (0x100UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000100 */
#define ADC_OFR2_OFFSET2_9             (0x200UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000200 */
#define ADC_OFR2_OFFSET2_10            (0x400UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000400 */
#define ADC_OFR2_OFFSET2_11            (0x800UL << ADC_OFR2_OFFSET2_Pos)       /*!< 0x00000800 */

#define ADC_OFR2_OFFSET2_CH_Pos        (26U)
#define ADC_OFR2_OFFSET2_CH_Msk        (0x1FUL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x7C000000 */
#define ADC_OFR2_OFFSET2_CH            ADC_OFR2_OFFSET2_CH_Msk                 /*!< ADC offset number 2 channel selection */
#define ADC_OFR2_OFFSET2_CH_0          (0x01UL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x04000000 */
#define ADC_OFR2_OFFSET2_CH_1          (0x02UL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x08000000 */
#define ADC_OFR2_OFFSET2_CH_2          (0x04UL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x10000000 */
#define ADC_OFR2_OFFSET2_CH_3          (0x08UL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x20000000 */
#define ADC_OFR2_OFFSET2_CH_4          (0x10UL << ADC_OFR2_OFFSET2_CH_Pos)     /*!< 0x40000000 */

#define ADC_OFR2_OFFSET2_EN_Pos        (31U)
#define ADC_OFR2_OFFSET2_EN_Msk        (0x1UL << ADC_OFR2_OFFSET2_EN_Pos)      /*!< 0x80000000 */
#define ADC_OFR2_OFFSET2_EN            ADC_OFR2_OFFSET2_EN_Msk                 /*!< ADC offset number 2 enable */

/********************  Bit definition for ADC_OFR3 register  ******************/
#define ADC_OFR3_OFFSET3_Pos           (0U)
#define ADC_OFR3_OFFSET3_Msk           (0xFFFUL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000FFF */
#define ADC_OFR3_OFFSET3               ADC_OFR3_OFFSET3_Msk                    /*!< ADC offset number 3 offset level */
#define ADC_OFR3_OFFSET3_0             (0x001UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000001 */
#define ADC_OFR3_OFFSET3_1             (0x002UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000002 */
#define ADC_OFR3_OFFSET3_2             (0x004UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000004 */
#define ADC_OFR3_OFFSET3_3             (0x008UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000008 */
#define ADC_OFR3_OFFSET3_4             (0x010UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000010 */
#define ADC_OFR3_OFFSET3_5             (0x020UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000020 */
#define ADC_OFR3_OFFSET3_6             (0x040UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000040 */
#define ADC_OFR3_OFFSET3_7             (0x080UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000080 */
#define ADC_OFR3_OFFSET3_8             (0x100UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000100 */
#define ADC_OFR3_OFFSET3_9             (0x200UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000200 */
#define ADC_OFR3_OFFSET3_10            (0x400UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000400 */
#define ADC_OFR3_OFFSET3_11            (0x800UL << ADC_OFR3_OFFSET3_Pos)       /*!< 0x00000800 */

#define ADC_OFR3_OFFSET3_CH_Pos        (26U)
#define ADC_OFR3_OFFSET3_CH_Msk        (0x1FUL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x7C000000 */
#define ADC_OFR3_OFFSET3_CH            ADC_OFR3_OFFSET3_CH_Msk                 /*!< ADC offset number 3 channel selection */
#define ADC_OFR3_OFFSET3_CH_0          (0x01UL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x04000000 */
#define ADC_OFR3_OFFSET3_CH_1          (0x02UL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x08000000 */
#define ADC_OFR3_OFFSET3_CH_2          (0x04UL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x10000000 */
#define ADC_OFR3_OFFSET3_CH_3          (0x08UL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x20000000 */
#define ADC_OFR3_OFFSET3_CH_4          (0x10UL << ADC_OFR3_OFFSET3_CH_Pos)     /*!< 0x40000000 */

#define ADC_OFR3_OFFSET3_EN_Pos        (31U)
#define ADC_OFR3_OFFSET3_EN_Msk        (0x1UL << ADC_OFR3_OFFSET3_EN_Pos)      /*!< 0x80000000 */
#define ADC_OFR3_OFFSET3_EN            ADC_OFR3_OFFSET3_EN_Msk                 /*!< ADC offset number 3 enable */

/********************  Bit definition for ADC_OFR4 register  ******************/
#define ADC_OFR4_OFFSET4_Pos           (0U)
#define ADC_OFR4_OFFSET4_Msk           (0xFFFUL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000FFF */
#define ADC_OFR4_OFFSET4               ADC_OFR4_OFFSET4_Msk                    /*!< ADC offset number 4 offset level */
#define ADC_OFR4_OFFSET4_0             (0x001UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000001 */
#define ADC_OFR4_OFFSET4_1             (0x002UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000002 */
#define ADC_OFR4_OFFSET4_2             (0x004UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000004 */
#define ADC_OFR4_OFFSET4_3             (0x008UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000008 */
#define ADC_OFR4_OFFSET4_4             (0x010UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000010 */
#define ADC_OFR4_OFFSET4_5             (0x020UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000020 */
#define ADC_OFR4_OFFSET4_6             (0x040UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000040 */
#define ADC_OFR4_OFFSET4_7             (0x080UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000080 */
#define ADC_OFR4_OFFSET4_8             (0x100UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000100 */
#define ADC_OFR4_OFFSET4_9             (0x200UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000200 */
#define ADC_OFR4_OFFSET4_10            (0x400UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000400 */
#define ADC_OFR4_OFFSET4_11            (0x800UL << ADC_OFR4_OFFSET4_Pos)       /*!< 0x00000800 */

#define ADC_OFR4_OFFSET4_CH_Pos        (26U)
#define ADC_OFR4_OFFSET4_CH_Msk        (0x1FUL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x7C000000 */
#define ADC_OFR4_OFFSET4_CH            ADC_OFR4_OFFSET4_CH_Msk                 /*!< ADC offset number 4 channel selection */
#define ADC_OFR4_OFFSET4_CH_0          (0x01UL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x04000000 */
#define ADC_OFR4_OFFSET4_CH_1          (0x02UL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x08000000 */
#define ADC_OFR4_OFFSET4_CH_2          (0x04UL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x10000000 */
#define ADC_OFR4_OFFSET4_CH_3          (0x08UL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x20000000 */
#define ADC_OFR4_OFFSET4_CH_4          (0x10UL << ADC_OFR4_OFFSET4_CH_Pos)     /*!< 0x40000000 */

#define ADC_OFR4_OFFSET4_EN_Pos        (31U)
#define ADC_OFR4_OFFSET4_EN_Msk        (0x1UL << ADC_OFR4_OFFSET4_EN_Pos)      /*!< 0x80000000 */
#define ADC_OFR4_OFFSET4_EN            ADC_OFR4_OFFSET4_EN_Msk                 /*!< ADC offset number 4 enable */

/********************  Bit definition for ADC_JDR1 register  ******************/
#define ADC_JDR1_JDATA_Pos             (0U)
#define ADC_JDR1_JDATA_Msk             (0xFFFFUL << ADC_JDR1_JDATA_Pos)        /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                 ADC_JDR1_JDATA_Msk                      /*!< ADC group injected sequencer rank 1 conversion data */
#define ADC_JDR1_JDATA_0               (0x0001UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000001 */
#define ADC_JDR1_JDATA_1               (0x0002UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000002 */
#define ADC_JDR1_JDATA_2               (0x0004UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000004 */
#define ADC_JDR1_JDATA_3               (0x0008UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000008 */
#define ADC_JDR1_JDATA_4               (0x0010UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000010 */
#define ADC_JDR1_JDATA_5               (0x0020UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000020 */
#define ADC_JDR1_JDATA_6               (0x0040UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000040 */
#define ADC_JDR1_JDATA_7               (0x0080UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000080 */
#define ADC_JDR1_JDATA_8               (0x0100UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000100 */
#define ADC_JDR1_JDATA_9               (0x0200UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000200 */
#define ADC_JDR1_JDATA_10              (0x0400UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000400 */
#define ADC_JDR1_JDATA_11              (0x0800UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00000800 */
#define ADC_JDR1_JDATA_12              (0x1000UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00001000 */
#define ADC_JDR1_JDATA_13              (0x2000UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00002000 */
#define ADC_JDR1_JDATA_14              (0x4000UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00004000 */
#define ADC_JDR1_JDATA_15              (0x8000UL << ADC_JDR1_JDATA_Pos)        /*!< 0x00008000 */

/********************  Bit definition for ADC_JDR2 register  ******************/
#define ADC_JDR2_JDATA_Pos             (0U)
#define ADC_JDR2_JDATA_Msk             (0xFFFFUL << ADC_JDR2_JDATA_Pos)        /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                 ADC_JDR2_JDATA_Msk                      /*!< ADC group injected sequencer rank 2 conversion data */
#define ADC_JDR2_JDATA_0               (0x0001UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000001 */
#define ADC_JDR2_JDATA_1               (0x0002UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000002 */
#define ADC_JDR2_JDATA_2               (0x0004UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000004 */
#define ADC_JDR2_JDATA_3               (0x0008UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000008 */
#define ADC_JDR2_JDATA_4               (0x0010UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000010 */
#define ADC_JDR2_JDATA_5               (0x0020UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000020 */
#define ADC_JDR2_JDATA_6               (0x0040UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000040 */
#define ADC_JDR2_JDATA_7               (0x0080UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000080 */
#define ADC_JDR2_JDATA_8               (0x0100UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000100 */
#define ADC_JDR2_JDATA_9               (0x0200UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000200 */
#define ADC_JDR2_JDATA_10              (0x0400UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000400 */
#define ADC_JDR2_JDATA_11              (0x0800UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00000800 */
#define ADC_JDR2_JDATA_12              (0x1000UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00001000 */
#define ADC_JDR2_JDATA_13              (0x2000UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00002000 */
#define ADC_JDR2_JDATA_14              (0x4000UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00004000 */
#define ADC_JDR2_JDATA_15              (0x8000UL << ADC_JDR2_JDATA_Pos)        /*!< 0x00008000 */

/********************  Bit definition for ADC_JDR3 register  ******************/
#define ADC_JDR3_JDATA_Pos             (0U)
#define ADC_JDR3_JDATA_Msk             (0xFFFFUL << ADC_JDR3_JDATA_Pos)        /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                 ADC_JDR3_JDATA_Msk                      /*!< ADC group injected sequencer rank 3 conversion data */
#define ADC_JDR3_JDATA_0               (0x0001UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000001 */
#define ADC_JDR3_JDATA_1               (0x0002UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000002 */
#define ADC_JDR3_JDATA_2               (0x0004UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000004 */
#define ADC_JDR3_JDATA_3               (0x0008UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000008 */
#define ADC_JDR3_JDATA_4               (0x0010UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000010 */
#define ADC_JDR3_JDATA_5               (0x0020UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000020 */
#define ADC_JDR3_JDATA_6               (0x0040UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000040 */
#define ADC_JDR3_JDATA_7               (0x0080UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000080 */
#define ADC_JDR3_JDATA_8               (0x0100UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000100 */
#define ADC_JDR3_JDATA_9               (0x0200UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000200 */
#define ADC_JDR3_JDATA_10              (0x0400UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000400 */
#define ADC_JDR3_JDATA_11              (0x0800UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00000800 */
#define ADC_JDR3_JDATA_12              (0x1000UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00001000 */
#define ADC_JDR3_JDATA_13              (0x2000UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00002000 */
#define ADC_JDR3_JDATA_14              (0x4000UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00004000 */
#define ADC_JDR3_JDATA_15              (0x8000UL << ADC_JDR3_JDATA_Pos)        /*!< 0x00008000 */

/********************  Bit definition for ADC_JDR4 register  ******************/
#define ADC_JDR4_JDATA_Pos             (0U)
#define ADC_JDR4_JDATA_Msk             (0xFFFFUL << ADC_JDR4_JDATA_Pos)        /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                 ADC_JDR4_JDATA_Msk                      /*!< ADC group injected sequencer rank 4 conversion data */
#define ADC_JDR4_JDATA_0               (0x0001UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000001 */
#define ADC_JDR4_JDATA_1               (0x0002UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000002 */
#define ADC_JDR4_JDATA_2               (0x0004UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000004 */
#define ADC_JDR4_JDATA_3               (0x0008UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000008 */
#define ADC_JDR4_JDATA_4               (0x0010UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000010 */
#define ADC_JDR4_JDATA_5               (0x0020UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000020 */
#define ADC_JDR4_JDATA_6               (0x0040UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000040 */
#define ADC_JDR4_JDATA_7               (0x0080UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000080 */
#define ADC_JDR4_JDATA_8               (0x0100UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000100 */
#define ADC_JDR4_JDATA_9               (0x0200UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000200 */
#define ADC_JDR4_JDATA_10              (0x0400UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000400 */
#define ADC_JDR4_JDATA_11              (0x0800UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00000800 */
#define ADC_JDR4_JDATA_12              (0x1000UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00001000 */
#define ADC_JDR4_JDATA_13              (0x2000UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00002000 */
#define ADC_JDR4_JDATA_14              (0x4000UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00004000 */
#define ADC_JDR4_JDATA_15              (0x8000UL << ADC_JDR4_JDATA_Pos)        /*!< 0x00008000 */

/********************  Bit definition for ADC_AWD2CR register  ****************/
#define ADC_AWD2CR_AWD2CH_Pos          (0U)
#define ADC_AWD2CR_AWD2CH_Msk          (0x7FFFFUL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x0007FFFF */
#define ADC_AWD2CR_AWD2CH              ADC_AWD2CR_AWD2CH_Msk                   /*!< ADC analog watchdog 2 monitored channel selection */
#define ADC_AWD2CR_AWD2CH_0            (0x00001UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000001 */
#define ADC_AWD2CR_AWD2CH_1            (0x00002UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000002 */
#define ADC_AWD2CR_AWD2CH_2            (0x00004UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000004 */
#define ADC_AWD2CR_AWD2CH_3            (0x00008UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000008 */
#define ADC_AWD2CR_AWD2CH_4            (0x00010UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000010 */
#define ADC_AWD2CR_AWD2CH_5            (0x00020UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000020 */
#define ADC_AWD2CR_AWD2CH_6            (0x00040UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000040 */
#define ADC_AWD2CR_AWD2CH_7            (0x00080UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000080 */
#define ADC_AWD2CR_AWD2CH_8            (0x00100UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000100 */
#define ADC_AWD2CR_AWD2CH_9            (0x00200UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000200 */
#define ADC_AWD2CR_AWD2CH_10           (0x00400UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000400 */
#define ADC_AWD2CR_AWD2CH_11           (0x00800UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00000800 */
#define ADC_AWD2CR_AWD2CH_12           (0x01000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00001000 */
#define ADC_AWD2CR_AWD2CH_13           (0x02000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00002000 */
#define ADC_AWD2CR_AWD2CH_14           (0x04000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00004000 */
#define ADC_AWD2CR_AWD2CH_15           (0x08000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00008000 */
#define ADC_AWD2CR_AWD2CH_16           (0x10000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00010000 */
#define ADC_AWD2CR_AWD2CH_17           (0x20000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00020000 */
#define ADC_AWD2CR_AWD2CH_18           (0x40000UL << ADC_AWD2CR_AWD2CH_Pos)    /*!< 0x00040000 */

/********************  Bit definition for ADC_AWD3CR register  ****************/
#define ADC_AWD3CR_AWD3CH_Pos          (0U)
#define ADC_AWD3CR_AWD3CH_Msk          (0x7FFFFUL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x0007FFFF */
#define ADC_AWD3CR_AWD3CH              ADC_AWD3CR_AWD3CH_Msk                   /*!< ADC analog watchdog 3 monitored channel selection */
#define ADC_AWD3CR_AWD3CH_0            (0x00001UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000001 */
#define ADC_AWD3CR_AWD3CH_1            (0x00002UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000002 */
#define ADC_AWD3CR_AWD3CH_2            (0x00004UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000004 */
#define ADC_AWD3CR_AWD3CH_3            (0x00008UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000008 */
#define ADC_AWD3CR_AWD3CH_4            (0x00010UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000010 */
#define ADC_AWD3CR_AWD3CH_5            (0x00020UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000020 */
#define ADC_AWD3CR_AWD3CH_6            (0x00040UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000040 */
#define ADC_AWD3CR_AWD3CH_7            (0x00080UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000080 */
#define ADC_AWD3CR_AWD3CH_8            (0x00100UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000100 */
#define ADC_AWD3CR_AWD3CH_9            (0x00200UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000200 */
#define ADC_AWD3CR_AWD3CH_10           (0x00400UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000400 */
#define ADC_AWD3CR_AWD3CH_11           (0x00800UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00000800 */
#define ADC_AWD3CR_AWD3CH_12           (0x01000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00001000 */
#define ADC_AWD3CR_AWD3CH_13           (0x02000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00002000 */
#define ADC_AWD3CR_AWD3CH_14           (0x04000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00004000 */
#define ADC_AWD3CR_AWD3CH_15           (0x08000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00008000 */
#define ADC_AWD3CR_AWD3CH_16           (0x10000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00010000 */
#define ADC_AWD3CR_AWD3CH_17           (0x20000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00020000 */
#define ADC_AWD3CR_AWD3CH_18           (0x40000UL << ADC_AWD3CR_AWD3CH_Pos)    /*!< 0x00040000 */

/********************  Bit definition for ADC_DIFSEL register  ****************/
#define ADC_DIFSEL_DIFSEL_Pos          (0U)
#define ADC_DIFSEL_DIFSEL_Msk          (0x7FFFFUL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x0007FFFF */
#define ADC_DIFSEL_DIFSEL              ADC_DIFSEL_DIFSEL_Msk                   /*!< ADC channel differential or single-ended mode */
#define ADC_DIFSEL_DIFSEL_0            (0x00001UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000001 */
#define ADC_DIFSEL_DIFSEL_1            (0x00002UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000002 */
#define ADC_DIFSEL_DIFSEL_2            (0x00004UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000004 */
#define ADC_DIFSEL_DIFSEL_3            (0x00008UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000008 */
#define ADC_DIFSEL_DIFSEL_4            (0x00010UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000010 */
#define ADC_DIFSEL_DIFSEL_5            (0x00020UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000020 */
#define ADC_DIFSEL_DIFSEL_6            (0x00040UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000040 */
#define ADC_DIFSEL_DIFSEL_7            (0x00080UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000080 */
#define ADC_DIFSEL_DIFSEL_8            (0x00100UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000100 */
#define ADC_DIFSEL_DIFSEL_9            (0x00200UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000200 */
#define ADC_DIFSEL_DIFSEL_10           (0x00400UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000400 */
#define ADC_DIFSEL_DIFSEL_11           (0x00800UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00000800 */
#define ADC_DIFSEL_DIFSEL_12           (0x01000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00001000 */
#define ADC_DIFSEL_DIFSEL_13           (0x02000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00002000 */
#define ADC_DIFSEL_DIFSEL_14           (0x04000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00004000 */
#define ADC_DIFSEL_DIFSEL_15           (0x08000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00008000 */
#define ADC_DIFSEL_DIFSEL_16           (0x10000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00010000 */
#define ADC_DIFSEL_DIFSEL_17           (0x20000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00020000 */
#define ADC_DIFSEL_DIFSEL_18           (0x40000UL << ADC_DIFSEL_DIFSEL_Pos)    /*!< 0x00040000 */

/********************  Bit definition for ADC_CALFACT register  ***************/
#define ADC_CALFACT_CALFACT_S_Pos      (0U)
#define ADC_CALFACT_CALFACT_S_Msk      (0x7FUL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x0000007F */
#define ADC_CALFACT_CALFACT_S          ADC_CALFACT_CALFACT_S_Msk               /*!< ADC calibration factor in single-ended mode */
#define ADC_CALFACT_CALFACT_S_0        (0x01UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000001 */
#define ADC_CALFACT_CALFACT_S_1        (0x02UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000002 */
#define ADC_CALFACT_CALFACT_S_2        (0x04UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000004 */
#define ADC_CALFACT_CALFACT_S_3        (0x08UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000008 */
#define ADC_CALFACT_CALFACT_S_4        (0x10UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000010 */
#define ADC_CALFACT_CALFACT_S_5        (0x20UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000020 */
#define ADC_CALFACT_CALFACT_S_6        (0x40UL << ADC_CALFACT_CALFACT_S_Pos)   /*!< 0x00000040 */

#define ADC_CALFACT_CALFACT_D_Pos      (16U)
#define ADC_CALFACT_CALFACT_D_Msk      (0x7FUL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x007F0000 */
#define ADC_CALFACT_CALFACT_D          ADC_CALFACT_CALFACT_D_Msk               /*!< ADC calibration factor in differential mode */
#define ADC_CALFACT_CALFACT_D_0        (0x01UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00010000 */
#define ADC_CALFACT_CALFACT_D_1        (0x02UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00020000 */
#define ADC_CALFACT_CALFACT_D_2        (0x04UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00040000 */
#define ADC_CALFACT_CALFACT_D_3        (0x08UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00080000 */
#define ADC_CALFACT_CALFACT_D_4        (0x10UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00100000 */
#define ADC_CALFACT_CALFACT_D_5        (0x20UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00200000 */
#define ADC_CALFACT_CALFACT_D_6        (0x40UL << ADC_CALFACT_CALFACT_D_Pos)   /*!< 0x00400000 */

/*************************  ADC Common registers  *****************************/
/********************  Bit definition for ADC_CCR register  *******************/
#define ADC_CCR_CKMODE_Pos             (16U)
#define ADC_CCR_CKMODE_Msk             (0x3UL << ADC_CCR_CKMODE_Pos)           /*!< 0x00030000 */
#define ADC_CCR_CKMODE                 ADC_CCR_CKMODE_Msk                      /*!< ADC common clock source and prescaler (prescaler only for clock source synchronous) */
#define ADC_CCR_CKMODE_0               (0x1UL << ADC_CCR_CKMODE_Pos)           /*!< 0x00010000 */
#define ADC_CCR_CKMODE_1               (0x2UL << ADC_CCR_CKMODE_Pos)           /*!< 0x00020000 */

#define ADC_CCR_PRESC_Pos              (18U)
#define ADC_CCR_PRESC_Msk              (0xFUL << ADC_CCR_PRESC_Pos)            /*!< 0x003C0000 */
#define ADC_CCR_PRESC                  ADC_CCR_PRESC_Msk                       /*!< ADC common clock prescaler, only for clock source asynchronous */
#define ADC_CCR_PRESC_0                (0x1UL << ADC_CCR_PRESC_Pos)            /*!< 0x00040000 */
#define ADC_CCR_PRESC_1                (0x2UL << ADC_CCR_PRESC_Pos)            /*!< 0x00080000 */
#define ADC_CCR_PRESC_2                (0x4UL << ADC_CCR_PRESC_Pos)            /*!< 0x00100000 */
#define ADC_CCR_PRESC_3                (0x8UL << ADC_CCR_PRESC_Pos)            /*!< 0x00200000 */

#define ADC_CCR_VREFEN_Pos             (22U)
#define ADC_CCR_VREFEN_Msk             (0x1UL << ADC_CCR_VREFEN_Pos)           /*!< 0x00400000 */
#define ADC_CCR_VREFEN                 ADC_CCR_VREFEN_Msk                      /*!< ADC internal path to VrefInt enable */
#define ADC_CCR_TSEN_Pos               (23U)
#define ADC_CCR_TSEN_Msk               (0x1UL << ADC_CCR_TSEN_Pos)             /*!< 0x00800000 */
#define ADC_CCR_TSEN                   ADC_CCR_TSEN_Msk                        /*!< ADC internal path to temperature sensor enable */
#define ADC_CCR_VBATEN_Pos             (24U)
#define ADC_CCR_VBATEN_Msk             (0x1UL << ADC_CCR_VBATEN_Pos)           /*!< 0x01000000 */
#define ADC_CCR_VBATEN                 ADC_CCR_VBATEN_Msk                      /*!< ADC internal path to battery voltage enable */

#define RCC_ADC_CLK_SYS_SEL()			(RCC->CCIPR |= RCC_CCIPR_ADCSEL)

typedef struct {
	uint32_t number;
	uint32_t sampling_time;
	uint32_t sequence;
	uint32_t status;
} adc_channel_conf_t; 

typedef struct { 
	ADC_TypeDef *instance;
	adc_channel_conf_t	*channels;
	uint32_t 	numOfChannels;
	uint32_t 	numOfConversions;
} ADCx_init_t;


void ADCInit(ADCx_init_t *init_struct);