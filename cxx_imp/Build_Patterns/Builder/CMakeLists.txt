cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Builder)

add_executable(
        main
        main.cpp
        Person.hpp
        Pc.hpp

)