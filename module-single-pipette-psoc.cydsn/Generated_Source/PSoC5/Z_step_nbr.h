/*******************************************************************************
* File Name: Z_step_nbr.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_Z_step_nbr_H)
#define CY_COUNTER_Z_step_nbr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Z_step_nbr_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed Z_step_nbr_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef Z_step_nbr_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* Z_step_nbr_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define Z_step_nbr_Resolution            32u
#define Z_step_nbr_UsingFixedFunction    0u
#define Z_step_nbr_ControlRegRemoved     0u
#define Z_step_nbr_COMPARE_MODE_SOFTWARE 0u
#define Z_step_nbr_CAPTURE_MODE_SOFTWARE 0u
#define Z_step_nbr_RunModeUsed           1u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint32 CounterUdb;         /* Current Counter Value */

    #if (!Z_step_nbr_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!Z_step_nbr_ControlRegRemoved) */

}Z_step_nbr_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    Z_step_nbr_Start(void) ;
void    Z_step_nbr_Stop(void) ;
void    Z_step_nbr_SetInterruptMode(uint8 interruptsMask) ;
uint8   Z_step_nbr_ReadStatusRegister(void) ;
#define Z_step_nbr_GetInterruptSource() Z_step_nbr_ReadStatusRegister()
#if(!Z_step_nbr_ControlRegRemoved)
    uint8   Z_step_nbr_ReadControlRegister(void) ;
    void    Z_step_nbr_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Z_step_nbr_ControlRegRemoved) */
#if (!(Z_step_nbr_UsingFixedFunction && (CY_PSOC5A)))
    void    Z_step_nbr_WriteCounter(uint32 counter) \
            ; 
#endif /* (!(Z_step_nbr_UsingFixedFunction && (CY_PSOC5A))) */
uint32  Z_step_nbr_ReadCounter(void) ;
uint32  Z_step_nbr_ReadCapture(void) ;
void    Z_step_nbr_WritePeriod(uint32 period) \
    ;
uint32  Z_step_nbr_ReadPeriod( void ) ;
#if (!Z_step_nbr_UsingFixedFunction)
    void    Z_step_nbr_WriteCompare(uint32 compare) \
        ;
    uint32  Z_step_nbr_ReadCompare( void ) \
        ;
#endif /* (!Z_step_nbr_UsingFixedFunction) */

#if (Z_step_nbr_COMPARE_MODE_SOFTWARE)
    void    Z_step_nbr_SetCompareMode(uint8 compareMode) ;
#endif /* (Z_step_nbr_COMPARE_MODE_SOFTWARE) */
#if (Z_step_nbr_CAPTURE_MODE_SOFTWARE)
    void    Z_step_nbr_SetCaptureMode(uint8 captureMode) ;
#endif /* (Z_step_nbr_CAPTURE_MODE_SOFTWARE) */
void Z_step_nbr_ClearFIFO(void)     ;
void Z_step_nbr_Init(void)          ;
void Z_step_nbr_Enable(void)        ;
void Z_step_nbr_SaveConfig(void)    ;
void Z_step_nbr_RestoreConfig(void) ;
void Z_step_nbr_Sleep(void)         ;
void Z_step_nbr_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define Z_step_nbr__B_COUNTER__LESS_THAN 1
#define Z_step_nbr__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define Z_step_nbr__B_COUNTER__EQUAL 0
#define Z_step_nbr__B_COUNTER__GREATER_THAN 3
#define Z_step_nbr__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define Z_step_nbr__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define Z_step_nbr_CMP_MODE_LT 1u
#define Z_step_nbr_CMP_MODE_LTE 2u
#define Z_step_nbr_CMP_MODE_EQ 0u
#define Z_step_nbr_CMP_MODE_GT 3u
#define Z_step_nbr_CMP_MODE_GTE 4u
#define Z_step_nbr_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define Z_step_nbr__B_COUNTER__NONE 0
#define Z_step_nbr__B_COUNTER__RISING_EDGE 1
#define Z_step_nbr__B_COUNTER__FALLING_EDGE 2
#define Z_step_nbr__B_COUNTER__EITHER_EDGE 3
#define Z_step_nbr__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define Z_step_nbr_CAP_MODE_NONE 0u
#define Z_step_nbr_CAP_MODE_RISE 1u
#define Z_step_nbr_CAP_MODE_FALL 2u
#define Z_step_nbr_CAP_MODE_BOTH 3u
#define Z_step_nbr_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define Z_step_nbr_CAPTURE_MODE_CONF       0u
#define Z_step_nbr_INIT_PERIOD_VALUE       4294967295u
#define Z_step_nbr_INIT_COUNTER_VALUE      0u
#if (Z_step_nbr_UsingFixedFunction)
#define Z_step_nbr_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << Z_step_nbr_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define Z_step_nbr_INIT_COMPARE_VALUE      128u
#define Z_step_nbr_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << Z_step_nbr_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << Z_step_nbr_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Z_step_nbr_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Z_step_nbr_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Z_step_nbr_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define Z_step_nbr_DEFAULT_COMPARE_MODE    4u

