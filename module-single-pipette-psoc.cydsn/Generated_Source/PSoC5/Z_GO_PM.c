/*******************************************************************************
* File Name: Z_GO_PM.c
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

#include "Z_GO.h"

/* Check for removal by optimization */
#if !defined(Z_GO_Sync_ctrl_reg__REMOVED)

static Z_GO_BACKUP_STRUCT  Z_GO_backup = {0u};

    
/*******************************************************************************
* Function Name: Z_GO_SaveConfig
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
void Z_GO_SaveConfig(void) 
{
    Z_GO_backup.controlState = Z_GO_Control;
}


/*******************************************************************************
* Function Name: Z_GO_RestoreConfig
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
void Z_GO_RestoreConfig(void) 
{
     Z_GO_Control = Z_GO_backup.controlState;
}


/*******************************************************************************
* Function Name: Z_GO_Sleep
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
void Z_GO_Sleep(void) 
{
    Z_GO_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_GO_Wakeup
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
void Z_GO_Wakeup(void)  
{
    Z_GO_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
