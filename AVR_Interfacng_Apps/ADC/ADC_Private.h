/*
 * ADC_Private.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Abdullah
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADEN_BIT                      7

//#define ADCSRG_REG


#define ADCH_REG              *((volatile u8*) 0x25)
#define ADCL_REG              *((volatile u8*) 0x24)
#define ADC                   *((volatile u16*) 0x24)



#define SFIOR_REG             *((volatile u8*) 0x50)


#define ADTS0_BIT                     5
#define ADTS1_BIT                     6
#define ADTS2_BIT                     7

#define ADMUX_REG            *( (volatile u8*) 0x27)
#define MUX0_BIT               0
#define MUX1_BIT               1
#define MUX2_BIT               2
#define MUX3_BIT               3
#define MUX4_BIT               4
#define REFS1_BIT              7
#define REFS0_BIT              6
#define ADLAR_BIT              5

#define ADCSRA_REG          *((volatile u8*) 0x26)
#define ADATE_BIT          5
#define ADIF_BIT           4
#define ADIE_BIT           3
#define ADEN_BIT           7
#define ADSC_BIT           6
#define ADPS2_BIT          2
#define ADPS1_BIT          1
#define ADPS0_BIT          0

#define Start_Coversion   1




#endif /* ADC_PRIVATE_H_ */
