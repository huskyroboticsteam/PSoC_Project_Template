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
#include <stdint.h>

//States in FSM
#define UNINIT          0xFF
#define MODE1           0x0
#define MODE2           0x1
#define CHECK_CAN       0x2
#define QUEUE_ERROR     0x3

void GotoUninitState();
void SetStateTo(uint8_t state);
void SetModeTo(uint8_t mode);
uint8_t GetState();
uint8_t GetMode();

/* [] END OF FILE */