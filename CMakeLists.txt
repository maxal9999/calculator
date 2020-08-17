set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.8)

project(calculator)

set(SRC_LIST main.cpp
             calculator/calculator.cpp)

set(HEADER calculator/calculator.hpp)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADER})
