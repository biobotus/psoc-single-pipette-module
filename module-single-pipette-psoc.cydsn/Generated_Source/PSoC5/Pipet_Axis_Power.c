/*******************************************************************************
* File Name: Pipet_Axis_Power.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Pipet_Axis_Power.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Pipet_Axis_Power_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Pipet_Axis_Power_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Pipet_Axis_Power_backupStruct Pipet_Axis_Power_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_Init(void) 
{
    Pipet_Axis_Power_CR0 = (Pipet_Axis_Power_MODE_V );

    /* Set default data source */
    #if(Pipet_Axis_Power_DEFAULT_DATA_SRC != 0 )
        Pipet_Axis_Power_CR1 = (Pipet_Axis_Power_DEFAULT_CNTL | Pipet_Axis_Power_DACBUS_ENABLE) ;
    #else
        Pipet_Axis_Power_CR1 = (Pipet_Axis_Power_DEFAULT_CNTL | Pipet_Axis_Power_DACBUS_DISABLE) ;
    #endif /* (Pipet_Axis_Power_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Pipet_Axis_Power_DEFAULT_STRB != 0)
        Pipet_Axis_Power_Strobe |= Pipet_Axis_Power_STRB_EN ;
    #endif/* (Pipet_Axis_Power_DEFAULT_STRB != 0) */

    /* Set default range */
    Pipet_Axis_Power_SetRange(Pipet_Axis_Power_DEFAULT_RANGE); 

    /* Set default speed */
    Pipet_Axis_Power_SetSpeed(Pipet_Axis_Power_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_Enable(void) 
{
    Pipet_Axis_Power_PWRMGR |= Pipet_Axis_Power_ACT_PWR_EN;
    Pipet_Axis_Power_STBY_PWRMGR |= Pipet_Axis_Power_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Pipet_Axis_Power_restoreVal == 1u) 
        {
             Pipet_Axis_Power_CR0 = Pipet_Axis_Power_backup.data_value;
             Pipet_Axis_Power_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  Pipet_Axis_Power_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Pipet_Axis_Power_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Pipet_Axis_Power_initVar == 0u)
    { 
        Pipet_Axis_Power_Init();
        Pipet_Axis_Power_initVar = 1u;
    }

    /* Enable power to DAC */
    Pipet_Axis_Power_Enable();

    /* Set default value */
    Pipet_Axis_Power_SetValue(Pipet_Axis_Power_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_Stop(void) 
{
    /* Disble power to DAC */
    Pipet_Axis_Power_PWRMGR &= (uint8)(~Pipet_Axis_Power_ACT_PWR_EN);
    Pipet_Axis_Power_STBY_PWRMGR &= (uint8)(~Pipet_Axis_Power_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Pipet_Axis_Power_backup.data_value = Pipet_Axis_Power_CR0;
        Pipet_Axis_Power_CR0 = Pipet_Axis_Power_CUR_MODE_OUT_OFF;
        Pipet_Axis_Power_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Pipet_Axis_Power_CR0 &= (uint8)(~Pipet_Axis_Power_HS_MASK);
    Pipet_Axis_Power_CR0 |=  (speed & Pipet_Axis_Power_HS_MASK);
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_SetRange(uint8 range) 
{
    Pipet_Axis_Power_CR0 &= (uint8)(~Pipet_Axis_Power_RANGE_MASK);      /* Clear existing mode */
    Pipet_Axis_Power_CR0 |= (range & Pipet_Axis_Power_RANGE_MASK);      /*  Set Range  */
    Pipet_Axis_Power_DacTrim();
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Pipet_Axis_Power_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Pipet_Axis_Power_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Pipet_Axis_Power_Data = value;
        CyExitCriticalSection(Pipet_Axis_Power_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Pipet_Axis_Power_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Pipet_Axis_Power_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Pipet_Axis_Power_CR0 & Pipet_Axis_Power_RANGE_MASK) >> 2) + Pipet_Axis_Power_TRIM_M7_1V_RNG_OFFSET;
    Pipet_Axis_Power_TR = CY_GET_XTND_REG8((uint8 *)(Pipet_Axis_Power_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
