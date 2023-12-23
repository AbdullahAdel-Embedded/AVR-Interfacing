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
#include "EINT_Interface.h"
#include "EINT_Private.h"
#include "EINT_Config.h"

u8 volatile active_tick_counts = 0;
u8 volatile deactive_tick_counts = 0;
int main()
{

	//Enabling Globale Interrupt
	SET_BIT(SFIOR_REG,7);
	// SETTING THE DIRECTION OF THE OC0 PIN
	M_DIO_VOID_SetPinDirection(PB3_ID, Output);
	// SETTING THE DIRECTION OF THE INt0 PIN
	M_DIO_VOID_SetPinDirection(PD2_ID, Input);

	// Starting the pwm signal
    PWM_Inint();
    // starting the timer2
    MCAL_TIMER2_Inint();
    // LCD_Intialization
    H_LCD_Void_LCDInint();


    // enable INT0 to sense rising edge
    M_EXTINT_void_ExtintEnable(0, RISING_EDGE);
    //MCAL_TIMER_Init();
    H_LCD_Void_LCDWriteNumber(TCNT2_REG);
	while(1)
	{
		//H_LCD_Void_LCDClear();

		//u16 duty= active_tick_counts*100 / (deactive_tick_counts+active_tick_counts);
		/*H_LCD_Void_LCDWriteNumber(active_tick_counts);
		_delay_ms(1000);
		H_LCD_Void_LCDWriteNumber(deactive_tick_counts);
		_delay_ms(1000);*/

		//H_LCD_Void_LCDWriteNumber(TCNT2_REG);
		//_delay_ms(1000);

	}




	return 0;
}


