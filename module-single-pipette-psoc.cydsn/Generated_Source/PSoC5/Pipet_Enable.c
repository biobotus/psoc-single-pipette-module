/*******************************************************************************
* File Name: Pipet_Enable.c  
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
#include "Pipet_Enable.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Pipet_Enable__PORT == 15 && ((Pipet_Enable__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Pipet_Enable_Write
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
void Pipet_Enable_Write(uint8 value) 
{
    uint8 staticBits = (Pipet_Enable_DR & (uint8)(~Pipet_Enable_MASK));
    Pipet_Enable_DR = staticBits | ((uint8)(value << Pipet_Enable_SHIFT) & Pipet_Enable_MASK);
}


/*******************************************************************************
* Function Name: Pipet_Enable_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pipet_Enable_DM_STRONG     Strong Drive 
*  Pipet_Enable_DM_OD_HI      Open Drain, Drives High 
*  Pipet_Enable_DM_OD_LO      Open Drain, Drives Low 
*  Pipet_Enable_DM_RES_UP     Resistive Pull Up 
*  Pipet_Enable_DM_RES_DWN    Resistive Pull Down 
*  Pipet_Enable_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pipet_Enable_DM_DIG_HIZ    High Impedance Digital 
*  Pipet_Enable_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pipet_Enable_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pipet_Enable_0, mode);
}


/*******************************************************************************
* Function Name: Pipet_Enable_Read
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
*  Macro Pipet_Enable_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pipet_Enable_Read(void) 
{
    return (Pipet_Enable_PS & Pipet_Enable_MASK) >> Pipet_Enable_SHIFT;
}


/*******************************************************************************
* Function Name: Pipet_Enable_ReadDataReg
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
uint8 Pipet_Enable_ReadDataReg(void) 
{
    return (Pipet_Enable_DR & Pipet_Enable_MASK) >> Pipet_Enable_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pipet_Enable_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pipet_Enable_ClearInterrupt
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
    uint8 Pipet_Enable_ClearInterrupt(void) 
    {
        return (Pipet_Enable_INTSTAT & Pipet_Enable_MASK) >> Pipet_Enable_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
