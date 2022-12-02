/*******************************************************************************
* File Name: SWDIO.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SWDIO_H) /* Pins SWDIO_H */
#define CY_PINS_SWDIO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SWDIO_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} SWDIO_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SWDIO_Read(void);
void    SWDIO_Write(uint8 value);
uint8   SWDIO_ReadDataReg(void);
#if defined(SWDIO__PC) || (CY_PSOC4_4200L) 
    void    SWDIO_SetDriveMode(uint8 mode);
#endif
void    SWDIO_SetInterruptMode(uint16 position, uint16 mode);
uint8   SWDIO_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SWDIO_Sleep(void); 
void SWDIO_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SWDIO__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SWDIO_DRIVE_MODE_BITS        (3)
    #define SWDIO_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SWDIO_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SWDIO_SetDriveMode() function.
         *  @{
         */
        #define SWDIO_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SWDIO_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SWDIO_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SWDIO_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SWDIO_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SWDIO_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SWDIO_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SWDIO_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SWDIO_MASK               SWDIO__MASK
#define SWDIO_SHIFT              SWDIO__SHIFT
#define SWDIO_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SWDIO_SetInterruptMode() function.
     *  @{
     */
        #define SWDIO_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SWDIO_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SWDIO_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SWDIO_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SWDIO__SIO)
    #define SWDIO_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SWDIO__PC) && (CY_PSOC4_4200L)
    #define SWDIO_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SWDIO_USBIO_DISABLE              ((uint32)(~SWDIO_USBIO_ENABLE))
    #define SWDIO_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SWDIO_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SWDIO_USBIO_ENTER_SLEEP          ((uint32)((1u << SWDIO_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SWDIO_USBIO_SUSPEND_DEL_SHIFT)))
    #define SWDIO_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SWDIO_USBIO_SUSPEND_SHIFT)))
    #define SWDIO_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SWDIO_USBIO_SUSPEND_DEL_SHIFT)))
    #define SWDIO_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SWDIO__PC)
    /* Port Configuration */
    #define SWDIO_PC                 (* (reg32 *) SWDIO__PC)
#endif
/* Pin State */
#define SWDIO_PS                     (* (reg32 *) SWDIO__PS)
/* Data Register */
#define SWDIO_DR                     (* (reg32 *) SWDIO__DR)
/* Input Buffer Disable Override */
#define SWDIO_INP_DIS                (* (reg32 *) SWDIO__PC2)

/* Interrupt configuration Registers */
#define SWDIO_INTCFG                 (* (reg32 *) SWDIO__INTCFG)
#define SWDIO_INTSTAT                (* (reg32 *) SWDIO__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SWDIO_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SWDIO__SIO)
    #define SWDIO_SIO_REG            (* (reg32 *) SWDIO__SIO)
#endif /* (SWDIO__SIO_CFG) */

/* USBIO registers */
#if !defined(SWDIO__PC) && (CY_PSOC4_4200L)
    #define SWDIO_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SWDIO_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SWDIO_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SWDIO_DRIVE_MODE_SHIFT       (0x00u)
#define SWDIO_DRIVE_MODE_MASK        (0x07u << SWDIO_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SWDIO_H */


/* [] END OF FILE */
