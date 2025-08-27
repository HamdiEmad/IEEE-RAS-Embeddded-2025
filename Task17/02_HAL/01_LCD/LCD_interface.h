/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LCD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : LCD
 *
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_config.h"

#if LCD_MODE == 4
#define FOUR_BITS 0x28
#elif LCD_MODE == 8
#define EIGHT_BITS 0x38
#endif

#define lcd_DisplayOn_CursorOff 0x0c
#define lcd_DisplayOn_CursorOn 0x0e
#define lcd_DisplayOff_CursorOff 0x08
#define lcd_Clear 0x01
#define lcd_EntryMode 0x06
#define lcd_Home 0x02
#define lcd_CGRAM 0x40
#define lcd_SetCursor 0x80
#define lcd_FunctionReset 0x30

#define LCD_ROW_1 1
#define LCD_ROW_2 2

#define LCD_COL_1 1
#define LCD_COL_2 2
#define LCD_COL_3 3
#define LCD_COL_4 4
#define LCD_COL_5 5
#define LCD_COL_6 6
#define LCD_COL_7 7
#define LCD_COL_8 8
#define LCD_COL_9 9
#define LCD_COL_10 10
#define LCD_COL_11 11
#define LCD_COL_12 12
#define LCD_COL_13 13
#define LCD_COL_14 14
#define LCD_COL_15 15
#define LCD_COL_16 16

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Commend);
void LCD_voidSendString(const u8 *Copy_u8ptrString);
void LCD_voidSendNumber(u64 Copy_u64Number);
void LCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_voidClearScreen(void);

#endif
