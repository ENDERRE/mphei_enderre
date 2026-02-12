cmake_minimum_required(VERSION 3.22)

project(Lab3b)

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

add_executable(Lab3b lab3b.c)

target_link_libraries(Lab3b 
    PRIVATE table 
    PRIVATE global 
    readline
    )
