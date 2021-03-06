/*******************************************************************************
* File Name: StepSizeB2.h  
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

#if !defined(CY_PINS_StepSizeB2_H) /* Pins StepSizeB2_H */
#define CY_PINS_StepSizeB2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "StepSizeB2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 StepSizeB2__PORT == 15 && ((StepSizeB2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    StepSizeB2_Write(uint8 value) ;
void    StepSizeB2_SetDriveMode(uint8 mode) ;
uint8   StepSizeB2_ReadDataReg(void) ;
uint8   StepSizeB2_Read(void) ;
uint8   StepSizeB2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StepSizeB2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define StepSizeB2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define StepSizeB2_DM_RES_UP          PIN_DM_RES_UP
#define StepSizeB2_DM_RES_DWN         PIN_DM_RES_DWN
#define StepSizeB2_DM_OD_LO           PIN_DM_OD_LO
#define StepSizeB2_DM_OD_HI           PIN_DM_OD_HI
#define StepSizeB2_DM_STRONG          PIN_DM_STRONG
#define StepSizeB2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define StepSizeB2_MASK               StepSizeB2__MASK
#define StepSizeB2_SHIFT              StepSizeB2__SHIFT
#define StepSizeB2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StepSizeB2_PS                     (* (reg8 *) StepSizeB2__PS)
/* Data Register */
#define StepSizeB2_DR                     (* (reg8 *) StepSizeB2__DR)
/* Port Number */
#define StepSizeB2_PRT_NUM                (* (reg8 *) StepSizeB2__PRT) 
/* Connect to Analog Globals */                                                  
#define StepSizeB2_AG                     (* (reg8 *) StepSizeB2__AG)                       
/* Analog MUX bux enable */
#define StepSizeB2_AMUX                   (* (reg8 *) StepSizeB2__AMUX) 
/* Bidirectional Enable */                                                        
#define StepSizeB2_BIE                    (* (reg8 *) StepSizeB2__BIE)
/* Bit-mask for Aliased Register Access */
#define StepSizeB2_BIT_MASK               (* (reg8 *) StepSizeB2__BIT_MASK)
/* Bypass Enable */
#define StepSizeB2_BYP                    (* (reg8 *) StepSizeB2__BYP)
/* Port wide control signals */                                                   
#define StepSizeB2_CTL                    (* (reg8 *) StepSizeB2__CTL)
/* Drive Modes */
#define StepSizeB2_DM0                    (* (reg8 *) StepSizeB2__DM0) 
#define StepSizeB2_DM1                    (* (reg8 *) StepSizeB2__DM1)
#define StepSizeB2_DM2                    (* (reg8 *) StepSizeB2__DM2) 
/* Input Buffer Disable Override */
#define StepSizeB2_INP_DIS                (* (reg8 *) StepSizeB2__INP_DIS)
/* LCD Common or Segment Drive */
#define StepSizeB2_LCD_COM_SEG            (* (reg8 *) StepSizeB2__LCD_COM_SEG)
/* Enable Segment LCD */
#define StepSizeB2_LCD_EN                 (* (reg8 *) StepSizeB2__LCD_EN)
/* Slew Rate Control */
#define StepSizeB2_SLW                    (* (reg8 *) StepSizeB2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define StepSizeB2_PRTDSI__CAPS_SEL       (* (reg8 *) StepSizeB2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define StepSizeB2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) StepSizeB2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define StepSizeB2_PRTDSI__OE_SEL0        (* (reg8 *) StepSizeB2__PRTDSI__OE_SEL0) 
#define StepSizeB2_PRTDSI__OE_SEL1        (* (reg8 *) StepSizeB2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define StepSizeB2_PRTDSI__OUT_SEL0       (* (reg8 *) StepSizeB2__PRTDSI__OUT_SEL0) 
#define StepSizeB2_PRTDSI__OUT_SEL1       (* (reg8 *) StepSizeB2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define StepSizeB2_PRTDSI__SYNC_OUT       (* (reg8 *) StepSizeB2__PRTDSI__SYNC_OUT) 


#if defined(StepSizeB2__INTSTAT)  /* Interrupt Registers */

    #define StepSizeB2_INTSTAT                (* (reg8 *) StepSizeB2__INTSTAT)
    #define StepSizeB2_SNAP                   (* (reg8 *) StepSizeB2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_StepSizeB2_H */


/* [] END OF FILE */
