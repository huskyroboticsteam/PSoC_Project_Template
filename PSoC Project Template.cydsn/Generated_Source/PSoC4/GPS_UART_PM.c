/***************************************************************************//**
* \file GPS_UART_PM.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
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

#include "GPS_UART.h"
#include "GPS_UART_PVT.h"

#if(GPS_UART_SCB_MODE_I2C_INC)
    #include "GPS_UART_I2C_PVT.h"
#endif /* (GPS_UART_SCB_MODE_I2C_INC) */

#if(GPS_UART_SCB_MODE_EZI2C_INC)
    #include "GPS_UART_EZI2C_PVT.h"
#endif /* (GPS_UART_SCB_MODE_EZI2C_INC) */

#if(GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC)
    #include "GPS_UART_SPI_UART_PVT.h"
#endif /* (GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
   (GPS_UART_SCB_MODE_I2C_CONST_CFG   && (!GPS_UART_I2C_WAKE_ENABLE_CONST))   || \
   (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && (!GPS_UART_EZI2C_WAKE_ENABLE_CONST)) || \
   (GPS_UART_SCB_MODE_SPI_CONST_CFG   && (!GPS_UART_SPI_WAKE_ENABLE_CONST))   || \
   (GPS_UART_SCB_MODE_UART_CONST_CFG  && (!GPS_UART_UART_WAKE_ENABLE_CONST)))

    GPS_UART_BACKUP_STRUCT GPS_UART_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: GPS_UART_Sleep
****************************************************************************//**
*
*  Prepares the GPS_UART component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the GPS_UART_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void GPS_UART_Sleep(void)
{
#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(GPS_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CSaveConfig();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CSaveConfig();
        }
    #if(!GPS_UART_CY_SCBIP_V1)
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiSaveConfig();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartSaveConfig();
        }
    #endif /* (!GPS_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        GPS_UART_backup.enableState = (uint8) GPS_UART_GET_CTRL_ENABLED;

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Stop();
        }
    }

#else

    #if (GPS_UART_SCB_MODE_I2C_CONST_CFG && GPS_UART_I2C_WAKE_ENABLE_CONST)
        GPS_UART_I2CSaveConfig();

    #elif (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && GPS_UART_EZI2C_WAKE_ENABLE_CONST)
        GPS_UART_EzI2CSaveConfig();

    #elif (GPS_UART_SCB_MODE_SPI_CONST_CFG && GPS_UART_SPI_WAKE_ENABLE_CONST)
        GPS_UART_SpiSaveConfig();

    #elif (GPS_UART_SCB_MODE_UART_CONST_CFG && GPS_UART_UART_WAKE_ENABLE_CONST)
        GPS_UART_UartSaveConfig();

    #else

        GPS_UART_backup.enableState = (uint8) GPS_UART_GET_CTRL_ENABLED;

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Stop();
        }

    #endif /* defined (GPS_UART_SCB_MODE_I2C_CONST_CFG) && (GPS_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: GPS_UART_Wakeup
****************************************************************************//**
*
*  Prepares the GPS_UART component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the GPS_UART_Wakeup() function without first calling the 
*   GPS_UART_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void GPS_UART_Wakeup(void)
{
#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(GPS_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CRestoreConfig();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CRestoreConfig();
        }
    #if(!GPS_UART_CY_SCBIP_V1)
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiRestoreConfig();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartRestoreConfig();
        }
    #endif /* (!GPS_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Enable();
        }
    }

#else

    #if (GPS_UART_SCB_MODE_I2C_CONST_CFG  && GPS_UART_I2C_WAKE_ENABLE_CONST)
        GPS_UART_I2CRestoreConfig();

    #elif (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && GPS_UART_EZI2C_WAKE_ENABLE_CONST)
        GPS_UART_EzI2CRestoreConfig();

    #elif (GPS_UART_SCB_MODE_SPI_CONST_CFG && GPS_UART_SPI_WAKE_ENABLE_CONST)
        GPS_UART_SpiRestoreConfig();

    #elif (GPS_UART_SCB_MODE_UART_CONST_CFG && GPS_UART_UART_WAKE_ENABLE_CONST)
        GPS_UART_UartRestoreConfig();

    #else

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Enable();
        }

    #endif /* (GPS_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
