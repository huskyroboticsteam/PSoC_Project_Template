/***************************************************************************//**
* \file USB_DEBUG_PINS.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_USB_DEBUG_H)
#define CY_SCB_PINS_USB_DEBUG_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define USB_DEBUG_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define USB_DEBUG_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define USB_DEBUG_REMOVE_TX_SDA_MISO_PIN      (1u)
#define USB_DEBUG_REMOVE_CTS_SCLK_PIN      (1u)
#define USB_DEBUG_REMOVE_RTS_SS0_PIN      (1u)
#define USB_DEBUG_REMOVE_SS1_PIN                 (1u)
#define USB_DEBUG_REMOVE_SS2_PIN                 (1u)
#define USB_DEBUG_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define USB_DEBUG_REMOVE_I2C_PINS                (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_PINS         (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define USB_DEBUG_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define USB_DEBUG_REMOVE_SPI_SLAVE_PINS          (1u)
#define USB_DEBUG_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define USB_DEBUG_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define USB_DEBUG_REMOVE_UART_TX_PIN             (0u)
#define USB_DEBUG_REMOVE_UART_RX_TX_PIN          (1u)
#define USB_DEBUG_REMOVE_UART_RX_PIN             (0u)
#define USB_DEBUG_REMOVE_UART_RX_WAKE_PIN        (1u)
#define USB_DEBUG_REMOVE_UART_RTS_PIN            (1u)
#define USB_DEBUG_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define USB_DEBUG_RX_WAKE_SCL_MOSI_PIN (0u == USB_DEBUG_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define USB_DEBUG_RX_SCL_MOSI_PIN     (0u == USB_DEBUG_REMOVE_RX_SCL_MOSI_PIN)
#define USB_DEBUG_TX_SDA_MISO_PIN     (0u == USB_DEBUG_REMOVE_TX_SDA_MISO_PIN)
#define USB_DEBUG_CTS_SCLK_PIN     (0u == USB_DEBUG_REMOVE_CTS_SCLK_PIN)
#define USB_DEBUG_RTS_SS0_PIN     (0u == USB_DEBUG_REMOVE_RTS_SS0_PIN)
#define USB_DEBUG_SS1_PIN                (0u == USB_DEBUG_REMOVE_SS1_PIN)
#define USB_DEBUG_SS2_PIN                (0u == USB_DEBUG_REMOVE_SS2_PIN)
#define USB_DEBUG_SS3_PIN                (0u == USB_DEBUG_REMOVE_SS3_PIN)

/* Mode defined pins */
#define USB_DEBUG_I2C_PINS               (0u == USB_DEBUG_REMOVE_I2C_PINS)
#define USB_DEBUG_SPI_MASTER_PINS        (0u == USB_DEBUG_REMOVE_SPI_MASTER_PINS)
#define USB_DEBUG_SPI_MASTER_SCLK_PIN    (0u == USB_DEBUG_REMOVE_SPI_MASTER_SCLK_PIN)
#define USB_DEBUG_SPI_MASTER_MOSI_PIN    (0u == USB_DEBUG_REMOVE_SPI_MASTER_MOSI_PIN)
#define USB_DEBUG_SPI_MASTER_MISO_PIN    (0u == USB_DEBUG_REMOVE_SPI_MASTER_MISO_PIN)
#define USB_DEBUG_SPI_MASTER_SS0_PIN     (0u == USB_DEBUG_REMOVE_SPI_MASTER_SS0_PIN)
#define USB_DEBUG_SPI_MASTER_SS1_PIN     (0u == USB_DEBUG_REMOVE_SPI_MASTER_SS1_PIN)
#define USB_DEBUG_SPI_MASTER_SS2_PIN     (0u == USB_DEBUG_REMOVE_SPI_MASTER_SS2_PIN)
#define USB_DEBUG_SPI_MASTER_SS3_PIN     (0u == USB_DEBUG_REMOVE_SPI_MASTER_SS3_PIN)
#define USB_DEBUG_SPI_SLAVE_PINS         (0u == USB_DEBUG_REMOVE_SPI_SLAVE_PINS)
#define USB_DEBUG_SPI_SLAVE_MOSI_PIN     (0u == USB_DEBUG_REMOVE_SPI_SLAVE_MOSI_PIN)
#define USB_DEBUG_SPI_SLAVE_MISO_PIN     (0u == USB_DEBUG_REMOVE_SPI_SLAVE_MISO_PIN)
#define USB_DEBUG_UART_TX_PIN            (0u == USB_DEBUG_REMOVE_UART_TX_PIN)
#define USB_DEBUG_UART_RX_TX_PIN         (0u == USB_DEBUG_REMOVE_UART_RX_TX_PIN)
#define USB_DEBUG_UART_RX_PIN            (0u == USB_DEBUG_REMOVE_UART_RX_PIN)
#define USB_DEBUG_UART_RX_WAKE_PIN       (0u == USB_DEBUG_REMOVE_UART_RX_WAKE_PIN)
#define USB_DEBUG_UART_RTS_PIN           (0u == USB_DEBUG_REMOVE_UART_RTS_PIN)
#define USB_DEBUG_UART_CTS_PIN           (0u == USB_DEBUG_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (USB_DEBUG_RX_WAKE_SCL_MOSI_PIN)
    #include "USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (USB_DEBUG_RX_SCL_MOSI) */

#if (USB_DEBUG_RX_SCL_MOSI_PIN)
    #include "USB_DEBUG_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (USB_DEBUG_RX_SCL_MOSI) */

#if (USB_DEBUG_TX_SDA_MISO_PIN)
    #include "USB_DEBUG_uart_tx_i2c_sda_spi_miso.h"
#endif /* (USB_DEBUG_TX_SDA_MISO) */

#if (USB_DEBUG_CTS_SCLK_PIN)
    #include "USB_DEBUG_uart_cts_spi_sclk.h"
#endif /* (USB_DEBUG_CTS_SCLK) */

#if (USB_DEBUG_RTS_SS0_PIN)
    #include "USB_DEBUG_uart_rts_spi_ss0.h"
#endif /* (USB_DEBUG_RTS_SS0_PIN) */

