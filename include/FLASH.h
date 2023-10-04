#include <stm32l432kc.h>


/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos             (0U)
#define FLASH_ACR_LATENCY_Msk             (0x7UL << FLASH_ACR_LATENCY_Pos)     /*!< 0x00000007 */
#define FLASH_ACR_LATENCY                 FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS             (0x00000000UL)
#define FLASH_ACR_LATENCY_1WS             (0x00000001UL)
#define FLASH_ACR_LATENCY_2WS             (0x00000002UL)
#define FLASH_ACR_LATENCY_3WS             (0x00000003UL)
#define FLASH_ACR_LATENCY_4WS             (0x00000004UL)
#define FLASH_ACR_PRFTEN_Pos              (8U)
#define FLASH_ACR_PRFTEN_Msk              (0x1UL << FLASH_ACR_PRFTEN_Pos)      /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN                  FLASH_ACR_PRFTEN_Msk
#define FLASH_ACR_ICEN_Pos                (9U)
#define FLASH_ACR_ICEN_Msk                (0x1UL << FLASH_ACR_ICEN_Pos)        /*!< 0x00000200 */
#define FLASH_ACR_ICEN                    FLASH_ACR_ICEN_Msk
#define FLASH_ACR_DCEN_Pos                (10U)
#define FLASH_ACR_DCEN_Msk                (0x1UL << FLASH_ACR_DCEN_Pos)        /*!< 0x00000400 */
#define FLASH_ACR_DCEN                    FLASH_ACR_DCEN_Msk
#define FLASH_ACR_ICRST_Pos               (11U)
#define FLASH_ACR_ICRST_Msk               (0x1UL << FLASH_ACR_ICRST_Pos)       /*!< 0x00000800 */
#define FLASH_ACR_ICRST                   FLASH_ACR_ICRST_Msk
#define FLASH_ACR_DCRST_Pos               (12U)
#define FLASH_ACR_DCRST_Msk               (0x1UL << FLASH_ACR_DCRST_Pos)       /*!< 0x00001000 */
#define FLASH_ACR_DCRST                   FLASH_ACR_DCRST_Msk
#define FLASH_ACR_RUN_PD_Pos              (13U)
#define FLASH_ACR_RUN_PD_Msk              (0x1UL << FLASH_ACR_RUN_PD_Pos)      /*!< 0x00002000 */
#define FLASH_ACR_RUN_PD                  FLASH_ACR_RUN_PD_Msk                 /*!< Flash power down mode during run */
#define FLASH_ACR_SLEEP_PD_Pos            (14U)
#define FLASH_ACR_SLEEP_PD_Msk            (0x1UL << FLASH_ACR_SLEEP_PD_Pos)    /*!< 0x00004000 */
#define FLASH_ACR_SLEEP_PD                FLASH_ACR_SLEEP_PD_Msk               /*!< Flash power down mode during sleep */

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos                  (0U)
#define FLASH_SR_EOP_Msk                  (0x1UL << FLASH_SR_EOP_Pos)          /*!< 0x00000001 */
#define FLASH_SR_EOP                      FLASH_SR_EOP_Msk
#define FLASH_SR_OPERR_Pos                (1U)
#define FLASH_SR_OPERR_Msk                (0x1UL << FLASH_SR_OPERR_Pos)        /*!< 0x00000002 */
#define FLASH_SR_OPERR                    FLASH_SR_OPERR_Msk
#define FLASH_SR_PROGERR_Pos              (3U)
#define FLASH_SR_PROGERR_Msk              (0x1UL << FLASH_SR_PROGERR_Pos)      /*!< 0x00000008 */
#define FLASH_SR_PROGERR                  FLASH_SR_PROGERR_Msk
#define FLASH_SR_WRPERR_Pos               (4U)
#define FLASH_SR_WRPERR_Msk               (0x1UL << FLASH_SR_WRPERR_Pos)       /*!< 0x00000010 */
#define FLASH_SR_WRPERR                   FLASH_SR_WRPERR_Msk
#define FLASH_SR_PGAERR_Pos               (5U)
#define FLASH_SR_PGAERR_Msk               (0x1UL << FLASH_SR_PGAERR_Pos)       /*!< 0x00000020 */
#define FLASH_SR_PGAERR                   FLASH_SR_PGAERR_Msk
#define FLASH_SR_SIZERR_Pos               (6U)
#define FLASH_SR_SIZERR_Msk               (0x1UL << FLASH_SR_SIZERR_Pos)       /*!< 0x00000040 */
#define FLASH_SR_SIZERR                   FLASH_SR_SIZERR_Msk
#define FLASH_SR_PGSERR_Pos               (7U)
#define FLASH_SR_PGSERR_Msk               (0x1UL << FLASH_SR_PGSERR_Pos)       /*!< 0x00000080 */
#define FLASH_SR_PGSERR                   FLASH_SR_PGSERR_Msk
#define FLASH_SR_MISERR_Pos               (8U)
#define FLASH_SR_MISERR_Msk               (0x1UL << FLASH_SR_MISERR_Pos)       /*!< 0x00000100 */
#define FLASH_SR_MISERR                   FLASH_SR_MISERR_Msk
#define FLASH_SR_FASTERR_Pos              (9U)
#define FLASH_SR_FASTERR_Msk              (0x1UL << FLASH_SR_FASTERR_Pos)      /*!< 0x00000200 */
#define FLASH_SR_FASTERR                  FLASH_SR_FASTERR_Msk
#define FLASH_SR_RDERR_Pos                (14U)
#define FLASH_SR_RDERR_Msk                (0x1UL << FLASH_SR_RDERR_Pos)        /*!< 0x00004000 */
#define FLASH_SR_RDERR                    FLASH_SR_RDERR_Msk
#define FLASH_SR_OPTVERR_Pos              (15U)
#define FLASH_SR_OPTVERR_Msk              (0x1UL << FLASH_SR_OPTVERR_Pos)      /*!< 0x00008000 */
#define FLASH_SR_OPTVERR                  FLASH_SR_OPTVERR_Msk
#define FLASH_SR_BSY_Pos                  (16U)
#define FLASH_SR_BSY_Msk                  (0x1UL << FLASH_SR_BSY_Pos)          /*!< 0x00010000 */
#define FLASH_SR_BSY                      FLASH_SR_BSY_Msk
#define FLASH_SR_PEMPTY_Pos               (17U)
#define FLASH_SR_PEMPTY_Msk               (0x1UL << FLASH_SR_PEMPTY_Pos)       /*!< 0x00020000 */
#define FLASH_SR_PEMPTY                   FLASH_SR_PEMPTY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                   (0U)
#define FLASH_CR_PG_Msk                   (0x1UL << FLASH_CR_PG_Pos)           /*!< 0x00000001 */
#define FLASH_CR_PG                       FLASH_CR_PG_Msk
#define FLASH_CR_PER_Pos                  (1U)
#define FLASH_CR_PER_Msk                  (0x1UL << FLASH_CR_PER_Pos)          /*!< 0x00000002 */
#define FLASH_CR_PER                      FLASH_CR_PER_Msk
#define FLASH_CR_MER1_Pos                 (2U)
#define FLASH_CR_MER1_Msk                 (0x1UL << FLASH_CR_MER1_Pos)         /*!< 0x00000004 */
#define FLASH_CR_MER1                     FLASH_CR_MER1_Msk
#define FLASH_CR_PNB_Pos                  (3U)
#define FLASH_CR_PNB_Msk                  (0x7FUL << FLASH_CR_PNB_Pos)         /*!< 0x000003F8 */
#define FLASH_CR_PNB                      FLASH_CR_PNB_Msk
#define FLASH_CR_STRT_Pos                 (16U)
#define FLASH_CR_STRT_Msk                 (0x1UL << FLASH_CR_STRT_Pos)         /*!< 0x00010000 */
#define FLASH_CR_STRT                     FLASH_CR_STRT_Msk
#define FLASH_CR_OPTSTRT_Pos              (17U)
#define FLASH_CR_OPTSTRT_Msk              (0x1UL << FLASH_CR_OPTSTRT_Pos)      /*!< 0x00020000 */
#define FLASH_CR_OPTSTRT                  FLASH_CR_OPTSTRT_Msk
#define FLASH_CR_FSTPG_Pos                (18U)
#define FLASH_CR_FSTPG_Msk                (0x1UL << FLASH_CR_FSTPG_Pos)        /*!< 0x00040000 */
#define FLASH_CR_FSTPG                    FLASH_CR_FSTPG_Msk
#define FLASH_CR_EOPIE_Pos                (24U)
#define FLASH_CR_EOPIE_Msk                (0x1UL << FLASH_CR_EOPIE_Pos)        /*!< 0x01000000 */
#define FLASH_CR_EOPIE                    FLASH_CR_EOPIE_Msk
#define FLASH_CR_ERRIE_Pos                (25U)
#define FLASH_CR_ERRIE_Msk                (0x1UL << FLASH_CR_ERRIE_Pos)        /*!< 0x02000000 */
#define FLASH_CR_ERRIE                    FLASH_CR_ERRIE_Msk
#define FLASH_CR_RDERRIE_Pos              (26U)
#define FLASH_CR_RDERRIE_Msk              (0x1UL << FLASH_CR_RDERRIE_Pos)      /*!< 0x04000000 */
#define FLASH_CR_RDERRIE                  FLASH_CR_RDERRIE_Msk
#define FLASH_CR_OBL_LAUNCH_Pos           (27U)
#define FLASH_CR_OBL_LAUNCH_Msk           (0x1UL << FLASH_CR_OBL_LAUNCH_Pos)   /*!< 0x08000000 */
#define FLASH_CR_OBL_LAUNCH               FLASH_CR_OBL_LAUNCH_Msk
#define FLASH_CR_OPTLOCK_Pos              (30U)
#define FLASH_CR_OPTLOCK_Msk              (0x1UL << FLASH_CR_OPTLOCK_Pos)      /*!< 0x40000000 */
#define FLASH_CR_OPTLOCK                  FLASH_CR_OPTLOCK_Msk
#define FLASH_CR_LOCK_Pos                 (31U)
#define FLASH_CR_LOCK_Msk                 (0x1UL << FLASH_CR_LOCK_Pos)         /*!< 0x80000000 */
#define FLASH_CR_LOCK                     FLASH_CR_LOCK_Msk

