#include "cmsis_os.h"
#include "UserTaskDef.h"
#include <stdio.h>

//--------------------------------------------------------
// static functions
//--------------------------------------------------------
static void dummyTask1Func(void const *arg);
static void dummyTask2Func(void const *arg);
static osThreadId 			taskHandle1;
static osThreadId 			taskHandle2;

//--------------------------------------------------------
//
//--------------------------------------------------------
//          Task Name     Entry Function    Priority         instance   Stack Size
osThreadDef(dummyTask1   ,dummyTask1Func   ,osPriorityHigh  , 0       , 0x800);
osThreadDef(dummyTask2   ,dummyTask2Func   ,osPriorityHigh  , 0       , 0x800);

//--------------------------------------------------------
//
//--------------------------------------------------------
int TaskInit(void){
    printf("dummy_task1_Init!!\n");
    taskHandle1 = osThreadCreate(&os_thread_def_dummyTask1, NULL);
    printf("dummy_task2_Init!!\n");
    taskHandle2 = osThreadCreate(&os_thread_def_dummyTask2, NULL);
}
//--------------------------------------------------------
//
//--------------------------------------------------------
void UserTaskStart(){
    int32_t run_sts;
    run_sts = osKernelRunning();
    printf("osKernelRunning = %d\n" , run_sts );
    osKernelStart();

    printf("@@ osKernelRunning = %d\n" , run_sts );
}
//--------------------------------------------------------
//
//--------------------------------------------------------
static void dummyTask1Func(void const *arg){
  uint32_t PreviousWakeTime;
	for(int i=0; i<5; i++){
		printf("dummy_task1\n");
    osDelayUntil(&PreviousWakeTime , 1000);
	}
  osThreadTerminate(taskHandle1);
}
static void dummyTask2Func(void const *arg){
  uint32_t PreviousWakeTime;
	for(int i=0; i<5; i++){
		printf("           dummy_task2\n");
    osDelayUntil(&PreviousWakeTime , 2000);
	}
  osThreadTerminate(taskHandle2);
}
//--------------------------------------------------------
//
//--------------------------------------------------------
void vApplicationMallocFailedHook( void ){
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
