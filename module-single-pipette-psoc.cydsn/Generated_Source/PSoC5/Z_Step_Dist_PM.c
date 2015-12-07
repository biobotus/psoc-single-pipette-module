/*******************************************************************************
* File Name: Z_Step_Dist_PM.c  
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

#include "Z_Step_Dist.h"

static Z_Step_Dist_backupStruct Z_Step_Dist_backup;


/*******************************************************************************
* Function Name: Z_Step_Dist_SaveConfig
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
*  Z_Step_Dist_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Z_Step_Dist_SaveConfig(void) 
{
    #if (!Z_Step_Dist_UsingFixedFunction)

        Z_Step_Dist_backup.CounterUdb = Z_Step_Dist_ReadCounter();

        #if(!Z_Step_Dist_ControlRegRemoved)
            Z_Step_Dist_backup.CounterControlRegister = Z_Step_Dist_ReadControlRegister();
        #endif /* (!Z_Step_Dist_ControlRegRemoved) */

    #endif /* (!Z_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Z_Step_Dist_RestoreConfig
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
*  Z_Step_Dist_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Z_Step_Dist_RestoreConfig(void) 
{      
    #if (!Z_Step_Dist_UsingFixedFunction)

       Z_Step_Dist_WriteCounter(Z_Step_Dist_backup.CounterUdb);

        #if(!Z_Step_Dist_ControlRegRemoved)
            Z_Step_Dist_WriteControlRegister(Z_Step_Dist_backup.CounterControlRegister);
        #endif /* (!Z_Step_Dist_ControlRegRemoved) */

    #endif /* (!Z_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Z_Step_Dist_Sleep
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
*  Z_Step_Dist_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Z_Step_Dist_Sleep(void) 
{
    #if(!Z_Step_Dist_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Z_Step_Dist_CTRL_ENABLE == (Z_Step_Dist_CONTROL & Z_Step_Dist_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Z_Step_Dist_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Z_Step_Dist_backup.CounterEnableState = 0u;
        }
    #else
        Z_Step_Dist_backup.CounterEnableState = 1u;
        if(Z_Step_Dist_backup.CounterEnableState != 0u)
        {
            Z_Step_Dist_backup.CounterEnableState = 0u;
        }
    #endif /* (!Z_Step_Dist_ControlRegRemoved) */
    
    Z_Step_Dist_Stop();
    Z_Step_Dist_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_Step_Dist_Wakeup
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
*  Z_Step_Dist_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Z_Step_Dist_Wakeup(void) 
{
    Z_Step_Dist_RestoreConfig();
    #if(!Z_Step_Dist_ControlRegRemoved)
        if(Z_Step_Dist_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Z_Step_Dist_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Z_Step_Dist_ControlRegRemoved) */
    
}


/* [] END OF FILE */
