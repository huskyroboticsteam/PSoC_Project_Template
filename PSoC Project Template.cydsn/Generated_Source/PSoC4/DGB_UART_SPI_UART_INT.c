/***************************************************************************//**
* \file DGB_UART_SPI_UART_INT.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DGB_UART_PVT.h"
#include "DGB_UART_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (DGB_UART_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: DGB_UART_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(DGB_UART_SPI_UART_ISR)
{
#if (DGB_UART_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (DGB_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if (DGB_UART_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (DGB_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef DGB_UART_SPI_UART_ISR_ENTRY_CALLBACK
    DGB_UART_SPI_UART_ISR_EntryCallback();
#endif /* DGB_UART_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != DGB_UART_customIntrHandler)
    {
        DGB_UART_customIntrHandler();
    }

    #if(DGB_UART_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        DGB_UART_ClearSpiExtClkInterruptSource(DGB_UART_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (DGB_UART_CHECK_RX_SW_BUFFER)
    {
        if (DGB_UART_CHECK_INTR_RX_MASKED(DGB_UART_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (DGB_UART_rxBufferHead + 1u);

                /* Adjust local head index */
                if (DGB_UART_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == DGB_UART_rxBufferTail)
                {
                    #if (DGB_UART_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        DGB_UART_INTR_RX_MASK_REG &= ~DGB_UART_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) DGB_UART_RX_FIFO_RD_REG;
                        DGB_UART_rxBufferOverflow = (uint8) DGB_UART_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    DGB_UART_PutWordInRxBuffer(locHead, DGB_UART_RX_FIFO_RD_REG);

                    /* Move head index */
                    DGB_UART_rxBufferHead = locHead;
                }
            }
            while(0u != DGB_UART_GET_RX_FIFO_ENTRIES);

            DGB_UART_ClearRxInterruptSource(DGB_UART_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (DGB_UART_CHECK_TX_SW_BUFFER)
    {
        if (DGB_UART_CHECK_INTR_TX_MASKED(DGB_UART_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (DGB_UART_txBufferHead != DGB_UART_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (DGB_UART_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (DGB_UART_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    DGB_UART_TX_FIFO_WR_REG = DGB_UART_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    DGB_UART_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    DGB_UART_DISABLE_INTR_TX(DGB_UART_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (DGB_UART_SPI_UART_FIFO_SIZE != DGB_UART_GET_TX_FIFO_ENTRIES);

            DGB_UART_ClearTxInterruptSource(DGB_UART_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef DGB_UART_SPI_UART_ISR_EXIT_CALLBACK
    DGB_UART_SPI_UART_ISR_ExitCallback();
#endif /* DGB_UART_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (DGB_UART_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
