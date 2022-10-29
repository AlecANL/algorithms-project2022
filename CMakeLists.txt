cmake_minimum_required(VERSION 3.23)
project(basic_traductor)

set(CMAKE_CXX_STANDARD 14)

add_executable(basic_traductor main.cpp utils.cpp menu.cpp crud.cpp code_traductor.cpp translations.cpp)
