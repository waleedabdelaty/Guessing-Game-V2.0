/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: TOSHIBA PC
 */

#include "lcd.h"
#include "keypad.h"
#include <stdlib.h>

uint32_t arraytoint(const uint8_t* S)
{
	uint32_t num = 0;

	uint32_t i = 0;

	// run till the end of the string is reached, or the
	// current character is non-numeric
	 while (S[i] && (S[i] >= 0 && S[i] <= 9))
	{
		num = num * 10 + S[i];
		i++;
	}
	return num;

}

int main(void)
{
	/* LCD Initialization */
	LCD_init();

	uint8_t number,counter,input;
	uint8_t array[10];
	uint32_t input_int;
	while(1)
	{
		counter=0;
		number = ( rand() % 14 ) + 1;
		LCD_clearScreen();
		LCD_displayString("Guess: ");
		do
		{
			input = KeyPad_getPressedKey();
			_delay_ms(250);
			if (input != '=')
			{
				array[counter] = input;
				counter++;
			}
			if(input >=0 && input <=9)
			{
				LCD_integerToString(input);
			}

		}while(input != '=' );

		array[counter] = '\0';

		input_int=arraytoint(array);

		while(1)
		{
			_delay_ms(1000);
			LCD_clearScreen();
			if(input_int==number)
			{
				LCD_displayString("Right Guess!!");

			}
			else if(input_int <0 || input_int >15)
			{
				LCD_displayString("Invalid Range!");
			}
			else
			{
				LCD_clearScreen();
				LCD_displayString("Wrong Guess!!");
				LCD_goToRowColumn(1,0);
				LCD_displayString("Right Guess: ");
				LCD_integerToString(number);
			}
			_delay_ms(1000);
			break;

		}

	}
}
