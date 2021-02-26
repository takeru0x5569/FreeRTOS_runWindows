#include "FreeRTOS.h"
#include "task.h"

#include <stdio.h>

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

//===================================================================
//
//===================================================================
int main(){
	/* Create one of the two tasks. */
	xTaskCreate(vTask1,		/* Pointer to the function that implements the task. */
				"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
				1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,		/* We are not using the task parameter. */
				1,			/* This task will run at priority 1. */
				NULL );		/* We are not using the task handle. */
	
	xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );


	vTaskStartScheduler();
	for( ;; );
	return 0;
}
//==================================================================
//
//==================================================================
void vTask1( void *pvParameters ){
	const portTickType xDelay = 1000 / portTICK_RATE_MS;
	for( ;; )
	{
	printf("task1\n");
	vTaskDelay( xDelay );
	}
}
//==================================================================
//
//==================================================================
void vTask2( void *pvParameters ){
	const portTickType xDelay = 2000 / portTICK_RATE_MS;
	for( ;; )
	{
	printf("\ttask2\n");
	vTaskDelay( xDelay );
	}
}
