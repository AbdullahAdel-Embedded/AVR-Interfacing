/*
 * TIMER_Private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define TIFR_REG           *((volatile u8*) 0X58)
#define TOV0_BIT            0
#define TIMSK_REG          *((volatile u8*) 0X59)
#define TOIE0_BIT           0
#define SREG_REG           *((volatile u8*) 0x5F)

#define OCR0_REG           *((volatile u8*) 0X5C)
#define TCNT0_REG		   *((volatile u8*) 0X52)
#define TCCR0_REG          *((volatile u8*) 0X53)
#define COM01_BIT           5


#define TCCR2_REG          *((volatile u8*) 0X45)
#define TCNT2_REG          *((volatile u8*) 0X44)

#define TCCR1A_REG          *((volatile u8*) 0X4F)
#define TCCR1B_REG          *((volatile u8*) 0X4E)
#define TCNT1_REG          *((volatile u16*) 0XFC)


#define TOIE2_BIT            6



#define COM00_BIT           4




#define CS00_BIT            0
#define CS01_BIT            1
#define CS02_BIT            2

#define WGM00               6
#define WGM01               3


#define WGM20               6
#define WGM21               3

#define COM01               5
#define COM00               4


void MCAL_TIMER2_Inint(void);
void MCAL_TIMER_Init(void);

#endif /* TIMER_PRIVATE_H_ */
