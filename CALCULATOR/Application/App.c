/*
 * main.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#include"../MCAL/DIO_Interface.h"
#include"../MCAL/DIO_Config.h"
#include"../MCAL/DIO_Private.h"
#include"../HAL/Keyboard/Keypad_Config.h"
#include"../HAL/Keyboard/Keypad_Private.h"
#include"../HAL/Keyboard/Keypad_Interface.h"
#include"../HAL/LCD/LCD_Config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Private.h"
#include "../LIB/STD.h"
#include"../LIB/BitMath.h"

//#define NULL '/0'


int main()
{
    // Initialize LCD and Keypad
    H_Lcd_Void_LCDInit();
    H_KeyPad_Void_KeyPadInit();

    // Variables for button value, right value, left value, operation, and sign
    u8 button_val = 1;
    s32 right_val = 0;
    s32 left_val =  0;
    u8 operation = NULL;
    u8 sign = NULL;

    // Main calculator loop
    while(1)
    {
        button_val = 1;

        // Wait for a button press
        while(button_val == 1)
        {
            button_val = H_KeyPad_U8_KeyPadRead();
        }

        // Handle different button presses
        switch(button_val)
        {
            case '-':
                // Handle subtraction, consider sign if right_val is 0
                if(right_val == 0)
                {
                    sign = '-';
                    H_Lcd_Void_LCDWriteCharacter(button_val);
                    break;
                }
                operation = button_val;
                H_Lcd_Void_LCDWriteCharacter(button_val);
                break;
            case '+':
            case '*':
            case '/':
                // Handle addition, multiplication, and division
                operation = button_val;
                H_Lcd_Void_LCDWriteCharacter(button_val);
                break;
            case '=':
                // Handle equals, consider sign for subtraction
                if(sign == '-')
                {
                    right_val *= -1;
                    sign = NULL;
                }
                H_Lcd_Void_LCDWriteCharacter(button_val);

                // Perform the arithmetic operation based on the operator
                switch(operation)
                {
                    case '+':
                        H_Lcd_Void_LCDWriteNumber(right_val + left_val);
                        break;
                    case '-':
                        H_Lcd_Void_LCDWriteNumber(right_val - left_val);
                        break;
                    case '*':
                        H_Lcd_Void_LCDWriteNumber(right_val * left_val);
                        break;
                    case '/':
                        // Handle division by zero
                        if(left_val == 0)
                        {
                            u8 infi[12] = "infinity";
                            H_Lcd_Void_LCDWriteString(infi);
                            break;
                        }
                        else
                        {
                            H_Lcd_Void_LCDWriteNumber(right_val / left_val);
                            break;
                        }
                }

                // Reset values and clear the LCD
                right_val = 0;
                left_val = 0;
                operation = NULL;
                while(H_KeyPad_U8_KeyPadRead() == 1);
                H_Lcd_Void_LCDClear();
                break;
            case 'C':
                // Clear the calculator
                H_Lcd_Void_LCDClear();
                right_val = 0;
                left_val = 0;
                operation = NULL;
                break;
            default:
                // Handle numeric input
                if(operation == NULL)
                {
                    H_Lcd_Void_LCDWriteCharacter(button_val);
                    right_val *= 10;
                    right_val += (int)(button_val - '0');
                }
                else
                {
                    H_Lcd_Void_LCDWriteCharacter(button_val);
                    left_val *= 10;
                    left_val += (int)(button_val - '0');
                }
                break;
        }
    }

    return 0;
}

