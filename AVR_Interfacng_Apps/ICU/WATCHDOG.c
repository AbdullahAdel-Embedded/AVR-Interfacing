/*
 * WATCHDOG.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Abdullah
 */

#include "avr\io.h"
void WatchDog_Disable(void)
{
	WDTCR= 0xFF;
	WDTCR= 0x00;

}

void WatchDog_Enable(u8 prescaler)
{
	WDTCR= 0xFF;
	WDTCR= 0x00;

}
