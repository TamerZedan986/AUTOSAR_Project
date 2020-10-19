/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Tamer_Zedan
 ******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/* Id for the company in the AUTOSAR
 * for example Tamer Zedan's ID = 1998 :) */
#define PORT_VENDOR_ID    (1998U)

/* PORT Module Id */
#define PORT_MODULE_ID    (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"


/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for PORT Init */
#define PORT_INIT_SID                   (uint8)0x00

/*Service ID for Set pin direction*/
#define PORT_SET_PIN_DIRECTION_SID      (uint8)0x01

/*Service ID for Refresh port direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID (uint8)0x02

/*Service ID for Get version info*/
#define PORT_GET_VERSION_INFO_SID       (uint8)0x03

/*Service ID for Set pin mode*/
#define PORT_SET_PIN_MODE_SID           (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report Incorrect Port Pin ID passed*/
#define PORT_E_PARAM_PIN                (uint8)0x0A
/* DET code to report Port Pin not configured as changeable*/

#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
/* DET code to report Port_Init service called with wrong parameter*/

#define PORT_E_PARAM_CONFIG             (uint8)0x0C
/* DET code to report Incorrect Port Pin ID passed */

#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
/* DET code to report Port_SetPinMode service called when the mode is unchangeable*/

#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
/* DET code to report API service called prior to module initialization*/

#define PORT_E_UNINIT                   (uint8)0x0F
/* DET code to report Api called with a NULL Pointer Parameter */

#define PORT_E_PARAM_POINTER            (uint8)0x010
/* DET code to report Port Pin Mode passed not valid */

#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Data type for the symbolic name of a port pin*/
typedef uint8 Port_PinType;

/*Different port pin modes*/
typedef uint8 Port_PinModeType;

/* type for defining the direction of a Port Pin*/
typedef enum
{
	PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* type for defining the Mode of a Port Pin*/
typedef enum
{
	PORT_PIN_MODE_ADC,PORT_PIN_MODE_CAN,PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,PORT_PIN_MODE_DIO_WDG,PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,PORT_PIN_MODE_LIN,PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,PORT_PIN_MODE_SPI
}PORT_PIN_INITIAL_MODE;

/* type for defining the Level of a Port Pin*/
typedef enum
{
	PORT_PIN_LEVEL_HIGH,PORT_PIN_LEVEL_LOW
}PORT_PIN_LEVEL_VALUE;

/* data structure containing the initialization data for the PORT Driver*/
typedef struct
{
	Port_PinType pin;
	Port_PinDirectionType dir;
	PORT_PIN_INITIAL_MODE mode;
	PORT_PIN_LEVEL_VALUE value;
	boolean PORT_PIN_DIRECTION_GHANGEABLE;
	boolean PORT_PIN_MODE_CHANGEABLE;
}Port_Configpin;

/* Data Structure required for initializing the PORT Driver */
typedef struct{
	Port_Configpin Port_Pins[PORT_NUMBER_OF_PORT_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*Function for Initializing the Port Driver module*/
void Port_Init(const Port_ConfigType* ConfigPtr );

/*Function for Setting the port pin direction*/
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);

/*Function for Refreshing port direction*/
void Port_RefreshPortDirection(void);

/*Function for Setting the port pin mode*/
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);

#if (PORT_VERSION_INFO_API == STD_ON)
/*Returns the version information of this module*/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo );
#endif
/* Extern PB structures to be used by PORT and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H_ */
