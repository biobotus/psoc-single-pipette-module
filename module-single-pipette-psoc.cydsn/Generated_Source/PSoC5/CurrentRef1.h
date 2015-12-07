/*******************************************************************************
* File Name: CurrentRef1.h  
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

#if !defined(CY_PINS_CurrentRef1_H) /* Pins CurrentRef1_H */
#define CY_PINS_CurrentRef1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CurrentRef1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CurrentRef1__PORT == 15 && ((CurrentRef1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CurrentRef1_Write(uint8 value) ;
void    CurrentRef1_SetDriveMode(uint8 mode) ;
uint8   CurrentRef1_ReadDataReg(void) ;
uint8   CurrentRef1_Read(void) ;
uint8   CurrentRef1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CurrentRef1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CurrentRef1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CurrentRef1_DM_RES_UP          PIN_DM_RES_UP
#define CurrentRef1_DM_RES_DWN         PIN_DM_RES_DWN
#define CurrentRef1_DM_OD_LO           PIN_DM_OD_LO
#define CurrentRef1_DM_OD_HI           PIN_DM_OD_HI
#define CurrentRef1_DM_STRONG          PIN_DM_STRONG
#define CurrentRef1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CurrentRef1_MASK               CurrentRef1__MASK
#define CurrentRef1_SHIFT              CurrentRef1__SHIFT
#define CurrentRef1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CurrentRef1_PS                     (* (reg8 *) CurrentRef1__PS)
/* Data Register */
#define CurrentRef1_DR                     (* (reg8 *) CurrentRef1__DR)
/* Port Number */
#define CurrentRef1_PRT_NUM                (* (reg8 *) CurrentRef1__PRT) 
/* Connect to Analog Globals */                                                  
#define CurrentRef1_AG                     (* (reg8 *) CurrentRef1__AG)                       
/* Analog MUX bux enable */
#define CurrentRef1_AMUX                   (* (reg8 *) CurrentRef1__AMUX) 
/* Bidirectional Enable */                                                        
#define CurrentRef1_BIE                    (* (reg8 *) CurrentRef1__BIE)
/* Bit-mask for Aliased Register Access */
#define CurrentRef1_BIT_MASK               (* (reg8 *) CurrentRef1__BIT_MASK)
/* Bypass Enable */
#define CurrentRef1_BYP                    (* (reg8 *) CurrentRef1__BYP)
/* Port wide control signals */                                                   
#define CurrentRef1_CTL                    (* (reg8 *) CurrentRef1__CTL)
/* Drive Modes */
#define CurrentRef1_DM0                    (* (reg8 *) CurrentRef1__DM0) 
#define CurrentRef1_DM1                    (* (reg8 *) CurrentRef1__DM1)
#define CurrentRef1_DM2                    (* (reg8 *) CurrentRef1__DM2) 
/* Input Buffer Disable Override */
#define CurrentRef1_INP_DIS                (* (reg8 *) CurrentRef1__INP_DIS)
/* LCD Common or Segment Drive */
#define CurrentRef1_LCD_COM_SEG            (* (reg8 *) CurrentRef1__LCD_COM_SEG)
/* Enable Segment LCD */
#define CurrentRef1_LCD_EN                 (* (reg8 *) CurrentRef1__LCD_EN)
/* Slew Rate Control */
#define CurrentRef1_SLW                    (* (reg8 *) CurrentRef1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CurrentRef1_PRTDSI__CAPS_SEL       (* (reg8 *) CurrentRef1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CurrentRef1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CurrentRef1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CurrentRef1_PRTDSI__OE_SEL0        (* (reg8 *) CurrentRef1__PRTDSI__OE_SEL0) 
#define CurrentRef1_PRTDSI__OE_SEL1        (* (reg8 *) CurrentRef1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CurrentRef1_PRTDSI__OUT_SEL0       (* (reg8 *) CurrentRef1__PRTDSI__OUT_SEL0) 
#define CurrentRef1_PRTDSI__OUT_SEL1       (* (reg8 *) CurrentRef1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CurrentRef1_PRTDSI__SYNC_OUT       (* (reg8 *) CurrentRef1__PRTDSI__SYNC_OUT) 


#if defined(CurrentRef1__INTSTAT)  /* Interrupt Registers */

    #define CurrentRef1_INTSTAT                (* (reg8 *) CurrentRef1__INTSTAT)
    #define CurrentRef1_SNAP                   (* (reg8 *) CurrentRef1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CurrentRef1_H */


/* [] END OF FILE */
