cmake_minimum_required(VERSION 3.13)
project(course_project_yellow)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(course_project_yellow token.cpp condition_parser.cpp date.cpp node.cpp main.cpp database.cpp tests.cpp test_runner.cpp condition_parser_test.cpp)