#if (USB_DEBUG_SS1_PIN)
    #include "USB_DEBUG_spi_ss1.h"
#endif /* (USB_DEBUG_SS1_PIN) */

#if (USB_DEBUG_SS2_PIN)
    #include "USB_DEBUG_spi_ss2.h"
#endif /* (USB_DEBUG_SS2_PIN) */

#if (USB_DEBUG_SS3_PIN)
    #include "USB_DEBUG_spi_ss3.h"
#endif /* (USB_DEBUG_SS3_PIN) */

#if (USB_DEBUG_I2C_PINS)
    #include "USB_DEBUG_scl.h"
    #include "USB_DEBUG_sda.h"
#endif /* (USB_DEBUG_I2C_PINS) */

#if (USB_DEBUG_SPI_MASTER_PINS)
#if (USB_DEBUG_SPI_MASTER_SCLK_PIN)
    #include "USB_DEBUG_sclk_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_SCLK_PIN) */

#if (USB_DEBUG_SPI_MASTER_MOSI_PIN)
    #include "USB_DEBUG_mosi_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_MOSI_PIN) */

#if (USB_DEBUG_SPI_MASTER_MISO_PIN)
    #include "USB_DEBUG_miso_m.h"
#endif /*(USB_DEBUG_SPI_MASTER_MISO_PIN) */
#endif /* (USB_DEBUG_SPI_MASTER_PINS) */

#if (USB_DEBUG_SPI_SLAVE_PINS)
    #include "USB_DEBUG_sclk_s.h"
    #include "USB_DEBUG_ss_s.h"

#if (USB_DEBUG_SPI_SLAVE_MOSI_PIN)
    #include "USB_DEBUG_mosi_s.h"
#endif /* (USB_DEBUG_SPI_SLAVE_MOSI_PIN) */

#if (USB_DEBUG_SPI_SLAVE_MISO_PIN)
    #include "USB_DEBUG_miso_s.h"
#endif /*(USB_DEBUG_SPI_SLAVE_MISO_PIN) */
#endif /* (USB_DEBUG_SPI_SLAVE_PINS) */

#if (USB_DEBUG_SPI_MASTER_SS0_PIN)
    #include "USB_DEBUG_ss0_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_SS0_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS1_PIN)
    #include "USB_DEBUG_ss1_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_SS1_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS2_PIN)
    #include "USB_DEBUG_ss2_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_SS2_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS3_PIN)
    #include "USB_DEBUG_ss3_m.h"
#endif /* (USB_DEBUG_SPI_MASTER_SS3_PIN) */

#if (USB_DEBUG_UART_TX_PIN)
    #include "USB_DEBUG_tx.h"
#endif /* (USB_DEBUG_UART_TX_PIN) */

#if (USB_DEBUG_UART_RX_TX_PIN)
    #include "USB_DEBUG_rx_tx.h"
#endif /* (USB_DEBUG_UART_RX_TX_PIN) */

#if (USB_DEBUG_UART_RX_PIN)
    #include "USB_DEBUG_rx.h"
#endif /* (USB_DEBUG_UART_RX_PIN) */

#if (USB_DEBUG_UART_RX_WAKE_PIN)
    #include "USB_DEBUG_rx_wake.h"
#endif /* (USB_DEBUG_UART_RX_WAKE_PIN) */

#if (USB_DEBUG_UART_RTS_PIN)
    #include "USB_DEBUG_rts.h"
#endif /* (USB_DEBUG_UART_RTS_PIN) */

#if (USB_DEBUG_UART_CTS_PIN)
    #include "USB_DEBUG_cts.h"
#endif /* (USB_DEBUG_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (USB_DEBUG_RX_SCL_MOSI_PIN)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_MASK      (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_POS       (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_SEL_GPIO  (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_SEL_I2C   (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_SEL_SPI   (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define USB_DEBUG_RX_SCL_MOSI_HSIOM_SEL_UART  (USB_DEBUG_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (USB_DEBUG_RX_WAKE_SCL_MOSI_PIN)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_MASK      (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_POS       (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define USB_DEBUG_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) USB_DEBUG_INTCFG_TYPE_MASK << \
                                                                           USB_DEBUG_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins USB_DEBUG_RX_SCL_MOSI_PIN or USB_DEBUG_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (USB_DEBUG_RX_SCL_MOSI_PIN) */

#if (USB_DEBUG_TX_SDA_MISO_PIN)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_MASK      (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_POS       (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_SEL_GPIO  (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_SEL_I2C   (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_SEL_SPI   (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define USB_DEBUG_TX_SDA_MISO_HSIOM_SEL_UART  (USB_DEBUG_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (USB_DEBUG_TX_SDA_MISO_PIN) */

#if (USB_DEBUG_CTS_SCLK_PIN)
    #define USB_DEBUG_CTS_SCLK_HSIOM_REG   (*(reg32 *) USB_DEBUG_uart_cts_spi_sclk__0__HSIOM)
    #define USB_DEBUG_CTS_SCLK_HSIOM_PTR   ( (reg32 *) USB_DEBUG_uart_cts_spi_sclk__0__HSIOM)
    
    #define USB_DEBUG_CTS_SCLK_HSIOM_MASK      (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define USB_DEBUG_CTS_SCLK_HSIOM_POS       (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_SHIFT)
    #define USB_DEBUG_CTS_SCLK_HSIOM_SEL_GPIO  (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_GPIO)
    #define USB_DEBUG_CTS_SCLK_HSIOM_SEL_I2C   (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_I2C)
    #define USB_DEBUG_CTS_SCLK_HSIOM_SEL_SPI   (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_SPI)
    #define USB_DEBUG_CTS_SCLK_HSIOM_SEL_UART  (USB_DEBUG_uart_cts_spi_sclk__0__HSIOM_UART)
#endif /* (USB_DEBUG_CTS_SCLK_PIN) */

