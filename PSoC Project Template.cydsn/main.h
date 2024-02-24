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
#ifndef MAIN_HEADER
    #define MAIN_HEADER
    
    #include "HindsightCAN/CANLibrary.h"
    #include "cyapicallbacks.h"
    #include <stdint.h>
            
    #define ON  1
    #define OFF 0

    #define TX_DATA_SIZE            (100u)
    
    #define ERROR_INVALID_PACKET  0x0
    #define ERROR_WRONG_MODE      0x1
    
    #define Print(message) DBG_UART_UartPutString(message)
    #define PrintChar(character) DBG_UART_UartPutChar(character)
    #define PrintInt(integer) DBG_UART_UartPutString(itoa(integer, debugOutput, 10))
    #define PrintIntBin(integer) DBG_UART_UartPutString(itoa(integer, debugOutput, 2))

    //void check_Pin(void);
    struct Error
    {
        uint8_t code, param, done;  
    };
    
    void Initialize(void);
        
    //debug tool for that prints packet to UART
    void PrintCanPacket(CANPacket receivedPacket);
    
    /*Returns the Packet ID or 0xFF if there is no Packet
    This pulls from the CAN lib's FIFO
    Also Triggers LED
    */
    uint16_t ReadCAN(CANPacket *receivedPacket);
    
    void DebugPrint(char input);
    void DisplayErrorCode(uint8_t code);
    
#endif
    
/* [] END OF FILE */
