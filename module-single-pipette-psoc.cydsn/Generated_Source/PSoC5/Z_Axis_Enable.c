/*******************************************************************************
* File Name: Z_Axis_Enable.c  
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
#include "Z_Axis_Enable.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Z_Axis_Enable__PORT == 15 && ((Z_Axis_Enable__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Z_Axis_Enable_Write
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
void Z_Axis_Enable_Write(uint8 value) 
{
    uint8 staticBits = (Z_Axis_Enable_DR & (uint8)(~Z_Axis_Enable_MASK));
    Z_Axis_Enable_DR = staticBits | ((uint8)(value << Z_Axis_Enable_SHIFT) & Z_Axis_Enable_MASK);
}


/*******************************************************************************
* Function Name: Z_Axis_Enable_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Z_Axis_Enable_DM_STRONG     Strong Drive 
*  Z_Axis_Enable_DM_OD_HI      Open Drain, Drives High 
*  Z_Axis_Enable_DM_OD_LO      Open Drain, Drives Low 
*  Z_Axis_Enable_DM_RES_UP     Resistive Pull Up 
*  Z_Axis_Enable_DM_RES_DWN    Resistive Pull Down 
*  Z_Axis_Enable_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Z_Axis_Enable_DM_DIG_HIZ    High Impedance Digital 
*  Z_Axis_Enable_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Z_Axis_Enable_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Z_Axis_Enable_0, mode);
}


/*******************************************************************************
* Function Name: Z_Axis_Enable_Read
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
*  Macro Z_Axis_Enable_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Z_Axis_Enable_Read(void) 
{
    return (Z_Axis_Enable_PS & Z_Axis_Enable_MASK) >> Z_Axis_Enable_SHIFT;
}


/*******************************************************************************
* Function Name: Z_Axis_Enable_ReadDataReg
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
uint8 Z_Axis_Enable_ReadDataReg(void) 
{
    return (Z_Axis_Enable_DR & Z_Axis_Enable_MASK) >> Z_Axis_Enable_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Z_Axis_Enable_INTSTAT) 

    /*******************************************************************************
    * Function Name: Z_Axis_Enable_ClearInterrupt
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
    uint8 Z_Axis_Enable_ClearInterrupt(void) 
    {
        return (Z_Axis_Enable_INTSTAT & Z_Axis_Enable_MASK) >> Z_Axis_Enable_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
