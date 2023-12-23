/*
 * adresses.h
 *
 *  Created on: Jun 10, 2023
 *      Author: Abdullah
 */

#ifndef ADRESSES_H_
#define ADRESSES_H_

#define PORTA   *((u_8*) 0x3B)
#define PORTB   *((u_8*) 0x38)
#define PORTC   *((u_8*) 0x35)
#define PORTD   *((u_8*) 0x32)

#define DDRA    *((u_8*) 0x3A)
#define DDRB    *((u_8*) 0x37)
#define DDRC    *((u_8*) 0x34)
#define DDRD    *((u_8*) 0x31)

#define PINA    *((u_8*) 0x39)
#define PINB    *((u_8*) 0x36)
#define PINC    *((u_8*) 0x33)
#define PIND    *((u_8*) 0x30)

#define SFIOR   *((u_8*) 0x50)
#define PUD 2

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#endif /* ADRESSES_H_ */
