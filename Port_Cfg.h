/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Configuration Header file for Port Module.
 *
 * Author: Tamer_Zedan
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                 (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_SET_PIN_DIRECTION_API            (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_SET_PIN_MODE_API                 (STD_OFF)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                 (STD_OFF)

/* Pre-compile option for DIRECTION CHANGEABLE  API */
#define PORT_PIN_DIRECTION                    (STD_ON)

/* Pre-compile option for PIN_DIRECTION_CHANGEABLE Config*/
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_ON)

#define PORT_NUMBER_OF_PORT_PINS              (uint8)0x20

#define PORT_NUMBER_OF_MODES                  (uint8)0xB

/* PORT Pins Index in the array of structures in Dio_PBcfg.c */
#define PORTConf_LED_PIN_ID_INDEX             (uint8)0x15

#define PORTConf_BUTTON_PIN_ID_INDEX          (uint8)0x1A

#define PORTConf_BUTTON_PORT_PIN_DIRECTION     PORT_PIN_IN

#define PORTConf_LED_PORT_PIN_DIRECTION        PORT_PIN_OUT

#define DEFAULT_DIRECTION                      PORT_PIN_IN

#define DEFAULT_LEVEL_VALUE                    PORT_PIN_LEVEL_LOW

#define DEFAULT_DIRECTION_CHANGABLE            TRUE

#define DEFAULT_MODE_CHANGEABLE                TRUE

#define PORTConf_BUTTON_PORT_PIN_LEVEL_VALUE   PORT_PIN_LEVEL_LOW

#define PORTConf_LED_PORT_PIN_LEVEL_VALUE      PORT_PIN_LEVEL_LOW

#endif /* PORT_CFG_H_ */
