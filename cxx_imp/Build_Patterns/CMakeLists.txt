cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Build_Patterns)

add_subdirectory(Factory)
add_subdirectory(Prototype)
add_subdirectory(Singleton)
