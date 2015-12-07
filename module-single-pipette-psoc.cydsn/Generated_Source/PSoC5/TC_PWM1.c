/*******************************************************************************
* File Name: TC_PWM1.c  
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
#include "TC_PWM1.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TC_PWM1__PORT == 15 && ((TC_PWM1__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TC_PWM1_Write
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
void TC_PWM1_Write(uint8 value) 
{
    uint8 staticBits = (TC_PWM1_DR & (uint8)(~TC_PWM1_MASK));
    TC_PWM1_DR = staticBits | ((uint8)(value << TC_PWM1_SHIFT) & TC_PWM1_MASK);
}


/*******************************************************************************
* Function Name: TC_PWM1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TC_PWM1_DM_STRONG     Strong Drive 
*  TC_PWM1_DM_OD_HI      Open Drain, Drives High 
*  TC_PWM1_DM_OD_LO      Open Drain, Drives Low 
*  TC_PWM1_DM_RES_UP     Resistive Pull Up 
*  TC_PWM1_DM_RES_DWN    Resistive Pull Down 
*  TC_PWM1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TC_PWM1_DM_DIG_HIZ    High Impedance Digital 
*  TC_PWM1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TC_PWM1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TC_PWM1_0, mode);
}


/*******************************************************************************
* Function Name: TC_PWM1_Read
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
*  Macro TC_PWM1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TC_PWM1_Read(void) 
{
    return (TC_PWM1_PS & TC_PWM1_MASK) >> TC_PWM1_SHIFT;
}


/*******************************************************************************
* Function Name: TC_PWM1_ReadDataReg
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
uint8 TC_PWM1_ReadDataReg(void) 
{
    return (TC_PWM1_DR & TC_PWM1_MASK) >> TC_PWM1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TC_PWM1_INTSTAT) 

    /*******************************************************************************
    * Function Name: TC_PWM1_ClearInterrupt
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
    uint8 TC_PWM1_ClearInterrupt(void) 
    {
        return (TC_PWM1_INTSTAT & TC_PWM1_MASK) >> TC_PWM1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
