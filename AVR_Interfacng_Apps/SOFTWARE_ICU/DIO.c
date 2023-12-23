/*
 * DIO.c
 *
 *  Created on: Jun 13, 2023
 *      Author: Abdullah
 */


#include "DIO_Interface.h"
#include <util/delay.h>
/*
int main()
{

	return 0;
}*/

/*
int main(void)
{
	M_DIO_VOID_SetPinDirection(PA4_ID, Output);
	M_DIO_VOID_SetPinDirection(PA5_ID, Output);
	M_DIO_VOID_SetPinDirection(PA6_ID, Output);
	M_DIO_VOID_SetPinDirection(PB7_ID, Output);

	while(1)
	{
		M_DIO_Void_SetPinValue(PA4_ID,	High);
		_delay_ms(100);
		M_DIO_Void_SetPinValue(PA4_ID,	Low);

		M_DIO_Void_SetPinValue(PA5_ID,	High);
		_delay_ms(100);
		M_DIO_Void_SetPinValue(PA5_ID,	Low);

		M_DIO_Void_SetPinValue(PA6_ID,	High);
		_delay_ms(100);
		M_DIO_Void_SetPinValue(PA6_ID,	Low);

		M_DIO_Void_SetPinValue(PB7_ID,	High);
		_delay_ms(100);
		M_DIO_Void_SetPinValue(PB7_ID,	Low);

	}


	return 0;
}*/

void M_DIO_VOID_SetPinDirection(u8 PORT_PIN, u8 U8_Copy_State)
{

	u8 PIN_NUM = PORT_PIN %10;
	u8 PORT_NUM = PORT_PIN /10;

    if(U8_Copy_State == Output)
    {
        switch(PORT_NUM)
        {
        case 1: DDRA_REG |= (1<<PIN_NUM);  break;
        case 2: DDRB_REG |= (1<<PIN_NUM);  break;
        case 3: DDRC_REG |= (1<<PIN_NUM); break;
        case 4: DDRD_REG |= (1<<PIN_NUM); break;
        }
    }

    else if(U8_Copy_State == Input)
    {
        switch(PORT_NUM)
        {
        case 1: DDRA_REG |= (1<<PIN_NUM);  break;
        case 2: DDRB_REG |= (1<<PIN_NUM);  break;
        case 3: DDRC_REG |= (1<<PIN_NUM); break;
        case 4: DDRD_REG |= (1<<PIN_NUM); break;
        }
    }

}


void M_DIO_Void_SetPinValue(u8 PORT_PIN, u8 U8_Value)
{
	u8 PIN_NUM = PORT_PIN %10;
	u8 PORT_NUM = PORT_PIN /10;

    if(U8_Value == High)
    {
        switch(PORT_NUM)
        {
        case 1: SET_BIT(PORTA_REG, PIN_NUM); break;
        case 2: SET_BIT(PORTB_REG, PIN_NUM); break;
        case 3: SET_BIT(PORTC_REG, PIN_NUM); break;
        case 4: SET_BIT(PORTD_REG, PIN_NUM); break;
        }
    }
    else
    {
        switch(PORT_NUM)
        {
        case 1: CLR_BIT(PORTA_REG, PIN_NUM); break;
        case 2: CLR_BIT(PORTB_REG, PIN_NUM); break;
        case 3: CLR_BIT(PORTC_REG, PIN_NUM); break;
        case 4: CLR_BIT(PORTD_REG, PIN_NUM); break;
        }
    }
}

u8 M_DIO_U8_GetPinValue(u8 PORT_PIN)
{
	u8 PIN_NUM = PORT_PIN %10;
	u8 PORT_NUM = PORT_PIN /10;

    switch(PORT_NUM)
    {
    case 1: //portA
        return GET_BIT(PINA_REG, PIN_NUM);
        break;
    case 2: //portB
        return GET_BIT(PINB_REG, PIN_NUM);
        break;
    case 3: //portC
        return GET_BIT(PINC_REG, PIN_NUM);
        break;
    case 4: //portD
        return GET_BIT(PIND_REG, PIN_NUM);
        break;
    }

    return 0;

}

void M_DIO_Void_SetPinPullUpRes(u8 PORT_PIN, u8 U8_Copy_State)
{
	u8 PIN_NUM = PORT_PIN %10;
	u8 PORT_NUM = PORT_PIN /10;

	switch(U8_Copy_State)
	{
	case Enable:
		switch(PORT_NUM)
		{
		case 1: SET_BIT(PORTA_REG,  PIN_NUM); break;
		case 2: SET_BIT(PORTB_REG,  PIN_NUM); break;
		case 3: SET_BIT(PORTC_REG,  PIN_NUM); break;
		case 4: SET_BIT(PORTD_REG,  PIN_NUM); break;
		}
	break;

	case Disable:
		switch(PORT_NUM)
		{
		case 1: CLR_BIT(PORTA_REG,  PIN_NUM); break;
		case 2: CLR_BIT(PORTB_REG,  PIN_NUM); break;
		case 3: CLR_BIT(PORTC_REG,  PIN_NUM); break;
		case 4: CLR_BIT(PORTD_REG,  PIN_NUM); break;
		}
	break;
	}

}

void Disable_Pullup()
{
    SFIOR_REG |=(1<<2);
}

