/*******************************************************************************
* File Name: Pipet_Motor_Speed_PM.c
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

#include "Pipet_Motor_Speed.h"

static Pipet_Motor_Speed_backupStruct Pipet_Motor_Speed_backup;


/*******************************************************************************
* Function Name: Pipet_Motor_Speed_SaveConfig
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
*  Pipet_Motor_Speed_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Pipet_Motor_Speed_SaveConfig(void) 
{

    #if(!Pipet_Motor_Speed_UsingFixedFunction)
        #if(!Pipet_Motor_Speed_PWMModeIsCenterAligned)
            Pipet_Motor_Speed_backup.PWMPeriod = Pipet_Motor_Speed_ReadPeriod();
        #endif /* (!Pipet_Motor_Speed_PWMModeIsCenterAligned) */
        Pipet_Motor_Speed_backup.PWMUdb = Pipet_Motor_Speed_ReadCounter();
        #if (Pipet_Motor_Speed_UseStatus)
            Pipet_Motor_Speed_backup.InterruptMaskValue = Pipet_Motor_Speed_STATUS_MASK;
        #endif /* (Pipet_Motor_Speed_UseStatus) */

        #if(Pipet_Motor_Speed_DeadBandMode == Pipet_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
            Pipet_Motor_Speed_DeadBandMode == Pipet_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
            Pipet_Motor_Speed_backup.PWMdeadBandValue = Pipet_Motor_Speed_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Pipet_Motor_Speed_KillModeMinTime)
             Pipet_Motor_Speed_backup.PWMKillCounterPeriod = Pipet_Motor_Speed_ReadKillTime();
        #endif /* (Pipet_Motor_Speed_KillModeMinTime) */

        #if(Pipet_Motor_Speed_UseControl)
            Pipet_Motor_Speed_backup.PWMControlRegister = Pipet_Motor_Speed_ReadControlRegister();
        #endif /* (Pipet_Motor_Speed_UseControl) */
    #endif  /* (!Pipet_Motor_Speed_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Pipet_Motor_Speed_RestoreConfig
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
*  Pipet_Motor_Speed_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Pipet_Motor_Speed_RestoreConfig(void) 
{
        #if(!Pipet_Motor_Speed_UsingFixedFunction)
            #if(!Pipet_Motor_Speed_PWMModeIsCenterAligned)
                Pipet_Motor_Speed_WritePeriod(Pipet_Motor_Speed_backup.PWMPeriod);
            #endif /* (!Pipet_Motor_Speed_PWMModeIsCenterAligned) */

            Pipet_Motor_Speed_WriteCounter(Pipet_Motor_Speed_backup.PWMUdb);

            #if (Pipet_Motor_Speed_UseStatus)
                Pipet_Motor_Speed_STATUS_MASK = Pipet_Motor_Speed_backup.InterruptMaskValue;
            #endif /* (Pipet_Motor_Speed_UseStatus) */

            #if(Pipet_Motor_Speed_DeadBandMode == Pipet_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
                Pipet_Motor_Speed_DeadBandMode == Pipet_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
                Pipet_Motor_Speed_WriteDeadTime(Pipet_Motor_Speed_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Pipet_Motor_Speed_KillModeMinTime)
                Pipet_Motor_Speed_WriteKillTime(Pipet_Motor_Speed_backup.PWMKillCounterPeriod);
            #endif /* (Pipet_Motor_Speed_KillModeMinTime) */

            #if(Pipet_Motor_Speed_UseControl)
                Pipet_Motor_Speed_WriteControlRegister(Pipet_Motor_Speed_backup.PWMControlRegister);
            #endif /* (Pipet_Motor_Speed_UseControl) */
        #endif  /* (!Pipet_Motor_Speed_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Pipet_Motor_Speed_Sleep
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
*  Pipet_Motor_Speed_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Pipet_Motor_Speed_Sleep(void) 
{
    #if(Pipet_Motor_Speed_UseControl)
        if(Pipet_Motor_Speed_CTRL_ENABLE == (Pipet_Motor_Speed_CONTROL & Pipet_Motor_Speed_CTRL_ENABLE))
        {
            /*Component is enabled */
            Pipet_Motor_Speed_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Pipet_Motor_Speed_backup.PWMEnableState = 0u;
        }
    #endif /* (Pipet_Motor_Speed_UseControl) */

    /* Stop component */
    Pipet_Motor_Speed_Stop();

    /* Save registers configuration */
    Pipet_Motor_Speed_SaveConfig();
}


/*******************************************************************************
* Function Name: Pipet_Motor_Speed_Wakeup
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
*  Pipet_Motor_Speed_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Pipet_Motor_Speed_Wakeup(void) 
{
     /* Restore registers values */
    Pipet_Motor_Speed_RestoreConfig();

    if(Pipet_Motor_Speed_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Pipet_Motor_Speed_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
