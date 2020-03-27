cmake_minimum_required(VERSION 3.13)
project(print_vector_part)

set(CMAKE_CXX_STANDARD 14)

add_executable(print_vector_part main.cpp test_runner.cpp tests.cpp print_vector_part.cpp)