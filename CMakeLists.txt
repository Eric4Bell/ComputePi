cmake_minimum_required(VERSION 3.0)
project(ComputePi)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(ComputePi computePiDigit.hpp digitHash.hpp digitHash.cpp taskQueue.hpp taskQueue.cpp main.cpp)
