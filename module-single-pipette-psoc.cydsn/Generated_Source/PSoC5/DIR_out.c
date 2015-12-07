/*******************************************************************************
* File Name: DIR_out.c  
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
#include "DIR_out.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 DIR_out__PORT == 15 && ((DIR_out__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: DIR_out_Write
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
void DIR_out_Write(uint8 value) 
{
    uint8 staticBits = (DIR_out_DR & (uint8)(~DIR_out_MASK));
    DIR_out_DR = staticBits | ((uint8)(value << DIR_out_SHIFT) & DIR_out_MASK);
}


/*******************************************************************************
* Function Name: DIR_out_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  DIR_out_DM_STRONG     Strong Drive 
*  DIR_out_DM_OD_HI      Open Drain, Drives High 
*  DIR_out_DM_OD_LO      Open Drain, Drives Low 
*  DIR_out_DM_RES_UP     Resistive Pull Up 
*  DIR_out_DM_RES_DWN    Resistive Pull Down 
*  DIR_out_DM_RES_UPDWN  Resistive Pull Up/Down 
*  DIR_out_DM_DIG_HIZ    High Impedance Digital 
*  DIR_out_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void DIR_out_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DIR_out_0, mode);
}


/*******************************************************************************
* Function Name: DIR_out_Read
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
*  Macro DIR_out_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DIR_out_Read(void) 
{
    return (DIR_out_PS & DIR_out_MASK) >> DIR_out_SHIFT;
}


/*******************************************************************************
* Function Name: DIR_out_ReadDataReg
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
uint8 DIR_out_ReadDataReg(void) 
{
    return (DIR_out_DR & DIR_out_MASK) >> DIR_out_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DIR_out_INTSTAT) 

    /*******************************************************************************
    * Function Name: DIR_out_ClearInterrupt
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
    uint8 DIR_out_ClearInterrupt(void) 
    {
        return (DIR_out_INTSTAT & DIR_out_MASK) >> DIR_out_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
