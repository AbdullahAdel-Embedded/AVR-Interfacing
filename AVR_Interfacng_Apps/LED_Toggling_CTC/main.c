/*
 * main.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */
#include"DIO_Interface.h"
#include"TIMER_Private.h"
#include <util/delay.h>
#include"../LIB/STD.h"
int main()
{


	M_DIO_VOID_SetPinDirection(PA6_ID, Output);
	SET_BIT(SREG_REG, 7);
	MCAL_TIMER_Inint();
	MCAL_TIMER_Delay(1);

	while(1)
	{
		/*TOG_BIT(PORTA_REG, 6);
		_delay_ms(500);*/
	}




	return 0;
}


