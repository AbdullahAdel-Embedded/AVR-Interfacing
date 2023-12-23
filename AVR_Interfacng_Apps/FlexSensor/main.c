/*
 * main.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Abdullah
 */


#include <util/delay.h>

#include"ADC_Private.h"
//#include"ADC_Interface.h"
#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include"DIO_Interface.h"
#include "ADC_Private.h"
#include "LCD_Interface.h"
#include"FlexSensor.h"
#include <util/delay.h>


int main(void)
{
	ADC_Inint();// Initialize ADC
    DDRB_REG |= (1 << 0); // Configure PB0 as output for controlling LED

    while(1)
    {
        u16 adc_result = ADC_Read_Value(); // Read ADC result
        u8 flex_value = Flex_Value(adc_result); // Map ADC result to flex sensor value
        if(flex_value > 0)
        {
            PORTB_REG |= (1 << 0); // Turn on LED if flex sensor is bent
        }
        else
        {
        	PORTB_REG &= ~(1 << 0); // Turn off LED if flex sensor is not bent
        }
        _delay_ms(100); // Wait for some time before taking the next reading
    }
}
