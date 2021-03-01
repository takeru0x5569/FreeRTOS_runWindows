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
// task Definition
//--------------------------------------------------------
//          Task Name     Entry Function    Priority         instance   Stack Size
osThreadDef(dummyTask1   ,dummyTask1Func   ,osPriorityHigh  , 0       , 0x800);
osThreadDef(dummyTask2   ,dummyTask2Func   ,osPriorityHigh  , 0       , 0x800);

//--------------------------------------------------------
// task Registration
//--------------------------------------------------------
int TaskInit(void){
    if( 1 == osKernelRunning() ){
        return 1;//error
    }

    taskHandle1 = osThreadCreate(osThread(dummyTask1), NULL);
    taskHandle2 = osThreadCreate(osThread(dummyTask2), NULL);
    return 0;//
}
//--------------------------------------------------------
// task Start
//--------------------------------------------------------
void UserTaskStart(){
    if( 0 == osKernelRunning() ){
        osKernelStart();
	}
}
//--------------------------------------------------------
// task1
//--------------------------------------------------------
static void dummyTask1Func(void const *arg){
  uint32_t PreviousWakeTime;
	for(int i=0; i<5; i++){
		printf("dummy_task1\n");
    	osDelayUntil(&PreviousWakeTime , 1000);//1秒周期
	}
  osThreadTerminate(taskHandle1);//タスク停止
}
//--------------------------------------------------------
// task2
//--------------------------------------------------------
static void dummyTask2Func(void const *arg){
  uint32_t PreviousWakeTime;
	for(int i=0; i<5; i++){
		printf("           dummy_task2\n");
    	osDelayUntil(&PreviousWakeTime , 2000);//2秒周期
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
