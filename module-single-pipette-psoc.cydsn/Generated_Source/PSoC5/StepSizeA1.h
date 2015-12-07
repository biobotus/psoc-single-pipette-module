/*******************************************************************************
* File Name: StepSizeA1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_StepSizeA1_H) /* Pins StepSizeA1_H */
#define CY_PINS_StepSizeA1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "StepSizeA1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 StepSizeA1__PORT == 15 && ((StepSizeA1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    StepSizeA1_Write(uint8 value) ;
void    StepSizeA1_SetDriveMode(uint8 mode) ;
uint8   StepSizeA1_ReadDataReg(void) ;
uint8   StepSizeA1_Read(void) ;
uint8   StepSizeA1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StepSizeA1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define StepSizeA1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define StepSizeA1_DM_RES_UP          PIN_DM_RES_UP
#define StepSizeA1_DM_RES_DWN         PIN_DM_RES_DWN
#define StepSizeA1_DM_OD_LO           PIN_DM_OD_LO
#define StepSizeA1_DM_OD_HI           PIN_DM_OD_HI
#define StepSizeA1_DM_STRONG          PIN_DM_STRONG
#define StepSizeA1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define StepSizeA1_MASK               StepSizeA1__MASK
#define StepSizeA1_SHIFT              StepSizeA1__SHIFT
#define StepSizeA1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StepSizeA1_PS                     (* (reg8 *) StepSizeA1__PS)
/* Data Register */
#define StepSizeA1_DR                     (* (reg8 *) StepSizeA1__DR)
/* Port Number */
#define StepSizeA1_PRT_NUM                (* (reg8 *) StepSizeA1__PRT) 
/* Connect to Analog Globals */                                                  
#define StepSizeA1_AG                     (* (reg8 *) StepSizeA1__AG)                       
/* Analog MUX bux enable */
#define StepSizeA1_AMUX                   (* (reg8 *) StepSizeA1__AMUX) 
/* Bidirectional Enable */                                                        
#define StepSizeA1_BIE                    (* (reg8 *) StepSizeA1__BIE)
/* Bit-mask for Aliased Register Access */
#define StepSizeA1_BIT_MASK               (* (reg8 *) StepSizeA1__BIT_MASK)
/* Bypass Enable */
#define StepSizeA1_BYP                    (* (reg8 *) StepSizeA1__BYP)
/* Port wide control signals */                                                   
#define StepSizeA1_CTL                    (* (reg8 *) StepSizeA1__CTL)
/* Drive Modes */
#define StepSizeA1_DM0                    (* (reg8 *) StepSizeA1__DM0) 
#define StepSizeA1_DM1                    (* (reg8 *) StepSizeA1__DM1)
#define StepSizeA1_DM2                    (* (reg8 *) StepSizeA1__DM2) 
/* Input Buffer Disable Override */
#define StepSizeA1_INP_DIS                (* (reg8 *) StepSizeA1__INP_DIS)
/* LCD Common or Segment Drive */
#define StepSizeA1_LCD_COM_SEG            (* (reg8 *) StepSizeA1__LCD_COM_SEG)
/* Enable Segment LCD */
#define StepSizeA1_LCD_EN                 (* (reg8 *) StepSizeA1__LCD_EN)
/* Slew Rate Control */
#define StepSizeA1_SLW                    (* (reg8 *) StepSizeA1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define StepSizeA1_PRTDSI__CAPS_SEL       (* (reg8 *) StepSizeA1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define StepSizeA1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) StepSizeA1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define StepSizeA1_PRTDSI__OE_SEL0        (* (reg8 *) StepSizeA1__PRTDSI__OE_SEL0) 
#define StepSizeA1_PRTDSI__OE_SEL1        (* (reg8 *) StepSizeA1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define StepSizeA1_PRTDSI__OUT_SEL0       (* (reg8 *) StepSizeA1__PRTDSI__OUT_SEL0) 
#define StepSizeA1_PRTDSI__OUT_SEL1       (* (reg8 *) StepSizeA1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define StepSizeA1_PRTDSI__SYNC_OUT       (* (reg8 *) StepSizeA1__PRTDSI__SYNC_OUT) 


#if defined(StepSizeA1__INTSTAT)  /* Interrupt Registers */

    #define StepSizeA1_INTSTAT                (* (reg8 *) StepSizeA1__INTSTAT)
    #define StepSizeA1_SNAP                   (* (reg8 *) StepSizeA1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_StepSizeA1_H */


/* [] END OF FILE */
