cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Composite)

add_executable(
        Composite
        main.cpp
        "Creature.hpp"
 "GraphicObj.hpp"   )