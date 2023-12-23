/*
 * Ohm_Meter.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Abdullah
 */

#ifndef OHM_METER_H_
#define OHM_METER_H_

#include "../LIB/STD.h"

#define ADC_PIN 0 // ADC input pin
#define VREF 5.0 // ADC reference voltage
#define R_REF 10000.0 // Reference resistor value

void ADC_Inint(void);
u16 ADC_Read_Value(void);
void ADC_Start_Conversion(void);
f32 calculate_resistance(u16 ADC_Result);

#endif /* OHM_METER_H_ */
