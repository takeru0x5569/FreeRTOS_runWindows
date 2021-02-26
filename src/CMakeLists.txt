# add_subdirectory(./lib)
add_subdirectory(./RTOS)

# include_directories(./lib)
include_directories(./)
include_directories(./RTOS/include)
include_directories(./RTOS/portable/MSVC-MingW)
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
)

target_link_libraries(EXE_OBJECT  PUBLIC ${STATIC_LIB} ${DLL_LIB} )
