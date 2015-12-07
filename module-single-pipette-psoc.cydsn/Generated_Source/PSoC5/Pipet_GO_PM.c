/*******************************************************************************
* File Name: Pipet_GO_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Pipet_GO.h"

/* Check for removal by optimization */
#if !defined(Pipet_GO_Sync_ctrl_reg__REMOVED)

static Pipet_GO_BACKUP_STRUCT  Pipet_GO_backup = {0u};

    
/*******************************************************************************
* Function Name: Pipet_GO_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Pipet_GO_SaveConfig(void) 
{
    Pipet_GO_backup.controlState = Pipet_GO_Control;
}


/*******************************************************************************
* Function Name: Pipet_GO_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Pipet_GO_RestoreConfig(void) 
{
     Pipet_GO_Control = Pipet_GO_backup.controlState;
}


/*******************************************************************************
* Function Name: Pipet_GO_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Pipet_GO_Sleep(void) 
{
    Pipet_GO_SaveConfig();
}


/*******************************************************************************
* Function Name: Pipet_GO_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Pipet_GO_Wakeup(void)  
{
    Pipet_GO_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