/*******************  Bits definition for FLASH_ECCR register  ***************/
#define FLASH_ECCR_ADDR_ECC_Pos           (0U)
#define FLASH_ECCR_ADDR_ECC_Msk           (0x7FFFFUL << FLASH_ECCR_ADDR_ECC_Pos) /*!< 0x0007FFFF */
#define FLASH_ECCR_ADDR_ECC               FLASH_ECCR_ADDR_ECC_Msk
#define FLASH_ECCR_SYSF_ECC_Pos           (20U)
#define FLASH_ECCR_SYSF_ECC_Msk           (0x1UL << FLASH_ECCR_SYSF_ECC_Pos)   /*!< 0x00100000 */
#define FLASH_ECCR_SYSF_ECC               FLASH_ECCR_SYSF_ECC_Msk
#define FLASH_ECCR_ECCIE_Pos              (24U)
#define FLASH_ECCR_ECCIE_Msk              (0x1UL << FLASH_ECCR_ECCIE_Pos)      /*!< 0x01000000 */
#define FLASH_ECCR_ECCIE                  FLASH_ECCR_ECCIE_Msk
#define FLASH_ECCR_ECCC_Pos               (30U)
#define FLASH_ECCR_ECCC_Msk               (0x1UL << FLASH_ECCR_ECCC_Pos)       /*!< 0x40000000 */
#define FLASH_ECCR_ECCC                   FLASH_ECCR_ECCC_Msk
#define FLASH_ECCR_ECCD_Pos               (31U)
#define FLASH_ECCR_ECCD_Msk               (0x1UL << FLASH_ECCR_ECCD_Pos)       /*!< 0x80000000 */
#define FLASH_ECCR_ECCD                   FLASH_ECCR_ECCD_Msk

