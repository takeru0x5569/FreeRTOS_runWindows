#include "cmsis_os.h"
#include "dummy_task.h"
#include <stdio.h>

static void dummyTask1(void const *arg);
static void dummyTask2(void const *arg);
static osThreadId 			taskHandle1;
static osThreadId 			taskHandle2;
static const osThreadDef_t 	taskDef1 = {
  .name 	 = "dummyTask1",
  .pthread 	 = dummyTask1,
  .tpriority = osPriorityHigh,
  .instances = 0,
  .stacksize = 0x800
};
static const osThreadDef_t 	taskDef2 = {
  .name 	 = "dummyTask2",
  .pthread 	 = dummyTask2,
  .tpriority = osPriorityHigh,
  .instances = 0,
  .stacksize = 0x800
};


//--------------------------------
//
//--------------------------------
static void dummyTask1(void const *arg){
	for(;;){
		printf("dummy_task1\n");
	}
}
static void dummyTask2(void const *arg){
	for(;;){
		printf("dummy_task2\n");
	}
}

//--------------------------------
//
//--------------------------------
int dummyTaskInit1(void){
	taskHandle1 = osThreadCreate(&taskDef1, NULL);
}
int dummyTaskInit2(void){
	taskHandle2 = osThreadCreate(&taskDef2, NULL);
}