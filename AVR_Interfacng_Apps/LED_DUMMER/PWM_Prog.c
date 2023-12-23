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
	OCR0_REG = 0;
	//selecting FAST PWM mode
	SET_BIT(TCCR0_REG, 6);
	SET_BIT(TCCR0_REG, 3);

	//NON inverting mode
	SET_BIT(TCCR0_REG, 5);
	CLR_BIT(TCCR0_REG, 4);

	// prescaler 8
	CLR_BIT(TCCR0_REG, CS00_BIT);
	SET_BIT(TCCR0_REG, CS01_BIT);
	CLR_BIT(TCCR0_REG, CS02_BIT);

	// ocr 127

	TCNT0_REG = 0;
}

#endif /* PWM_PROG_C_ */