#if (USB_DEBUG_RTS_SS0_PIN)
    #define USB_DEBUG_RTS_SS0_HSIOM_REG   (*(reg32 *) USB_DEBUG_uart_rts_spi_ss0__0__HSIOM)
    #define USB_DEBUG_RTS_SS0_HSIOM_PTR   ( (reg32 *) USB_DEBUG_uart_rts_spi_ss0__0__HSIOM)
    
    #define USB_DEBUG_RTS_SS0_HSIOM_MASK      (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define USB_DEBUG_RTS_SS0_HSIOM_POS       (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_SHIFT)
    #define USB_DEBUG_RTS_SS0_HSIOM_SEL_GPIO  (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_GPIO)
    #define USB_DEBUG_RTS_SS0_HSIOM_SEL_I2C   (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_I2C)
    #define USB_DEBUG_RTS_SS0_HSIOM_SEL_SPI   (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_SPI)
#if !(USB_DEBUG_CY_SCBIP_V0 || USB_DEBUG_CY_SCBIP_V1)
    #define USB_DEBUG_RTS_SS0_HSIOM_SEL_UART  (USB_DEBUG_uart_rts_spi_ss0__0__HSIOM_UART)
#endif /* !(USB_DEBUG_CY_SCBIP_V0 || USB_DEBUG_CY_SCBIP_V1) */
#endif /* (USB_DEBUG_RTS_SS0_PIN) */

#if (USB_DEBUG_SS1_PIN)
    #define USB_DEBUG_SS1_HSIOM_REG  (*(reg32 *) USB_DEBUG_spi_ss1__0__HSIOM)
    #define USB_DEBUG_SS1_HSIOM_PTR  ( (reg32 *) USB_DEBUG_spi_ss1__0__HSIOM)
    
    #define USB_DEBUG_SS1_HSIOM_MASK     (USB_DEBUG_spi_ss1__0__HSIOM_MASK)
    #define USB_DEBUG_SS1_HSIOM_POS      (USB_DEBUG_spi_ss1__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS1_HSIOM_SEL_GPIO (USB_DEBUG_spi_ss1__0__HSIOM_GPIO)
    #define USB_DEBUG_SS1_HSIOM_SEL_I2C  (USB_DEBUG_spi_ss1__0__HSIOM_I2C)
    #define USB_DEBUG_SS1_HSIOM_SEL_SPI  (USB_DEBUG_spi_ss1__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SS1_PIN) */

#if (USB_DEBUG_SS2_PIN)
    #define USB_DEBUG_SS2_HSIOM_REG     (*(reg32 *) USB_DEBUG_spi_ss2__0__HSIOM)
    #define USB_DEBUG_SS2_HSIOM_PTR     ( (reg32 *) USB_DEBUG_spi_ss2__0__HSIOM)
    
    #define USB_DEBUG_SS2_HSIOM_MASK     (USB_DEBUG_spi_ss2__0__HSIOM_MASK)
    #define USB_DEBUG_SS2_HSIOM_POS      (USB_DEBUG_spi_ss2__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS2_HSIOM_SEL_GPIO (USB_DEBUG_spi_ss2__0__HSIOM_GPIO)
    #define USB_DEBUG_SS2_HSIOM_SEL_I2C  (USB_DEBUG_spi_ss2__0__HSIOM_I2C)
    #define USB_DEBUG_SS2_HSIOM_SEL_SPI  (USB_DEBUG_spi_ss2__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SS2_PIN) */

#if (USB_DEBUG_SS3_PIN)
    #define USB_DEBUG_SS3_HSIOM_REG     (*(reg32 *) USB_DEBUG_spi_ss3__0__HSIOM)
    #define USB_DEBUG_SS3_HSIOM_PTR     ( (reg32 *) USB_DEBUG_spi_ss3__0__HSIOM)
    
    #define USB_DEBUG_SS3_HSIOM_MASK     (USB_DEBUG_spi_ss3__0__HSIOM_MASK)
    #define USB_DEBUG_SS3_HSIOM_POS      (USB_DEBUG_spi_ss3__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS3_HSIOM_SEL_GPIO (USB_DEBUG_spi_ss3__0__HSIOM_GPIO)
    #define USB_DEBUG_SS3_HSIOM_SEL_I2C  (USB_DEBUG_spi_ss3__0__HSIOM_I2C)
    #define USB_DEBUG_SS3_HSIOM_SEL_SPI  (USB_DEBUG_spi_ss3__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SS3_PIN) */

#if (USB_DEBUG_I2C_PINS)
    #define USB_DEBUG_SCL_HSIOM_REG  (*(reg32 *) USB_DEBUG_scl__0__HSIOM)
    #define USB_DEBUG_SCL_HSIOM_PTR  ( (reg32 *) USB_DEBUG_scl__0__HSIOM)
    
    #define USB_DEBUG_SCL_HSIOM_MASK     (USB_DEBUG_scl__0__HSIOM_MASK)
    #define USB_DEBUG_SCL_HSIOM_POS      (USB_DEBUG_scl__0__HSIOM_SHIFT)
    #define USB_DEBUG_SCL_HSIOM_SEL_GPIO (USB_DEBUG_sda__0__HSIOM_GPIO)
    #define USB_DEBUG_SCL_HSIOM_SEL_I2C  (USB_DEBUG_sda__0__HSIOM_I2C)
    
    #define USB_DEBUG_SDA_HSIOM_REG  (*(reg32 *) USB_DEBUG_sda__0__HSIOM)
    #define USB_DEBUG_SDA_HSIOM_PTR  ( (reg32 *) USB_DEBUG_sda__0__HSIOM)
    
    #define USB_DEBUG_SDA_HSIOM_MASK     (USB_DEBUG_sda__0__HSIOM_MASK)
    #define USB_DEBUG_SDA_HSIOM_POS      (USB_DEBUG_sda__0__HSIOM_SHIFT)
    #define USB_DEBUG_SDA_HSIOM_SEL_GPIO (USB_DEBUG_sda__0__HSIOM_GPIO)
    #define USB_DEBUG_SDA_HSIOM_SEL_I2C  (USB_DEBUG_sda__0__HSIOM_I2C)
#endif /* (USB_DEBUG_I2C_PINS) */

