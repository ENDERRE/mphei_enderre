cmake_minimum_required(VERSION 3.22)

project(Lab5)

add_library(
    table
    main.c

)
add_library(
    global
    h.h
    f.c

)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

add_executable(Lab5 main.c)

target_link_libraries(Lab5
    PRIVATE table 
    PRIVATE global 
    readline
    )