#if( 0 != Z_step_nbr_CAPTURE_MODE_CONF)
    #define Z_step_nbr_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << Z_step_nbr_CTRL_CAPMODE0_SHIFT))
#else    
    #define Z_step_nbr_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != Z_step_nbr_CAPTURE_MODE_CONF) */

#endif /* (Z_step_nbr_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (Z_step_nbr_UsingFixedFunction)
    #define Z_step_nbr_STATICCOUNT_LSB     (*(reg16 *) Z_step_nbr_CounterHW__CAP0 )
    #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg16 *) Z_step_nbr_CounterHW__CAP0 )
    #define Z_step_nbr_PERIOD_LSB          (*(reg16 *) Z_step_nbr_CounterHW__PER0 )
    #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg16 *) Z_step_nbr_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define Z_step_nbr_COMPARE_LSB         (*(reg16 *) Z_step_nbr_CounterHW__CNT_CMP0 )
    #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg16 *) Z_step_nbr_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define Z_step_nbr_COUNTER_LSB         (*(reg16 *) Z_step_nbr_CounterHW__CNT_CMP0 )
    #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg16 *) Z_step_nbr_CounterHW__CNT_CMP0 )
    #define Z_step_nbr_RT1                 (*(reg8 *) Z_step_nbr_CounterHW__RT1)
    #define Z_step_nbr_RT1_PTR             ( (reg8 *) Z_step_nbr_CounterHW__RT1)
