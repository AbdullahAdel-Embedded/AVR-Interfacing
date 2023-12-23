/*
 * main.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Abdullah
 */


#if 0
#include       "EXT_EEPROM_int.h"
#include       "EXT_EEPROM_private.h"
#include       "LCD_Interface.h"
#include       "LCD_Private.h"



int main(void)
{
	H_EXT_EEPROM_void_Init();
	H_EXT_EEPROM_void_Write(250, 'M');
	//H_Lcd_Void_LCDInit();
	//H_Lcd_Void_LCDWriteCharacter(H_EXT_EEPROM_void_Read(250));

	while(1)
	{

	}

	return 0;
}
#endif
