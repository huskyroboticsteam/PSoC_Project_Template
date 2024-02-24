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

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "cyapicallbacks.h"
#include "Temp_CAN.h"
#include "Temp_FSM.h"

// LED stuff
uint8_t CAN_time_LED = 0;
uint8_t ERROR_time_LED = 0;

// UART stuff
char txData[TX_DATA_SIZE];

uint8 address = 0;

CY_ISR(Period_Reset_Handler) {
    CAN_time_LED++;
    ERROR_time_LED++;

    if(ERROR_time_LED >= 3) {
        LED_ERR_Write(OFF);
    }
    if(CAN_time_LED >= 3){
        LED_CAN_Write(OFF);
    }
}

CY_ISR(Button_1_Handler) {
    LED_DBG_1_Write(!LED_DBG_1_Read());
}

int main(void)
{ 
    Initialize();
    int err;
    
    for(;;)
    {
        switch(GetState()) {
            case(UNINIT):
                SetStateTo(CHECK_CAN);
                break;
            case(CHECK_CAN):
                CheckCAN();
                break;
            default:
                DisplayErrorCode(ERROR_INVALID_STATE);
                GotoUninitState();
                break;
        }
        
        if (DBG_UART_SpiUartGetRxBufferSize()) {
            DebugPrint(DBG_UART_UartGetByte());
        }
    }
}

void Initialize(void) {
    CyGlobalIntEnable; /* Enable global interrupts. LED arrays need this first */
    
    address = Can_addr_Read();
    
    DBG_UART_Start();
    sprintf(txData, "Dip Addr: %x \r\n", address);
    Print(txData);
    

    LED_DBG_1_Write(0);
    
    InitCAN(0x4, (int)address);
    Timer_Period_Reset_Start();

    isr_Button_1_StartEx(Button_1_Handler);
    isr_Period_Reset_StartEx(Period_Reset_Handler);
}

void DebugPrint(char input) {
    switch(input) {
        case 'f':
            sprintf(txData, "Mode: %x State:%x \r\n", GetMode(), GetState());
            break;
        case 'x':
            sprintf(txData, "bruh\r\n");
            break;
        default:
            sprintf(txData, "what\r\n");
            break;
    }
    Print(txData);
}

/*
Returns the Packet ID or 0xFF if there is no Packet
This pulls from the CAN lib's FIFO
Also Triggers LED
*/
uint16_t ReadCAN(CANPacket *receivedPacket){
    volatile int error = PollAndReceiveCANPacket(receivedPacket);
    if(!error){
        LED_CAN_Write(ON);
        CAN_time_LED = 0;
        return receivedPacket->data[0];
    }
    return NO_NEW_CAN_PACKET; //Means no Packet
}

void DisplayErrorCode(uint8_t code) {    
    ERROR_time_LED = 0;
    LED_ERR_Write(ON);
    
    Print("Error ");
    PrintInt(code);
    Print("\r\n");

    switch(code)
    {   
        //case0: CAN Packet ERROR
        case 1://Mode Error
            LED_DBG_1_Write(ON);
            break;
        default:
            //some error
            break;
    }

}

/* [] END OF FILE */
