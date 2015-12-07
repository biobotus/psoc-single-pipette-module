#include <project.h>
#include <cypins.h>
#include <CAN_Communication.h>
#include <Defines.h>
#include <Z_Axis.h>
#include <Pipet.h>

/*===========================================================================*/
// Variables
/*===========================================================================*/
int msgToBeTreatedIndex = 0;
int msgToBeStoredIndex = 0;
int messageToBeTreatedCount = 0;
CAN_MSG receivedMsgs[MAX_MSG_BUFFER_SIZE];
uint16 step_period;
uint8 treatMessage(CAN_MSG* msgToTreatPtr);
void CAN_Init();

/*===========================================================================*/
// Main loop
/*===========================================================================*/
int main()
{     
    //******Functions********//
    CYGlobalIntEnable;
    CAN_Init();
    Z_Axis_Init();
    Pipet_Init();
    
    uint8 anwser;
    for(;;)
    {        
        //Verify if a message needs to be treated in the message received buffer.       
        if(messageToBeTreatedCount>0)
        {
            // Treat the last message received and echo it back on the CAN bus as an acknowledgement.
            CAN_MSG msgToTreat = getReceivedMessage();
            anwser = treatMessage(&msgToTreat);
        }
    }
    return 0;
}

// Treat a message received from the CAN bus.
uint8 treatMessage(CAN_MSG* msgToTreatPtr)
{    
    // Variables
    uint32 data;
    uint32 databyte_array[4];
    
    // Load basic information from the message being treated.
	// Replace the indexes to those you are using (Set in Defines.h)
    uint8 device_id = msgToTreatPtr->msgBytes.byte[INDEX_DEVICE_ID_BYTE];
    uint8 subModuleNumber = msgToTreatPtr->msgBytes.byte[INDEX_SUBMODULE_NUMBER_BYTE];
    uint8 instruction = msgToTreatPtr->msgBytes.byte[INDEX_INSTRUCTION_BYTE];
    uint8 spare = msgToTreatPtr->msgBytes.byte[INDEX_SPARE_BYTE];
    databyte_array[0] = msgToTreatPtr->msgBytes.byte[INDEX_DATABYTE1];
    databyte_array[1] = msgToTreatPtr->msgBytes.byte[INDEX_DATABYTE2];
    databyte_array[2] = msgToTreatPtr->msgBytes.byte[INDEX_DATABYTE3];
    databyte_array[3] = msgToTreatPtr->msgBytes.byte[INDEX_DATABYTE4];
    
    data = (databyte_array[0] << 24) + (databyte_array[1] << 16) + (databyte_array[2] << 8) + databyte_array[3];
    
    // Verify if the message is for our device or not. - THIS DEVICE ID WILL HAVE TO BE ALLOCATED BY THE MASTER
    // WHEN IT WILL BE CONNECTED FOR THE FIRST TIME ON THE PLATFORM.
    if(device_id!=DEVICE_ID)
    {
        return 1;
    }
    
	// Initialize a variable to indicate if a value has to be returned to the master or not.
    uint8 isReplyWithValueRequired = 0;
    
  
    
	// Initialize a message that will be sent back to the master if isReplyWithValueRequired is set to 1.
    // CAN_MSG msgToSendBack = {{device_id,instruction,subModuleNumber,0,0,0,0,0},{8},{0xF9}}; // Sets the first bytes of the message.

    // CHANGE THE SWITCH CONDITIONS ACCORDING TO THE DEFINES YOU HAVE IN YOUR OWN PROJECT
    switch (instruction)
    {
        // TODO : Complete this section.        
        case CAN_INSTRUCTION_SET_Z_AXIS_POSITION:
        {   
            Z_Axis_GoTo(data);           
            isReplyWithValueRequired = 1;
            break;
        }
        
        case CAN_INSTRUCTION_SET_Z_AXIS_HOME:
        {  
            Z_Axis_Home();           
            isReplyWithValueRequired = 1;
            break;
        }
        
        case CAN_INSTRUCTION_SET_PIPET_FILL:
        {  
            Pipet_Fill(data);           
            isReplyWithValueRequired = 1;
            break;
        }
        
        case CAN_INSTRUCTION_SET_PIPET_EMPTY:
        {  
            Pipet_Empty(data);           
            isReplyWithValueRequired = 1;
            break;
        }
        
        case CAN_INSTRUCTION_SET_PIPET_RESET:
        {  
            Pipet_Reset();
            isReplyWithValueRequired = 1;
            break;
        }
        default:          
            break;
    }
    
    
    
    // Echo back the command that was received (The master will wait for this instruction as an acknowledgement of reception)
	
    // If required, send the message containing the value that has to be sent to the master.
    // Reply to the master with bytes 0-2 exactly as the received instruction 
    // and the rest of the bytes (3-7) containing the answer (values of temperature, etc) 
    if (isReplyWithValueRequired == 1)
    {
        //echoBackToMaster(msgToTreatPtr);
        //sendMessage(&msgToSendBack, MASTER_ID);
    }
    return 1;
}

// Initializing required components for CAN communication
void CAN_Init()
{
    CAN_1_Start();
    CAN_1_GlobalIntEnable();
    CAN_Standby_Write(0);
}