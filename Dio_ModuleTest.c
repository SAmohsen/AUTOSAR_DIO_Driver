 /******************************************************************************
 *
 * Module: ModuleTest
 *
 * File Name: Dio_ModuleTest.c
 *
 * Description: Source file for the Dio Test Cases.
 *
 * Author: sayed mohsen
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"

/************************************************************************************
* Test ID :TestCase1
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be turned on.
*                  2. Press the second button the two leds shall be turned off.
*************************************************************************************/

void TestCase1(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Turn on the two Leds */
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
	Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_HIGH);

	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Turn off the two Leds */
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
	Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_LOW);
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be flipped (OFF --> ON).
*                  2. Press the second button the two leds shall be flipped (ON --> OFF).
*************************************************************************************/
void TestCase2(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);

	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);
}
/************************************************************************************
* Test ID :TestCase3
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the channel group1 shall be set.
*                  2. Press the second button the second channel group shall be set.
*************************************************************************************/
void TestCase3(){
		uint8 button1 = STD_LOW;
		uint8 button2 = STD_LOW;

		/* Wait until the first button is pressed */
		while(button1 != STD_HIGH)
		{
			button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
		}

		Dio_WriteChannelGroup(&Dio_Configuration.groups[0],0x03);

		/* Wait until the second button is pressed */
		while(button2 != STD_HIGH)
		{
			button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
		}
		uint8 level = Dio_ReadChannelGroup(&Dio_Configuration.groups[0]);
		Dio_WriteChannelGroup(&Dio_Configuration.groups[1],level);
}
/************************************************************************************
* Test ID :TestCase4
* Description: Test for Write and Read ports API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the port1 shall be set.
*                  2. Press the second button the second port shall be set.
*************************************************************************************/
void TestCase4(){
		uint8 button1 = STD_LOW;
		uint8 button2 = STD_LOW;

		/* Wait until the first button is pressed */
		while(button1 != STD_HIGH)
		{
			button1 = Dio_ReadChannel(DioConf_BUTTON1_CHANNEL_ID_INDEX);
		}

		Dio_WritePort(DioConf_PORT1_PORT_ID_INDEX,0x05);

		/* Wait until the second button is pressed */
		while(button2 != STD_HIGH)
		{
			button2 = Dio_ReadChannel(DioConf_BUTTON2_CHANNEL_ID_INDEX);
		}
		uint8 level = Dio_ReadPort(DioConf_PORT1_PORT_ID_INDEX);
		Dio_WritePort(DioConf_PORT2_PORT_ID_INDEX,level);
}
int main(void)
 {
	/* Configuring the direction of the pins is the responsibility of the PORT driver */

	CLEAR_BIT(DDRA_REG, 2); /* Configure Button1 pin as i/p pin */
	CLEAR_BIT(DDRB_REG, 4); /* Configure Button2 pin as i/p pin */
	SET_BIT(DDRC_REG, 3); /* Configure Led1 pin as o/p pin */
	SET_BIT(DDRD_REG, 6); /* Configure Led2 pin as o/p pin */
	DDRC_REG = 0xFF;
	DDRD_REG = 0xFF;
	/* Initialize the Dio Driver */
	Dio_Init(&Dio_Configuration);

	/* Run the First Test Case */
	TestCase1();

	/* Run the Second Test Case */
	TestCase2();
	/* Run the third Test Case */
	TestCase3();
	/* Run the fourth Test Case */
	TestCase4();

}
