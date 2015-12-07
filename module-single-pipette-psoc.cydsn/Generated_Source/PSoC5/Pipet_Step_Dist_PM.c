/*******************************************************************************
* File Name: Pipet_Step_Dist_PM.c  
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

#include "Pipet_Step_Dist.h"

static Pipet_Step_Dist_backupStruct Pipet_Step_Dist_backup;


/*******************************************************************************
* Function Name: Pipet_Step_Dist_SaveConfig
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
*  Pipet_Step_Dist_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Pipet_Step_Dist_SaveConfig(void) 
{
    #if (!Pipet_Step_Dist_UsingFixedFunction)

        Pipet_Step_Dist_backup.CounterUdb = Pipet_Step_Dist_ReadCounter();

        #if(!Pipet_Step_Dist_ControlRegRemoved)
            Pipet_Step_Dist_backup.CounterControlRegister = Pipet_Step_Dist_ReadControlRegister();
        #endif /* (!Pipet_Step_Dist_ControlRegRemoved) */

    #endif /* (!Pipet_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pipet_Step_Dist_RestoreConfig
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
*  Pipet_Step_Dist_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Pipet_Step_Dist_RestoreConfig(void) 
{      
    #if (!Pipet_Step_Dist_UsingFixedFunction)

       Pipet_Step_Dist_WriteCounter(Pipet_Step_Dist_backup.CounterUdb);

        #if(!Pipet_Step_Dist_ControlRegRemoved)
            Pipet_Step_Dist_WriteControlRegister(Pipet_Step_Dist_backup.CounterControlRegister);
        #endif /* (!Pipet_Step_Dist_ControlRegRemoved) */

    #endif /* (!Pipet_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pipet_Step_Dist_Sleep
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
*  Pipet_Step_Dist_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Pipet_Step_Dist_Sleep(void) 
{
    #if(!Pipet_Step_Dist_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Pipet_Step_Dist_CTRL_ENABLE == (Pipet_Step_Dist_CONTROL & Pipet_Step_Dist_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Pipet_Step_Dist_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Pipet_Step_Dist_backup.CounterEnableState = 0u;
        }
    #else
        Pipet_Step_Dist_backup.CounterEnableState = 1u;
        if(Pipet_Step_Dist_backup.CounterEnableState != 0u)
        {
            Pipet_Step_Dist_backup.CounterEnableState = 0u;
        }
    #endif /* (!Pipet_Step_Dist_ControlRegRemoved) */
    
    Pipet_Step_Dist_Stop();
    Pipet_Step_Dist_SaveConfig();
}


/*******************************************************************************
* Function Name: Pipet_Step_Dist_Wakeup
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
*  Pipet_Step_Dist_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Pipet_Step_Dist_Wakeup(void) 
{
    Pipet_Step_Dist_RestoreConfig();
    #if(!Pipet_Step_Dist_ControlRegRemoved)
        if(Pipet_Step_Dist_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Pipet_Step_Dist_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Pipet_Step_Dist_ControlRegRemoved) */
    
}


/* [] END OF FILE */