#if (USB_DEBUG_SPI_SLAVE_PINS)
    #define USB_DEBUG_SCLK_S_HSIOM_REG   (*(reg32 *) USB_DEBUG_sclk_s__0__HSIOM)
    #define USB_DEBUG_SCLK_S_HSIOM_PTR   ( (reg32 *) USB_DEBUG_sclk_s__0__HSIOM)
    
    #define USB_DEBUG_SCLK_S_HSIOM_MASK      (USB_DEBUG_sclk_s__0__HSIOM_MASK)
    #define USB_DEBUG_SCLK_S_HSIOM_POS       (USB_DEBUG_sclk_s__0__HSIOM_SHIFT)
    #define USB_DEBUG_SCLK_S_HSIOM_SEL_GPIO  (USB_DEBUG_sclk_s__0__HSIOM_GPIO)
    #define USB_DEBUG_SCLK_S_HSIOM_SEL_SPI   (USB_DEBUG_sclk_s__0__HSIOM_SPI)
    
    #define USB_DEBUG_SS0_S_HSIOM_REG    (*(reg32 *) USB_DEBUG_ss0_s__0__HSIOM)
    #define USB_DEBUG_SS0_S_HSIOM_PTR    ( (reg32 *) USB_DEBUG_ss0_s__0__HSIOM)
    
    #define USB_DEBUG_SS0_S_HSIOM_MASK       (USB_DEBUG_ss0_s__0__HSIOM_MASK)
    #define USB_DEBUG_SS0_S_HSIOM_POS        (USB_DEBUG_ss0_s__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS0_S_HSIOM_SEL_GPIO   (USB_DEBUG_ss0_s__0__HSIOM_GPIO)  
    #define USB_DEBUG_SS0_S_HSIOM_SEL_SPI    (USB_DEBUG_ss0_s__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_SLAVE_PINS) */

#if (USB_DEBUG_SPI_SLAVE_MOSI_PIN)
    #define USB_DEBUG_MOSI_S_HSIOM_REG   (*(reg32 *) USB_DEBUG_mosi_s__0__HSIOM)
    #define USB_DEBUG_MOSI_S_HSIOM_PTR   ( (reg32 *) USB_DEBUG_mosi_s__0__HSIOM)
    
    #define USB_DEBUG_MOSI_S_HSIOM_MASK      (USB_DEBUG_mosi_s__0__HSIOM_MASK)
    #define USB_DEBUG_MOSI_S_HSIOM_POS       (USB_DEBUG_mosi_s__0__HSIOM_SHIFT)
    #define USB_DEBUG_MOSI_S_HSIOM_SEL_GPIO  (USB_DEBUG_mosi_s__0__HSIOM_GPIO)
    #define USB_DEBUG_MOSI_S_HSIOM_SEL_SPI   (USB_DEBUG_mosi_s__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_SLAVE_MOSI_PIN) */

#if (USB_DEBUG_SPI_SLAVE_MISO_PIN)
    #define USB_DEBUG_MISO_S_HSIOM_REG   (*(reg32 *) USB_DEBUG_miso_s__0__HSIOM)
    #define USB_DEBUG_MISO_S_HSIOM_PTR   ( (reg32 *) USB_DEBUG_miso_s__0__HSIOM)
    
    #define USB_DEBUG_MISO_S_HSIOM_MASK      (USB_DEBUG_miso_s__0__HSIOM_MASK)
    #define USB_DEBUG_MISO_S_HSIOM_POS       (USB_DEBUG_miso_s__0__HSIOM_SHIFT)
    #define USB_DEBUG_MISO_S_HSIOM_SEL_GPIO  (USB_DEBUG_miso_s__0__HSIOM_GPIO)
    #define USB_DEBUG_MISO_S_HSIOM_SEL_SPI   (USB_DEBUG_miso_s__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_SLAVE_MISO_PIN) */

#if (USB_DEBUG_SPI_MASTER_MISO_PIN)
    #define USB_DEBUG_MISO_M_HSIOM_REG   (*(reg32 *) USB_DEBUG_miso_m__0__HSIOM)
    #define USB_DEBUG_MISO_M_HSIOM_PTR   ( (reg32 *) USB_DEBUG_miso_m__0__HSIOM)
    
    #define USB_DEBUG_MISO_M_HSIOM_MASK      (USB_DEBUG_miso_m__0__HSIOM_MASK)
    #define USB_DEBUG_MISO_M_HSIOM_POS       (USB_DEBUG_miso_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_MISO_M_HSIOM_SEL_GPIO  (USB_DEBUG_miso_m__0__HSIOM_GPIO)
    #define USB_DEBUG_MISO_M_HSIOM_SEL_SPI   (USB_DEBUG_miso_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_MISO_PIN) */

#if (USB_DEBUG_SPI_MASTER_MOSI_PIN)
    #define USB_DEBUG_MOSI_M_HSIOM_REG   (*(reg32 *) USB_DEBUG_mosi_m__0__HSIOM)
    #define USB_DEBUG_MOSI_M_HSIOM_PTR   ( (reg32 *) USB_DEBUG_mosi_m__0__HSIOM)
    
    #define USB_DEBUG_MOSI_M_HSIOM_MASK      (USB_DEBUG_mosi_m__0__HSIOM_MASK)
    #define USB_DEBUG_MOSI_M_HSIOM_POS       (USB_DEBUG_mosi_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_MOSI_M_HSIOM_SEL_GPIO  (USB_DEBUG_mosi_m__0__HSIOM_GPIO)
    #define USB_DEBUG_MOSI_M_HSIOM_SEL_SPI   (USB_DEBUG_mosi_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_MOSI_PIN) */

