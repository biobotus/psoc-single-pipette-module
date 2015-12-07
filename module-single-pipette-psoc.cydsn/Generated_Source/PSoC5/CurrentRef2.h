/*******************************************************************************
* File Name: CurrentRef2.h  
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

#if !defined(CY_PINS_CurrentRef2_H) /* Pins CurrentRef2_H */
#define CY_PINS_CurrentRef2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CurrentRef2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CurrentRef2__PORT == 15 && ((CurrentRef2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CurrentRef2_Write(uint8 value) ;
void    CurrentRef2_SetDriveMode(uint8 mode) ;
uint8   CurrentRef2_ReadDataReg(void) ;
uint8   CurrentRef2_Read(void) ;
uint8   CurrentRef2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CurrentRef2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CurrentRef2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CurrentRef2_DM_RES_UP          PIN_DM_RES_UP
#define CurrentRef2_DM_RES_DWN         PIN_DM_RES_DWN
#define CurrentRef2_DM_OD_LO           PIN_DM_OD_LO
#define CurrentRef2_DM_OD_HI           PIN_DM_OD_HI
#define CurrentRef2_DM_STRONG          PIN_DM_STRONG
#define CurrentRef2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CurrentRef2_MASK               CurrentRef2__MASK
#define CurrentRef2_SHIFT              CurrentRef2__SHIFT
#define CurrentRef2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CurrentRef2_PS                     (* (reg8 *) CurrentRef2__PS)
/* Data Register */
#define CurrentRef2_DR                     (* (reg8 *) CurrentRef2__DR)
/* Port Number */
#define CurrentRef2_PRT_NUM                (* (reg8 *) CurrentRef2__PRT) 
/* Connect to Analog Globals */                                                  
#define CurrentRef2_AG                     (* (reg8 *) CurrentRef2__AG)                       
/* Analog MUX bux enable */
#define CurrentRef2_AMUX                   (* (reg8 *) CurrentRef2__AMUX) 
/* Bidirectional Enable */                                                        
#define CurrentRef2_BIE                    (* (reg8 *) CurrentRef2__BIE)
/* Bit-mask for Aliased Register Access */
#define CurrentRef2_BIT_MASK               (* (reg8 *) CurrentRef2__BIT_MASK)
/* Bypass Enable */
#define CurrentRef2_BYP                    (* (reg8 *) CurrentRef2__BYP)
/* Port wide control signals */                                                   
#define CurrentRef2_CTL                    (* (reg8 *) CurrentRef2__CTL)
/* Drive Modes */
#define CurrentRef2_DM0                    (* (reg8 *) CurrentRef2__DM0) 
#define CurrentRef2_DM1                    (* (reg8 *) CurrentRef2__DM1)
#define CurrentRef2_DM2                    (* (reg8 *) CurrentRef2__DM2) 
/* Input Buffer Disable Override */
#define CurrentRef2_INP_DIS                (* (reg8 *) CurrentRef2__INP_DIS)
/* LCD Common or Segment Drive */
#define CurrentRef2_LCD_COM_SEG            (* (reg8 *) CurrentRef2__LCD_COM_SEG)
/* Enable Segment LCD */
#define CurrentRef2_LCD_EN                 (* (reg8 *) CurrentRef2__LCD_EN)
/* Slew Rate Control */
#define CurrentRef2_SLW                    (* (reg8 *) CurrentRef2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CurrentRef2_PRTDSI__CAPS_SEL       (* (reg8 *) CurrentRef2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CurrentRef2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CurrentRef2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CurrentRef2_PRTDSI__OE_SEL0        (* (reg8 *) CurrentRef2__PRTDSI__OE_SEL0) 
#define CurrentRef2_PRTDSI__OE_SEL1        (* (reg8 *) CurrentRef2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CurrentRef2_PRTDSI__OUT_SEL0       (* (reg8 *) CurrentRef2__PRTDSI__OUT_SEL0) 
#define CurrentRef2_PRTDSI__OUT_SEL1       (* (reg8 *) CurrentRef2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CurrentRef2_PRTDSI__SYNC_OUT       (* (reg8 *) CurrentRef2__PRTDSI__SYNC_OUT) 


#if defined(CurrentRef2__INTSTAT)  /* Interrupt Registers */

    #define CurrentRef2_INTSTAT                (* (reg8 *) CurrentRef2__INTSTAT)
    #define CurrentRef2_SNAP                   (* (reg8 *) CurrentRef2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CurrentRef2_H */


/* [] END OF FILE */