/*******************  Bits definition for FLASH_OPTR register  ***************/
#define FLASH_OPTR_RDP_Pos                (0U)
#define FLASH_OPTR_RDP_Msk                (0xFFUL << FLASH_OPTR_RDP_Pos)       /*!< 0x000000FF */
#define FLASH_OPTR_RDP                    FLASH_OPTR_RDP_Msk
#define FLASH_OPTR_BOR_LEV_Pos            (8U)
#define FLASH_OPTR_BOR_LEV_Msk            (0x7UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000700 */
#define FLASH_OPTR_BOR_LEV                FLASH_OPTR_BOR_LEV_Msk
#define FLASH_OPTR_BOR_LEV_0              (0x0UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000000 */
#define FLASH_OPTR_BOR_LEV_1              (0x1UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000100 */
#define FLASH_OPTR_BOR_LEV_2              (0x2UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000200 */
#define FLASH_OPTR_BOR_LEV_3              (0x3UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000300 */
#define FLASH_OPTR_BOR_LEV_4              (0x4UL << FLASH_OPTR_BOR_LEV_Pos)    /*!< 0x00000400 */
#define FLASH_OPTR_nRST_STOP_Pos          (12U)
#define FLASH_OPTR_nRST_STOP_Msk          (0x1UL << FLASH_OPTR_nRST_STOP_Pos)  /*!< 0x00001000 */
#define FLASH_OPTR_nRST_STOP              FLASH_OPTR_nRST_STOP_Msk
#define FLASH_OPTR_nRST_STDBY_Pos         (13U)
#define FLASH_OPTR_nRST_STDBY_Msk         (0x1UL << FLASH_OPTR_nRST_STDBY_Pos) /*!< 0x00002000 */
#define FLASH_OPTR_nRST_STDBY             FLASH_OPTR_nRST_STDBY_Msk
#define FLASH_OPTR_nRST_SHDW_Pos          (14U)
#define FLASH_OPTR_nRST_SHDW_Msk          (0x1UL << FLASH_OPTR_nRST_SHDW_Pos)  /*!< 0x00004000 */
#define FLASH_OPTR_nRST_SHDW              FLASH_OPTR_nRST_SHDW_Msk
#define FLASH_OPTR_IWDG_SW_Pos            (16U)
#define FLASH_OPTR_IWDG_SW_Msk            (0x1UL << FLASH_OPTR_IWDG_SW_Pos)    /*!< 0x00010000 */
#define FLASH_OPTR_IWDG_SW                FLASH_OPTR_IWDG_SW_Msk
#define FLASH_OPTR_IWDG_STOP_Pos          (17U)
#define FLASH_OPTR_IWDG_STOP_Msk          (0x1UL << FLASH_OPTR_IWDG_STOP_Pos)  /*!< 0x00020000 */
#define FLASH_OPTR_IWDG_STOP              FLASH_OPTR_IWDG_STOP_Msk
#define FLASH_OPTR_IWDG_STDBY_Pos         (18U)
#define FLASH_OPTR_IWDG_STDBY_Msk         (0x1UL << FLASH_OPTR_IWDG_STDBY_Pos) /*!< 0x00040000 */
#define FLASH_OPTR_IWDG_STDBY             FLASH_OPTR_IWDG_STDBY_Msk
#define FLASH_OPTR_WWDG_SW_Pos            (19U)
#define FLASH_OPTR_WWDG_SW_Msk            (0x1UL << FLASH_OPTR_WWDG_SW_Pos)    /*!< 0x00080000 */
#define FLASH_OPTR_WWDG_SW                FLASH_OPTR_WWDG_SW_Msk
#define FLASH_OPTR_nBOOT1_Pos             (23U)
#define FLASH_OPTR_nBOOT1_Msk             (0x1UL << FLASH_OPTR_nBOOT1_Pos)     /*!< 0x00800000 */
#define FLASH_OPTR_nBOOT1                 FLASH_OPTR_nBOOT1_Msk
#define FLASH_OPTR_SRAM2_PE_Pos           (24U)
#define FLASH_OPTR_SRAM2_PE_Msk           (0x1UL << FLASH_OPTR_SRAM2_PE_Pos)   /*!< 0x01000000 */
#define FLASH_OPTR_SRAM2_PE               FLASH_OPTR_SRAM2_PE_Msk
#define FLASH_OPTR_SRAM2_RST_Pos          (25U)
#define FLASH_OPTR_SRAM2_RST_Msk          (0x1UL << FLASH_OPTR_SRAM2_RST_Pos)  /*!< 0x02000000 */
#define FLASH_OPTR_SRAM2_RST              FLASH_OPTR_SRAM2_RST_Msk
#define FLASH_OPTR_nSWBOOT0_Pos           (26U)
#define FLASH_OPTR_nSWBOOT0_Msk           (0x1UL << FLASH_OPTR_nSWBOOT0_Pos)   /*!< 0x04000000 */
#define FLASH_OPTR_nSWBOOT0               FLASH_OPTR_nSWBOOT0_Msk
#define FLASH_OPTR_nBOOT0_Pos             (27U)
#define FLASH_OPTR_nBOOT0_Msk             (0x1UL << FLASH_OPTR_nBOOT0_Pos)     /*!< 0x08000000 */
#define FLASH_OPTR_nBOOT0                 FLASH_OPTR_nBOOT0_Msk

