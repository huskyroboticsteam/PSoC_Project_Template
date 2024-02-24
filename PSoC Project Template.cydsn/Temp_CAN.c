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

#include "main.h"
#include "Temp_CAN.h"
#include "Temp_FSM.h"
#include <stdio.h>

CANPacket can_recieve;
CANPacket can_send;

extern char txData[TX_DATA_SIZE];
extern uint8 address;

//Reads from CAN FIFO and changes the state and mode accordingly
int CheckCAN() {
    uint16_t packageID = ReadCAN(&can_recieve);
    uint8_t serial = GetDeviceSerialNumber(&can_recieve);
    uint8_t sender_DG = GetSenderDeviceGroupCode(&can_recieve);
    uint8_t sender_SN = GetSenderDeviceSerialNumber(&can_recieve);
    uint8_t mode;
    
    switch(packageID){
        case(ID_MOTOR_UNIT_MODE_SEL):
            mode = GetModeFromPacket(&can_recieve);
            
            if(mode == MODE1) {
                SetModeTo(MODE1);
                SetStateTo(CHECK_CAN);
            } else if (mode == MODE2) {
                SetModeTo(MODE2);
                SetStateTo(CHECK_CAN);
            } else {
                GotoUninitState();
            }
            break;
            
        // Common Packets 
        case(ID_ESTOP):
            Print("\r\n\r\n\r\nSTOP\r\n\r\n\r\n");
            GotoUninitState();
            break;
        
        case(ID_TELEMETRY_PULL):
            sendRequestedData(DecodeTelemetryType(&can_recieve));
            SetStateTo(CHECK_CAN);
            break;
            
        default://for 0xFF/no packets or Non recognized Packets
            
            //recieved Packet with Non Valid ID
            if(packageID != NO_NEW_CAN_PACKET) {
                DisplayErrorCode(ERROR_INVALID_PACKET);
                return 1;
            }
            break;
    }
    
    return 0;
}

void PrintCanPacket(CANPacket packet){
    for(int i = 0; i < packet.dlc; i++ ) {
        sprintf(txData,"Byte%d %x   ", i+1, packet.data[i]);
        Print(txData);
    }

    sprintf(txData,"ID:%x %x %x\r\n",packet.id >> 10, 
        (packet.id >> 6) & 0xF , packet.id & 0x3F);
    Print(txData);
}

int sendRequestedData(int TTC) {
    int32_t data = 0;

    switch(TTC)
    {
        // USE CONSTANTS FOR CASES
        case(0):
            // ADD CODE HERE
        default:
            Print("Cannot Send That Data Type!\n\r");
    }   

    // Assemble and send packet
    AssembleTelemetryReportPacket(&can_send, DEVICE_GROUP_JETSON, DEVICE_SERIAL_JETSON, TTC, data);
    int check = SendCANPacket(&can_send);
    return check;
}

/* [] END OF FILE */