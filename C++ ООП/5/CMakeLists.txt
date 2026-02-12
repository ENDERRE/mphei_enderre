cmake_minimum_required(VERSION 3.22)

project(Lab5)

add_library(
    table
    table_i_out.c
    table_i_out.h 
    table.c 
    table.h
    table_s.h

)
add_library(
    global
    global.c 
    global.h 

)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

add_executable(Lab5 lab5.c)

target_link_libraries(Lab5
    PRIVATE table 
    PRIVATE global 
    readline
    )
