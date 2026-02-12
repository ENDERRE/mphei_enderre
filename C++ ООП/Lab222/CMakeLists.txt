cmake_minimum_required(VERSION 3.22)

project(main LANGUAGES CXX)

add_library(lab2 STATIC
    lab2.cpp
    lab2_s.cpp
    global.cpp
    global.hpp
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
target_include_directories(lab2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main lab2.cpp)

target_link_libraries(main PRIVATE lab2)