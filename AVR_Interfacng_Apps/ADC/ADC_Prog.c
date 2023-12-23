/*
 * ADC_Prog.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */

#include"../LIB/Bit_Math.h"
#include"../LIB/STD.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"


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
	//prescaler selection
	SET_BIT(ADCSRA_REG, ADPS0_BIT);
	SET_BIT(ADCSRA_REG, ADPS1_BIT);
	SET_BIT(ADCSRA_REG, ADPS2_BIT);
	//enable ADC
	SET_BIT(ADCSRA_REG, ADEN_BIT);
}

u16 ADC_Read_Value(void)
{
	u16  readings;
	ADC_Start_Conversion();
	while( GET_BIT(ADCSRA_REG, ADIF_BIT) == 0 );
	//SET_BIT(ADCSRA_REG, ADIF_BIT);
	readings = ADC;
	return readings;
}

void ADC_Channel_Select(void)
{

	//CLR_BIT(ADMUX_REG, MUX0_BIT);
	//CLR_BIT(ADMUX_REG, MUX1_BIT);
	//CLR_BIT(ADMUX_REG, MUX2_BIT);
	//CLR_BIT(ADMUX_REG, MUX3_BIT);
	//CLR_BIT(ADMUX_REG, MUX4_BIT);


	SET_BIT(ADMUX_REG, MUX0_BIT);
	CLR_BIT(ADMUX_REG, MUX1_BIT);
	CLR_BIT(ADMUX_REG, MUX2_BIT);
	CLR_BIT(ADMUX_REG, MUX3_BIT);
	CLR_BIT(ADMUX_REG, MUX4_BIT);

}


void ADC_Start_Conversion(void)
{

	SET_BIT(ADCSRA_REG, ADSC_BIT);
	while(! GET_BIT(ADCSRA_REG, ADIF_BIT));
	SET_BIT(ADCSRA_REG, ADIF_BIT);
}

void ADC_AutoTrigger_Enable_Select()
{
	SET_BIT(ADCSRA_REG, ADATE_BIT);
	//010 interrupt 0 selection
	CLR_BIT(SFIOR_REG, ADTS0_BIT);
	SET_BIT(SFIOR_REG, ADTS1_BIT);
	CLR_BIT(SFIOR_REG, ADTS0_BIT);
}