/******************  Bits definition for FLASH_PCROP1SR register  **********/
#define FLASH_PCROP1SR_PCROP1_STRT_Pos    (0U)
#define FLASH_PCROP1SR_PCROP1_STRT_Msk    (0x7FFFUL << FLASH_PCROP1SR_PCROP1_STRT_Pos) /*!< 0x00007FFF */
#define FLASH_PCROP1SR_PCROP1_STRT        FLASH_PCROP1SR_PCROP1_STRT_Msk

/******************  Bits definition for FLASH_PCROP1ER register  ***********/
#define FLASH_PCROP1ER_PCROP1_END_Pos     (0U)
#define FLASH_PCROP1ER_PCROP1_END_Msk     (0x7FFFUL << FLASH_PCROP1ER_PCROP1_END_Pos) /*!< 0x00007FFF */
#define FLASH_PCROP1ER_PCROP1_END         FLASH_PCROP1ER_PCROP1_END_Msk
#define FLASH_PCROP1ER_PCROP_RDP_Pos      (31U)
#define FLASH_PCROP1ER_PCROP_RDP_Msk      (0x1UL << FLASH_PCROP1ER_PCROP_RDP_Pos) /*!< 0x80000000 */
#define FLASH_PCROP1ER_PCROP_RDP          FLASH_PCROP1ER_PCROP_RDP_Msk

