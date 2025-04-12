cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Adapter)

add_executable(
        Adapter
        main.cpp
        Image.hpp
)