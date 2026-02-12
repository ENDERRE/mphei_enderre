cmake_minimum_required(VERSION 3.22)

project(lab4b)

add_library(
    tree
    tree_s.h
    tree_f.c
    tree_f.h

)
add_library(
    global
    global.c 
    global.h 

)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

add_executable(lab4b main.c)

target_link_libraries(lab4b 
    PRIVATE tree 
    PRIVATE global 
    readline
    )

