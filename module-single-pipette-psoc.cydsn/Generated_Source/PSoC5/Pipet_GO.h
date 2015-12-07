/*******************************************************************************
* File Name: Pipet_GO.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_Pipet_GO_H) /* CY_CONTROL_REG_Pipet_GO_H */
#define CY_CONTROL_REG_Pipet_GO_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Pipet_GO_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Pipet_GO_Write(uint8 control) ;
uint8   Pipet_GO_Read(void) ;

void Pipet_GO_SaveConfig(void) ;
void Pipet_GO_RestoreConfig(void) ;
void Pipet_GO_Sleep(void) ; 
void Pipet_GO_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Pipet_GO_Control        (* (reg8 *) Pipet_GO_Sync_ctrl_reg__CONTROL_REG )
#define Pipet_GO_Control_PTR    (  (reg8 *) Pipet_GO_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Pipet_GO_H */


/* [] END OF FILE */
