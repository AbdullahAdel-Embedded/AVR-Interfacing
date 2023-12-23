/*
 * main.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Mahmoud EL-Imbabi
 */

#include "../MCAL/DIO/DIO_Interface.h"
#include "../LIB/STD.h"
#include <util/delay.h>


int main(){

	u8 Loc_u8Led_1 =0;
	u8 Loc_u8Led_Switch =0;
	while(1){

							M_DIO_Void_SetPinDirection(PA7_PIN,HIGH);
							M_DIO_Void_SetPinValue(PA7_PIN,HIGH);
		      	  	  	  	M_DIO_Void_SetPinDirection(PB5_PIN,HIGH);


			  Loc_u8Led_1 = M_DIO_Void_GetPinValue(PA7_PIN);
							M_DIO_Void_SetPinDirection(PB7_PIN,HIGH);
							M_DIO_Void_SetPinValue(PB7_PIN , Loc_u8Led_1);

							M_DIO_Void_SetPinDirection(PC7_PIN,HIGH);
							M_DIO_Void_TogPin(PC7_PIN);

							M_DIO_Void_SetPinDirection(PD0_PIN,LOW);
							M_DIO_Void_SetPinPullUpRes(PD0_PIN,HIGH); //pullup

							_delay_ms(10);

		 Loc_u8Led_Switch = M_DIO_Void_GetPinValue(PD0_PIN);
		      			    M_DIO_Void_SetPinValue(PB5_PIN , Loc_u8Led_Switch);







	}


	return 0;
}
