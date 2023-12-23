

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#ifndef NULL
#define NULL (void *)0
#endif



/**
 * The Aim of This Project to Use 1 Push Button to Start the DC Motor
 * when the I Press Push Button the DC Motor Shall Invert it's State after
 * 3 Seconds
 * **/

 int main(void)
{

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}


















