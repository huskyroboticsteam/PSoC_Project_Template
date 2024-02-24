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
#include "main.h"
#include "cyapicallbacks.h"
#include "Temp_CAN.h"
#include "Temp_FSM.h"

// LED stuff
uint8_t CAN_time_LED = 0;
uint8_t ERROR_time_LED = 0;

// UART stuff
char txData[TX_DATA_SIZE];

// CAN stuff
CANPacket can_recieve;
CANPacket can_send;

uint8 address = 0;

CY_ISR(Period_Reset_Handler) {
    CAN_time_LED++;
    CAN_check_delay ++;
    ERRORTimeLED++;

    if(ERRORTimeLED >= 3) {
        
        ERROR_LED_Write(LED_OFF);
    }
    if(CAN_time_LED >= 3){
        CAN_LED_Write(LED_OFF);
    }
}

CY_ISR(Button_1_Handler) {
    invalidate++;
    CAN_time_LED++;
    CAN_check_delay ++;
    ERRORTimeLED++;

    if(invalidate >= 20){
        set_PWM(0, 0, 0);   
    }
    if(ERRORTimeLED >= 3) {
        #ifdef ERROR_LED
        ERROR_LED_Write(LED_OFF);
        #endif
        #ifdef DEBUG_LED1   
        Debug_1_Write(LED_OFF);
        #endif
    }
    if(CAN_time_LED >= 3){
        #ifdef CAN_LED
        CAN_LED_Write(LED_OFF);
        #endif
    }
}

int main(void)
{ 
    Initialize();
    
    for(;;)
    {
        switch(GetState()) {
            case(UNINIT):
                SetStateTo(CHECK_CAN);
                break;
            case(QUEUE_ERROR):
                SetStateTo(CHECK_CAN);
                break;
            case(CHECK_CAN):
                NextStateFromCAN(&can_recieve, &can_send);
                #ifdef PRINT_CAN_PACKET
                PrintCanPacket(can_recieve);
                #endif
                break;
            default:
                //Should Never Get Here
                //TODO: ERROR
                GotoUninitState();
                break;
        }
        
        if (UART_SpiUartGetRxBufferSize()) {
            DebugPrint(UART_UartGetByte());
        }
    }
}

void Initialize(void) {
    CyGlobalIntEnable; /* Enable global interrupts. LED arrays need this first */
    
    Status_Reg_Switches_InterruptEnable();
    
    address = Can_addr_Read();
    
    DBG_UART_Start();
    sprintf(txData, "Dip Addr: %x \r\n", address);
    Print(txData);
    #endif
    

    LED_DBG_1_Write(0);
    
    InitCAN(0x4, (int)address);
    Timer_Period_Reset_Start();

    isr_Button_1_StartEx(Button_1_Handler);
    isr_Period_Reset_StartEx(Period_Reset_Handler);
}

void DebugPrint(char input) {
    switch(input) {
        case 'e':
            sprintf(txData, "Encoder Value: %li  \r\n", QuadDec_GetCounter());
            break;
        case 'f':
            sprintf(txData, "Mode: %x State:%x \r\n", GetMode(), GetState());
            break;
        case 'd':
            sprintf(txData, "P: %i I: %i D: %i Conv: %i Ready: %i \r\n", 
            GetkPosition(), GetkIntegral(), GetkDerivative(), (int) GetConversion(), PIDconstsSet());
            break;
        case 'p':
            sprintf(txData, "Position (mDeg): %i \r\n", GetPositionmDeg());
            break;
        case 'x':
            sprintf(txData, "Value: %d  ADC range: %d-%d  mDeg range: %d-%d  usePot=%d\r\n", 
                            GetPotVal(), GetTickMin(), GetTickMax(),
                            GetmDegMin(), GetmDegMax(), GetUsingPot());
            break;
        default:
            sprintf(txData, "what\r\n");
            break;
    }
    Print(txData);
}

void PrintCanPacket(CANPacket receivedPacket){
    for(int i = 0; i < receivedPacket.dlc; i++ ) {
        sprintf(txData,"Byte%d %x   ", i+1, receivedPacket.data[i]);
        UART_UartPutString(txData);
    }

    sprintf(txData,"ID:%x %x %x\r\n",receivedPacket.id >> 10, 
        (receivedPacket.id >> 6) & 0xF , receivedPacket.id & 0x3F);
    UART_UartPutString(txData);
}

uint16_t ReadCAN(CANPacket *receivedPacket){
    volatile int error = PollAndReceiveCANPacket(receivedPacket);
    if(!error){
        #ifdef CAN_LED
        CAN_LED_Write(LED_ON);
        #endif
        CAN_time_LED = 0;
        return receivedPacket->data[0];
    }
    return NO_NEW_CAN_PACKET; //Means no Packet
}

void DisplayErrorCode(uint8_t code) {
    
    #ifdef ERROR_LED
    ERROR_LED_Write(LED_OFF);
    #endif
    #ifdef DEBUG_LED1   
    Debug_1_Write(LED_OFF);
    #endif
    
    ERRORTimeLED = 0;
    ERROR_LED_Write(LED_ON);
    
    #ifdef PRINT_MOTOR_ERROR
        //TODO: PRINT ERROR
    #endif

    switch(code)
    {   
        //case0: CAN Packet ERROR
        case 1://Mode Error
            #ifdef DEBUG_LED1
            Debug_1_Write(LED_ON);
            #endif
            break;
        default:
            //some error
            break;
    }

}

/* [] END OF FILE */
