/*******************************************************************************
* File Name: Z_Axis_Power_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Z_Axis_Power.h"

static Z_Axis_Power_backupStruct Z_Axis_Power_backup;


/*******************************************************************************
* Function Name: Z_Axis_Power_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Z_Axis_Power_SaveConfig(void) 
{
    if (!((Z_Axis_Power_CR1 & Z_Axis_Power_SRC_MASK) == Z_Axis_Power_SRC_UDB))
    {
        Z_Axis_Power_backup.data_value = Z_Axis_Power_Data;
    }
}


/*******************************************************************************
* Function Name: Z_Axis_Power_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void Z_Axis_Power_RestoreConfig(void) 
{
    if (!((Z_Axis_Power_CR1 & Z_Axis_Power_SRC_MASK) == Z_Axis_Power_SRC_UDB))
    {
        if((Z_Axis_Power_Strobe & Z_Axis_Power_STRB_MASK) == Z_Axis_Power_STRB_EN)
        {
            Z_Axis_Power_Strobe &= (uint8)(~Z_Axis_Power_STRB_MASK);
            Z_Axis_Power_Data = Z_Axis_Power_backup.data_value;
            Z_Axis_Power_Strobe |= Z_Axis_Power_STRB_EN;
        }
        else
        {
            Z_Axis_Power_Data = Z_Axis_Power_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Z_Axis_Power_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  Z_Axis_Power_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Z_Axis_Power_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Z_Axis_Power_ACT_PWR_EN == (Z_Axis_Power_PWRMGR & Z_Axis_Power_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Z_Axis_Power_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Z_Axis_Power_backup.enableState = 0u;
    }
    
    Z_Axis_Power_Stop();
    Z_Axis_Power_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_Axis_Power_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Z_Axis_Power_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Z_Axis_Power_Wakeup(void) 
{
    Z_Axis_Power_RestoreConfig();
    
    if(Z_Axis_Power_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Z_Axis_Power_Enable();

        /* Restore the data register */
        Z_Axis_Power_SetValue(Z_Axis_Power_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
