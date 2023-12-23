/*
 * Ohm_Meter.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Abdullah
 */
#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include "ADC_Private.h"
//#include "ADC_Interface.h"
#include"FlexSensor.h"

#define ADC_PIN 0 // ADC input pin
#define VREF 5.0 // ADC reference voltage
#define FLEX_THRESHOLD 100 // Threshold value for flex sensor


void ADC_Inint(void) //(u8 Voltage_Ref_Select, u8 Lift_Right_Ad, )
{
	// disable ADC
	CLR_BIT(ADCSRA_REG, ADEN_BIT);

	//vcc as volatge
	CLR_BIT(ADMUX_REG, REFS1_BIT);
	SET_BIT(ADMUX_REG, REFS0_BIT);

	//right adjustment
	CLR_BIT(ADMUX_REG, ADLAR_BIT);

	//disable interrupt
	CLR_BIT(ADCSRA_REG, ADIE_BIT);

	//prescaler selection of 128
	SET_BIT(ADCSRA_REG, ADPS0_BIT);
	SET_BIT(ADCSRA_REG, ADPS1_BIT);
	SET_BIT(ADCSRA_REG, ADPS2_BIT);

	//enable ADC
	SET_BIT(ADCSRA_REG, ADEN_BIT);
}



u16 ADC_Read_Value(void)
{
	u16  readings;
	// Selecting Channel 0
	ADMUX_REG = (ADMUX_REG & 0xF0) | (0 & 0x0F);
	// calling start completion function
	ADC_Start_Conversion();
	// getting the reading
	readings = ADC;
	return readings;
}


void ADC_Start_Conversion(void)
{
	//start conversion
	SET_BIT(ADCSRA_REG, ADSC_BIT);
	// wait untill conversion complete
	while( GET_BIT(ADCSRA_REG, ADIF_BIT) == 0 );
	// clear the completion flag
	SET_BIT(ADCSRA_REG, ADIF_BIT);
}


u8 Flex_Value(u16 adc_result)
{
    // Map ADC result to flex sensor value
    if(adc_result < FLEX_THRESHOLD)
    {
        return 0; // Flex sensor not bent
    }
    else
    {
        return (adc_result - FLEX_THRESHOLD) / ((VREF * 1024.0 / 128.0) - FLEX_THRESHOLD) * 255.0; // Flex sensor bent
    }
}
