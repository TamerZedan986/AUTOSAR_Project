/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Tamer_Zedan
 ******************************************************************************/
#include "port.h"
#include "Dio_Regs.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
		|| (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
		|| (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC Port_ConfigType * PORT_Pins = NULL_PTR;
STATIC uint8 PORT_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Pointer to configuration set
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Port Driver module
 ************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		uint8 i,pin_num;
		Port_PinType* DDR_ptr=NULL_PTR;
		Port_PinType* Port_ptr=NULL_PTR;
		for(i=0;i<32;i++){
			if(ConfigPtr->Port_Pins[i].mode==PORT_PIN_MODE_DIO){
				if(ConfigPtr->Port_Pins[i].pin<8){
					DDR_ptr=&DDRA_REG;
					Port_ptr=&PORTA_REG;
					pin_num=ConfigPtr->Port_Pins[i].pin;
				}else if(ConfigPtr->Port_Pins[i].pin>=8&&ConfigPtr->Port_Pins[i].pin<16){
					DDR_ptr=&DDRB_REG;
					Port_ptr=&PORTB_REG;
					pin_num=ConfigPtr->Port_Pins[i].pin-8;
				}else if(ConfigPtr->Port_Pins[i].pin>=16&&ConfigPtr->Port_Pins[i].pin<24){
					DDR_ptr=&DDRC_REG;
					Port_ptr=&PORTC_REG;
					pin_num=ConfigPtr->Port_Pins[i].pin-16;
				}else{
					DDR_ptr=&DDRD_REG;
					Port_ptr=&PORTD_REG;
					pin_num=ConfigPtr->Port_Pins[i].pin-24;
				}
			}
			if(ConfigPtr->Port_Pins[i].dir==PORT_PIN_OUT)
			{
				SET_BIT(*DDR_ptr,pin_num);
				if(ConfigPtr->Port_Pins[i].value==PORT_PIN_LEVEL_HIGH)
				{
					SET_BIT(*Port_ptr,pin_num);
				}
				else if(ConfigPtr->Port_Pins[i].value==PORT_PIN_LEVEL_LOW)
				{
					CLEAR_BIT(*Port_ptr,pin_num);
				}
			}
			else if(ConfigPtr->Port_Pins[i].dir==PORT_PIN_IN){
				CLEAR_BIT(*DDR_ptr,pin_num);
				if(ConfigPtr->Port_Pins[i].value==PORT_PIN_LEVEL_HIGH)
				{
					SET_BIT(*Port_ptr,pin_num);
				}
				else if(ConfigPtr->Port_Pins[i].value==PORT_PIN_LEVEL_LOW)
				{
					CLEAR_BIT(*Port_ptr,pin_num);
				}
			}

		}
	}
	PORT_Pins=ConfigPtr;
	PORT_Status=PORT_INITIALIZED;
}

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port Pin ID number -Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Set the port pin direction
 ************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction){
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == PORT_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* MISRA */
	}
	/* Check if the used pin is within the valid range */
	if (PORT_NUMBER_OF_PORT_PINS <= Pin)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* MISRA*/
	}
	if(FALSE==PORT_Pins->Port_Pins[Pin].PORT_PIN_DIRECTION_GHANGEABLE)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
						PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE );
				error = TRUE;

	}
	else
	{
		/*MISRA*/
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
			uint8 pin_num=0;
			Port_PinType* DDR_ptr=NULL_PTR;
			if(Pin<8){
				DDR_ptr=&DDRA_REG;
			}else if(Pin>=8&&Pin<16){
				DDR_ptr=&DDRB_REG;
				pin_num=Pin-8;
			}else if(Pin>=16&&Pin<24){
				DDR_ptr=&DDRC_REG;
				pin_num=Pin-16;
			}else{
				DDR_ptr=&DDRD_REG;
				pin_num=Pin-24;
			}
			if(PORT_PIN_OUT==Direction){
				SET_BIT(*DDR_ptr,pin_num);
			}else if(PORT_PIN_IN==Direction){
				CLEAR_BIT(*DDR_ptr,pin_num);
			}
		}
	else
	{
		/*MISRA*/
	}
}

/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Refreshe port direction
 ************************************************************************************/
void Port_RefreshPortDirection(void){
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == PORT_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* MISRA */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		uint8 i,pin_num=0;
		Port_PinType* DDR_ptr=NULL_PTR;
		for(i=0;i<32;i++){
			if(i<8){
				DDR_ptr=&DDRA_REG;
			}else if(i>=8&&i<16){
				DDR_ptr=&DDRB_REG;
				pin_num=i-8;
			}else if(i>=16&&i<24){
				DDR_ptr=&DDRC_REG;
				pin_num=i-16;
			}else{
				DDR_ptr=&DDRD_REG;
				pin_num=i-24;
			}
			if(PORT_Pins->Port_Pins[i].dir==PORT_PIN_OUT){
				SET_BIT(*DDR_ptr,pin_num);
			}else if(PORT_Pins->Port_Pins[i].dir==PORT_PIN_IN){
				CLEAR_BIT(*DDR_ptr,pin_num);
			}
		}
	}
}

/************************************************************************************
 * Service Name: PORT_SetpinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port Pin ID number -New Port Pin mode to be set on port pin.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Set the port pin mode
 ************************************************************************************/
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode){
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == PORT_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* MISRA */
	}
	/* Check if the used pin is within the valid range */
	if (PORT_NUMBER_OF_PORT_PINS <= Pin)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* MISRA*/
	}
	if(PORT_NUMBER_OF_MODES<=Mode)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID,PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	}
	else
	{
		/*MISRA*/
	}
	if(FALSE==PORT_Pins->Port_Pins[Pin].PORT_PIN_MODE_CHANGEABLE)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID,PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/*MESRA*/
	}
#endif
	/* In-case there are no errors */
	if(FALSE == error)
	{

	}
	else
	{
		/*MISRA*/
	}
}

/************************************************************************************
 * Service Name: PORT_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: NON Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 ************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void PORT_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif
