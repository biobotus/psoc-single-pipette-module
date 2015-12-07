/*******************************************************************************
* File Name: StepSizeB1.h  
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

#if !defined(CY_PINS_StepSizeB1_H) /* Pins StepSizeB1_H */
#define CY_PINS_StepSizeB1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "StepSizeB1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 StepSizeB1__PORT == 15 && ((StepSizeB1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    StepSizeB1_Write(uint8 value) ;
void    StepSizeB1_SetDriveMode(uint8 mode) ;
uint8   StepSizeB1_ReadDataReg(void) ;
uint8   StepSizeB1_Read(void) ;
uint8   StepSizeB1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StepSizeB1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define StepSizeB1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define StepSizeB1_DM_RES_UP          PIN_DM_RES_UP
#define StepSizeB1_DM_RES_DWN         PIN_DM_RES_DWN
#define StepSizeB1_DM_OD_LO           PIN_DM_OD_LO
#define StepSizeB1_DM_OD_HI           PIN_DM_OD_HI
#define StepSizeB1_DM_STRONG          PIN_DM_STRONG
#define StepSizeB1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define StepSizeB1_MASK               StepSizeB1__MASK
#define StepSizeB1_SHIFT              StepSizeB1__SHIFT
#define StepSizeB1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StepSizeB1_PS                     (* (reg8 *) StepSizeB1__PS)
/* Data Register */
#define StepSizeB1_DR                     (* (reg8 *) StepSizeB1__DR)
/* Port Number */
#define StepSizeB1_PRT_NUM                (* (reg8 *) StepSizeB1__PRT) 
/* Connect to Analog Globals */                                                  
#define StepSizeB1_AG                     (* (reg8 *) StepSizeB1__AG)                       
/* Analog MUX bux enable */
#define StepSizeB1_AMUX                   (* (reg8 *) StepSizeB1__AMUX) 
/* Bidirectional Enable */                                                        
#define StepSizeB1_BIE                    (* (reg8 *) StepSizeB1__BIE)
/* Bit-mask for Aliased Register Access */
#define StepSizeB1_BIT_MASK               (* (reg8 *) StepSizeB1__BIT_MASK)
/* Bypass Enable */
#define StepSizeB1_BYP                    (* (reg8 *) StepSizeB1__BYP)
/* Port wide control signals */                                                   
#define StepSizeB1_CTL                    (* (reg8 *) StepSizeB1__CTL)
/* Drive Modes */
#define StepSizeB1_DM0                    (* (reg8 *) StepSizeB1__DM0) 
#define StepSizeB1_DM1                    (* (reg8 *) StepSizeB1__DM1)
#define StepSizeB1_DM2                    (* (reg8 *) StepSizeB1__DM2) 
/* Input Buffer Disable Override */
#define StepSizeB1_INP_DIS                (* (reg8 *) StepSizeB1__INP_DIS)
/* LCD Common or Segment Drive */
#define StepSizeB1_LCD_COM_SEG            (* (reg8 *) StepSizeB1__LCD_COM_SEG)
/* Enable Segment LCD */
#define StepSizeB1_LCD_EN                 (* (reg8 *) StepSizeB1__LCD_EN)
/* Slew Rate Control */
#define StepSizeB1_SLW                    (* (reg8 *) StepSizeB1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define StepSizeB1_PRTDSI__CAPS_SEL       (* (reg8 *) StepSizeB1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define StepSizeB1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) StepSizeB1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define StepSizeB1_PRTDSI__OE_SEL0        (* (reg8 *) StepSizeB1__PRTDSI__OE_SEL0) 
#define StepSizeB1_PRTDSI__OE_SEL1        (* (reg8 *) StepSizeB1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define StepSizeB1_PRTDSI__OUT_SEL0       (* (reg8 *) StepSizeB1__PRTDSI__OUT_SEL0) 
#define StepSizeB1_PRTDSI__OUT_SEL1       (* (reg8 *) StepSizeB1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define StepSizeB1_PRTDSI__SYNC_OUT       (* (reg8 *) StepSizeB1__PRTDSI__SYNC_OUT) 


#if defined(StepSizeB1__INTSTAT)  /* Interrupt Registers */

    #define StepSizeB1_INTSTAT                (* (reg8 *) StepSizeB1__INTSTAT)
    #define StepSizeB1_SNAP                   (* (reg8 *) StepSizeB1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_StepSizeB1_H */


/* [] END OF FILE */