#else
    
    #if (Z_step_nbr_Resolution <= 8u) /* 8-bit Counter */
    
        #define Z_step_nbr_STATICCOUNT_LSB     (*(reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define Z_step_nbr_PERIOD_LSB          (*(reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define Z_step_nbr_COMPARE_LSB         (*(reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define Z_step_nbr_COUNTER_LSB         (*(reg8 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )  
        #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg8 *)\
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )
    
    #elif(Z_step_nbr_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define Z_step_nbr_STATICCOUNT_LSB     (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define Z_step_nbr_PERIOD_LSB          (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define Z_step_nbr_COMPARE_LSB         (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define Z_step_nbr_COUNTER_LSB         (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )  
            #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg16 *)\
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Z_step_nbr_STATICCOUNT_LSB     (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_F0_REG )
            #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_F0_REG )
            #define Z_step_nbr_PERIOD_LSB          (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_D0_REG )
            #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_D0_REG )
            #define Z_step_nbr_COMPARE_LSB         (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_D1_REG )
            #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_D1_REG )
            #define Z_step_nbr_COUNTER_LSB         (*(reg16 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_A0_REG )  
            #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg16 *)\
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(Z_step_nbr_Resolution <= 24u) /* 24-bit Counter */
        
        #define Z_step_nbr_STATICCOUNT_LSB     (*(reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define Z_step_nbr_PERIOD_LSB          (*(reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define Z_step_nbr_COMPARE_LSB         (*(reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define Z_step_nbr_COUNTER_LSB         (*(reg32 *) \
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )  
        #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg32 *)\
            Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Z_step_nbr_STATICCOUNT_LSB     (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define Z_step_nbr_PERIOD_LSB          (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define Z_step_nbr_COMPARE_LSB         (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define Z_step_nbr_COUNTER_LSB         (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )  
            #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg32 *)\
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Z_step_nbr_STATICCOUNT_LSB     (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_F0_REG )
            #define Z_step_nbr_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_F0_REG )
            #define Z_step_nbr_PERIOD_LSB          (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_D0_REG )
            #define Z_step_nbr_PERIOD_LSB_PTR      ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_D0_REG )
            #define Z_step_nbr_COMPARE_LSB         (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_D1_REG )
            #define Z_step_nbr_COMPARE_LSB_PTR     ( (reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_D1_REG )
            #define Z_step_nbr_COUNTER_LSB         (*(reg32 *) \
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_A0_REG )  
            #define Z_step_nbr_COUNTER_LSB_PTR     ( (reg32 *)\
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define Z_step_nbr_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                Z_step_nbr_CounterUDB_sC32_counterdp_u0__A0_REG )
				
    #define Z_step_nbr_AUX_CONTROLDP0 \
        (*(reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u0__DP_AUX_CTL_REG)
    
    #define Z_step_nbr_AUX_CONTROLDP0_PTR \
        ( (reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (Z_step_nbr_Resolution == 16 || Z_step_nbr_Resolution == 24 || Z_step_nbr_Resolution == 32)
       #define Z_step_nbr_AUX_CONTROLDP1 \
           (*(reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u1__DP_AUX_CTL_REG)
       #define Z_step_nbr_AUX_CONTROLDP1_PTR \
           ( (reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (Z_step_nbr_Resolution == 16 || Z_step_nbr_Resolution == 24 || Z_step_nbr_Resolution == 32) */
    
    #if (Z_step_nbr_Resolution == 24 || Z_step_nbr_Resolution == 32)
       #define Z_step_nbr_AUX_CONTROLDP2 \
           (*(reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u2__DP_AUX_CTL_REG)
       #define Z_step_nbr_AUX_CONTROLDP2_PTR \
           ( (reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (Z_step_nbr_Resolution == 24 || Z_step_nbr_Resolution == 32) */
    
    #if (Z_step_nbr_Resolution == 32)
       #define Z_step_nbr_AUX_CONTROLDP3 \
           (*(reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u3__DP_AUX_CTL_REG)
       #define Z_step_nbr_AUX_CONTROLDP3_PTR \
           ( (reg8 *) Z_step_nbr_CounterUDB_sC32_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (Z_step_nbr_Resolution == 32) */

#endif  /* (Z_step_nbr_UsingFixedFunction) */

#if (Z_step_nbr_UsingFixedFunction)
    #define Z_step_nbr_STATUS         (*(reg8 *) Z_step_nbr_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Z_step_nbr_STATUS_MASK             (*(reg8 *) Z_step_nbr_CounterHW__SR0 )
    #define Z_step_nbr_STATUS_MASK_PTR         ( (reg8 *) Z_step_nbr_CounterHW__SR0 )
    #define Z_step_nbr_CONTROL                 (*(reg8 *) Z_step_nbr_CounterHW__CFG0)
    #define Z_step_nbr_CONTROL_PTR             ( (reg8 *) Z_step_nbr_CounterHW__CFG0)
    #define Z_step_nbr_CONTROL2                (*(reg8 *) Z_step_nbr_CounterHW__CFG1)
    #define Z_step_nbr_CONTROL2_PTR            ( (reg8 *) Z_step_nbr_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Z_step_nbr_CONTROL3       (*(reg8 *) Z_step_nbr_CounterHW__CFG2)
        #define Z_step_nbr_CONTROL3_PTR   ( (reg8 *) Z_step_nbr_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Z_step_nbr_GLOBAL_ENABLE           (*(reg8 *) Z_step_nbr_CounterHW__PM_ACT_CFG)
    #define Z_step_nbr_GLOBAL_ENABLE_PTR       ( (reg8 *) Z_step_nbr_CounterHW__PM_ACT_CFG)
    #define Z_step_nbr_GLOBAL_STBY_ENABLE      (*(reg8 *) Z_step_nbr_CounterHW__PM_STBY_CFG)
    #define Z_step_nbr_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Z_step_nbr_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define Z_step_nbr_BLOCK_EN_MASK          Z_step_nbr_CounterHW__PM_ACT_MSK
    #define Z_step_nbr_BLOCK_STBY_EN_MASK     Z_step_nbr_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define Z_step_nbr_CTRL_ENABLE_SHIFT      0x00u
    #define Z_step_nbr_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define Z_step_nbr_CTRL_ENABLE            ((uint8)((uint8)0x01u << Z_step_nbr_CTRL_ENABLE_SHIFT))         
    #define Z_step_nbr_ONESHOT                ((uint8)((uint8)0x01u << Z_step_nbr_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define Z_step_nbr_CTRL_MODE_SHIFT        0x01u    
        #define Z_step_nbr_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << Z_step_nbr_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define Z_step_nbr_CTRL_MODE_SHIFT        0x00u    
        #define Z_step_nbr_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << Z_step_nbr_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define Z_step_nbr_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define Z_step_nbr_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << Z_step_nbr_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define Z_step_nbr_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define Z_step_nbr_STATUS_ZERO_INT_EN_MASK_SHIFT      (Z_step_nbr_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define Z_step_nbr_STATUS_ZERO            ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define Z_step_nbr_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)Z_step_nbr_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Z_step_nbr_RT1_SHIFT            0x04u
    #define Z_step_nbr_RT1_MASK             ((uint8)((uint8)0x03u << Z_step_nbr_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define Z_step_nbr_SYNC                 ((uint8)((uint8)0x03u << Z_step_nbr_RT1_SHIFT))
    #define Z_step_nbr_SYNCDSI_SHIFT        0x00u
    #define Z_step_nbr_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << Z_step_nbr_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define Z_step_nbr_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << Z_step_nbr_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !Z_step_nbr_UsingFixedFunction */
    #define Z_step_nbr_STATUS               (* (reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Z_step_nbr_STATUS_PTR           (  (reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Z_step_nbr_STATUS_MASK          (* (reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Z_step_nbr_STATUS_MASK_PTR      (  (reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Z_step_nbr_STATUS_AUX_CTRL      (*(reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Z_step_nbr_STATUS_AUX_CTRL_PTR  ( (reg8 *) Z_step_nbr_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Z_step_nbr_CONTROL              (* (reg8 *) Z_step_nbr_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define Z_step_nbr_CONTROL_PTR          (  (reg8 *) Z_step_nbr_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define Z_step_nbr_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define Z_step_nbr_CTRL_CMPMODE_MASK      0x07u 
    #define Z_step_nbr_CTRL_CAPMODE_MASK      0x03u  
    #define Z_step_nbr_CTRL_RESET             ((uint8)((uint8)0x01u << Z_step_nbr_CTRL_RESET_SHIFT))  
    #define Z_step_nbr_CTRL_ENABLE            ((uint8)((uint8)0x01u << Z_step_nbr_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define Z_step_nbr_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define Z_step_nbr_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Z_step_nbr_STATUS_CMP_INT_EN_MASK_SHIFT       Z_step_nbr_STATUS_CMP_SHIFT       
    #define Z_step_nbr_STATUS_ZERO_INT_EN_MASK_SHIFT      Z_step_nbr_STATUS_ZERO_SHIFT      
    #define Z_step_nbr_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  Z_step_nbr_STATUS_OVERFLOW_SHIFT  
    #define Z_step_nbr_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT Z_step_nbr_STATUS_UNDERFLOW_SHIFT 
    #define Z_step_nbr_STATUS_CAPTURE_INT_EN_MASK_SHIFT   Z_step_nbr_STATUS_CAPTURE_SHIFT   
    #define Z_step_nbr_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  Z_step_nbr_STATUS_FIFOFULL_SHIFT  
    #define Z_step_nbr_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  Z_step_nbr_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define Z_step_nbr_STATUS_CMP             ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_CMP_SHIFT))  
    #define Z_step_nbr_STATUS_ZERO            ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_ZERO_SHIFT)) 
    #define Z_step_nbr_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_OVERFLOW_SHIFT)) 
    #define Z_step_nbr_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_UNDERFLOW_SHIFT)) 
    #define Z_step_nbr_STATUS_CAPTURE         ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_CAPTURE_SHIFT)) 
    #define Z_step_nbr_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_FIFOFULL_SHIFT))
    #define Z_step_nbr_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << Z_step_nbr_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Z_step_nbr_STATUS_CMP_INT_EN_MASK            Z_step_nbr_STATUS_CMP                    
    #define Z_step_nbr_STATUS_ZERO_INT_EN_MASK           Z_step_nbr_STATUS_ZERO            
    #define Z_step_nbr_STATUS_OVERFLOW_INT_EN_MASK       Z_step_nbr_STATUS_OVERFLOW        
    #define Z_step_nbr_STATUS_UNDERFLOW_INT_EN_MASK      Z_step_nbr_STATUS_UNDERFLOW       
    #define Z_step_nbr_STATUS_CAPTURE_INT_EN_MASK        Z_step_nbr_STATUS_CAPTURE         
    #define Z_step_nbr_STATUS_FIFOFULL_INT_EN_MASK       Z_step_nbr_STATUS_FIFOFULL        
    #define Z_step_nbr_STATUS_FIFONEMP_INT_EN_MASK       Z_step_nbr_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define Z_step_nbr_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define Z_step_nbr_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define Z_step_nbr_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define Z_step_nbr_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define Z_step_nbr_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define Z_step_nbr_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* Z_step_nbr_UsingFixedFunction */

#endif  /* CY_COUNTER_Z_step_nbr_H */


/* [] END OF FILE */

