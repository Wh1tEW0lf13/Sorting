cmake_minimum_required(VERSION 3.30)
project(ProjectMrozo1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjectMrozo1 main.cpp
        Vector.cpp
        Vector.h
        Timer.cpp
        Timer.h
        SortingAlgorythms/InsertionSort.cpp
        SortingAlgorythms/InsertionSort.h
)
