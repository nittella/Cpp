cmake_minimum_required(VERSION 3.13)
project(diploma)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        diploma
        main.cpp
        cartesian_atomic_coordinates.cpp
        cartesin_coordinate.cpp
        string_parser.cpp
        internal_atomic_coordinates.cpp
        internal_atomic_coordinates.h
        conditions.cpp
        atom.cpp
        distances_manager.cpp
        internal_coordinate_type.cpp
        internal_coordinate_type.h
        internal_coordinate.cpp
        internal_coordinate.h
        converter.h
        deviation_reader.cpp
        deviation_reader.h
        calculate_distance.cpp
        calculate_distance.h
        distance_predicator.h
        circles_dict.h converter_5.cpp)