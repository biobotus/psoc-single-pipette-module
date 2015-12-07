/*******************************************************************************
* File Name: Pipet_StepSizeB.h  
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

#if !defined(CY_PINS_Pipet_StepSizeB_H) /* Pins Pipet_StepSizeB_H */
#define CY_PINS_Pipet_StepSizeB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pipet_StepSizeB_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pipet_StepSizeB__PORT == 15 && ((Pipet_StepSizeB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pipet_StepSizeB_Write(uint8 value) ;
void    Pipet_StepSizeB_SetDriveMode(uint8 mode) ;
uint8   Pipet_StepSizeB_ReadDataReg(void) ;
uint8   Pipet_StepSizeB_Read(void) ;
uint8   Pipet_StepSizeB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pipet_StepSizeB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pipet_StepSizeB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pipet_StepSizeB_DM_RES_UP          PIN_DM_RES_UP
#define Pipet_StepSizeB_DM_RES_DWN         PIN_DM_RES_DWN
#define Pipet_StepSizeB_DM_OD_LO           PIN_DM_OD_LO
#define Pipet_StepSizeB_DM_OD_HI           PIN_DM_OD_HI
#define Pipet_StepSizeB_DM_STRONG          PIN_DM_STRONG
#define Pipet_StepSizeB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pipet_StepSizeB_MASK               Pipet_StepSizeB__MASK
#define Pipet_StepSizeB_SHIFT              Pipet_StepSizeB__SHIFT
#define Pipet_StepSizeB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pipet_StepSizeB_PS                     (* (reg8 *) Pipet_StepSizeB__PS)
/* Data Register */
#define Pipet_StepSizeB_DR                     (* (reg8 *) Pipet_StepSizeB__DR)
/* Port Number */
#define Pipet_StepSizeB_PRT_NUM                (* (reg8 *) Pipet_StepSizeB__PRT) 
/* Connect to Analog Globals */                                                  
#define Pipet_StepSizeB_AG                     (* (reg8 *) Pipet_StepSizeB__AG)                       
/* Analog MUX bux enable */
#define Pipet_StepSizeB_AMUX                   (* (reg8 *) Pipet_StepSizeB__AMUX) 
/* Bidirectional Enable */                                                        
#define Pipet_StepSizeB_BIE                    (* (reg8 *) Pipet_StepSizeB__BIE)
/* Bit-mask for Aliased Register Access */
#define Pipet_StepSizeB_BIT_MASK               (* (reg8 *) Pipet_StepSizeB__BIT_MASK)
/* Bypass Enable */
#define Pipet_StepSizeB_BYP                    (* (reg8 *) Pipet_StepSizeB__BYP)
/* Port wide control signals */                                                   
#define Pipet_StepSizeB_CTL                    (* (reg8 *) Pipet_StepSizeB__CTL)
/* Drive Modes */
#define Pipet_StepSizeB_DM0                    (* (reg8 *) Pipet_StepSizeB__DM0) 
#define Pipet_StepSizeB_DM1                    (* (reg8 *) Pipet_StepSizeB__DM1)
#define Pipet_StepSizeB_DM2                    (* (reg8 *) Pipet_StepSizeB__DM2) 
/* Input Buffer Disable Override */
#define Pipet_StepSizeB_INP_DIS                (* (reg8 *) Pipet_StepSizeB__INP_DIS)
/* LCD Common or Segment Drive */
#define Pipet_StepSizeB_LCD_COM_SEG            (* (reg8 *) Pipet_StepSizeB__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pipet_StepSizeB_LCD_EN                 (* (reg8 *) Pipet_StepSizeB__LCD_EN)
/* Slew Rate Control */
#define Pipet_StepSizeB_SLW                    (* (reg8 *) Pipet_StepSizeB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pipet_StepSizeB_PRTDSI__CAPS_SEL       (* (reg8 *) Pipet_StepSizeB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pipet_StepSizeB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pipet_StepSizeB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pipet_StepSizeB_PRTDSI__OE_SEL0        (* (reg8 *) Pipet_StepSizeB__PRTDSI__OE_SEL0) 
#define Pipet_StepSizeB_PRTDSI__OE_SEL1        (* (reg8 *) Pipet_StepSizeB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pipet_StepSizeB_PRTDSI__OUT_SEL0       (* (reg8 *) Pipet_StepSizeB__PRTDSI__OUT_SEL0) 
#define Pipet_StepSizeB_PRTDSI__OUT_SEL1       (* (reg8 *) Pipet_StepSizeB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pipet_StepSizeB_PRTDSI__SYNC_OUT       (* (reg8 *) Pipet_StepSizeB__PRTDSI__SYNC_OUT) 


#if defined(Pipet_StepSizeB__INTSTAT)  /* Interrupt Registers */

    #define Pipet_StepSizeB_INTSTAT                (* (reg8 *) Pipet_StepSizeB__INTSTAT)
    #define Pipet_StepSizeB_SNAP                   (* (reg8 *) Pipet_StepSizeB__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pipet_StepSizeB_H */


/* [] END OF FILE */
