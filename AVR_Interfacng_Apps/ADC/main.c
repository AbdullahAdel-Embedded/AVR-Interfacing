/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */
#include"ADC_Private.h"
#include"ADC_Interface.h"
#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include"DIO_Interface.h"
#include "ADC_Private.h"
#include "LCD_Interface.h"
#include <util/delay.h>


int main()
{
	//M_DIO_VOID_SetPinDirection( PA4_ID, Input );
	 ADC_Inint();
	 ADC_Channel_Select();
	 H_LCD_Void_LCDInint();

	 H_LCD_Void_LCDWriteString("The Value is =");
	 while(1)
	 {

		 H_LCD_Void_LCDClear();
		 H_LCD_Void_LCDWriteString("The Value is =");

		 ADC_Start_Conversion();
		 u16 reading = ADC_Read_Value();

		 reading=reading*500/1024;
		 H_LCD_Void_LCDWriteNumber(reading);
		 _delay_ms(1000);


	 }


	return 0;
}
