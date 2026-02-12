cmake_minimum_required(VERSION 3.22)

project(Lab3)

add_library(
    table
    table_s.h
    table_g.c 
    table_g.h 
    table_i.c 
    table_i.h 
    table_out.c 
    table_out.h 
    tablets.c 
    tablets.h 
    table_d.c
    table_d.h 
)
add_library(
    global
    global.c 
    global.h 

)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

add_executable(Lab3a Lab3.c)

target_link_libraries(Lab3a 
    PRIVATE table 
    PRIVATE global 
    readline
    )
