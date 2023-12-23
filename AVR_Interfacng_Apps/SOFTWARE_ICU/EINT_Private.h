/*
 * EINT_private.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#ifndef EINT_PRIVATE_H_
#define EINT_PRIVATE_H_

#define SREG_REG              *((u8*) 0x5F)
#define GICR_REG              *((u8*) 0x5B)
#define MCUCR_REG             *((u8*) 0x55)
#define MCUCSR_REG            *((u8*) 0x54)
#define GIFR_REG              *((u8*) 0x5A)


#define INT0_PIN                  6
#define INT1_PIN                  7
#define INT2_PIN                  5


#define ISC00_PIN                 0
#define ISC01_PIN                 1
#define ISC10_PIN                 2
#define ISC11_PIN                 3


#define LOW_LEVEL                 0
#define LOGIC_CHANGE              1
#define FALLING_EDGE              2
#define RISING_EDGE               3


#define ISC2_PIN                  6



#endif /* EINT_PRIVATE_H_ */
