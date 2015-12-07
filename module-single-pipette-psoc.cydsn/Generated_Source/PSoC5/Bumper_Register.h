/*******************************************************************************
* File Name: Bumper_Register.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_Bumper_Register_H) /* CY_STATUS_REG_Bumper_Register_H */
#define CY_STATUS_REG_Bumper_Register_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} Bumper_Register_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 Bumper_Register_Read(void) ;
void Bumper_Register_InterruptEnable(void) ;
void Bumper_Register_InterruptDisable(void) ;
void Bumper_Register_WriteMask(uint8 mask) ;
uint8 Bumper_Register_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Bumper_Register_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Bumper_Register_INPUTS              4


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Bumper_Register_Status             (* (reg8 *) Bumper_Register_sts_intr_sts_reg__STATUS_REG )
#define Bumper_Register_Status_PTR         (  (reg8 *) Bumper_Register_sts_intr_sts_reg__STATUS_REG )
#define Bumper_Register_Status_Mask        (* (reg8 *) Bumper_Register_sts_intr_sts_reg__MASK_REG )
#define Bumper_Register_Status_Aux_Ctrl    (* (reg8 *) Bumper_Register_sts_intr_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Bumper_Register_H */


/* [] END OF FILE */
