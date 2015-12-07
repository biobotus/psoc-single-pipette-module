/*******************************************************************************
* File Name: Bumper_Z_Down.c  
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
#include "Bumper_Z_Down.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Bumper_Z_Down__PORT == 15 && ((Bumper_Z_Down__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Bumper_Z_Down_Write
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
void Bumper_Z_Down_Write(uint8 value) 
{
    uint8 staticBits = (Bumper_Z_Down_DR & (uint8)(~Bumper_Z_Down_MASK));
    Bumper_Z_Down_DR = staticBits | ((uint8)(value << Bumper_Z_Down_SHIFT) & Bumper_Z_Down_MASK);
}


/*******************************************************************************
* Function Name: Bumper_Z_Down_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Bumper_Z_Down_DM_STRONG     Strong Drive 
*  Bumper_Z_Down_DM_OD_HI      Open Drain, Drives High 
*  Bumper_Z_Down_DM_OD_LO      Open Drain, Drives Low 
*  Bumper_Z_Down_DM_RES_UP     Resistive Pull Up 
*  Bumper_Z_Down_DM_RES_DWN    Resistive Pull Down 
*  Bumper_Z_Down_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Bumper_Z_Down_DM_DIG_HIZ    High Impedance Digital 
*  Bumper_Z_Down_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Bumper_Z_Down_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Bumper_Z_Down_0, mode);
}


/*******************************************************************************
* Function Name: Bumper_Z_Down_Read
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
*  Macro Bumper_Z_Down_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Bumper_Z_Down_Read(void) 
{
    return (Bumper_Z_Down_PS & Bumper_Z_Down_MASK) >> Bumper_Z_Down_SHIFT;
}


/*******************************************************************************
* Function Name: Bumper_Z_Down_ReadDataReg
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
uint8 Bumper_Z_Down_ReadDataReg(void) 
{
    return (Bumper_Z_Down_DR & Bumper_Z_Down_MASK) >> Bumper_Z_Down_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Bumper_Z_Down_INTSTAT) 

    /*******************************************************************************
    * Function Name: Bumper_Z_Down_ClearInterrupt
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
    uint8 Bumper_Z_Down_ClearInterrupt(void) 
    {
        return (Bumper_Z_Down_INTSTAT & Bumper_Z_Down_MASK) >> Bumper_Z_Down_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
