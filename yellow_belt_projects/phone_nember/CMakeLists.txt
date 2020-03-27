cmake_minimum_required(VERSION 3.13)
project(phone_nember)

set(CMAKE_CXX_STANDARD 14)

add_executable(phone_nember main.cpp test_runner.cpp tests.cpp phone_number.cpp)