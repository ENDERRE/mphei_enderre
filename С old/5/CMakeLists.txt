cmake_minimum_required(VERSION 3.22)

project(lab5)



set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
add_library(
   graph
   graph.c
   graph.h
   graph_s.h


)
add_library(
    global
    global.c 
    global.h 

)
add_executable(lab5 main.c)

target_link_libraries(lab5 
    PRIVATE graph 
    PRIVATE global 
    readline
    )

