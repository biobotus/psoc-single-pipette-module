/*******************************************************************************
* File Name: StepSizeA2.h  
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

#if !defined(CY_PINS_StepSizeA2_H) /* Pins StepSizeA2_H */
#define CY_PINS_StepSizeA2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "StepSizeA2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 StepSizeA2__PORT == 15 && ((StepSizeA2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    StepSizeA2_Write(uint8 value) ;
void    StepSizeA2_SetDriveMode(uint8 mode) ;
uint8   StepSizeA2_ReadDataReg(void) ;
uint8   StepSizeA2_Read(void) ;
uint8   StepSizeA2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StepSizeA2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define StepSizeA2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define StepSizeA2_DM_RES_UP          PIN_DM_RES_UP
#define StepSizeA2_DM_RES_DWN         PIN_DM_RES_DWN
#define StepSizeA2_DM_OD_LO           PIN_DM_OD_LO
#define StepSizeA2_DM_OD_HI           PIN_DM_OD_HI
#define StepSizeA2_DM_STRONG          PIN_DM_STRONG
#define StepSizeA2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define StepSizeA2_MASK               StepSizeA2__MASK
#define StepSizeA2_SHIFT              StepSizeA2__SHIFT
#define StepSizeA2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StepSizeA2_PS                     (* (reg8 *) StepSizeA2__PS)
/* Data Register */
#define StepSizeA2_DR                     (* (reg8 *) StepSizeA2__DR)
/* Port Number */
#define StepSizeA2_PRT_NUM                (* (reg8 *) StepSizeA2__PRT) 
/* Connect to Analog Globals */                                                  
#define StepSizeA2_AG                     (* (reg8 *) StepSizeA2__AG)                       
/* Analog MUX bux enable */
#define StepSizeA2_AMUX                   (* (reg8 *) StepSizeA2__AMUX) 
/* Bidirectional Enable */                                                        
#define StepSizeA2_BIE                    (* (reg8 *) StepSizeA2__BIE)
/* Bit-mask for Aliased Register Access */
#define StepSizeA2_BIT_MASK               (* (reg8 *) StepSizeA2__BIT_MASK)
/* Bypass Enable */
#define StepSizeA2_BYP                    (* (reg8 *) StepSizeA2__BYP)
/* Port wide control signals */                                                   
#define StepSizeA2_CTL                    (* (reg8 *) StepSizeA2__CTL)
/* Drive Modes */
#define StepSizeA2_DM0                    (* (reg8 *) StepSizeA2__DM0) 
#define StepSizeA2_DM1                    (* (reg8 *) StepSizeA2__DM1)
#define StepSizeA2_DM2                    (* (reg8 *) StepSizeA2__DM2) 
/* Input Buffer Disable Override */
#define StepSizeA2_INP_DIS                (* (reg8 *) StepSizeA2__INP_DIS)
/* LCD Common or Segment Drive */
#define StepSizeA2_LCD_COM_SEG            (* (reg8 *) StepSizeA2__LCD_COM_SEG)
/* Enable Segment LCD */
#define StepSizeA2_LCD_EN                 (* (reg8 *) StepSizeA2__LCD_EN)
/* Slew Rate Control */
#define StepSizeA2_SLW                    (* (reg8 *) StepSizeA2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define StepSizeA2_PRTDSI__CAPS_SEL       (* (reg8 *) StepSizeA2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define StepSizeA2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) StepSizeA2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define StepSizeA2_PRTDSI__OE_SEL0        (* (reg8 *) StepSizeA2__PRTDSI__OE_SEL0) 
#define StepSizeA2_PRTDSI__OE_SEL1        (* (reg8 *) StepSizeA2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define StepSizeA2_PRTDSI__OUT_SEL0       (* (reg8 *) StepSizeA2__PRTDSI__OUT_SEL0) 
#define StepSizeA2_PRTDSI__OUT_SEL1       (* (reg8 *) StepSizeA2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define StepSizeA2_PRTDSI__SYNC_OUT       (* (reg8 *) StepSizeA2__PRTDSI__SYNC_OUT) 


#if defined(StepSizeA2__INTSTAT)  /* Interrupt Registers */

    #define StepSizeA2_INTSTAT                (* (reg8 *) StepSizeA2__INTSTAT)
    #define StepSizeA2_SNAP                   (* (reg8 *) StepSizeA2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_StepSizeA2_H */


/* [] END OF FILE */
