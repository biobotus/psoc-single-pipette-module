/* ========================================
 *
 * Copyright BioBot Instrumentation, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF BioBot Instrumentation.
 *
 * WRITTEN BY : Philippe-Antoine Major &
 *              Louis-Vincent Major
 * ========================================
*/

#include <project.h>
#include <Defines.h>

// CAN DEVICE ID
#define CAN_DEVICE_ID                           (0x71)

// GLOBAL DEFINITIONS FOR THE CAN BUS.
#define MAX_MSG_BUFFER_SIZE                     (50)    // Maximum amount of bytes to be stored in the CAN_MSG_BUFFER
#define MASTER_ID                               (0xFF)
#define MSG_RTR                                 (0)
#define MSG_IDE                                 (0)
#define MSG_IRQ                                 (0)
#define DATALENGTH                              0x08

// CAN MESSAGES
#define CAN_INSTRUCTION_SET_Z_AXIS_HOME         0
#define CAN_INSTRUCTION_SET_Z_AXIS_POSITION     1
#define CAN_INSTRUCTION_SET_PIPET_FILL          2
#define CAN_INSTRUCTION_SET_PIPET_EMPTY         3
#define CAN_INSTRUCTION_SET_PIPET_RESET         4

// Byte positionning in CAN message
#define INDEX_DEVICE_ID_BYTE        1
#define INDEX_SUBMODULE_NUMBER_BYTE 2
#define INDEX_INSTRUCTION_BYTE      0
#define INDEX_SPARE_BYTE            3
#define INDEX_DATABYTE1             4
#define INDEX_DATABYTE2             5
#define INDEX_DATABYTE3             6
#define INDEX_DATABYTE4             7

// CAN MESSAGE FORMAT :
// Byte 0       : Device ID, this is the MCU ID.
// Byte 1       : # of the desired module (1 or 2 for a TAC containing two separated modules controlled by 1 MCU)
// Byte 2       : Instruction to run or answer
// Byte 3       : Spare byte
// Bytes 4-7    : Data bytes

#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H
// Structure of a basic CAN Message.
typedef struct
{
    #if (!(CY_PSOC3 || CY_PSOC5))
        uint8 sst;
    #endif /* (!(CY_PSOC3 || CY_PSOC5)) */
    CAN_1_DATA_BYTES_MSG msgBytes;
    uint8 DLC;
    uint32 CAN_ID;
}CAN_MSG;
#endif

// Definitions and variables used throughout the entire program.
extern int msgToBeTreatedIndex;
extern int msgToBeStoredIndex;
extern int messageToBeTreatedCount;
extern CAN_MSG receivedMsgs[MAX_MSG_BUFFER_SIZE];

// Declaration of the functions used with the CAN bus.
CAN_MSG getReceivedMessage(void);
int8 sendMessage(CAN_MSG* msgPtr, uint32 ID);
int8 answerToMaster(uint8 definedAnswer, uint8 submoduleNumber);
int8 echoBackToMaster(CAN_MSG* msgPtr);
void sendDataToCAN(uint8 instruction, uint8 byte1, uint8 byte2, uint8 byte3, uint8 byte4, uint8 byte5, uint8 byte6, uint8 byte7);

/* [] END OF FILE */
