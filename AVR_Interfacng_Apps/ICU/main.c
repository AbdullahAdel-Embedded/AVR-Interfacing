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

	//Enabling Globale Interrupt
	SET_BIT(SFIOR_REG,7);
	// SETTING THE DIRECTION OF THE OC0 PIN
	M_DIO_VOID_SetPinDirection(PB3_ID, Output);
	// SETTING THE DIRECTION OF THE ICU PIN
	M_DIO_VOID_SetPinDirection(PD6_ID, Input);

	// Starting the pwm signal
    PWM_Inint();
    // LCD_Intialization
    H_LCD_Void_LCDInint();

	while(1)
	{


	}




	return 0;
}


