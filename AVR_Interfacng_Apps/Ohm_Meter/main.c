/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */
#include"ADC_Private.h"
//#include"ADC_Interface.h"
#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include"DIO_Interface.h"
#include "ADC_Private.h"
#include "LCD_Interface.h"
#include"Ohm_Meter.h"
#include <util/delay.h>



int main()
{
	// SETTING THE DIRECTION OF THE AC0 PIN
	M_DIO_VOID_SetPinDirection(PA0_ID, Input);
	// Initialize ADC
	ADC_Inint();
	// Initialize LCD
	H_LCD_Void_LCDInint();
	u8 string[] = "The Value is =";
	while(1)
	{
		// Read ADC result
		u16 adc_result = ADC_Read_Value();
		// Calculate resistance
		f32 resistor_value = calculate_resistance(adc_result);
		// write the resistor value on the lcd
		 H_LCD_Void_LCDClear();
		 H_LCD_Void_LCDWriteString(string);
		 H_LCD_Void_LCDWriteNumber(adc_result);
		 _delay_ms(500);
	}


	return 0;
}



