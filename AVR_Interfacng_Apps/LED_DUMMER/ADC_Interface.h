/*
 * ADC_Interface.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "../LIB/STD.h"

void ADC_Inint(void);
u16 ADC_Read_Value(void);
void ADC_Start_Conversion(void);
void ADC_Channel_Select(void);

#endif /* ADC_INTERFACE_H_ */
