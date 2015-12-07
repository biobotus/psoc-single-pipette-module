/*******************************************************************************
* File Name: Step2.h  
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

#if !defined(CY_PINS_Step2_H) /* Pins Step2_H */
#define CY_PINS_Step2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Step2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Step2__PORT == 15 && ((Step2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Step2_Write(uint8 value) ;
void    Step2_SetDriveMode(uint8 mode) ;
uint8   Step2_ReadDataReg(void) ;
uint8   Step2_Read(void) ;
uint8   Step2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Step2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Step2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Step2_DM_RES_UP          PIN_DM_RES_UP
#define Step2_DM_RES_DWN         PIN_DM_RES_DWN
#define Step2_DM_OD_LO           PIN_DM_OD_LO
#define Step2_DM_OD_HI           PIN_DM_OD_HI
#define Step2_DM_STRONG          PIN_DM_STRONG
#define Step2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Step2_MASK               Step2__MASK
#define Step2_SHIFT              Step2__SHIFT
#define Step2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Step2_PS                     (* (reg8 *) Step2__PS)
/* Data Register */
#define Step2_DR                     (* (reg8 *) Step2__DR)
/* Port Number */
#define Step2_PRT_NUM                (* (reg8 *) Step2__PRT) 
/* Connect to Analog Globals */                                                  
#define Step2_AG                     (* (reg8 *) Step2__AG)                       
/* Analog MUX bux enable */
#define Step2_AMUX                   (* (reg8 *) Step2__AMUX) 
/* Bidirectional Enable */                                                        
#define Step2_BIE                    (* (reg8 *) Step2__BIE)
/* Bit-mask for Aliased Register Access */
#define Step2_BIT_MASK               (* (reg8 *) Step2__BIT_MASK)
/* Bypass Enable */
#define Step2_BYP                    (* (reg8 *) Step2__BYP)
/* Port wide control signals */                                                   
#define Step2_CTL                    (* (reg8 *) Step2__CTL)
/* Drive Modes */
#define Step2_DM0                    (* (reg8 *) Step2__DM0) 
#define Step2_DM1                    (* (reg8 *) Step2__DM1)
#define Step2_DM2                    (* (reg8 *) Step2__DM2) 
/* Input Buffer Disable Override */
#define Step2_INP_DIS                (* (reg8 *) Step2__INP_DIS)
/* LCD Common or Segment Drive */
#define Step2_LCD_COM_SEG            (* (reg8 *) Step2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Step2_LCD_EN                 (* (reg8 *) Step2__LCD_EN)
/* Slew Rate Control */
#define Step2_SLW                    (* (reg8 *) Step2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Step2_PRTDSI__CAPS_SEL       (* (reg8 *) Step2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Step2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Step2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Step2_PRTDSI__OE_SEL0        (* (reg8 *) Step2__PRTDSI__OE_SEL0) 
#define Step2_PRTDSI__OE_SEL1        (* (reg8 *) Step2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Step2_PRTDSI__OUT_SEL0       (* (reg8 *) Step2__PRTDSI__OUT_SEL0) 
#define Step2_PRTDSI__OUT_SEL1       (* (reg8 *) Step2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Step2_PRTDSI__SYNC_OUT       (* (reg8 *) Step2__PRTDSI__SYNC_OUT) 


#if defined(Step2__INTSTAT)  /* Interrupt Registers */

    #define Step2_INTSTAT                (* (reg8 *) Step2__INTSTAT)
    #define Step2_SNAP                   (* (reg8 *) Step2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Step2_H */


/* [] END OF FILE */
