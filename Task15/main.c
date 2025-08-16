/*
 * main.c
 *
 *  Created on: Aug 16, 2025
 *      Author: Hamdy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

#include "util/delay.h"
#include <string.h>
#include <stdlib.h>

u8 num1[10] = "";
u8 num2[10] = "";

int n1 = 0, n2 = 0, res = 0;

u8 op = 0;

int main() {

	KEYPAD_Init();
	LCD_voidInit();
	LCD_voidSendString("   HAMDI EMAD");
	_delay_ms(1000);
	LCD_voidClearScreen();

	while (1) {
		display();
	}
}

void display() {
	switch (KEYPAD_u8GetPressed()) {
		case '0' :
			LCD_voidSendNumber(0);
			if (op == 0)
				strcat(num1, "0");
			else
				strcat(num2, "0");
			break;

		case '1' :
			LCD_voidSendNumber(1);
			if (op == 0)
				strcat(num1, "1");
			else
				strcat(num2, "1");
			break;

		case '2' :
			LCD_voidSendNumber(2);
			if (op == 0)
				strcat(num1, "2");
			else
				strcat(num2, "2");
			break;

		case '3' :
			LCD_voidSendNumber(3);
			if (op == 0)
				strcat(num1, "3");
			else
				strcat(num2, "3");
			break;

		case '4' :
			LCD_voidSendNumber(4);
			if (op == 0)
				strcat(num1, "4");
			else
				strcat(num2, "4");
			break;

		case '5':
			LCD_voidSendNumber(5);
			if (op == 0)
				strcat(num1, "5");
			else
				strcat(num2, "5");
			break;

		case '6' :
			LCD_voidSendNumber(6);
			if (op == 0)
				strcat(num1, "6");
			else
				strcat(num2, "6");
			break;

		case '7' :
			LCD_voidSendNumber(7);
			if (op == 0)
				strcat(num1, "7");
			else
				strcat(num2, "7");
			break;

		case '8' :
			LCD_voidSendNumber(8);
			if (op == 0)
				strcat(num1, "8");
			else
				strcat(num2, "8");
			break;

		case '9' :
			LCD_voidSendNumber(9);
			if (op == 0)
				strcat(num1, "9");
			else
				strcat(num2, "9");
			break;

		case '?' :
			LCD_voidClearScreen();
			strcpy(num1, "");
			strcpy(num2, "");
			op = 0;
			break;
		case '+' :
			LCD_voidSendString("+");
			n1 = atoi(num1);
			op = 1;
			break;
		case '-' :
			LCD_voidSendString("-");
			n1 = atoi(num1);
			op = 2;
			break;
		case '/' :
			LCD_voidSendString("/");
			n1 = atoi(num1);
			op = 3;
			break;
		case '*' :
			LCD_voidSendString("*");
			n1 = atoi(num1);
			op = 4;
			break;
		case '=' :
			LCD_voidSendString("=");
			n2 = atoi(num2);
			switch(op) {
			case 1:
				res = n1 + n2;
				break;
			case 2:
				res = n1 - n2;
				break;
			case 3:
				if (n2 == 0) {
					LCD_voidClearScreen();
					LCD_voidSendString("Division by zero");
					res = 0;
				}
				else
					res = n1 / n2;
				break;
			case 4:
				res = n1 * n2;
				break;
			}

			LCD_voidSendNumber(res);
			strcpy(num1, "");
			strcpy(num2, "");
			op = 0;
			res = 0;
			break;
		default :
			break;
	}
}
