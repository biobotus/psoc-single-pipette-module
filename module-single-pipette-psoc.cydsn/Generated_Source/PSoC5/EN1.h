/*******************************************************************************
* File Name: EN1.h  
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

#if !defined(CY_PINS_EN1_H) /* Pins EN1_H */
#define CY_PINS_EN1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EN1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EN1__PORT == 15 && ((EN1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EN1_Write(uint8 value) ;
void    EN1_SetDriveMode(uint8 mode) ;
uint8   EN1_ReadDataReg(void) ;
uint8   EN1_Read(void) ;
uint8   EN1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EN1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EN1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EN1_DM_RES_UP          PIN_DM_RES_UP
#define EN1_DM_RES_DWN         PIN_DM_RES_DWN
#define EN1_DM_OD_LO           PIN_DM_OD_LO
#define EN1_DM_OD_HI           PIN_DM_OD_HI
#define EN1_DM_STRONG          PIN_DM_STRONG
#define EN1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EN1_MASK               EN1__MASK
#define EN1_SHIFT              EN1__SHIFT
#define EN1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN1_PS                     (* (reg8 *) EN1__PS)
/* Data Register */
#define EN1_DR                     (* (reg8 *) EN1__DR)
/* Port Number */
#define EN1_PRT_NUM                (* (reg8 *) EN1__PRT) 
/* Connect to Analog Globals */                                                  
#define EN1_AG                     (* (reg8 *) EN1__AG)                       
/* Analog MUX bux enable */
#define EN1_AMUX                   (* (reg8 *) EN1__AMUX) 
/* Bidirectional Enable */                                                        
#define EN1_BIE                    (* (reg8 *) EN1__BIE)
/* Bit-mask for Aliased Register Access */
#define EN1_BIT_MASK               (* (reg8 *) EN1__BIT_MASK)
/* Bypass Enable */
#define EN1_BYP                    (* (reg8 *) EN1__BYP)
/* Port wide control signals */                                                   
#define EN1_CTL                    (* (reg8 *) EN1__CTL)
/* Drive Modes */
#define EN1_DM0                    (* (reg8 *) EN1__DM0) 
#define EN1_DM1                    (* (reg8 *) EN1__DM1)
#define EN1_DM2                    (* (reg8 *) EN1__DM2) 
/* Input Buffer Disable Override */
#define EN1_INP_DIS                (* (reg8 *) EN1__INP_DIS)
/* LCD Common or Segment Drive */
#define EN1_LCD_COM_SEG            (* (reg8 *) EN1__LCD_COM_SEG)
/* Enable Segment LCD */
#define EN1_LCD_EN                 (* (reg8 *) EN1__LCD_EN)
/* Slew Rate Control */
#define EN1_SLW                    (* (reg8 *) EN1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EN1_PRTDSI__CAPS_SEL       (* (reg8 *) EN1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EN1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EN1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EN1_PRTDSI__OE_SEL0        (* (reg8 *) EN1__PRTDSI__OE_SEL0) 
#define EN1_PRTDSI__OE_SEL1        (* (reg8 *) EN1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EN1_PRTDSI__OUT_SEL0       (* (reg8 *) EN1__PRTDSI__OUT_SEL0) 
#define EN1_PRTDSI__OUT_SEL1       (* (reg8 *) EN1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EN1_PRTDSI__SYNC_OUT       (* (reg8 *) EN1__PRTDSI__SYNC_OUT) 


#if defined(EN1__INTSTAT)  /* Interrupt Registers */

    #define EN1_INTSTAT                (* (reg8 *) EN1__INTSTAT)
    #define EN1_SNAP                   (* (reg8 *) EN1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EN1_H */


/* [] END OF FILE */
