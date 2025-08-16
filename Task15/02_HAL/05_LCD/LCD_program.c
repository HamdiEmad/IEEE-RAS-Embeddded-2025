/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LCD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : LCD
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_extrachar.h"

void LCD_voidInit(void)
{

#if LCD_MODE == 8

	_delay_ms(50);

	DIO_enumSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_OUTPUT);

	LCD_voidSendCommand(lcd_Home);
	_delay_ms(1);

	LCD_voidSendCommand(EIGHT_BITS);
	_delay_ms(1);

	LCD_voidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1);

	LCD_voidClearScreen();

	LCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);

#elif LCD_MODE == 4

	_delay_ms(50);
	DIO_enumSetPinDirection(LCD_DATA_PORT, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_DATA_PORT, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_DATA_PORT, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_DATA_PORT, DIO_PIN7, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_OUTPUT);

	LCD_voidSendCommand(lcd_Home);
	_delay_ms(30);

	LCD_voidSendCommand(FOUR_BITS);
	_delay_ms(1);

	LCD_voidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1);

	LCD_voidClearScreen();

	LCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);

#endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{

#if LCD_MODE == 8

	DIO_enumSetPortValue(LCD_DATA_PORT, Copy_u8Data);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	LCD_voidSendFallingEdge();

#elif LCD_MODE == 4

	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	DIO_voidWriteHighNibbles(LCD_DATA_PORT, (Copy_u8Data >> 4));
	LCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles(LCD_DATA_PORT, Copy_u8Data);
	LCD_voidSendFallingEdge();

#endif

	_delay_ms(1);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{

#if LCD_MODE == 8

	DIO_enumSetPortValue(LCD_DATA_PORT, Copy_u8Command);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_LOW);

	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	LCD_voidSendFallingEdge();

#elif LCD_MODE == 4

	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_LOW);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	DIO_voidWriteHighNibbles(LCD_DATA_PORT, Copy_u8Command >> 4);
	LCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles(LCD_DATA_PORT, Copy_u8Command);
	LCD_voidSendFallingEdge();

#endif

	_delay_ms(1);
}

void LCD_voidSendString(const u8 *Copy_u8ptrString)
{

	u8 LOC_u8Iterator = 0;

	while (Copy_u8ptrString[LOC_u8Iterator] != '\0')
	{

		LCD_voidSendData(Copy_u8ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}

void LCD_voidSendNumber(u64 Copy_u64Number)
{

	u64 LOC_u64Reversed = 1;

	if (Copy_u64Number == 0)
	{
		LCD_voidSendData('0');
	}

	else
	{

		while (Copy_u64Number != 0)
		{

			LOC_u64Reversed = (LOC_u64Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}
		while (LOC_u64Reversed != 1)
		{

			LCD_voidSendData((LOC_u64Reversed % 10) + 48);
			LOC_u64Reversed /= 10;
		}
	}
}

void LCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{

	u8 LOC_u8data;

	if (Copy_u8Row > 2 || Copy_u8Row < 1 || Copy_u8Col > 16 || Copy_u8Col < 1)
	{
		LOC_u8data = lcd_SetCursor;
	}

	else if (Copy_u8Row == LCD_ROW_1)
	{

		LOC_u8data = ((lcd_SetCursor) + (Copy_u8Col - 1));
	}

	else if (Copy_u8Row == LCD_ROW_2)
	{

		LOC_u8data = ((lcd_SetCursor) + (64) + (Copy_u8Col - 1));
	}
	LCD_voidSendCommand(LOC_u8data);
	_delay_ms(1);
}

void LCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col)
{

	u8 LOC_u8Iterator = 0;

	LCD_voidSendCommand(lcd_CGRAM);

	for (LOC_u8Iterator = 0; LOC_u8Iterator < sizeof(LCD_u8ExtraChar) / sizeof(LCD_u8ExtraChar[0]); LOC_u8Iterator++)
	{

		LCD_voidSendData(LCD_u8ExtraChar[LOC_u8Iterator]);
	}

	LCD_voidSetPosition(Copy_u8Row, Copy_u8Col);

	for (LOC_u8Iterator = 0; LOC_u8Iterator < 8; LOC_u8Iterator++)
	{

		LCD_voidSendData(LOC_u8Iterator);
	}
}

void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(lcd_Clear);
	_delay_ms(10); // wait more than 1.53 ms
}

static void LCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);
	_delay_ms(1);
}