#if (USB_DEBUG_SPI_MASTER_SCLK_PIN)
    #define USB_DEBUG_SCLK_M_HSIOM_REG   (*(reg32 *) USB_DEBUG_sclk_m__0__HSIOM)
    #define USB_DEBUG_SCLK_M_HSIOM_PTR   ( (reg32 *) USB_DEBUG_sclk_m__0__HSIOM)
    
    #define USB_DEBUG_SCLK_M_HSIOM_MASK      (USB_DEBUG_sclk_m__0__HSIOM_MASK)
    #define USB_DEBUG_SCLK_M_HSIOM_POS       (USB_DEBUG_sclk_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_SCLK_M_HSIOM_SEL_GPIO  (USB_DEBUG_sclk_m__0__HSIOM_GPIO)
    #define USB_DEBUG_SCLK_M_HSIOM_SEL_SPI   (USB_DEBUG_sclk_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_SCLK_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS0_PIN)
    #define USB_DEBUG_SS0_M_HSIOM_REG    (*(reg32 *) USB_DEBUG_ss0_m__0__HSIOM)
    #define USB_DEBUG_SS0_M_HSIOM_PTR    ( (reg32 *) USB_DEBUG_ss0_m__0__HSIOM)
    
    #define USB_DEBUG_SS0_M_HSIOM_MASK       (USB_DEBUG_ss0_m__0__HSIOM_MASK)
    #define USB_DEBUG_SS0_M_HSIOM_POS        (USB_DEBUG_ss0_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS0_M_HSIOM_SEL_GPIO   (USB_DEBUG_ss0_m__0__HSIOM_GPIO)
    #define USB_DEBUG_SS0_M_HSIOM_SEL_SPI    (USB_DEBUG_ss0_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_SS0_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS1_PIN)
    #define USB_DEBUG_SS1_M_HSIOM_REG    (*(reg32 *) USB_DEBUG_ss1_m__0__HSIOM)
    #define USB_DEBUG_SS1_M_HSIOM_PTR    ( (reg32 *) USB_DEBUG_ss1_m__0__HSIOM)
    
    #define USB_DEBUG_SS1_M_HSIOM_MASK       (USB_DEBUG_ss1_m__0__HSIOM_MASK)
    #define USB_DEBUG_SS1_M_HSIOM_POS        (USB_DEBUG_ss1_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS1_M_HSIOM_SEL_GPIO   (USB_DEBUG_ss1_m__0__HSIOM_GPIO)
    #define USB_DEBUG_SS1_M_HSIOM_SEL_SPI    (USB_DEBUG_ss1_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_SS1_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS2_PIN)
    #define USB_DEBUG_SS2_M_HSIOM_REG    (*(reg32 *) USB_DEBUG_ss2_m__0__HSIOM)
    #define USB_DEBUG_SS2_M_HSIOM_PTR    ( (reg32 *) USB_DEBUG_ss2_m__0__HSIOM)
    
    #define USB_DEBUG_SS2_M_HSIOM_MASK       (USB_DEBUG_ss2_m__0__HSIOM_MASK)
    #define USB_DEBUG_SS2_M_HSIOM_POS        (USB_DEBUG_ss2_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS2_M_HSIOM_SEL_GPIO   (USB_DEBUG_ss2_m__0__HSIOM_GPIO)
    #define USB_DEBUG_SS2_M_HSIOM_SEL_SPI    (USB_DEBUG_ss2_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_SS2_PIN) */

#if (USB_DEBUG_SPI_MASTER_SS3_PIN)
    #define USB_DEBUG_SS3_M_HSIOM_REG    (*(reg32 *) USB_DEBUG_ss3_m__0__HSIOM)
    #define USB_DEBUG_SS3_M_HSIOM_PTR    ( (reg32 *) USB_DEBUG_ss3_m__0__HSIOM)
    
    #define USB_DEBUG_SS3_M_HSIOM_MASK      (USB_DEBUG_ss3_m__0__HSIOM_MASK)
    #define USB_DEBUG_SS3_M_HSIOM_POS       (USB_DEBUG_ss3_m__0__HSIOM_SHIFT)
    #define USB_DEBUG_SS3_M_HSIOM_SEL_GPIO  (USB_DEBUG_ss3_m__0__HSIOM_GPIO)
    #define USB_DEBUG_SS3_M_HSIOM_SEL_SPI   (USB_DEBUG_ss3_m__0__HSIOM_SPI)
#endif /* (USB_DEBUG_SPI_MASTER_SS3_PIN) */

#if (USB_DEBUG_UART_RX_PIN)
    #define USB_DEBUG_RX_HSIOM_REG   (*(reg32 *) USB_DEBUG_rx__0__HSIOM)
    #define USB_DEBUG_RX_HSIOM_PTR   ( (reg32 *) USB_DEBUG_rx__0__HSIOM)
    
    #define USB_DEBUG_RX_HSIOM_MASK      (USB_DEBUG_rx__0__HSIOM_MASK)
    #define USB_DEBUG_RX_HSIOM_POS       (USB_DEBUG_rx__0__HSIOM_SHIFT)
    #define USB_DEBUG_RX_HSIOM_SEL_GPIO  (USB_DEBUG_rx__0__HSIOM_GPIO)
    #define USB_DEBUG_RX_HSIOM_SEL_UART  (USB_DEBUG_rx__0__HSIOM_UART)
#endif /* (USB_DEBUG_UART_RX_PIN) */

#if (USB_DEBUG_UART_RX_WAKE_PIN)
    #define USB_DEBUG_RX_WAKE_HSIOM_REG   (*(reg32 *) USB_DEBUG_rx_wake__0__HSIOM)
    #define USB_DEBUG_RX_WAKE_HSIOM_PTR   ( (reg32 *) USB_DEBUG_rx_wake__0__HSIOM)
    
    #define USB_DEBUG_RX_WAKE_HSIOM_MASK      (USB_DEBUG_rx_wake__0__HSIOM_MASK)
    #define USB_DEBUG_RX_WAKE_HSIOM_POS       (USB_DEBUG_rx_wake__0__HSIOM_SHIFT)
    #define USB_DEBUG_RX_WAKE_HSIOM_SEL_GPIO  (USB_DEBUG_rx_wake__0__HSIOM_GPIO)
    #define USB_DEBUG_RX_WAKE_HSIOM_SEL_UART  (USB_DEBUG_rx_wake__0__HSIOM_UART)
#endif /* (USB_DEBUG_UART_WAKE_RX_PIN) */

