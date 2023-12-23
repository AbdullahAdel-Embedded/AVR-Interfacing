/*
 * main.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */
#include"DIO_Interface.h"
#include"TIMER_Private.h"
#include <util/delay.h>
#include "PWM_Interface.h"
int main()
{


	M_DIO_VOID_SetPinDirection(PB3_ID, Output);
    PWM_Inint();
    s8 i = 1;
	while(1)
	{
		if(OCR0_REG == 255)
			i = i*-1;
		OCR0_REG =OCR0_REG  +i;
		_delay_ms(10);

	}




	return 0;
}


