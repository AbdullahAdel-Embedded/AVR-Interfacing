/*
 * TIMER_Private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Abdullah
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
#include"../LIB/STD.h"

#define TIFR_REG           *((volatile u8*) 0X58)
#define TOV0_BIT            0
#define TIMSK_REG          *((volatile u8*) 0X59)
#define TOIE0_BIT           0
#define SREG_REG           *((volatile u8*) 0x5F)

#define OCR0_REG           *((volatile u8*) 0X5C)
#define TCNT0_REG		   *((volatile u8*) 0X52)
#define TCCR0_REG          *((volatile u8*) 0X53)
#define COM01_BIT           5
#define COM00_BIT           4

#define CS00_BIT            0
#define CS01_BIT            1
#define CS02_BIT            2

#define WGM00               6
#define WGM01               3



#endif /* TIMER_PRIVATE_H_ */
