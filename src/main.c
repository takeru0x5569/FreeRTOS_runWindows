#include "FreeRTOS.h"
#include "task.h"

#include <stdio.h>

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
	const portTickType xDelay = 1000 / portTICK_RATE_MS;//1000ms
	while(1){
		printf("task1\n");
		vTaskDelay( xDelay );
	}
}
//==================================================================
//
//==================================================================
void vTask2( void *pvParameters ){
	const portTickType xDelay = 2000 / portTICK_RATE_MS;//2000ms
	while(1){
		printf("\ttask2\n");
		vTaskDelay( xDelay );
	}
}


void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c, heap_2.c or heap_4.c is being used, then the
	size of the	heap available to pvPortMalloc() is defined by
	configTOTAL_HEAP_SIZE in FreeRTOSConfig.h, and the xPortGetFreeHeapSize()
	API function can be used to query the size of free heap space that remains
	(although it does not provide information on how the remaining heap might be
	fragmented).  See http://www.freertos.org/a00111.html for more
	information. */
	vAssertCalled( __LINE__, __FILE__ );
}

