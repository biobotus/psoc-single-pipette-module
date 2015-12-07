/*******************************************************************************
* File Name: Timer_Trig1.h  
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

#if !defined(CY_PINS_Timer_Trig1_H) /* Pins Timer_Trig1_H */
#define CY_PINS_Timer_Trig1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Timer_Trig1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Timer_Trig1__PORT == 15 && ((Timer_Trig1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Timer_Trig1_Write(uint8 value) ;
void    Timer_Trig1_SetDriveMode(uint8 mode) ;
uint8   Timer_Trig1_ReadDataReg(void) ;
uint8   Timer_Trig1_Read(void) ;
uint8   Timer_Trig1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Timer_Trig1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Timer_Trig1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Timer_Trig1_DM_RES_UP          PIN_DM_RES_UP
#define Timer_Trig1_DM_RES_DWN         PIN_DM_RES_DWN
#define Timer_Trig1_DM_OD_LO           PIN_DM_OD_LO
#define Timer_Trig1_DM_OD_HI           PIN_DM_OD_HI
#define Timer_Trig1_DM_STRONG          PIN_DM_STRONG
#define Timer_Trig1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Timer_Trig1_MASK               Timer_Trig1__MASK
#define Timer_Trig1_SHIFT              Timer_Trig1__SHIFT
#define Timer_Trig1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Timer_Trig1_PS                     (* (reg8 *) Timer_Trig1__PS)
/* Data Register */
#define Timer_Trig1_DR                     (* (reg8 *) Timer_Trig1__DR)
/* Port Number */
#define Timer_Trig1_PRT_NUM                (* (reg8 *) Timer_Trig1__PRT) 
/* Connect to Analog Globals */                                                  
#define Timer_Trig1_AG                     (* (reg8 *) Timer_Trig1__AG)                       
/* Analog MUX bux enable */
#define Timer_Trig1_AMUX                   (* (reg8 *) Timer_Trig1__AMUX) 
/* Bidirectional Enable */                                                        
#define Timer_Trig1_BIE                    (* (reg8 *) Timer_Trig1__BIE)
/* Bit-mask for Aliased Register Access */
#define Timer_Trig1_BIT_MASK               (* (reg8 *) Timer_Trig1__BIT_MASK)
/* Bypass Enable */
#define Timer_Trig1_BYP                    (* (reg8 *) Timer_Trig1__BYP)
/* Port wide control signals */                                                   
#define Timer_Trig1_CTL                    (* (reg8 *) Timer_Trig1__CTL)
/* Drive Modes */
#define Timer_Trig1_DM0                    (* (reg8 *) Timer_Trig1__DM0) 
#define Timer_Trig1_DM1                    (* (reg8 *) Timer_Trig1__DM1)
#define Timer_Trig1_DM2                    (* (reg8 *) Timer_Trig1__DM2) 
/* Input Buffer Disable Override */
#define Timer_Trig1_INP_DIS                (* (reg8 *) Timer_Trig1__INP_DIS)
/* LCD Common or Segment Drive */
#define Timer_Trig1_LCD_COM_SEG            (* (reg8 *) Timer_Trig1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Timer_Trig1_LCD_EN                 (* (reg8 *) Timer_Trig1__LCD_EN)
/* Slew Rate Control */
#define Timer_Trig1_SLW                    (* (reg8 *) Timer_Trig1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Timer_Trig1_PRTDSI__CAPS_SEL       (* (reg8 *) Timer_Trig1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Timer_Trig1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Timer_Trig1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Timer_Trig1_PRTDSI__OE_SEL0        (* (reg8 *) Timer_Trig1__PRTDSI__OE_SEL0) 
#define Timer_Trig1_PRTDSI__OE_SEL1        (* (reg8 *) Timer_Trig1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Timer_Trig1_PRTDSI__OUT_SEL0       (* (reg8 *) Timer_Trig1__PRTDSI__OUT_SEL0) 
#define Timer_Trig1_PRTDSI__OUT_SEL1       (* (reg8 *) Timer_Trig1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Timer_Trig1_PRTDSI__SYNC_OUT       (* (reg8 *) Timer_Trig1__PRTDSI__SYNC_OUT) 


#if defined(Timer_Trig1__INTSTAT)  /* Interrupt Registers */

    #define Timer_Trig1_INTSTAT                (* (reg8 *) Timer_Trig1__INTSTAT)
    #define Timer_Trig1_SNAP                   (* (reg8 *) Timer_Trig1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Timer_Trig1_H */


/* [] END OF FILE */
