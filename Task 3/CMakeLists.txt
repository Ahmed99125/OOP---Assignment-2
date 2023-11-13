cmake_minimum_required(VERSION 3.25)
project(Task_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_3
        Instructions.cpp
        Instructions.h
        Machine.cpp
        Machine.h
        main.cpp
        Memory.cpp
        Memory.h
        Registers.cpp
        Registers.h)
