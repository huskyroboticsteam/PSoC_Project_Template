/*******************************************************************************
* File Name: DGB_UART_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_DGB_UART_SCBCLK_H)
#define CY_CLOCK_DGB_UART_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void DGB_UART_SCBCLK_StartEx(uint32 alignClkDiv);
#define DGB_UART_SCBCLK_Start() \
    DGB_UART_SCBCLK_StartEx(DGB_UART_SCBCLK__PA_DIV_ID)

#else

void DGB_UART_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void DGB_UART_SCBCLK_Stop(void);

void DGB_UART_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 DGB_UART_SCBCLK_GetDividerRegister(void);
uint8  DGB_UART_SCBCLK_GetFractionalDividerRegister(void);

#define DGB_UART_SCBCLK_Enable()                         DGB_UART_SCBCLK_Start()
#define DGB_UART_SCBCLK_Disable()                        DGB_UART_SCBCLK_Stop()
#define DGB_UART_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    DGB_UART_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define DGB_UART_SCBCLK_SetDivider(clkDivider)           DGB_UART_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define DGB_UART_SCBCLK_SetDividerValue(clkDivider)      DGB_UART_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define DGB_UART_SCBCLK_DIV_ID     DGB_UART_SCBCLK__DIV_ID

#define DGB_UART_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define DGB_UART_SCBCLK_CTRL_REG   (*(reg32 *)DGB_UART_SCBCLK__CTRL_REGISTER)
#define DGB_UART_SCBCLK_DIV_REG    (*(reg32 *)DGB_UART_SCBCLK__DIV_REGISTER)

#define DGB_UART_SCBCLK_CMD_DIV_SHIFT          (0u)
#define DGB_UART_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define DGB_UART_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define DGB_UART_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define DGB_UART_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << DGB_UART_SCBCLK_CMD_DISABLE_SHIFT))
#define DGB_UART_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << DGB_UART_SCBCLK_CMD_ENABLE_SHIFT))

#define DGB_UART_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define DGB_UART_SCBCLK_DIV_FRAC_SHIFT (3u)
#define DGB_UART_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define DGB_UART_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define DGB_UART_SCBCLK_DIV_REG        (*(reg32 *)DGB_UART_SCBCLK__REGISTER)
#define DGB_UART_SCBCLK_ENABLE_REG     DGB_UART_SCBCLK_DIV_REG
#define DGB_UART_SCBCLK_DIV_FRAC_MASK  DGB_UART_SCBCLK__FRAC_MASK
#define DGB_UART_SCBCLK_DIV_FRAC_SHIFT (16u)
#define DGB_UART_SCBCLK_DIV_INT_MASK   DGB_UART_SCBCLK__DIVIDER_MASK
#define DGB_UART_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_DGB_UART_SCBCLK_H) */

/* [] END OF FILE */
