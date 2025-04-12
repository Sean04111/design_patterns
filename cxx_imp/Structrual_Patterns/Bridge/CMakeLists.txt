cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Bridge)

add_executable(
        Bridge
        main.cpp
        Pimpl.hpp
        Pimpl.cpp
        Render.hpp
)