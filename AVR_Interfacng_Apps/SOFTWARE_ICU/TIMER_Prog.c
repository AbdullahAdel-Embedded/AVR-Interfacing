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

#define CLR_BIT(REG,BIT)        REG &= ~(1 << BIT)
#define SET_BIT(REG,BIT)        REG |=  (1 << BIT)
/*
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
}*/

void MCAL_TIMER2_Inint(void)
{
	// normal mode of timer2
	CLR_BIT(TCCR2_REG, WGM20);
	CLR_BIT(TCCR2_REG, WGM21);

	// prescaler 8
	CLR_BIT(TCCR0_REG, CS00_BIT);
	SET_BIT(TCCR0_REG, CS01_BIT);
	CLR_BIT(TCCR0_REG, CS02_BIT);

	SET_BIT(TCCR2, 7);

	//Enabling Interrupt
	//SET_BIT(TIMSK_REG, TOIE2_BIT);

	// start from zero
	//TCNT2_REG  = 0;
}

void MCAL_TIMER_Init(void)
{
	SET_BIT(TCCR1A_REG, 2);
	SET_BIT(TCCR1A_REG, 3);
	SET_BIT(TCCR1B_REG, 1);
}





