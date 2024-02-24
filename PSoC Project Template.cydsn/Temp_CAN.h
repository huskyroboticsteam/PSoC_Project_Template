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

#include <project.h>
#include "HindsightCAN/CANLibrary.h"

#define NO_NEW_CAN_PACKET 0xFFFF

int CheckCAN();
int sendRequestedData(int TTC);
void PrintCanPacket(CANPacket packet);

/* [] END OF FILE */
    