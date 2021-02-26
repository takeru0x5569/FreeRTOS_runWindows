set(THIS_NAME "RTOS")

include_directories(../)					#include FreeRTOSConfig.h 
include_directories(./include)				#include Hedder file
include_directories(./portable/MSVC-MingW)

add_library(${THIS_NAME}  OBJECT
	portable/MemMang/heap_4.c
	portable/MSVC-MingW/port.c
	event_groups.c
	list.c
	queue.c
	timers.c
	vAssertCalled.c
	tasks.c
)
