/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#if !defined(Z_AXIS_H)
#define Z_AXIS_H

#include <project.h>
#include <CAN_Communication.h>

// Mask used for bitwise operations
#define MASK_BIT_0  0x01
#define MASK_BIT_1  0x02
#define MASK_BIT_2  0x04
#define MASK_BIT_3  0x08
#define MASK_BIT_4  0x10
#define MASK_BIT_5  0x20
#define MASK_BIT_6  0x40
#define MASK_BIT_7  0x80

/*Public functions declarations*/
void Z_Axis_Home();
void Z_Axis_GoTo(uint16);
void Z_Axis_Init();


#endif
/* [] END OF FILE */
