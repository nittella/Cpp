cmake_minimum_required(VERSION 3.13)
project(bus_stops)

set(CMAKE_CXX_STANDARD 14)

add_executable(bus_stops main.cpp query.cpp responses.cpp bus_manager.cpp)