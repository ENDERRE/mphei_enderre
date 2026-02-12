cmake_minimum_required(VERSION 3.22)

project(main)


add_library(
    global
    global.c 
    global.h 
    lib_s.h

)


add_executable(main main.c)

target_link_libraries(main
    PRIVATE global 
    )
