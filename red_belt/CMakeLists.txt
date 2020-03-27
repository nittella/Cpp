cmake_minimum_required(VERSION 3.13)
project(red_belt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


add_executable(red_belt priority_collection_2_2.cpp)