/*******************************************************************************
* File Name: EN2.h  
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

#if !defined(CY_PINS_EN2_H) /* Pins EN2_H */
#define CY_PINS_EN2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EN2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EN2__PORT == 15 && ((EN2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EN2_Write(uint8 value) ;
void    EN2_SetDriveMode(uint8 mode) ;
uint8   EN2_ReadDataReg(void) ;
uint8   EN2_Read(void) ;
uint8   EN2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EN2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EN2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EN2_DM_RES_UP          PIN_DM_RES_UP
#define EN2_DM_RES_DWN         PIN_DM_RES_DWN
#define EN2_DM_OD_LO           PIN_DM_OD_LO
#define EN2_DM_OD_HI           PIN_DM_OD_HI
#define EN2_DM_STRONG          PIN_DM_STRONG
#define EN2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EN2_MASK               EN2__MASK
#define EN2_SHIFT              EN2__SHIFT
#define EN2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN2_PS                     (* (reg8 *) EN2__PS)
/* Data Register */
#define EN2_DR                     (* (reg8 *) EN2__DR)
/* Port Number */
#define EN2_PRT_NUM                (* (reg8 *) EN2__PRT) 
/* Connect to Analog Globals */                                                  
#define EN2_AG                     (* (reg8 *) EN2__AG)                       
/* Analog MUX bux enable */
#define EN2_AMUX                   (* (reg8 *) EN2__AMUX) 
/* Bidirectional Enable */                                                        
#define EN2_BIE                    (* (reg8 *) EN2__BIE)
/* Bit-mask for Aliased Register Access */
#define EN2_BIT_MASK               (* (reg8 *) EN2__BIT_MASK)
/* Bypass Enable */
#define EN2_BYP                    (* (reg8 *) EN2__BYP)
/* Port wide control signals */                                                   
#define EN2_CTL                    (* (reg8 *) EN2__CTL)
/* Drive Modes */
#define EN2_DM0                    (* (reg8 *) EN2__DM0) 
#define EN2_DM1                    (* (reg8 *) EN2__DM1)
#define EN2_DM2                    (* (reg8 *) EN2__DM2) 
/* Input Buffer Disable Override */
#define EN2_INP_DIS                (* (reg8 *) EN2__INP_DIS)
/* LCD Common or Segment Drive */
#define EN2_LCD_COM_SEG            (* (reg8 *) EN2__LCD_COM_SEG)
/* Enable Segment LCD */
#define EN2_LCD_EN                 (* (reg8 *) EN2__LCD_EN)
/* Slew Rate Control */
#define EN2_SLW                    (* (reg8 *) EN2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EN2_PRTDSI__CAPS_SEL       (* (reg8 *) EN2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EN2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EN2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EN2_PRTDSI__OE_SEL0        (* (reg8 *) EN2__PRTDSI__OE_SEL0) 
#define EN2_PRTDSI__OE_SEL1        (* (reg8 *) EN2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EN2_PRTDSI__OUT_SEL0       (* (reg8 *) EN2__PRTDSI__OUT_SEL0) 
#define EN2_PRTDSI__OUT_SEL1       (* (reg8 *) EN2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EN2_PRTDSI__SYNC_OUT       (* (reg8 *) EN2__PRTDSI__SYNC_OUT) 


#if defined(EN2__INTSTAT)  /* Interrupt Registers */

    #define EN2_INTSTAT                (* (reg8 *) EN2__INTSTAT)
    #define EN2_SNAP                   (* (reg8 *) EN2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EN2_H */


/* [] END OF FILE */
