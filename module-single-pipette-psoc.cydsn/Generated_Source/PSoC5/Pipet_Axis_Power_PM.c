/*******************************************************************************
* File Name: Pipet_Axis_Power_PM.c  
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

#include "Pipet_Axis_Power.h"

static Pipet_Axis_Power_backupStruct Pipet_Axis_Power_backup;


/*******************************************************************************
* Function Name: Pipet_Axis_Power_SaveConfig
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
void Pipet_Axis_Power_SaveConfig(void) 
{
    if (!((Pipet_Axis_Power_CR1 & Pipet_Axis_Power_SRC_MASK) == Pipet_Axis_Power_SRC_UDB))
    {
        Pipet_Axis_Power_backup.data_value = Pipet_Axis_Power_Data;
    }
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_RestoreConfig
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
void Pipet_Axis_Power_RestoreConfig(void) 
{
    if (!((Pipet_Axis_Power_CR1 & Pipet_Axis_Power_SRC_MASK) == Pipet_Axis_Power_SRC_UDB))
    {
        if((Pipet_Axis_Power_Strobe & Pipet_Axis_Power_STRB_MASK) == Pipet_Axis_Power_STRB_EN)
        {
            Pipet_Axis_Power_Strobe &= (uint8)(~Pipet_Axis_Power_STRB_MASK);
            Pipet_Axis_Power_Data = Pipet_Axis_Power_backup.data_value;
            Pipet_Axis_Power_Strobe |= Pipet_Axis_Power_STRB_EN;
        }
        else
        {
            Pipet_Axis_Power_Data = Pipet_Axis_Power_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Sleep
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
*  Pipet_Axis_Power_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Pipet_Axis_Power_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Pipet_Axis_Power_ACT_PWR_EN == (Pipet_Axis_Power_PWRMGR & Pipet_Axis_Power_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Pipet_Axis_Power_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Pipet_Axis_Power_backup.enableState = 0u;
    }
    
    Pipet_Axis_Power_Stop();
    Pipet_Axis_Power_SaveConfig();
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Wakeup
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
*  Pipet_Axis_Power_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Pipet_Axis_Power_Wakeup(void) 
{
    Pipet_Axis_Power_RestoreConfig();
    
    if(Pipet_Axis_Power_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Pipet_Axis_Power_Enable();

        /* Restore the data register */
        Pipet_Axis_Power_SetValue(Pipet_Axis_Power_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
