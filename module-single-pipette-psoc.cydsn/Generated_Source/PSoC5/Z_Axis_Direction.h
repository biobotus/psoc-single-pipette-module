/*******************************************************************************
* File Name: Z_Axis_Direction.h  
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

#if !defined(CY_PINS_Z_Axis_Direction_H) /* Pins Z_Axis_Direction_H */
#define CY_PINS_Z_Axis_Direction_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Z_Axis_Direction_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Z_Axis_Direction__PORT == 15 && ((Z_Axis_Direction__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Z_Axis_Direction_Write(uint8 value) ;
void    Z_Axis_Direction_SetDriveMode(uint8 mode) ;
uint8   Z_Axis_Direction_ReadDataReg(void) ;
uint8   Z_Axis_Direction_Read(void) ;
uint8   Z_Axis_Direction_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Z_Axis_Direction_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Z_Axis_Direction_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Z_Axis_Direction_DM_RES_UP          PIN_DM_RES_UP
#define Z_Axis_Direction_DM_RES_DWN         PIN_DM_RES_DWN
#define Z_Axis_Direction_DM_OD_LO           PIN_DM_OD_LO
#define Z_Axis_Direction_DM_OD_HI           PIN_DM_OD_HI
#define Z_Axis_Direction_DM_STRONG          PIN_DM_STRONG
#define Z_Axis_Direction_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Z_Axis_Direction_MASK               Z_Axis_Direction__MASK
#define Z_Axis_Direction_SHIFT              Z_Axis_Direction__SHIFT
#define Z_Axis_Direction_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Z_Axis_Direction_PS                     (* (reg8 *) Z_Axis_Direction__PS)
/* Data Register */
#define Z_Axis_Direction_DR                     (* (reg8 *) Z_Axis_Direction__DR)
/* Port Number */
#define Z_Axis_Direction_PRT_NUM                (* (reg8 *) Z_Axis_Direction__PRT) 
/* Connect to Analog Globals */                                                  
#define Z_Axis_Direction_AG                     (* (reg8 *) Z_Axis_Direction__AG)                       
/* Analog MUX bux enable */
#define Z_Axis_Direction_AMUX                   (* (reg8 *) Z_Axis_Direction__AMUX) 
/* Bidirectional Enable */                                                        
#define Z_Axis_Direction_BIE                    (* (reg8 *) Z_Axis_Direction__BIE)
/* Bit-mask for Aliased Register Access */
#define Z_Axis_Direction_BIT_MASK               (* (reg8 *) Z_Axis_Direction__BIT_MASK)
/* Bypass Enable */
#define Z_Axis_Direction_BYP                    (* (reg8 *) Z_Axis_Direction__BYP)
/* Port wide control signals */                                                   
#define Z_Axis_Direction_CTL                    (* (reg8 *) Z_Axis_Direction__CTL)
/* Drive Modes */
#define Z_Axis_Direction_DM0                    (* (reg8 *) Z_Axis_Direction__DM0) 
#define Z_Axis_Direction_DM1                    (* (reg8 *) Z_Axis_Direction__DM1)
#define Z_Axis_Direction_DM2                    (* (reg8 *) Z_Axis_Direction__DM2) 
/* Input Buffer Disable Override */
#define Z_Axis_Direction_INP_DIS                (* (reg8 *) Z_Axis_Direction__INP_DIS)
/* LCD Common or Segment Drive */
#define Z_Axis_Direction_LCD_COM_SEG            (* (reg8 *) Z_Axis_Direction__LCD_COM_SEG)
/* Enable Segment LCD */
#define Z_Axis_Direction_LCD_EN                 (* (reg8 *) Z_Axis_Direction__LCD_EN)
/* Slew Rate Control */
#define Z_Axis_Direction_SLW                    (* (reg8 *) Z_Axis_Direction__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Z_Axis_Direction_PRTDSI__CAPS_SEL       (* (reg8 *) Z_Axis_Direction__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Z_Axis_Direction_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Z_Axis_Direction__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Z_Axis_Direction_PRTDSI__OE_SEL0        (* (reg8 *) Z_Axis_Direction__PRTDSI__OE_SEL0) 
#define Z_Axis_Direction_PRTDSI__OE_SEL1        (* (reg8 *) Z_Axis_Direction__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Z_Axis_Direction_PRTDSI__OUT_SEL0       (* (reg8 *) Z_Axis_Direction__PRTDSI__OUT_SEL0) 
#define Z_Axis_Direction_PRTDSI__OUT_SEL1       (* (reg8 *) Z_Axis_Direction__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Z_Axis_Direction_PRTDSI__SYNC_OUT       (* (reg8 *) Z_Axis_Direction__PRTDSI__SYNC_OUT) 


#if defined(Z_Axis_Direction__INTSTAT)  /* Interrupt Registers */

    #define Z_Axis_Direction_INTSTAT                (* (reg8 *) Z_Axis_Direction__INTSTAT)
    #define Z_Axis_Direction_SNAP                   (* (reg8 *) Z_Axis_Direction__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Z_Axis_Direction_H */


/* [] END OF FILE */
