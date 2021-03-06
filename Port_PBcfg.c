 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Port Module.
 *
 * Author: Tamer_Zedan
 ******************************************************************************/

#include "port.h"


/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
		||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
		||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
		||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
		||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

const Port_ConfigType Port_Configuration =
{
		0,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		PORT_PIN_LEVEL_LOW,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		1,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		2,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		3,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		4,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		5,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
		6,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
		DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
		DEFAULT_MODE_CHANGEABLE,
        7,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        8,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        9,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        10,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        11,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        12,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        13,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        14,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        15,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE
        ,DEFAULT_MODE_CHANGEABLE,
        16,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        17,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        18,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        19,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        20,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        PORTConf_LED_PIN_ID_INDEX,PORTConf_LED_PORT_PIN_DIRECTION,
        PORT_PIN_MODE_DIO,PORTConf_LED_PORT_PIN_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        PORTConf_BUTTON_PORT_PIN_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        22,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        23,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        24,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        25,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        PORTConf_BUTTON_PIN_ID_INDEX,PORTConf_BUTTON_PORT_PIN_DIRECTION,
        PORT_PIN_MODE_DIO,PORTConf_BUTTON_PORT_PIN_LEVEL_VALUE,
        PORTConf_LED_PORT_PIN_LEVEL_VALUE,
        DEFAULT_DIRECTION_CHANGABLE,DEFAULT_MODE_CHANGEABLE,
        27,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        28,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        29,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        30,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE,
        31,DEFAULT_DIRECTION,PORT_PIN_MODE_DIO,
        DEFAULT_LEVEL_VALUE,DEFAULT_DIRECTION_CHANGABLE,
        DEFAULT_MODE_CHANGEABLE
};
