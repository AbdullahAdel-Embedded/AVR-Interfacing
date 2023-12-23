/*
 * DIO_Interface.h
 *
 *  Created on: Jun 13, 2023
 *      Author: Abdullah
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*------------------------------------------------------------*/
/*              Includes           */
/*------------------------------------------------------------*/
#include "../LIB/Bit_Math.h"
#include "../LIB/STD.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

/*------------------------------------------------------------*/
/*              Defines           */
/*------------------------------------------------------------*/
#define Input         0
#define Output        1
#define High          1
#define Low           0
#define Disable       0
#define Enable        1


/* PORT A*/
#define PA0_ID    10
#define PA1_ID    11
#define PA2_ID    12
#define PA3_ID    13
#define PA4_ID    14
#define PA5_ID    15
#define PA6_ID    16
#define PA7_ID    17

/* PORT B*/
#define PB0_ID    20
#define PB1_ID    21
#define PB2_ID    22
#define PB3_ID    23
#define PB4_ID    24
#define PB5_ID    25
#define PB6_ID    26
#define PB7_ID    27


/* PORT C*/
#define PC0_ID    30
#define PC1_ID    31
#define PC2_ID    32
#define PC3_ID    33
#define PC4_ID    34
#define PC5_ID    35
#define PC6_ID    36
#define PC7_ID    37


/* PORT D*/
#define PD0_ID    40
#define PD1_ID    41
#define PD2_ID    42
#define PD3_ID    43
#define PD4_ID    44
#define PD5_ID    45
#define PD6_ID    46
#define PD7_ID    47


/*------------------------------------------------------------*/
/*              FUNCTION_PROTOTYPES           */
/*------------------------------------------------------------*/


void M_DIO_VOID_SetPinDirection(u8 , u8 );
void M_DIO_Void_SetPinValue(u8, u8 );
u8 M_DIO_U8_GetPinValue(u8 );
void M_DIO_Void_SetPinPullUpRes(u8, u8);
void Disable_Pullup();















#endif /* DIO_INTERFACE_H_ */
