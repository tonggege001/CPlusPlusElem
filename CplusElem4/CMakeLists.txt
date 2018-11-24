cmake_minimum_required(VERSION 3.8)
project(CplusElem4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QUEUE.cpp QUEUE.h STACK.cpp STACK.h)
add_executable(CplusElem4 ${SOURCE_FILES})