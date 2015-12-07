/*******************************************************************************
* File Name: Z_Motor_Speed_PM.c
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

#include "Z_Motor_Speed.h"

static Z_Motor_Speed_backupStruct Z_Motor_Speed_backup;


/*******************************************************************************
* Function Name: Z_Motor_Speed_SaveConfig
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
*  Z_Motor_Speed_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Z_Motor_Speed_SaveConfig(void) 
{

    #if(!Z_Motor_Speed_UsingFixedFunction)
        #if(!Z_Motor_Speed_PWMModeIsCenterAligned)
            Z_Motor_Speed_backup.PWMPeriod = Z_Motor_Speed_ReadPeriod();
        #endif /* (!Z_Motor_Speed_PWMModeIsCenterAligned) */
        Z_Motor_Speed_backup.PWMUdb = Z_Motor_Speed_ReadCounter();
        #if (Z_Motor_Speed_UseStatus)
            Z_Motor_Speed_backup.InterruptMaskValue = Z_Motor_Speed_STATUS_MASK;
        #endif /* (Z_Motor_Speed_UseStatus) */

        #if(Z_Motor_Speed_DeadBandMode == Z_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
            Z_Motor_Speed_DeadBandMode == Z_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
            Z_Motor_Speed_backup.PWMdeadBandValue = Z_Motor_Speed_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Z_Motor_Speed_KillModeMinTime)
             Z_Motor_Speed_backup.PWMKillCounterPeriod = Z_Motor_Speed_ReadKillTime();
        #endif /* (Z_Motor_Speed_KillModeMinTime) */

        #if(Z_Motor_Speed_UseControl)
            Z_Motor_Speed_backup.PWMControlRegister = Z_Motor_Speed_ReadControlRegister();
        #endif /* (Z_Motor_Speed_UseControl) */
    #endif  /* (!Z_Motor_Speed_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Z_Motor_Speed_RestoreConfig
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
*  Z_Motor_Speed_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Z_Motor_Speed_RestoreConfig(void) 
{
        #if(!Z_Motor_Speed_UsingFixedFunction)
            #if(!Z_Motor_Speed_PWMModeIsCenterAligned)
                Z_Motor_Speed_WritePeriod(Z_Motor_Speed_backup.PWMPeriod);
            #endif /* (!Z_Motor_Speed_PWMModeIsCenterAligned) */

            Z_Motor_Speed_WriteCounter(Z_Motor_Speed_backup.PWMUdb);

            #if (Z_Motor_Speed_UseStatus)
                Z_Motor_Speed_STATUS_MASK = Z_Motor_Speed_backup.InterruptMaskValue;
            #endif /* (Z_Motor_Speed_UseStatus) */

            #if(Z_Motor_Speed_DeadBandMode == Z_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
                Z_Motor_Speed_DeadBandMode == Z_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
                Z_Motor_Speed_WriteDeadTime(Z_Motor_Speed_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Z_Motor_Speed_KillModeMinTime)
                Z_Motor_Speed_WriteKillTime(Z_Motor_Speed_backup.PWMKillCounterPeriod);
            #endif /* (Z_Motor_Speed_KillModeMinTime) */

            #if(Z_Motor_Speed_UseControl)
                Z_Motor_Speed_WriteControlRegister(Z_Motor_Speed_backup.PWMControlRegister);
            #endif /* (Z_Motor_Speed_UseControl) */
        #endif  /* (!Z_Motor_Speed_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Z_Motor_Speed_Sleep
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
*  Z_Motor_Speed_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Z_Motor_Speed_Sleep(void) 
{
    #if(Z_Motor_Speed_UseControl)
        if(Z_Motor_Speed_CTRL_ENABLE == (Z_Motor_Speed_CONTROL & Z_Motor_Speed_CTRL_ENABLE))
        {
            /*Component is enabled */
            Z_Motor_Speed_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Z_Motor_Speed_backup.PWMEnableState = 0u;
        }
    #endif /* (Z_Motor_Speed_UseControl) */

    /* Stop component */
    Z_Motor_Speed_Stop();

    /* Save registers configuration */
    Z_Motor_Speed_SaveConfig();
}


/*******************************************************************************
* Function Name: Z_Motor_Speed_Wakeup
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
*  Z_Motor_Speed_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Z_Motor_Speed_Wakeup(void) 
{
     /* Restore registers values */
    Z_Motor_Speed_RestoreConfig();

    if(Z_Motor_Speed_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Z_Motor_Speed_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
