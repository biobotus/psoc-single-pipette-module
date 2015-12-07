/*******************************************************************************
* File Name: CAN_Standby.c  
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
#include "CAN_Standby.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CAN_Standby__PORT == 15 && ((CAN_Standby__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CAN_Standby_Write
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
void CAN_Standby_Write(uint8 value) 
{
    uint8 staticBits = (CAN_Standby_DR & (uint8)(~CAN_Standby_MASK));
    CAN_Standby_DR = staticBits | ((uint8)(value << CAN_Standby_SHIFT) & CAN_Standby_MASK);
}


/*******************************************************************************
* Function Name: CAN_Standby_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CAN_Standby_DM_STRONG     Strong Drive 
*  CAN_Standby_DM_OD_HI      Open Drain, Drives High 
*  CAN_Standby_DM_OD_LO      Open Drain, Drives Low 
*  CAN_Standby_DM_RES_UP     Resistive Pull Up 
*  CAN_Standby_DM_RES_DWN    Resistive Pull Down 
*  CAN_Standby_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CAN_Standby_DM_DIG_HIZ    High Impedance Digital 
*  CAN_Standby_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CAN_Standby_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CAN_Standby_0, mode);
}


/*******************************************************************************
* Function Name: CAN_Standby_Read
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
*  Macro CAN_Standby_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CAN_Standby_Read(void) 
{
    return (CAN_Standby_PS & CAN_Standby_MASK) >> CAN_Standby_SHIFT;
}


/*******************************************************************************
* Function Name: CAN_Standby_ReadDataReg
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
uint8 CAN_Standby_ReadDataReg(void) 
{
    return (CAN_Standby_DR & CAN_Standby_MASK) >> CAN_Standby_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CAN_Standby_INTSTAT) 

    /*******************************************************************************
    * Function Name: CAN_Standby_ClearInterrupt
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
    uint8 CAN_Standby_ClearInterrupt(void) 
    {
        return (CAN_Standby_INTSTAT & CAN_Standby_MASK) >> CAN_Standby_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
