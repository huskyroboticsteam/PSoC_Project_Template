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
#pragma once
    
#include "HindsightCAN/CANLibrary.h"
#include "cyapicallbacks.h"
#include <stdint.h>
        
#define ON  1
#define OFF 0

#define TX_DATA_SIZE            (100u)

#define ERROR_INVALID_PACKET  0x0
#define ERROR_WRONG_MODE      0x1
#define ERROR_INVALID_STATE   0x2

#define Print(message) DBG_UART_UartPutString(message)
#define PrintChar(character) DBG_UART_UartPutChar(character)
#define PrintInt(integer) DBG_UART_UartPutString(itoa(integer, txData, 10))
#define PrintIntBin(integer) DBG_UART_UartPutString(itoa(integer, txData, 2))

void Initialize(void);
int getSerialAddress();
uint16_t ReadCAN(CANPacket *receivedPacket);
void DebugPrint(char input);
void DisplayErrorCode(uint8_t code);


/* [] END OF FILE */
