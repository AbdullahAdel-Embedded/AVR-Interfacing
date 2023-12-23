/*
 * LCD.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include <util/delay.h>
/*
int main()
{
	H_LCD_Void_LCDInint();
	u8 name[12] = "Abdullah";
	H_LCD_Void_LCDWriteString(name);
}
*/



void H_LCD_Void_LCDInint(void)
{
	M_DIO_VOID_SetPinDirection(RS_PIN, Output);
	M_DIO_VOID_SetPinDirection(EN_PIN, Output);
	M_DIO_VOID_SetPinDirection(D4_PIN, Output);
	M_DIO_VOID_SetPinDirection(D5_PIN, Output);
	M_DIO_VOID_SetPinDirection(D6_PIN, Output);
	M_DIO_VOID_SetPinDirection(D7_PIN, Output);


	H_LCD_Void_LCDWriteCommand(ININT_COMMAND_1);
	H_LCD_Void_LCDWriteCommand(ININT_COMMAND_2);
	H_LCD_Void_LCDWriteCommand(ININT_COMMAND_3);
	H_LCD_Void_LCDWriteCommand(DISPLAY_ON_COMMAND);
	H_LCD_Void_LCDWriteCommand(CLEAR_COMMMAND);
	H_LCD_Void_LCDWriteCommand(RETURN_HOME_COMMAND);
}


void H_LCD_Void_LCDWriteCommand(u8 command)
{
	M_DIO_Void_SetPinValue(RS_PIN, COMMAND);

	M_DIO_Void_SetPinValue(D4_PIN, GET_BIT(command, 4) );
	M_DIO_Void_SetPinValue(D5_PIN, GET_BIT(command, 5) );
	M_DIO_Void_SetPinValue(D6_PIN, GET_BIT(command, 6) );
	M_DIO_Void_SetPinValue(D7_PIN, GET_BIT(command, 7) );

	M_DIO_Void_SetPinValue(EN_PIN, High);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(EN_PIN, Low);
	_delay_ms(1);

	M_DIO_Void_SetPinValue(D4_PIN, GET_BIT(command, 0) );
	M_DIO_Void_SetPinValue(D5_PIN, GET_BIT(command, 1) );
	M_DIO_Void_SetPinValue(D6_PIN, GET_BIT(command, 2) );
	M_DIO_Void_SetPinValue(D7_PIN, GET_BIT(command, 3) );

	M_DIO_Void_SetPinValue(EN_PIN, High);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(EN_PIN, Low);
	_delay_ms(5);
}

void H_LCD_Void_LCDWriteCharacter(u8 chararcter)
{
	M_DIO_Void_SetPinValue(RS_PIN, DATA);
	//chararcter = 'c';
	M_DIO_Void_SetPinValue(D4_PIN, GET_BIT(chararcter, 4) );
	M_DIO_Void_SetPinValue(D5_PIN, GET_BIT(chararcter, 5) );
	M_DIO_Void_SetPinValue(D6_PIN, GET_BIT(chararcter, 6) );
	M_DIO_Void_SetPinValue(D7_PIN, GET_BIT(chararcter, 7) );

	M_DIO_Void_SetPinValue(EN_PIN, High);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(EN_PIN, Low);
	_delay_ms(1);

	M_DIO_Void_SetPinValue(D4_PIN, GET_BIT(chararcter, 0) );
	M_DIO_Void_SetPinValue(D5_PIN, GET_BIT(chararcter, 1) );
	M_DIO_Void_SetPinValue(D6_PIN, GET_BIT(chararcter, 2) );
	M_DIO_Void_SetPinValue(D7_PIN, GET_BIT(chararcter, 3) );

	M_DIO_Void_SetPinValue(EN_PIN, High);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(EN_PIN, Low);
	_delay_ms(5);

}

void H_LCD_Void_LCDWriteString(u8 *string)
{
	for(int i=0; string[i]!=NULL; i++)
	{
		H_LCD_Void_LCDWriteCharacter(string[i]);
	}
}

void H_LCD_Void_LCDWriteNumber(s32 number)
{
	u8 Local_U8_Counter = 0;
	u8 Local_U8_Arr[10] = {0};

	if(number < 0)
	{
		number *= -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}

	do
	{
		Local_U8_Arr[Local_U8_Counter++] = number%10;
		number /= 10;
	}while(number >0 );

	while(Local_U8_Counter > 0)
	{
		H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[--Local_U8_Counter] +48);
	}
}

void H_LCD_Void_LCDClear()
{
	H_LCD_Void_LCDWriteCommand(CLEAR_COMMMAND);
}

void H_LCD_Void_LCDGoTo()
{
	H_LCD_Void_LCDWriteCommand(RETURN_HOME_COMMAND);
}
