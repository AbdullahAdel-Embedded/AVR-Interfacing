/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */
//#include"ADC_Private.h"
//#include"ADC_Interface.h"
#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include"DIO_Interface.h"
#include "ADC_Private.h"
#include "LCD_Interface.h"
#include"VoltMeter.h"
#include <util/delay.h>

int main()
{
	// Initialize ADC
	ADC_Inint();
	// SETTING THE DIRECTION OF THE AC0 PIN
	M_DIO_VOID_SetPinDirection(PA0_ID, Input);
	H_LCD_Void_LCDInint();
	H_LCD_Void_LCDClear();
	 u8 string[] ="the voltage is" ;
	H_LCD_Void_LCDWriteString(string);
	while(1)
	{
		// Read ADC result
		u16 adc_result = ADC_Read_Value();
		// Calculate Voltage
		f32 Voltage_Value = Calculate_Voltage(adc_result);
		// write the Voltage value on the lcd
		H_LCD_Void_LCDClear();
		 H_LCD_Void_LCDWriteString(string);
		 H_LCD_Void_LCDWriteNumber(Voltage_Value);
		 _delay_ms(10000);
	}


	return 0;
}


