cmake_minimum_required(VERSION 3.13)
project(sum_reverse_sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(sum_reverse_sort main.cpp sum_reverse_sort.cpp test_runner.h test_runner.cpp tests.h tests.cpp)