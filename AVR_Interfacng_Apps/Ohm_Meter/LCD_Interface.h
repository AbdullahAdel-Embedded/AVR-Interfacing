/*
 * LCD.Interface.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#define  COMMAND             0
#define  DATA                1

#define DISPLAY_ON_COMMAND            0x0C
#define RETURN_HOME_COMMAND           0x02
#define ININT_COMMAND_1               0x33
#define ININT_COMMAND_2               0x32
#define ININT_COMMAND_3               0x28
#define CLEAR_COMMMAND                0x01

#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4
#define NULL                          '\0'



void H_LCD_Void_LCDInint(void);
void H_LCD_Void_LCDWriteCommand(u8 );
void H_LCD_Void_LCDWriteCharacter(u8 );
void H_LCD_Void_LCDWriteString(u8 *);
void H_LCD_Void_LCDWriteNumber(s32 );
void H_LCD_Void_LCDClear();
void H_LCD_Void_LCDGoTo();


#endif /* LCD_INTERFACE_H_ */
