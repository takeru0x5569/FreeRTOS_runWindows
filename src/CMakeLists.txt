# add_subdirectory(./lib)
add_subdirectory(./RTOS)
add_subdirectory(./dummy_task)

# include_directories(./lib)
include_directories(./)
include_directories(./RTOS/include)
include_directories(./RTOS/portable/MSVC-MingW)
include_directories(./RTOS/CMSIS)

include_directories(./dummy_task)
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
    DUMMY_TASK
)

target_link_libraries(EXE_OBJECT  PUBLIC ${STATIC_LIB} ${DLL_LIB} )