#if (USB_DEBUG_UART_CTS_PIN)
    #define USB_DEBUG_CTS_HSIOM_REG   (*(reg32 *) USB_DEBUG_cts__0__HSIOM)
    #define USB_DEBUG_CTS_HSIOM_PTR   ( (reg32 *) USB_DEBUG_cts__0__HSIOM)
    
    #define USB_DEBUG_CTS_HSIOM_MASK      (USB_DEBUG_cts__0__HSIOM_MASK)
    #define USB_DEBUG_CTS_HSIOM_POS       (USB_DEBUG_cts__0__HSIOM_SHIFT)
    #define USB_DEBUG_CTS_HSIOM_SEL_GPIO  (USB_DEBUG_cts__0__HSIOM_GPIO)
    #define USB_DEBUG_CTS_HSIOM_SEL_UART  (USB_DEBUG_cts__0__HSIOM_UART)
#endif /* (USB_DEBUG_UART_CTS_PIN) */

#if (USB_DEBUG_UART_TX_PIN)
    #define USB_DEBUG_TX_HSIOM_REG   (*(reg32 *) USB_DEBUG_tx__0__HSIOM)
    #define USB_DEBUG_TX_HSIOM_PTR   ( (reg32 *) USB_DEBUG_tx__0__HSIOM)
    
    #define USB_DEBUG_TX_HSIOM_MASK      (USB_DEBUG_tx__0__HSIOM_MASK)
    #define USB_DEBUG_TX_HSIOM_POS       (USB_DEBUG_tx__0__HSIOM_SHIFT)
    #define USB_DEBUG_TX_HSIOM_SEL_GPIO  (USB_DEBUG_tx__0__HSIOM_GPIO)
    #define USB_DEBUG_TX_HSIOM_SEL_UART  (USB_DEBUG_tx__0__HSIOM_UART)
#endif /* (USB_DEBUG_UART_TX_PIN) */

#if (USB_DEBUG_UART_RX_TX_PIN)
    #define USB_DEBUG_RX_TX_HSIOM_REG   (*(reg32 *) USB_DEBUG_rx_tx__0__HSIOM)
    #define USB_DEBUG_RX_TX_HSIOM_PTR   ( (reg32 *) USB_DEBUG_rx_tx__0__HSIOM)
    
    #define USB_DEBUG_RX_TX_HSIOM_MASK      (USB_DEBUG_rx_tx__0__HSIOM_MASK)
    #define USB_DEBUG_RX_TX_HSIOM_POS       (USB_DEBUG_rx_tx__0__HSIOM_SHIFT)
    #define USB_DEBUG_RX_TX_HSIOM_SEL_GPIO  (USB_DEBUG_rx_tx__0__HSIOM_GPIO)
    #define USB_DEBUG_RX_TX_HSIOM_SEL_UART  (USB_DEBUG_rx_tx__0__HSIOM_UART)
#endif /* (USB_DEBUG_UART_RX_TX_PIN) */

#if (USB_DEBUG_UART_RTS_PIN)
    #define USB_DEBUG_RTS_HSIOM_REG      (*(reg32 *) USB_DEBUG_rts__0__HSIOM)
    #define USB_DEBUG_RTS_HSIOM_PTR      ( (reg32 *) USB_DEBUG_rts__0__HSIOM)
    
    #define USB_DEBUG_RTS_HSIOM_MASK     (USB_DEBUG_rts__0__HSIOM_MASK)
    #define USB_DEBUG_RTS_HSIOM_POS      (USB_DEBUG_rts__0__HSIOM_SHIFT)    
    #define USB_DEBUG_RTS_HSIOM_SEL_GPIO (USB_DEBUG_rts__0__HSIOM_GPIO)
    #define USB_DEBUG_RTS_HSIOM_SEL_UART (USB_DEBUG_rts__0__HSIOM_UART)    
#endif /* (USB_DEBUG_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define USB_DEBUG_HSIOM_DEF_SEL      (0x00u)
#define USB_DEBUG_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for USB_DEBUG_CY_SCBIP_V0 
* and USB_DEBUG_CY_SCBIP_V1. It is not recommended to use them for 
* USB_DEBUG_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define USB_DEBUG_HSIOM_UART_SEL     (0x09u)
#define USB_DEBUG_HSIOM_I2C_SEL      (0x0Eu)
#define USB_DEBUG_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define USB_DEBUG_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define USB_DEBUG_RX_SCL_MOSI_PIN_INDEX       (0u)
#define USB_DEBUG_TX_SDA_MISO_PIN_INDEX       (1u)
#define USB_DEBUG_CTS_SCLK_PIN_INDEX       (2u)
#define USB_DEBUG_RTS_SS0_PIN_INDEX       (3u)
#define USB_DEBUG_SS1_PIN_INDEX                  (4u)
#define USB_DEBUG_SS2_PIN_INDEX                  (5u)
#define USB_DEBUG_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define USB_DEBUG_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << USB_DEBUG_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define USB_DEBUG_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << USB_DEBUG_RX_SCL_MOSI_PIN_INDEX)
#define USB_DEBUG_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << USB_DEBUG_TX_SDA_MISO_PIN_INDEX)
#define USB_DEBUG_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << USB_DEBUG_CTS_SCLK_PIN_INDEX)
#define USB_DEBUG_RTS_SS0_PIN_MASK     ((uint32) 0x01u << USB_DEBUG_RTS_SS0_PIN_INDEX)
#define USB_DEBUG_SS1_PIN_MASK                ((uint32) 0x01u << USB_DEBUG_SS1_PIN_INDEX)
#define USB_DEBUG_SS2_PIN_MASK                ((uint32) 0x01u << USB_DEBUG_SS2_PIN_INDEX)
#define USB_DEBUG_SS3_PIN_MASK                ((uint32) 0x01u << USB_DEBUG_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define USB_DEBUG_INTCFG_TYPE_MASK           (0x03u)
#define USB_DEBUG_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define USB_DEBUG_PIN_DM_ALG_HIZ  (0u)
#define USB_DEBUG_PIN_DM_DIG_HIZ  (1u)
#define USB_DEBUG_PIN_DM_OD_LO    (4u)
#define USB_DEBUG_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define USB_DEBUG_DM_MASK    (0x7u)
#define USB_DEBUG_DM_SIZE    (3u)
#define USB_DEBUG_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) USB_DEBUG_DM_MASK << (USB_DEBUG_DM_SIZE * (pos)))) >> \
                                                              (USB_DEBUG_DM_SIZE * (pos)) )

