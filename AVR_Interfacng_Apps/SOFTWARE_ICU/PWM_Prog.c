/*
 * PWM_Prog.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Abdullah
 */

#ifndef PWM_PROG_C_
#define PWM_PROG_C_

#include"TIMER_Private.h"
#include"../LIB/STD.h"
#include"../LIB/Bit_Math.h"
#include"DIO_Interface.h"
#include <util/delay.h>
#include"PWM_Interface.h"

void PWM_Inint(void)
{
	OCR0_REG = 64;
	//selecting FAST PWM mode
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

	//NON inverting mode
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);

	// prescaler 8
	CLR_BIT(TCCR0_REG, CS00_BIT);
	SET_BIT(TCCR0_REG, CS01_BIT);
	CLR_BIT(TCCR0_REG, CS02_BIT);

	// ocr 127
	TCNT0_REG = 0;
	//Enabling Interrupt of timer0 over flow
	//SET_BIT(TIMSK_REG, TOIE0_BIT);
}

 //Compare Match Flag
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{


}
	// timer overflow flag
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	//Reload the value of ocr
	//OCR0_REG = 64;
}





#endif /* PWM_PROG_C_ */
