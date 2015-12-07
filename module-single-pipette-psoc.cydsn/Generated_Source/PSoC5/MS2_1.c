/*******************************************************************************
* File Name: MS2_1.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "MS2_1.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MS2_1__PORT == 15 && ((MS2_1__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MS2_1_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void MS2_1_Write(uint8 value) 
{
    uint8 staticBits = (MS2_1_DR & (uint8)(~MS2_1_MASK));
    MS2_1_DR = staticBits | ((uint8)(value << MS2_1_SHIFT) & MS2_1_MASK);
}


/*******************************************************************************
* Function Name: MS2_1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MS2_1_DM_STRONG     Strong Drive 
*  MS2_1_DM_OD_HI      Open Drain, Drives High 
*  MS2_1_DM_OD_LO      Open Drain, Drives Low 
*  MS2_1_DM_RES_UP     Resistive Pull Up 
*  MS2_1_DM_RES_DWN    Resistive Pull Down 
*  MS2_1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MS2_1_DM_DIG_HIZ    High Impedance Digital 
*  MS2_1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MS2_1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MS2_1_0, mode);
}


/*******************************************************************************
* Function Name: MS2_1_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro MS2_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MS2_1_Read(void) 
{
    return (MS2_1_PS & MS2_1_MASK) >> MS2_1_SHIFT;
}


/*******************************************************************************
* Function Name: MS2_1_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 MS2_1_ReadDataReg(void) 
{
    return (MS2_1_DR & MS2_1_MASK) >> MS2_1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MS2_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: MS2_1_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 MS2_1_ClearInterrupt(void) 
    {
        return (MS2_1_INTSTAT & MS2_1_MASK) >> MS2_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
