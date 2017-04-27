cmake_minimum_required(VERSION 3.7)
project(Lab0)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp schultz_method.cpp schultz_method.h matrix_util.cpp matrix_util.h target.h)
add_executable(Lab0 ${SOURCE_FILES})