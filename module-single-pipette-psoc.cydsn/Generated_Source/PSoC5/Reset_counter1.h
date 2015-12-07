/*******************************************************************************
* File Name: Reset_counter1.h  
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

#if !defined(CY_PINS_Reset_counter1_H) /* Pins Reset_counter1_H */
#define CY_PINS_Reset_counter1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Reset_counter1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Reset_counter1__PORT == 15 && ((Reset_counter1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Reset_counter1_Write(uint8 value) ;
void    Reset_counter1_SetDriveMode(uint8 mode) ;
uint8   Reset_counter1_ReadDataReg(void) ;
uint8   Reset_counter1_Read(void) ;
uint8   Reset_counter1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Reset_counter1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Reset_counter1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Reset_counter1_DM_RES_UP          PIN_DM_RES_UP
#define Reset_counter1_DM_RES_DWN         PIN_DM_RES_DWN
#define Reset_counter1_DM_OD_LO           PIN_DM_OD_LO
#define Reset_counter1_DM_OD_HI           PIN_DM_OD_HI
#define Reset_counter1_DM_STRONG          PIN_DM_STRONG
#define Reset_counter1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Reset_counter1_MASK               Reset_counter1__MASK
#define Reset_counter1_SHIFT              Reset_counter1__SHIFT
#define Reset_counter1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Reset_counter1_PS                     (* (reg8 *) Reset_counter1__PS)
/* Data Register */
#define Reset_counter1_DR                     (* (reg8 *) Reset_counter1__DR)
/* Port Number */
#define Reset_counter1_PRT_NUM                (* (reg8 *) Reset_counter1__PRT) 
/* Connect to Analog Globals */                                                  
#define Reset_counter1_AG                     (* (reg8 *) Reset_counter1__AG)                       
/* Analog MUX bux enable */
#define Reset_counter1_AMUX                   (* (reg8 *) Reset_counter1__AMUX) 
/* Bidirectional Enable */                                                        
#define Reset_counter1_BIE                    (* (reg8 *) Reset_counter1__BIE)
/* Bit-mask for Aliased Register Access */
#define Reset_counter1_BIT_MASK               (* (reg8 *) Reset_counter1__BIT_MASK)
/* Bypass Enable */
#define Reset_counter1_BYP                    (* (reg8 *) Reset_counter1__BYP)
/* Port wide control signals */                                                   
#define Reset_counter1_CTL                    (* (reg8 *) Reset_counter1__CTL)
/* Drive Modes */
#define Reset_counter1_DM0                    (* (reg8 *) Reset_counter1__DM0) 
#define Reset_counter1_DM1                    (* (reg8 *) Reset_counter1__DM1)
#define Reset_counter1_DM2                    (* (reg8 *) Reset_counter1__DM2) 
/* Input Buffer Disable Override */
#define Reset_counter1_INP_DIS                (* (reg8 *) Reset_counter1__INP_DIS)
/* LCD Common or Segment Drive */
#define Reset_counter1_LCD_COM_SEG            (* (reg8 *) Reset_counter1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Reset_counter1_LCD_EN                 (* (reg8 *) Reset_counter1__LCD_EN)
/* Slew Rate Control */
#define Reset_counter1_SLW                    (* (reg8 *) Reset_counter1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Reset_counter1_PRTDSI__CAPS_SEL       (* (reg8 *) Reset_counter1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Reset_counter1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Reset_counter1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Reset_counter1_PRTDSI__OE_SEL0        (* (reg8 *) Reset_counter1__PRTDSI__OE_SEL0) 
#define Reset_counter1_PRTDSI__OE_SEL1        (* (reg8 *) Reset_counter1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Reset_counter1_PRTDSI__OUT_SEL0       (* (reg8 *) Reset_counter1__PRTDSI__OUT_SEL0) 
#define Reset_counter1_PRTDSI__OUT_SEL1       (* (reg8 *) Reset_counter1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Reset_counter1_PRTDSI__SYNC_OUT       (* (reg8 *) Reset_counter1__PRTDSI__SYNC_OUT) 


#if defined(Reset_counter1__INTSTAT)  /* Interrupt Registers */

    #define Reset_counter1_INTSTAT                (* (reg8 *) Reset_counter1__INTSTAT)
    #define Reset_counter1_SNAP                   (* (reg8 *) Reset_counter1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Reset_counter1_H */


/* [] END OF FILE */
