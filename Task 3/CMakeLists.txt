cmake_minimum_required(VERSION 3.23)
project(Task_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_3
        Instructions.h
        Instructions.cpp
        Machine.h
        Machine.cpp
        Memory.h
        Memory.cpp
        Registers.h
        Registers.cpp
        main.cpp)
