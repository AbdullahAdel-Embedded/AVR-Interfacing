/*
 * TIMER_Prog.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */

#include"TIMER_Private.h"
#include"../LIB/STD.h"
#include"../LIB/Bit_Math.h"
#include"DIO_Interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>
volatile u32 count =0;
volatile u32 delay =0;

void MCAL_TIMER_Delay(u8 n_sec)
{
	delay = 1000*n_sec;
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{


	//TOG_BIT(PORTA_REG, 6);
	//_delay_ms(500);
	//M_DIO_Void_SetPinValue(PA6_ID, 1);
	//_delay_ms(500);
	count++;
	if(delay == count)
	{
		TOG_BIT(PORTA_REG, 6);
		count =0;
	}

	/*
	switch(count)
	{
	case 0: M_DIO_Void_SetPinValue(PA4_ID, High); break;
	case 1: M_DIO_Void_SetPinValue(PA5_ID, High); break;
	case 2: M_DIO_Void_SetPinValue(PA6_ID, High); break;
	default: count =0;
	}*/
	//SET_BIT(PORTA_REG, 6);

	TCNT0_REG= 6;
}

void MCAL_TIMER_Inint(void)
{

	//preloaded value
	TCNT0_REG= 6;
	//
	SET_BIT(TCCR0_REG, 7);
	//
	CLR_BIT(TCCR0_REG, 3);
	CLR_BIT(TCCR0_REG, 6);
	// prescaler 64
	SET_BIT(TCCR0_REG, CS00_BIT);
	SET_BIT(TCCR0_REG, CS01_BIT);
	CLR_BIT(TCCR0_REG, CS02_BIT);
   //Enabling Interrupt
	SET_BIT(TIMSK_REG, TOIE0_BIT);
}



