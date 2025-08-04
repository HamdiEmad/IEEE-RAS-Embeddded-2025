/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Seven_Segment_Display_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : Seven_Segments
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR;

void SSD_voidInitialDataPort(SSD_Type Copy_structConfig)
{
	DIO_enumSetPortDirection(Copy_structConfig.DataPort, 0xFF);
}

void SSD_voidSendNumber(SSD_Type Copy_structConfig, u8 Copy_u8Number)
{

	if (Copy_structConfig.Type == SSD_COMMON_CATHODE)
	{

		DIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
	}
	else if (Copy_structConfig.Type == SSD_COMMON_ANODE)
	{

		DIO_enumSetPortValue(Copy_structConfig.DataPort, ~(Local_u8SSDNumbers[Copy_u8Number]));
	}
}

void SSD_voidEnable(SSD_Type Copy_structConfig)
{

	if (Copy_structConfig.Type == SSD_COMMON_CATHODE)
	{

		DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_HIGH);
		DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_LOW);
	}
	else if (Copy_structConfig.Type == SSD_COMMON_ANODE)
	{

		DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_HIGH);
		DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_HIGH);
	}
}

void SSD_voidDisable(SSD_Type Copy_structConfig)
{
	if (Copy_structConfig.Type == SSD_COMMON_CATHODE)
	{

		DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_HIGH);
		DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_LOW);
	}
	else if (Copy_structConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, 1);
		DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, 0);
	}
}

void SSD_voidCount(SSD_Type Copy_structConfig0, SSD_Type Copy_structConfig1,
				   u8 time, u8 SSD_CountType)
{
	if (SSD_CountType == SSD_UP)
	{
		for (u8 i = 0; i <= time; i++)
		{
			u8 units = i % 10;
			u8 tens = i / 10;
			u16 cycles = 100;

			for (u16 i = 0; i < cycles; i++)
			{
				if (tens > 0)
				{
					SSD_voidEnable(Copy_structConfig1);
					SSD_voidDisable(Copy_structConfig0);
					SSD_voidSendNumber(Copy_structConfig1, tens);
					_delay_ms(1);
				}
				else
				{
					SSD_voidDisable(Copy_structConfig1);
					_delay_ms(1);
				}

				SSD_voidEnable(Copy_structConfig0);
				SSD_voidDisable(Copy_structConfig1);
				SSD_voidSendNumber(Copy_structConfig0, units);
				_delay_ms(1);
			}
		}
	}
	else if (SSD_CountType == SSD_DOWN)
	{
		for (u8 i = time; i > 0; i--)
		{
			u8 Local_u8Units = i % 10;
			u8 Local_u8Tens = i / 10;
			u16 Local_u16Cycles = 100;

			for (u16 i = 0; i < Local_u16Cycles; i++)
			{
				if (Local_u8Tens > 0)
				{
					SSD_voidEnable(Copy_structConfig1);
					SSD_voidDisable(Copy_structConfig0);
					SSD_voidSendNumber(Copy_structConfig1, Local_u8Tens);
					_delay_ms(1);
				}
				else
				{
					SSD_voidDisable(Copy_structConfig1);
					_delay_ms(1);
				}

				SSD_voidEnable(Copy_structConfig0);
				SSD_voidDisable(Copy_structConfig1);
				SSD_voidSendNumber(Copy_structConfig0, Local_u8Units);
				_delay_ms(1);
			}
		}
	}
}