/******************  Bits definition for FLASH_WRP1AR register  ***************/
#define FLASH_WRP1AR_WRP1A_STRT_Pos       (0U)
#define FLASH_WRP1AR_WRP1A_STRT_Msk       (0x7FUL << FLASH_WRP1AR_WRP1A_STRT_Pos) /*!< 0x0000007F */
#define FLASH_WRP1AR_WRP1A_STRT           FLASH_WRP1AR_WRP1A_STRT_Msk
#define FLASH_WRP1AR_WRP1A_END_Pos        (16U)
#define FLASH_WRP1AR_WRP1A_END_Msk        (0x7FUL << FLASH_WRP1AR_WRP1A_END_Pos)  /*!< 0x007F0000 */
#define FLASH_WRP1AR_WRP1A_END            FLASH_WRP1AR_WRP1A_END_Msk

/******************  Bits definition for FLASH_WRPB1R register  ***************/
#define FLASH_WRP1BR_WRP1B_STRT_Pos       (0U)
#define FLASH_WRP1BR_WRP1B_STRT_Msk       (0x7FUL << FLASH_WRP1BR_WRP1B_STRT_Pos) /*!< 0x0000007F */
#define FLASH_WRP1BR_WRP1B_STRT           FLASH_WRP1BR_WRP1B_STRT_Msk
#define FLASH_WRP1BR_WRP1B_END_Pos        (16U)
#define FLASH_WRP1BR_WRP1B_END_Msk        (0x7FUL << FLASH_WRP1BR_WRP1B_END_Pos)  /*!< 0x007F0000 */
#define FLASH_WRP1BR_WRP1B_END            FLASH_WRP1BR_WRP1B_END_Msk

#ifdef __cplusplus
extern "C" {
#endif                                      
	void FLASH_SET_LATENCY(uint32_t latency);
#ifdef __cplusplus
}
#endif                                      