/*
 * EINT_Interface.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Abdullah
 */

#ifndef EINT_INTERFACE_H_
#define EINT_INTERFACE_H_


void  task_2(void);
void M_EXTINT_void_ExtintEnable(u8 , u8 );
void M_EXTINT_void_ExtintDisable(u8 );
void M_EXTINT_void_ExtintSetCallBack(void (*)(void), u8);

#endif /* EINT_INTERFACE_H_ */