#if (USB_DEBUG_TX_SDA_MISO_PIN)
    #define USB_DEBUG_CHECK_TX_SDA_MISO_PIN_USED \
                (USB_DEBUG_PIN_DM_ALG_HIZ != \
                    USB_DEBUG_GET_P4_PIN_DM(USB_DEBUG_uart_tx_i2c_sda_spi_miso_PC, \
                                                   USB_DEBUG_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (USB_DEBUG_TX_SDA_MISO_PIN) */

#if (USB_DEBUG_RTS_SS0_PIN)
    #define USB_DEBUG_CHECK_RTS_SS0_PIN_USED \
                (USB_DEBUG_PIN_DM_ALG_HIZ != \
                    USB_DEBUG_GET_P4_PIN_DM(USB_DEBUG_uart_rts_spi_ss0_PC, \
                                                   USB_DEBUG_uart_rts_spi_ss0_SHIFT))
#endif /* (USB_DEBUG_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define USB_DEBUG_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define USB_DEBUG_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define USB_DEBUG_SET_HSIOM_SEL(reg, mask, pos, sel) USB_DEBUG_SET_REGISTER_BITS(reg, mask, pos, sel)
#define USB_DEBUG_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        USB_DEBUG_SET_REGISTER_BITS(reg, mask, pos, intType)
#define USB_DEBUG_SET_INP_DIS(reg, mask, val) USB_DEBUG_SET_REGISTER_BIT(reg, mask, val)

/* USB_DEBUG_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  USB_DEBUG_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (USB_DEBUG_CY_SCBIP_V0)
#if (USB_DEBUG_I2C_PINS)
    #define USB_DEBUG_SET_I2C_SCL_DR(val) USB_DEBUG_scl_Write(val)

    #define USB_DEBUG_SET_I2C_SCL_HSIOM_SEL(sel) \
                          USB_DEBUG_SET_HSIOM_SEL(USB_DEBUG_SCL_HSIOM_REG,  \
                                                         USB_DEBUG_SCL_HSIOM_MASK, \
                                                         USB_DEBUG_SCL_HSIOM_POS,  \
                                                         (sel))
    #define USB_DEBUG_WAIT_SCL_SET_HIGH  (0u == USB_DEBUG_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (USB_DEBUG_RX_WAKE_SCL_MOSI_PIN)
    #define USB_DEBUG_SET_I2C_SCL_DR(val) \
                            USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define USB_DEBUG_SET_I2C_SCL_HSIOM_SEL(sel) \
                    USB_DEBUG_SET_HSIOM_SEL(USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define USB_DEBUG_WAIT_SCL_SET_HIGH  (0u == USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (USB_DEBUG_RX_SCL_MOSI_PIN)
    #define USB_DEBUG_SET_I2C_SCL_DR(val) \
                            USB_DEBUG_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define USB_DEBUG_SET_I2C_SCL_HSIOM_SEL(sel) \
                            USB_DEBUG_SET_HSIOM_SEL(USB_DEBUG_RX_SCL_MOSI_HSIOM_REG,  \
                                                           USB_DEBUG_RX_SCL_MOSI_HSIOM_MASK, \
                                                           USB_DEBUG_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define USB_DEBUG_WAIT_SCL_SET_HIGH  (0u == USB_DEBUG_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define USB_DEBUG_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define USB_DEBUG_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define USB_DEBUG_WAIT_SCL_SET_HIGH  (0u)
#endif /* (USB_DEBUG_I2C_PINS) */

/* SCB I2C: sda signal */
#if (USB_DEBUG_I2C_PINS)
    #define USB_DEBUG_WAIT_SDA_SET_HIGH  (0u == USB_DEBUG_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (USB_DEBUG_TX_SDA_MISO_PIN)
    #define USB_DEBUG_WAIT_SDA_SET_HIGH  (0u == USB_DEBUG_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define USB_DEBUG_WAIT_SDA_SET_HIGH  (0u)
#endif /* (USB_DEBUG_MOSI_SCL_RX_PIN) */
#endif /* (USB_DEBUG_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (USB_DEBUG_RX_SCL_MOSI_PIN)
    #define USB_DEBUG_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (USB_DEBUG_RX_WAKE_SCL_MOSI_PIN)
    #define USB_DEBUG_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) USB_DEBUG_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(USB_DEBUG_UART_RX_WAKE_PIN)
    #define USB_DEBUG_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) USB_DEBUG_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (USB_DEBUG_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define USB_DEBUG_REMOVE_MOSI_SCL_RX_WAKE_PIN    USB_DEBUG_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define USB_DEBUG_REMOVE_MOSI_SCL_RX_PIN         USB_DEBUG_REMOVE_RX_SCL_MOSI_PIN
#define USB_DEBUG_REMOVE_MISO_SDA_TX_PIN         USB_DEBUG_REMOVE_TX_SDA_MISO_PIN
#ifndef USB_DEBUG_REMOVE_SCLK_PIN
#define USB_DEBUG_REMOVE_SCLK_PIN                USB_DEBUG_REMOVE_CTS_SCLK_PIN
#endif /* USB_DEBUG_REMOVE_SCLK_PIN */
#ifndef USB_DEBUG_REMOVE_SS0_PIN
#define USB_DEBUG_REMOVE_SS0_PIN                 USB_DEBUG_REMOVE_RTS_SS0_PIN
#endif /* USB_DEBUG_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define USB_DEBUG_MOSI_SCL_RX_WAKE_PIN   USB_DEBUG_RX_WAKE_SCL_MOSI_PIN
#define USB_DEBUG_MOSI_SCL_RX_PIN        USB_DEBUG_RX_SCL_MOSI_PIN
#define USB_DEBUG_MISO_SDA_TX_PIN        USB_DEBUG_TX_SDA_MISO_PIN
#ifndef USB_DEBUG_SCLK_PIN
#define USB_DEBUG_SCLK_PIN               USB_DEBUG_CTS_SCLK_PIN
#endif /* USB_DEBUG_SCLK_PIN */
#ifndef USB_DEBUG_SS0_PIN
#define USB_DEBUG_SS0_PIN                USB_DEBUG_RTS_SS0_PIN
#endif /* USB_DEBUG_SS0_PIN */

#if (USB_DEBUG_MOSI_SCL_RX_WAKE_PIN)
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_HSIOM_REG     USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_HSIOM_PTR     USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_HSIOM_MASK    USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_HSIOM_POS     USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define USB_DEBUG_MOSI_SCL_RX_WAKE_INTCFG_REG    USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_INTCFG_PTR    USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define USB_DEBUG_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  USB_DEBUG_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (USB_DEBUG_RX_WAKE_SCL_MOSI_PIN) */

#if (USB_DEBUG_MOSI_SCL_RX_PIN)
    #define USB_DEBUG_MOSI_SCL_RX_HSIOM_REG      USB_DEBUG_RX_SCL_MOSI_HSIOM_REG
    #define USB_DEBUG_MOSI_SCL_RX_HSIOM_PTR      USB_DEBUG_RX_SCL_MOSI_HSIOM_PTR
    #define USB_DEBUG_MOSI_SCL_RX_HSIOM_MASK     USB_DEBUG_RX_SCL_MOSI_HSIOM_MASK
    #define USB_DEBUG_MOSI_SCL_RX_HSIOM_POS      USB_DEBUG_RX_SCL_MOSI_HSIOM_POS
#endif /* (USB_DEBUG_MOSI_SCL_RX_PIN) */

#if (USB_DEBUG_MISO_SDA_TX_PIN)
    #define USB_DEBUG_MISO_SDA_TX_HSIOM_REG      USB_DEBUG_TX_SDA_MISO_HSIOM_REG
    #define USB_DEBUG_MISO_SDA_TX_HSIOM_PTR      USB_DEBUG_TX_SDA_MISO_HSIOM_REG
    #define USB_DEBUG_MISO_SDA_TX_HSIOM_MASK     USB_DEBUG_TX_SDA_MISO_HSIOM_REG
    #define USB_DEBUG_MISO_SDA_TX_HSIOM_POS      USB_DEBUG_TX_SDA_MISO_HSIOM_REG
#endif /* (USB_DEBUG_MISO_SDA_TX_PIN_PIN) */

#if (USB_DEBUG_SCLK_PIN)
    #ifndef USB_DEBUG_SCLK_HSIOM_REG
    #define USB_DEBUG_SCLK_HSIOM_REG     USB_DEBUG_CTS_SCLK_HSIOM_REG
    #define USB_DEBUG_SCLK_HSIOM_PTR     USB_DEBUG_CTS_SCLK_HSIOM_PTR
    #define USB_DEBUG_SCLK_HSIOM_MASK    USB_DEBUG_CTS_SCLK_HSIOM_MASK
    #define USB_DEBUG_SCLK_HSIOM_POS     USB_DEBUG_CTS_SCLK_HSIOM_POS
    #endif /* USB_DEBUG_SCLK_HSIOM_REG */
#endif /* (USB_DEBUG_SCLK_PIN) */

#if (USB_DEBUG_SS0_PIN)
    #ifndef USB_DEBUG_SS0_HSIOM_REG
    #define USB_DEBUG_SS0_HSIOM_REG      USB_DEBUG_RTS_SS0_HSIOM_REG
    #define USB_DEBUG_SS0_HSIOM_PTR      USB_DEBUG_RTS_SS0_HSIOM_PTR
    #define USB_DEBUG_SS0_HSIOM_MASK     USB_DEBUG_RTS_SS0_HSIOM_MASK
    #define USB_DEBUG_SS0_HSIOM_POS      USB_DEBUG_RTS_SS0_HSIOM_POS
    #endif /* USB_DEBUG_SS0_HSIOM_REG */
#endif /* (USB_DEBUG_SS0_PIN) */

#define USB_DEBUG_MOSI_SCL_RX_WAKE_PIN_INDEX USB_DEBUG_RX_WAKE_SCL_MOSI_PIN_INDEX
#define USB_DEBUG_MOSI_SCL_RX_PIN_INDEX      USB_DEBUG_RX_SCL_MOSI_PIN_INDEX
#define USB_DEBUG_MISO_SDA_TX_PIN_INDEX      USB_DEBUG_TX_SDA_MISO_PIN_INDEX
#ifndef USB_DEBUG_SCLK_PIN_INDEX
#define USB_DEBUG_SCLK_PIN_INDEX             USB_DEBUG_CTS_SCLK_PIN_INDEX
#endif /* USB_DEBUG_SCLK_PIN_INDEX */
#ifndef USB_DEBUG_SS0_PIN_INDEX
#define USB_DEBUG_SS0_PIN_INDEX              USB_DEBUG_RTS_SS0_PIN_INDEX
#endif /* USB_DEBUG_SS0_PIN_INDEX */

#define USB_DEBUG_MOSI_SCL_RX_WAKE_PIN_MASK USB_DEBUG_RX_WAKE_SCL_MOSI_PIN_MASK
#define USB_DEBUG_MOSI_SCL_RX_PIN_MASK      USB_DEBUG_RX_SCL_MOSI_PIN_MASK
#define USB_DEBUG_MISO_SDA_TX_PIN_MASK      USB_DEBUG_TX_SDA_MISO_PIN_MASK
#ifndef USB_DEBUG_SCLK_PIN_MASK
#define USB_DEBUG_SCLK_PIN_MASK             USB_DEBUG_CTS_SCLK_PIN_MASK
#endif /* USB_DEBUG_SCLK_PIN_MASK */
#ifndef USB_DEBUG_SS0_PIN_MASK
#define USB_DEBUG_SS0_PIN_MASK              USB_DEBUG_RTS_SS0_PIN_MASK
#endif /* USB_DEBUG_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_USB_DEBUG_H) */


/* [] END OF FILE */
