/*******************************************************************************
* File Name: Step1.h  
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

#if !defined(CY_PINS_Step1_H) /* Pins Step1_H */
#define CY_PINS_Step1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Step1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Step1__PORT == 15 && ((Step1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Step1_Write(uint8 value) ;
void    Step1_SetDriveMode(uint8 mode) ;
uint8   Step1_ReadDataReg(void) ;
uint8   Step1_Read(void) ;
uint8   Step1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Step1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Step1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Step1_DM_RES_UP          PIN_DM_RES_UP
#define Step1_DM_RES_DWN         PIN_DM_RES_DWN
#define Step1_DM_OD_LO           PIN_DM_OD_LO
#define Step1_DM_OD_HI           PIN_DM_OD_HI
#define Step1_DM_STRONG          PIN_DM_STRONG
#define Step1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Step1_MASK               Step1__MASK
#define Step1_SHIFT              Step1__SHIFT
#define Step1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Step1_PS                     (* (reg8 *) Step1__PS)
/* Data Register */
#define Step1_DR                     (* (reg8 *) Step1__DR)
/* Port Number */
#define Step1_PRT_NUM                (* (reg8 *) Step1__PRT) 
/* Connect to Analog Globals */                                                  
#define Step1_AG                     (* (reg8 *) Step1__AG)                       
/* Analog MUX bux enable */
#define Step1_AMUX                   (* (reg8 *) Step1__AMUX) 
/* Bidirectional Enable */                                                        
#define Step1_BIE                    (* (reg8 *) Step1__BIE)
/* Bit-mask for Aliased Register Access */
#define Step1_BIT_MASK               (* (reg8 *) Step1__BIT_MASK)
/* Bypass Enable */
#define Step1_BYP                    (* (reg8 *) Step1__BYP)
/* Port wide control signals */                                                   
#define Step1_CTL                    (* (reg8 *) Step1__CTL)
/* Drive Modes */
#define Step1_DM0                    (* (reg8 *) Step1__DM0) 
#define Step1_DM1                    (* (reg8 *) Step1__DM1)
#define Step1_DM2                    (* (reg8 *) Step1__DM2) 
/* Input Buffer Disable Override */
#define Step1_INP_DIS                (* (reg8 *) Step1__INP_DIS)
/* LCD Common or Segment Drive */
#define Step1_LCD_COM_SEG            (* (reg8 *) Step1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Step1_LCD_EN                 (* (reg8 *) Step1__LCD_EN)
/* Slew Rate Control */
#define Step1_SLW                    (* (reg8 *) Step1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Step1_PRTDSI__CAPS_SEL       (* (reg8 *) Step1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Step1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Step1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Step1_PRTDSI__OE_SEL0        (* (reg8 *) Step1__PRTDSI__OE_SEL0) 
#define Step1_PRTDSI__OE_SEL1        (* (reg8 *) Step1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Step1_PRTDSI__OUT_SEL0       (* (reg8 *) Step1__PRTDSI__OUT_SEL0) 
#define Step1_PRTDSI__OUT_SEL1       (* (reg8 *) Step1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Step1_PRTDSI__SYNC_OUT       (* (reg8 *) Step1__PRTDSI__SYNC_OUT) 


#if defined(Step1__INTSTAT)  /* Interrupt Registers */

    #define Step1_INTSTAT                (* (reg8 *) Step1__INTSTAT)
    #define Step1_SNAP                   (* (reg8 *) Step1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Step1_H */


/* [] END OF FILE */
