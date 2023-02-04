
/* 
Davis Sauer

Husky Robotics

2022

Template project adaptable to any PSoC Project

CHANGE CLOCKS TO USE EXT_CLK BEFORE USING ON REAL BOARD (See Clocks documentation)
*/

#include "main.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */ 
    DBG_UART_Start();
    InitCAN( DEVICE_GROUP_MOTOR_CONTROL, getSerialAddress() ); /*UPDATE THIS FOR EACH BOARD*/
           
    Print("\r\n");
    Print("\r\n***************\r\nBOARD INITIALIZED\n\r***************\r\n");
    
    
    int status;
    
    for(;;)
    {
        switch(state)
        {
           // DO SOMETHING
            case(IDLE):        
                
                state = CHECK_CAN;
                break;
            
            //Check CAN for new packet
            case(CHECK_CAN):
                 
                if (PollAndReceiveCANPacket( &receive ) == ERROR_NONE)
                {
                    Print("Packet Found!\r\n");
                    if(GetPacketID( &receive ) == ID_TELEMETRY_PULL)
                    {
                        uint8_t TTC = DecodeTelemetryType( &receive );
                        Print("Sending CAN Packet...\r\n");      
                        sendRequestedData(TTC);
                    }
                }
                
                state = IDLE;
                break;

        }
    }
}

//Reads dip switches to calculate the serial address
int getSerialAddress()
{
    int address = 0;
    if (DIP1_Read()==0)
        address += 1;
  
    if (DIP2_Read()==0)
        address += 2;

    if (DIP3_Read()==0)
        address += 4;

    if (DIP4_Read()==0)
        address += 8;
    
    if (address == 0)
        address = DEVICE_SERIAL_TELEM_LOCALIZATION;
    
    return address;
}

//Using the Telemetry Type Code (TTC), sends appropriate data to respond
//to a telemetry request

void sendRequestedData(int TTC)
{
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
    AssembleTelemetryReportPacket(&send, DEVICE_GROUP_JETSON, DEVICE_SERIAL_JETSON, TTC, data);
    int check = SendCANPacket( &send );
    
    // Blink LED if packet sent correctly
    if (check == ERROR_NONE){
        BlinkDBG();
        CyDelay(50);
    }
}
