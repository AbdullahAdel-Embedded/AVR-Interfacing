/*
 * DIO_Private.h
 *
 *  Created on: Jun 13, 2023
 *      Author: Abdullah
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

typedef struct
{
	u8 pin;
	u8 ddr;
	u8 port;
}DIO_PORT;


#define PORTA ((DIO_PORT*) 0x39)
#define PORTB ((DIO_PORT*) 0x36)
//PORTA->pin =

#define PINA_REG    *((u8*) 0x39)
#define DDRA_REG    *((u8*) 0x3A)
#define PORTA_REG   *((u8*) 0x3B)

#define PORTB_REG   *((volatile u8*) 0x38)
#define PORTC_REG   *((volatile u8*) 0x35)
#define PORTD_REG   *((u8*) 0x32)


#define DDRB_REG    *((u8*) 0x37)
#define DDRC_REG    *((u8*) 0x34)
#define DDRD_REG    *((u8*) 0x31)

#define PINA_REG    *((u8*) 0x39)
#define PINB_REG    *((u8*) 0x36)
#define PINC_REG    *((u8*) 0x33)
#define PIND_REG    *((u8*) 0x30)

#define SFIOR_REG   *((u8*) 0x50)


#endif /* DIO_PRIVATE_H_ */
