/*******************************************************************************
* File Name: StepperDrive_2_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "StepperDrive_2.h"

static StepperDrive_2_backupStruct StepperDrive_2_backup;


/*******************************************************************************
* Function Name: StepperDrive_2_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_2_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void StepperDrive_2_SaveConfig(void) 
{

    #if(!StepperDrive_2_UsingFixedFunction)
        #if(!StepperDrive_2_PWMModeIsCenterAligned)
            StepperDrive_2_backup.PWMPeriod = StepperDrive_2_ReadPeriod();
        #endif /* (!StepperDrive_2_PWMModeIsCenterAligned) */
        StepperDrive_2_backup.PWMUdb = StepperDrive_2_ReadCounter();
        #if (StepperDrive_2_UseStatus)
            StepperDrive_2_backup.InterruptMaskValue = StepperDrive_2_STATUS_MASK;
        #endif /* (StepperDrive_2_UseStatus) */

        #if(StepperDrive_2_DeadBandMode == StepperDrive_2__B_PWM__DBM_256_CLOCKS || \
            StepperDrive_2_DeadBandMode == StepperDrive_2__B_PWM__DBM_2_4_CLOCKS)
            StepperDrive_2_backup.PWMdeadBandValue = StepperDrive_2_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(StepperDrive_2_KillModeMinTime)
             StepperDrive_2_backup.PWMKillCounterPeriod = StepperDrive_2_ReadKillTime();
        #endif /* (StepperDrive_2_KillModeMinTime) */

        #if(StepperDrive_2_UseControl)
            StepperDrive_2_backup.PWMControlRegister = StepperDrive_2_ReadControlRegister();
        #endif /* (StepperDrive_2_UseControl) */
    #endif  /* (!StepperDrive_2_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepperDrive_2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_2_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void StepperDrive_2_RestoreConfig(void) 
{
        #if(!StepperDrive_2_UsingFixedFunction)
            #if(!StepperDrive_2_PWMModeIsCenterAligned)
                StepperDrive_2_WritePeriod(StepperDrive_2_backup.PWMPeriod);
            #endif /* (!StepperDrive_2_PWMModeIsCenterAligned) */

            StepperDrive_2_WriteCounter(StepperDrive_2_backup.PWMUdb);

            #if (StepperDrive_2_UseStatus)
                StepperDrive_2_STATUS_MASK = StepperDrive_2_backup.InterruptMaskValue;
            #endif /* (StepperDrive_2_UseStatus) */

            #if(StepperDrive_2_DeadBandMode == StepperDrive_2__B_PWM__DBM_256_CLOCKS || \
                StepperDrive_2_DeadBandMode == StepperDrive_2__B_PWM__DBM_2_4_CLOCKS)
                StepperDrive_2_WriteDeadTime(StepperDrive_2_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(StepperDrive_2_KillModeMinTime)
                StepperDrive_2_WriteKillTime(StepperDrive_2_backup.PWMKillCounterPeriod);
            #endif /* (StepperDrive_2_KillModeMinTime) */

            #if(StepperDrive_2_UseControl)
                StepperDrive_2_WriteControlRegister(StepperDrive_2_backup.PWMControlRegister);
            #endif /* (StepperDrive_2_UseControl) */
        #endif  /* (!StepperDrive_2_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: StepperDrive_2_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_2_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void StepperDrive_2_Sleep(void) 
{
    #if(StepperDrive_2_UseControl)
        if(StepperDrive_2_CTRL_ENABLE == (StepperDrive_2_CONTROL & StepperDrive_2_CTRL_ENABLE))
        {
            /*Component is enabled */
            StepperDrive_2_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            StepperDrive_2_backup.PWMEnableState = 0u;
        }
    #endif /* (StepperDrive_2_UseControl) */

    /* Stop component */
    StepperDrive_2_Stop();

    /* Save registers configuration */
    StepperDrive_2_SaveConfig();
}


/*******************************************************************************
* Function Name: StepperDrive_2_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_2_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void StepperDrive_2_Wakeup(void) 
{
     /* Restore registers values */
    StepperDrive_2_RestoreConfig();

    if(StepperDrive_2_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        StepperDrive_2_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
