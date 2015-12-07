/*******************************************************************************
* File Name: Z_step_nbr_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Z_step_nbr.h"

static Z_step_nbr_backupStruct Z_step_nbr_backup;


/*******************************************************************************
* Function Name: Z_step_nbr_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Z_step_nbr_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Z_step_nbr_SaveConfig(void) 
{
    #if (!Z_step_nbr_UsingFixedFunction)

        Z_step_nbr_backup.CounterUdb = Z_step_nbr_ReadCounter();

        #if(!Z_step_nbr_ControlRegRemoved)
            Z_step_nbr_backup.CounterControlRegister = Z_step_nbr_ReadControlRegister();
        #endif /* (!Z_step_nbr_ControlRegRemoved) */

    #endif /* (!Z_step_nbr_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Z_step_nbr_RestoreConfig
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
* Global variables:
*  Z_step_nbr_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Z_step_nbr_RestoreConfig(void) 
{      
    #if (!Z_step_nbr_UsingFixedFunction)

       Z_step_nbr_WriteCounter(Z_step_nbr_backup.CounterUdb);

        #if(!Z_step_nbr_ControlRegRemoved)
            Z_step_nbr_WriteControlRegister(Z_step_nbr_backup.CounterControlRegister);
        #endif /* (!Z_step_nbr_ControlRegRemoved) */

    #endif /* (!Z_step_nbr_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Z_step_nbr_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Z_step_nbr_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Z_step_nbr_Sleep(void) 
{
    #if(!Z_step_nbr_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Z_step_nbr_CTRL_ENABLE == (Z_step_nbr_CONTROL & Z_step_nbr_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Z_step_nbr_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Z_step_nbr_backup.CounterEnableState = 0u;
        }
    #else
        Z_step_nbr_backup.CounterEnableState = 1u;
        if(Z_step_nbr_backup.CounterEnableState != 0u)
        {
            Z_step_nbr_backup.CounterEnableState = 0u;
        }
    #endif /* (!Z_step_nbr_ControlRegRemoved) */
    
    Z_step_nbr_Stop();
    Z_step_nbr_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_step_nbr_Wakeup
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
*  Z_step_nbr_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Z_step_nbr_Wakeup(void) 
{
    Z_step_nbr_RestoreConfig();
    #if(!Z_step_nbr_ControlRegRemoved)
        if(Z_step_nbr_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Z_step_nbr_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Z_step_nbr_ControlRegRemoved) */
    
}


/* [] END OF FILE */
