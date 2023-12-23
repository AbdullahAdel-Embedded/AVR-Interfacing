/*
 * EINT_prog.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#include "DIO_Interface.h"
//#include "Buttons_Interface.h"
#include "EINT_Interface.h"
#include "EINT_Private.h"
#include "EINT_Config.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include"TIMER_Private.h"
#include <util/delay.h>
extern u8 active_tick_counts;
extern u8 deactive_tick_counts;

static void (*EXINT_AppfuncEXTINT[3])(void);
void M_EXTINT_void_ExtintEnable(u8 EXINT_NUM, u8 EXTINT_SEN)
{



	switch(EXINT_NUM)
	{
	case 0:
		switch(EXTINT_SEN)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC00_PIN);
			CLR_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR_REG, ISC00_PIN);
			CLR_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC00_PIN);
			SET_BIT(MCUCR_REG, ISC01_PIN);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00_PIN);
			SET_BIT(MCUCR_REG, ISC01_PIN);
			break;
		}
		SET_BIT(GICR_REG, INT0_PIN);
		break;

	case 1:
		switch(EXTINT_SEN)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC10_PIN);
			CLR_BIT(MCUCR_REG, ISC11_PIN);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR_REG, ISC10_PIN);
			CLR_BIT(MCUCR_REG, ISC11_PIN);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC10_PIN);
			SET_BIT(MCUCR_REG, ISC11_PIN);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC10_PIN);
			SET_BIT(MCUCR_REG, ISC11_PIN);
			break;
		}

	SET_BIT(GICR_REG, INT1_PIN);
	break;

	case 2:

		switch(EXTINT_SEN)
		{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR_REG, ISC2_PIN);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR_REG, ISC2_PIN);
			break;
		}
		SET_BIT(GICR_REG, INT2_PIN);
		break;
	}

	SET_BIT(SREG_REG, 7);
}

void M_EXTINT_void_ExtintDisable(u8 EXINT_NUM)
{
	switch(EXINT_NUM)
	{
	case 0: CLR_BIT(GICR_REG, INT0_PIN); break;
	case 1: CLR_BIT(GICR_REG, INT1_PIN); break;
	case 2: CLR_BIT(GICR_REG, INT2_PIN); break;
	}
}

void M_EXTINT_void_ExtintSetCallBack(void (*PtrFun)(void), u8 EXTINT_INX)
{
	EXINT_AppfuncEXTINT[EXTINT_INX] = PtrFun;
}




void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	static u8 count = 0;

	switch (count)
	{
	case 0:
		//H_LCD_Void_LCDWriteNumber(0);
		 H_LCD_Void_LCDWriteNumber(count);
		TCNT2_REG  = 0;
		TCNT1_REG = 0;
		// changing the interrupt sense
	    M_EXTINT_void_ExtintEnable(0, FALLING_EDGE);
	   // H_LCD_Void_LCDWriteNumber(TCNT1_REG);
		count++;
	    break;
	case 1:

		// getting the active ticks count
		active_tick_counts = TCNT2_REG;
		//H_LCD_Void_LCDWriteNumber(count);
		//_delay_ms(1000);
		// changing the interrupt sense
	    M_EXTINT_void_ExtintEnable(0, RISING_EDGE);
	    // Increasing the Counter count
	    count ++;
	    // Starting The counter from zero
	   // H_LCD_Void_LCDWriteNumber(1);
	    TCNT2_REG  = 0;
	    TCNT1_REG = 0;
	    break;
	case 2:
		// getting the active ticks count
		deactive_tick_counts = TCNT2_REG;
		// changing the interrupt sense to rising edge
	    M_EXTINT_void_ExtintEnable(0, FALLING_EDGE);
		//H_LCD_Void_LCDWriteNumber(count);
		//_delay_ms(1000);
	    // start the Counter count from zero
	    count =0;
	    // Starting The counter from zero
	    TCNT2_REG  = 0;
	    TCNT1_REG = 0;
	   // H_LCD_Void_LCDWriteNumber(2);
	    //_delay_ms(1000);
	    break;
	}


}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	EXINT_AppfuncEXTINT[1]();
}


void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	EXINT_AppfuncEXTINT[2]();
}
