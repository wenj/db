cmake_minimum_required(VERSION 3.8)
project(mydb)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(mydb ${SOURCE_FILES})