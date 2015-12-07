/*******************************************************************************
* File Name: Pipet_Direction.c  
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
#include "Pipet_Direction.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Pipet_Direction__PORT == 15 && ((Pipet_Direction__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Pipet_Direction_Write
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
void Pipet_Direction_Write(uint8 value) 
{
    uint8 staticBits = (Pipet_Direction_DR & (uint8)(~Pipet_Direction_MASK));
    Pipet_Direction_DR = staticBits | ((uint8)(value << Pipet_Direction_SHIFT) & Pipet_Direction_MASK);
}


/*******************************************************************************
* Function Name: Pipet_Direction_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pipet_Direction_DM_STRONG     Strong Drive 
*  Pipet_Direction_DM_OD_HI      Open Drain, Drives High 
*  Pipet_Direction_DM_OD_LO      Open Drain, Drives Low 
*  Pipet_Direction_DM_RES_UP     Resistive Pull Up 
*  Pipet_Direction_DM_RES_DWN    Resistive Pull Down 
*  Pipet_Direction_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pipet_Direction_DM_DIG_HIZ    High Impedance Digital 
*  Pipet_Direction_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pipet_Direction_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pipet_Direction_0, mode);
}


/*******************************************************************************
* Function Name: Pipet_Direction_Read
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
*  Macro Pipet_Direction_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pipet_Direction_Read(void) 
{
    return (Pipet_Direction_PS & Pipet_Direction_MASK) >> Pipet_Direction_SHIFT;
}


/*******************************************************************************
* Function Name: Pipet_Direction_ReadDataReg
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
uint8 Pipet_Direction_ReadDataReg(void) 
{
    return (Pipet_Direction_DR & Pipet_Direction_MASK) >> Pipet_Direction_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pipet_Direction_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pipet_Direction_ClearInterrupt
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
    uint8 Pipet_Direction_ClearInterrupt(void) 
    {
        return (Pipet_Direction_INTSTAT & Pipet_Direction_MASK) >> Pipet_Direction_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
