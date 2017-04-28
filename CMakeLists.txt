cmake_minimum_required(VERSION 3.7)
project(Lab0)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp algorithms/schultz_method.cpp algorithms/schultz_method.h constants.h matrix/Matrix.cpp matrix/Matrix.h types.h)
add_executable(Lab0 ${SOURCE_FILES})