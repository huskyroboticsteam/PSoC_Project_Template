#include "project.h"
#include "CANLibrary.h"


#define CHIP_TYPE CHIP_TYPE_PSOC_CY8C4248AZI_L485


//Debugging macros
#define Print(message) DBG_UART_UartPutString(message)
#define PrintChar(character) DBG_UART_UartPutChar(character)
#define PrintInt(integer) DBG_UART_UartPutString(itoa(integer, debugOutput, 10))
#define PrintIntBin(integer) DBG_UART_UartPutString(itoa(integer, debugOutput, 2))
#define BlinkDBG() DBG_Write( ! DBG_Read() )

char debugOutput[32];


//Switch values for FSM states
#define IDLE         0
#define CHECK_CAN    1

int state = IDLE;


//Global CAN related variables
CANPacket send;
CANPacket receive;


//Take a wild guess at what this function does
int getSerialAddress();


//Sends CAN packet with data that the TTC calls for
void sendRequestedData();