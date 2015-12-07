/*******************************************************************************
* File Name: Pipet_Step.h  
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

#if !defined(CY_PINS_Pipet_Step_H) /* Pins Pipet_Step_H */
#define CY_PINS_Pipet_Step_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pipet_Step_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pipet_Step__PORT == 15 && ((Pipet_Step__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pipet_Step_Write(uint8 value) ;
void    Pipet_Step_SetDriveMode(uint8 mode) ;
uint8   Pipet_Step_ReadDataReg(void) ;
uint8   Pipet_Step_Read(void) ;
uint8   Pipet_Step_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pipet_Step_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pipet_Step_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pipet_Step_DM_RES_UP          PIN_DM_RES_UP
#define Pipet_Step_DM_RES_DWN         PIN_DM_RES_DWN
#define Pipet_Step_DM_OD_LO           PIN_DM_OD_LO
#define Pipet_Step_DM_OD_HI           PIN_DM_OD_HI
#define Pipet_Step_DM_STRONG          PIN_DM_STRONG
#define Pipet_Step_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pipet_Step_MASK               Pipet_Step__MASK
#define Pipet_Step_SHIFT              Pipet_Step__SHIFT
#define Pipet_Step_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pipet_Step_PS                     (* (reg8 *) Pipet_Step__PS)
/* Data Register */
#define Pipet_Step_DR                     (* (reg8 *) Pipet_Step__DR)
/* Port Number */
#define Pipet_Step_PRT_NUM                (* (reg8 *) Pipet_Step__PRT) 
/* Connect to Analog Globals */                                                  
#define Pipet_Step_AG                     (* (reg8 *) Pipet_Step__AG)                       
/* Analog MUX bux enable */
#define Pipet_Step_AMUX                   (* (reg8 *) Pipet_Step__AMUX) 
/* Bidirectional Enable */                                                        
#define Pipet_Step_BIE                    (* (reg8 *) Pipet_Step__BIE)
/* Bit-mask for Aliased Register Access */
#define Pipet_Step_BIT_MASK               (* (reg8 *) Pipet_Step__BIT_MASK)
/* Bypass Enable */
#define Pipet_Step_BYP                    (* (reg8 *) Pipet_Step__BYP)
/* Port wide control signals */                                                   
#define Pipet_Step_CTL                    (* (reg8 *) Pipet_Step__CTL)
/* Drive Modes */
#define Pipet_Step_DM0                    (* (reg8 *) Pipet_Step__DM0) 
#define Pipet_Step_DM1                    (* (reg8 *) Pipet_Step__DM1)
#define Pipet_Step_DM2                    (* (reg8 *) Pipet_Step__DM2) 
/* Input Buffer Disable Override */
#define Pipet_Step_INP_DIS                (* (reg8 *) Pipet_Step__INP_DIS)
/* LCD Common or Segment Drive */
#define Pipet_Step_LCD_COM_SEG            (* (reg8 *) Pipet_Step__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pipet_Step_LCD_EN                 (* (reg8 *) Pipet_Step__LCD_EN)
/* Slew Rate Control */
#define Pipet_Step_SLW                    (* (reg8 *) Pipet_Step__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pipet_Step_PRTDSI__CAPS_SEL       (* (reg8 *) Pipet_Step__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pipet_Step_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pipet_Step__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pipet_Step_PRTDSI__OE_SEL0        (* (reg8 *) Pipet_Step__PRTDSI__OE_SEL0) 
#define Pipet_Step_PRTDSI__OE_SEL1        (* (reg8 *) Pipet_Step__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pipet_Step_PRTDSI__OUT_SEL0       (* (reg8 *) Pipet_Step__PRTDSI__OUT_SEL0) 
#define Pipet_Step_PRTDSI__OUT_SEL1       (* (reg8 *) Pipet_Step__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pipet_Step_PRTDSI__SYNC_OUT       (* (reg8 *) Pipet_Step__PRTDSI__SYNC_OUT) 


#if defined(Pipet_Step__INTSTAT)  /* Interrupt Registers */

    #define Pipet_Step_INTSTAT                (* (reg8 *) Pipet_Step__INTSTAT)
    #define Pipet_Step_SNAP                   (* (reg8 *) Pipet_Step__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pipet_Step_H */


/* [] END OF FILE */
