/*******************************************************************************
* File Name: CAN_Standby.h  
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

#if !defined(CY_PINS_CAN_Standby_H) /* Pins CAN_Standby_H */
#define CY_PINS_CAN_Standby_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAN_Standby_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAN_Standby__PORT == 15 && ((CAN_Standby__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CAN_Standby_Write(uint8 value) ;
void    CAN_Standby_SetDriveMode(uint8 mode) ;
uint8   CAN_Standby_ReadDataReg(void) ;
uint8   CAN_Standby_Read(void) ;
uint8   CAN_Standby_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CAN_Standby_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CAN_Standby_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CAN_Standby_DM_RES_UP          PIN_DM_RES_UP
#define CAN_Standby_DM_RES_DWN         PIN_DM_RES_DWN
#define CAN_Standby_DM_OD_LO           PIN_DM_OD_LO
#define CAN_Standby_DM_OD_HI           PIN_DM_OD_HI
#define CAN_Standby_DM_STRONG          PIN_DM_STRONG
#define CAN_Standby_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CAN_Standby_MASK               CAN_Standby__MASK
#define CAN_Standby_SHIFT              CAN_Standby__SHIFT
#define CAN_Standby_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAN_Standby_PS                     (* (reg8 *) CAN_Standby__PS)
/* Data Register */
#define CAN_Standby_DR                     (* (reg8 *) CAN_Standby__DR)
/* Port Number */
#define CAN_Standby_PRT_NUM                (* (reg8 *) CAN_Standby__PRT) 
/* Connect to Analog Globals */                                                  
#define CAN_Standby_AG                     (* (reg8 *) CAN_Standby__AG)                       
/* Analog MUX bux enable */
#define CAN_Standby_AMUX                   (* (reg8 *) CAN_Standby__AMUX) 
/* Bidirectional Enable */                                                        
#define CAN_Standby_BIE                    (* (reg8 *) CAN_Standby__BIE)
/* Bit-mask for Aliased Register Access */
#define CAN_Standby_BIT_MASK               (* (reg8 *) CAN_Standby__BIT_MASK)
/* Bypass Enable */
#define CAN_Standby_BYP                    (* (reg8 *) CAN_Standby__BYP)
/* Port wide control signals */                                                   
#define CAN_Standby_CTL                    (* (reg8 *) CAN_Standby__CTL)
/* Drive Modes */
#define CAN_Standby_DM0                    (* (reg8 *) CAN_Standby__DM0) 
#define CAN_Standby_DM1                    (* (reg8 *) CAN_Standby__DM1)
#define CAN_Standby_DM2                    (* (reg8 *) CAN_Standby__DM2) 
/* Input Buffer Disable Override */
#define CAN_Standby_INP_DIS                (* (reg8 *) CAN_Standby__INP_DIS)
/* LCD Common or Segment Drive */
#define CAN_Standby_LCD_COM_SEG            (* (reg8 *) CAN_Standby__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAN_Standby_LCD_EN                 (* (reg8 *) CAN_Standby__LCD_EN)
/* Slew Rate Control */
#define CAN_Standby_SLW                    (* (reg8 *) CAN_Standby__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAN_Standby_PRTDSI__CAPS_SEL       (* (reg8 *) CAN_Standby__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAN_Standby_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAN_Standby__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAN_Standby_PRTDSI__OE_SEL0        (* (reg8 *) CAN_Standby__PRTDSI__OE_SEL0) 
#define CAN_Standby_PRTDSI__OE_SEL1        (* (reg8 *) CAN_Standby__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAN_Standby_PRTDSI__OUT_SEL0       (* (reg8 *) CAN_Standby__PRTDSI__OUT_SEL0) 
#define CAN_Standby_PRTDSI__OUT_SEL1       (* (reg8 *) CAN_Standby__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAN_Standby_PRTDSI__SYNC_OUT       (* (reg8 *) CAN_Standby__PRTDSI__SYNC_OUT) 


#if defined(CAN_Standby__INTSTAT)  /* Interrupt Registers */

    #define CAN_Standby_INTSTAT                (* (reg8 *) CAN_Standby__INTSTAT)
    #define CAN_Standby_SNAP                   (* (reg8 *) CAN_Standby__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAN_Standby_H */


/* [] END OF FILE */
