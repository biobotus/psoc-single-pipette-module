/*******************************************************************************
* File Name: Bumper_Z_Down.h  
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

#if !defined(CY_PINS_Bumper_Z_Down_H) /* Pins Bumper_Z_Down_H */
#define CY_PINS_Bumper_Z_Down_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bumper_Z_Down_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bumper_Z_Down__PORT == 15 && ((Bumper_Z_Down__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Bumper_Z_Down_Write(uint8 value) ;
void    Bumper_Z_Down_SetDriveMode(uint8 mode) ;
uint8   Bumper_Z_Down_ReadDataReg(void) ;
uint8   Bumper_Z_Down_Read(void) ;
uint8   Bumper_Z_Down_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Bumper_Z_Down_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Bumper_Z_Down_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Bumper_Z_Down_DM_RES_UP          PIN_DM_RES_UP
#define Bumper_Z_Down_DM_RES_DWN         PIN_DM_RES_DWN
#define Bumper_Z_Down_DM_OD_LO           PIN_DM_OD_LO
#define Bumper_Z_Down_DM_OD_HI           PIN_DM_OD_HI
#define Bumper_Z_Down_DM_STRONG          PIN_DM_STRONG
#define Bumper_Z_Down_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Bumper_Z_Down_MASK               Bumper_Z_Down__MASK
#define Bumper_Z_Down_SHIFT              Bumper_Z_Down__SHIFT
#define Bumper_Z_Down_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bumper_Z_Down_PS                     (* (reg8 *) Bumper_Z_Down__PS)
/* Data Register */
#define Bumper_Z_Down_DR                     (* (reg8 *) Bumper_Z_Down__DR)
/* Port Number */
#define Bumper_Z_Down_PRT_NUM                (* (reg8 *) Bumper_Z_Down__PRT) 
/* Connect to Analog Globals */                                                  
#define Bumper_Z_Down_AG                     (* (reg8 *) Bumper_Z_Down__AG)                       
/* Analog MUX bux enable */
#define Bumper_Z_Down_AMUX                   (* (reg8 *) Bumper_Z_Down__AMUX) 
/* Bidirectional Enable */                                                        
#define Bumper_Z_Down_BIE                    (* (reg8 *) Bumper_Z_Down__BIE)
/* Bit-mask for Aliased Register Access */
#define Bumper_Z_Down_BIT_MASK               (* (reg8 *) Bumper_Z_Down__BIT_MASK)
/* Bypass Enable */
#define Bumper_Z_Down_BYP                    (* (reg8 *) Bumper_Z_Down__BYP)
/* Port wide control signals */                                                   
#define Bumper_Z_Down_CTL                    (* (reg8 *) Bumper_Z_Down__CTL)
/* Drive Modes */
#define Bumper_Z_Down_DM0                    (* (reg8 *) Bumper_Z_Down__DM0) 
#define Bumper_Z_Down_DM1                    (* (reg8 *) Bumper_Z_Down__DM1)
#define Bumper_Z_Down_DM2                    (* (reg8 *) Bumper_Z_Down__DM2) 
/* Input Buffer Disable Override */
#define Bumper_Z_Down_INP_DIS                (* (reg8 *) Bumper_Z_Down__INP_DIS)
/* LCD Common or Segment Drive */
#define Bumper_Z_Down_LCD_COM_SEG            (* (reg8 *) Bumper_Z_Down__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bumper_Z_Down_LCD_EN                 (* (reg8 *) Bumper_Z_Down__LCD_EN)
/* Slew Rate Control */
#define Bumper_Z_Down_SLW                    (* (reg8 *) Bumper_Z_Down__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bumper_Z_Down_PRTDSI__CAPS_SEL       (* (reg8 *) Bumper_Z_Down__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bumper_Z_Down_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bumper_Z_Down__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bumper_Z_Down_PRTDSI__OE_SEL0        (* (reg8 *) Bumper_Z_Down__PRTDSI__OE_SEL0) 
#define Bumper_Z_Down_PRTDSI__OE_SEL1        (* (reg8 *) Bumper_Z_Down__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bumper_Z_Down_PRTDSI__OUT_SEL0       (* (reg8 *) Bumper_Z_Down__PRTDSI__OUT_SEL0) 
#define Bumper_Z_Down_PRTDSI__OUT_SEL1       (* (reg8 *) Bumper_Z_Down__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bumper_Z_Down_PRTDSI__SYNC_OUT       (* (reg8 *) Bumper_Z_Down__PRTDSI__SYNC_OUT) 


#if defined(Bumper_Z_Down__INTSTAT)  /* Interrupt Registers */

    #define Bumper_Z_Down_INTSTAT                (* (reg8 *) Bumper_Z_Down__INTSTAT)
    #define Bumper_Z_Down_SNAP                   (* (reg8 *) Bumper_Z_Down__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bumper_Z_Down_H */


/* [] END OF FILE */
