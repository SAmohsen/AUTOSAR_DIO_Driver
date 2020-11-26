 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Dio Module.
 *
 * Author: sayed mohsen
 ******************************************************************************/

#include "Dio.h"

/*
 * Module Version 1.0.0
 */
#define DIO_PBCFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
const Dio_ConfigType Dio_Configuration = {
		.Channels[DioConf_LED1_CHANNEL_ID_INDEX ].Ch_Num =DioConf_LED1_CHANNEL_NUM,
		.Channels[DioConf_LED1_CHANNEL_ID_INDEX ].Port_Num =DioConf_LED1_PORT_NUM,
		.Channels[DioConf_LED2_CHANNEL_ID_INDEX ].Ch_Num =DioConf_LED2_CHANNEL_NUM,
		.Channels[DioConf_LED2_CHANNEL_ID_INDEX ].Port_Num =DioConf_LED2_PORT_NUM,
		.Channels[DioConf_BUTTON1_CHANNEL_ID_INDEX ].Ch_Num =DioConf_BUTTON1_CHANNEL_NUM,
		.Channels[DioConf_BUTTON1_CHANNEL_ID_INDEX ].Port_Num =DioConf_BUTTON1_PORT_NUM,
		.Channels[DioConf_BUTTON2_CHANNEL_ID_INDEX ].Ch_Num =DioConf_BUTTON2_CHANNEL_NUM,
		.Channels[DioConf_BUTTON2_CHANNEL_ID_INDEX ].Port_Num =DioConf_BUTTON2_PORT_NUM,
		.ports[DioConf_PORT2_PORT_ID_INDEX]=DioConf_PORT2_PORT_NUM ,
		.ports[DioConf_PORT1_PORT_ID_INDEX]=DioConf_PORT1_PORT_NUM ,

		.groups[DioConf_RGP_CHANNEL_GROUP_INDEX ].PortIndex =DioConf_RGB_PORT_NUM,
		.groups[DioConf_RGP_CHANNEL_GROUP_INDEX ].offset =DioConf_RGB_CHANNEL_GROUP_OFFSET,
		.groups[DioConf_RGP_CHANNEL_GROUP_INDEX ].mask =DioConf_RGB_CHANNEL_GROUP_MASK,

		.groups[DioConf_RGP1_CHANNEL_GROUP_INDEX ].PortIndex =DioConf_RGB1_PORT_NUM,
				.groups[DioConf_RGP1_CHANNEL_GROUP_INDEX ].offset =DioConf_RGB1_CHANNEL_GROUP_OFFSET,
				.groups[DioConf_RGP1_CHANNEL_GROUP_INDEX ].mask =DioConf_RGB1_CHANNEL_GROUP_MASK
};
