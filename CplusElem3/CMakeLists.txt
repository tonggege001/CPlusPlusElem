cmake_minimum_required(VERSION 3.8)
project(CplusElem3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp STACK.cpp STACK.h)
add_executable(CplusElem3 ${SOURCE_FILES} STACK.cpp STACK.h)