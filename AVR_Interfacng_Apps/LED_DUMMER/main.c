/*
 * main.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */
#include"DIO_Interface.h"
#include "ADC_Private.h"
#include <util/delay.h>
#include "PWM_Interface.h"
#include"ADC_Prog.c"
#include"TIMER_Private.h"
int main()
{


	ADC_Inint();
	M_DIO_VOID_SetPinDirection(PB3_ID, Output);
    PWM_Inint();
	while(1)
	{
		OCR0_REG = ADC_Read_Value() *255/1024;
	}




	return 0;
}


