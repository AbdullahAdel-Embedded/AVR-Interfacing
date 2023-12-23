/*
 * LDR_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "../../LIB/STD.h"
#include "../../MCAL/DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   LCD Location Defines   */
/*--------------------------------------------------------------------------------------------*/
#define First_Line 			0
#define Second_Line 		1
#define Third_Line 			2
#define Fourth_Line 		3

#define Char_One 			0
#define Char_Two 			1
#define Char_Three 			2
#define Char_Four 			3
#define Char_Five 			4
#define Char_Six 			5
#define Char_Seven 			6
#define Char_Eight 			7
#define Char_Nine 			8
#define Char_Ten 			9
#define Char_Eleven 		10
#define Char_Twelve 		11
#define Char_thirteen 		12
#define Char_Fourteen 		13
#define Char_Fifteen 		14
#define Char_Sixteen 		15
#define Char_Seventeen 		16
#define Char_Eighteen 		17
#define Char_Nineteen 		18
#define Char_Twenty 		19

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDInit(void);
void H_Lcd_Void_LCDWriteCharacter(u8);
void H_Lcd_Void_LCDWriteCommand(u8);
void H_Lcd_Void_LCDWriteString(u8*);
void H_Lcd_Void_LCDClear(void);
void H_Lcd_Void_LCDWriteNumber(s32);
void H_Lcd_Void_LCDGoTo(u8,u8);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
