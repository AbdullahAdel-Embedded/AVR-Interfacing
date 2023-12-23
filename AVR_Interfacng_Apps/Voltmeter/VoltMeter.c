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
#include"VoltMeter.h"

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
	CLR_BIT(ADMUX_REG, MUX0_BIT);
	CLR_BIT(ADMUX_REG, MUX1_BIT);
	CLR_BIT(ADMUX_REG, MUX2_BIT);
	CLR_BIT(ADMUX_REG, MUX3_BIT);
	CLR_BIT(ADMUX_REG, MUX4_BIT);
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

f32 Calculate_Voltage(u16 ADC_Result)
{
    f32 voltage = ADC_Result * VREF / 1023.0; // Calculate voltage

    return voltage;
}


