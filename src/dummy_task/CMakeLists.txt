set(THIS_NAME "DUMMY_TASK")

include_directories(../)
include_directories(../RTOS/CMSIS)
include_directories(../RTOS/include)
include_directories(../RTOS/portable/MSVC-MingW)

add_library(${THIS_NAME}  OBJECT
	dummy_task.c
)
