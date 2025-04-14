cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Decorator)

add_executable(
        Decorator
        main.cpp
 "Dynamic_Decorator.h" "Static_Decorator.h")