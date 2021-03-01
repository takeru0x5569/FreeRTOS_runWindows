add_subdirectory(./RTOS)
add_subdirectory(./UserTaskDef)

include_directories(./)
include_directories(./RTOS/include)
include_directories(./RTOS/portable/MSVC-MingW)
include_directories(./RTOS/CMSIS)

include_directories(./UserTaskDef)
#==============================================================
# genarate executable object
#==============================================================
set(SOURCE_FILES
	main.c
    )

add_executable(EXE_OBJECT ${SOURCE_FILES})

#==============================================================
# LINK
#==============================================================
set(DLL_LIB
    winmm 
    gdi32
)

set(STATIC_LIB
    RTOS
    USER_TASK
)

target_link_libraries(EXE_OBJECT  PUBLIC ${STATIC_LIB} ${DLL_LIB} )
