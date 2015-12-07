/*******************************************************************************
* File Name: Z_GO1_PM.c
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

#include "Z_GO1.h"

/* Check for removal by optimization */
#if !defined(Z_GO1_Sync_ctrl_reg__REMOVED)

static Z_GO1_BACKUP_STRUCT  Z_GO1_backup = {0u};

    
/*******************************************************************************
* Function Name: Z_GO1_SaveConfig
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
void Z_GO1_SaveConfig(void) 
{
    Z_GO1_backup.controlState = Z_GO1_Control;
}


/*******************************************************************************
* Function Name: Z_GO1_RestoreConfig
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
void Z_GO1_RestoreConfig(void) 
{
     Z_GO1_Control = Z_GO1_backup.controlState;
}


/*******************************************************************************
* Function Name: Z_GO1_Sleep
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
void Z_GO1_Sleep(void) 
{
    Z_GO1_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_GO1_Wakeup
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
void Z_GO1_Wakeup(void)  
{
    Z_GO1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
