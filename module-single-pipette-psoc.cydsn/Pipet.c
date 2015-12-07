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

#include <Pipet.h>

/*----Private functions declarations----*/
CY_ISR(Pipet_Bumper_ISR);
CY_ISR(Pipet_Move_ISR);
void Pipet_Bumper_Stops();

/*----Private variables---*/
uint16 volume_taken;
uint16 volume_to_run;
uint16 volume_step = 160;           // in hundreds of picoliters/step
uint16 pipet_f_ustepping = 16;             // microstepping factor (1,2,4,8,16)
uint8 pipet_motor_direction = 0;          // 0 = fill, 1 = empty
const uint8 fill = 0;
const uint8 empty = 1;
const uint16 max_volume = 7500;   // hundreds of micrometers

void Pipet_Init()
{
    Pipet_Clock_Start();
    
    //Motor speed init
    Pipet_Motor_Speed_Start();
    //Distance init
    Pipet_Step_Dist_Start();
    //Motor power init
    Pipet_Axis_Power_Start();
    
    //Interrupt initialization
    Pipet_Bumper_ISR_StartEx(Pipet_Bumper_ISR);
    Pipet_Bumper_Port_ClearInterrupt();
    Pipet_Bumper_ISR_ClearPending();
    
    //Movement interrupt initialization
    Pipet_Move_ISR_StartEx(Pipet_Move_ISR);
    Pipet_Move_ISR_ClearPending();
    
    switch (pipet_f_ustepping) {
        case 1: // 1 ustepping
        {
            Pipet_StepSizeA_Write(0);
            Pipet_StepSizeB_Write(0);
            break;
        }
        
        case 2: // 1/2 ustepping
        {
            Pipet_StepSizeA_Write(1);
            Pipet_StepSizeB_Write(0);
            break;
        }
        
        case 4: // 1/4 ustepping
        {
            Pipet_StepSizeA_Write(0);
            Pipet_StepSizeB_Write(1);
            break;
        }
        
        case 8: // 1/8 ustepping
        {
            //Allegro chip can't make 1/8 ustepping
            break;
        }
        
        case 16: // 1/16 ustepping
        {
            Pipet_StepSizeA_Write(1);
            Pipet_StepSizeB_Write(1);
            break;
        }
        default:
        {
            break;
        }
    }
    Pipet_Direction_Write(pipet_motor_direction);
    Pipet_Enable_Write(0);
    
    Pipet_Reset();
}

void Pipet_Reset() {
    //Verifies if already on bumper, otherwise gets to bumper
    if (!(Pipet_Bumper_Port_Read())){
        
        // Activate motor to get to bumper
        //Pipet_Direction_Write(pipet_motor_direction);
        //Pipet_Step_Dist_WriteCompare(max_distance*screw_lead/(motor_steps_turn*f_ustepping));
        //Pipet_GO_Write(1); //Motor starts
    }
    //Z_pos = 0;
}

// Initialization for
void Pipet_Bumper_Stops()
{   
    Pipet_Step_Dist_WriteCompare(0);
    volume_taken = 0;
}

void Pipet_Fill(uint16 volume) {
    if (volume > max_volume) {volume = max_volume;}
    volume_to_run = volume;
    uint32 steps_to_do;
    steps_to_do = volume*(volume_step/pipet_f_ustepping);
    // Setting up motor direction
    Pipet_Direction_Write(fill);
    Pipet_Step_Dist_WriteCompare(steps_to_do);
    Pipet_GO_Write(1);
}

void Pipet_Empty(uint16 volume) {
    if (volume > max_volume) {volume = max_volume;}
    volume_to_run = volume;
    uint32 steps_to_do;
    steps_to_do = volume*(volume_step/pipet_f_ustepping);
    // Setting up motor direction
    Pipet_Direction_Write(empty);
    Pipet_Step_Dist_WriteCompare(steps_to_do);
    Pipet_GO_Write(1);
}

CY_ISR(Pipet_Bumper_ISR){
    Pipet_Bumper_Stops();
    Pipet_Bumper_Port_ClearInterrupt();
}

CY_ISR(Pipet_Move_ISR){
    sendDataToCAN(0x00, 0x00, 0x02, 0x00, 0x00, 0x00, (uint8)(volume_to_run >> 8), (uint8)volume_to_run);
}
/* [] END OF FILE */
