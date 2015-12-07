/*******************************************************************************
* File Name: Bumper.h  
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

#if !defined(CY_PINS_Bumper_H) /* Pins Bumper_H */
#define CY_PINS_Bumper_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bumper_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bumper__PORT == 15 && ((Bumper__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Bumper_Write(uint8 value) ;
void    Bumper_SetDriveMode(uint8 mode) ;
uint8   Bumper_ReadDataReg(void) ;
uint8   Bumper_Read(void) ;
uint8   Bumper_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Bumper_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Bumper_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Bumper_DM_RES_UP          PIN_DM_RES_UP
#define Bumper_DM_RES_DWN         PIN_DM_RES_DWN
#define Bumper_DM_OD_LO           PIN_DM_OD_LO
#define Bumper_DM_OD_HI           PIN_DM_OD_HI
#define Bumper_DM_STRONG          PIN_DM_STRONG
#define Bumper_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Bumper_MASK               Bumper__MASK
#define Bumper_SHIFT              Bumper__SHIFT
#define Bumper_WIDTH              8u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bumper_PS                     (* (reg8 *) Bumper__PS)
/* Data Register */
#define Bumper_DR                     (* (reg8 *) Bumper__DR)
/* Port Number */
#define Bumper_PRT_NUM                (* (reg8 *) Bumper__PRT) 
/* Connect to Analog Globals */                                                  
#define Bumper_AG                     (* (reg8 *) Bumper__AG)                       
/* Analog MUX bux enable */
#define Bumper_AMUX                   (* (reg8 *) Bumper__AMUX) 
/* Bidirectional Enable */                                                        
#define Bumper_BIE                    (* (reg8 *) Bumper__BIE)
/* Bit-mask for Aliased Register Access */
#define Bumper_BIT_MASK               (* (reg8 *) Bumper__BIT_MASK)
/* Bypass Enable */
#define Bumper_BYP                    (* (reg8 *) Bumper__BYP)
/* Port wide control signals */                                                   
#define Bumper_CTL                    (* (reg8 *) Bumper__CTL)
/* Drive Modes */
#define Bumper_DM0                    (* (reg8 *) Bumper__DM0) 
#define Bumper_DM1                    (* (reg8 *) Bumper__DM1)
#define Bumper_DM2                    (* (reg8 *) Bumper__DM2) 
/* Input Buffer Disable Override */
#define Bumper_INP_DIS                (* (reg8 *) Bumper__INP_DIS)
/* LCD Common or Segment Drive */
#define Bumper_LCD_COM_SEG            (* (reg8 *) Bumper__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bumper_LCD_EN                 (* (reg8 *) Bumper__LCD_EN)
/* Slew Rate Control */
#define Bumper_SLW                    (* (reg8 *) Bumper__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bumper_PRTDSI__CAPS_SEL       (* (reg8 *) Bumper__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bumper_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bumper__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bumper_PRTDSI__OE_SEL0        (* (reg8 *) Bumper__PRTDSI__OE_SEL0) 
#define Bumper_PRTDSI__OE_SEL1        (* (reg8 *) Bumper__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bumper_PRTDSI__OUT_SEL0       (* (reg8 *) Bumper__PRTDSI__OUT_SEL0) 
#define Bumper_PRTDSI__OUT_SEL1       (* (reg8 *) Bumper__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bumper_PRTDSI__SYNC_OUT       (* (reg8 *) Bumper__PRTDSI__SYNC_OUT) 


#if defined(Bumper__INTSTAT)  /* Interrupt Registers */

    #define Bumper_INTSTAT                (* (reg8 *) Bumper__INTSTAT)
    #define Bumper_SNAP                   (* (reg8 *) Bumper__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bumper_H */


/* [] END OF FILE */
