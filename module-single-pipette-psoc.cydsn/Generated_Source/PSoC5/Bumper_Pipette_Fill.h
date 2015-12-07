/*******************************************************************************
* File Name: Bumper_Pipette_Fill.h  
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

#if !defined(CY_PINS_Bumper_Pipette_Fill_H) /* Pins Bumper_Pipette_Fill_H */
#define CY_PINS_Bumper_Pipette_Fill_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bumper_Pipette_Fill_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bumper_Pipette_Fill__PORT == 15 && ((Bumper_Pipette_Fill__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Bumper_Pipette_Fill_Write(uint8 value) ;
void    Bumper_Pipette_Fill_SetDriveMode(uint8 mode) ;
uint8   Bumper_Pipette_Fill_ReadDataReg(void) ;
uint8   Bumper_Pipette_Fill_Read(void) ;
uint8   Bumper_Pipette_Fill_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Bumper_Pipette_Fill_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Bumper_Pipette_Fill_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Bumper_Pipette_Fill_DM_RES_UP          PIN_DM_RES_UP
#define Bumper_Pipette_Fill_DM_RES_DWN         PIN_DM_RES_DWN
#define Bumper_Pipette_Fill_DM_OD_LO           PIN_DM_OD_LO
#define Bumper_Pipette_Fill_DM_OD_HI           PIN_DM_OD_HI
#define Bumper_Pipette_Fill_DM_STRONG          PIN_DM_STRONG
#define Bumper_Pipette_Fill_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Bumper_Pipette_Fill_MASK               Bumper_Pipette_Fill__MASK
#define Bumper_Pipette_Fill_SHIFT              Bumper_Pipette_Fill__SHIFT
#define Bumper_Pipette_Fill_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bumper_Pipette_Fill_PS                     (* (reg8 *) Bumper_Pipette_Fill__PS)
/* Data Register */
#define Bumper_Pipette_Fill_DR                     (* (reg8 *) Bumper_Pipette_Fill__DR)
/* Port Number */
#define Bumper_Pipette_Fill_PRT_NUM                (* (reg8 *) Bumper_Pipette_Fill__PRT) 
/* Connect to Analog Globals */                                                  
#define Bumper_Pipette_Fill_AG                     (* (reg8 *) Bumper_Pipette_Fill__AG)                       
/* Analog MUX bux enable */
#define Bumper_Pipette_Fill_AMUX                   (* (reg8 *) Bumper_Pipette_Fill__AMUX) 
/* Bidirectional Enable */                                                        
#define Bumper_Pipette_Fill_BIE                    (* (reg8 *) Bumper_Pipette_Fill__BIE)
/* Bit-mask for Aliased Register Access */
#define Bumper_Pipette_Fill_BIT_MASK               (* (reg8 *) Bumper_Pipette_Fill__BIT_MASK)
/* Bypass Enable */
#define Bumper_Pipette_Fill_BYP                    (* (reg8 *) Bumper_Pipette_Fill__BYP)
/* Port wide control signals */                                                   
#define Bumper_Pipette_Fill_CTL                    (* (reg8 *) Bumper_Pipette_Fill__CTL)
/* Drive Modes */
#define Bumper_Pipette_Fill_DM0                    (* (reg8 *) Bumper_Pipette_Fill__DM0) 
#define Bumper_Pipette_Fill_DM1                    (* (reg8 *) Bumper_Pipette_Fill__DM1)
#define Bumper_Pipette_Fill_DM2                    (* (reg8 *) Bumper_Pipette_Fill__DM2) 
/* Input Buffer Disable Override */
#define Bumper_Pipette_Fill_INP_DIS                (* (reg8 *) Bumper_Pipette_Fill__INP_DIS)
/* LCD Common or Segment Drive */
#define Bumper_Pipette_Fill_LCD_COM_SEG            (* (reg8 *) Bumper_Pipette_Fill__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bumper_Pipette_Fill_LCD_EN                 (* (reg8 *) Bumper_Pipette_Fill__LCD_EN)
/* Slew Rate Control */
#define Bumper_Pipette_Fill_SLW                    (* (reg8 *) Bumper_Pipette_Fill__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bumper_Pipette_Fill_PRTDSI__CAPS_SEL       (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bumper_Pipette_Fill_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bumper_Pipette_Fill_PRTDSI__OE_SEL0        (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__OE_SEL0) 
#define Bumper_Pipette_Fill_PRTDSI__OE_SEL1        (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bumper_Pipette_Fill_PRTDSI__OUT_SEL0       (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__OUT_SEL0) 
#define Bumper_Pipette_Fill_PRTDSI__OUT_SEL1       (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bumper_Pipette_Fill_PRTDSI__SYNC_OUT       (* (reg8 *) Bumper_Pipette_Fill__PRTDSI__SYNC_OUT) 


#if defined(Bumper_Pipette_Fill__INTSTAT)  /* Interrupt Registers */

    #define Bumper_Pipette_Fill_INTSTAT                (* (reg8 *) Bumper_Pipette_Fill__INTSTAT)
    #define Bumper_Pipette_Fill_SNAP                   (* (reg8 *) Bumper_Pipette_Fill__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bumper_Pipette_Fill_H */


/* [] END OF FILE */
