cmake_minimum_required(VERSION 3.30)
project(ProjectMrozo1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjectMrozo1 main.cpp
        Vector.h
        Timer.cpp
        Timer.h
        SortingAlgorythms/InsertionSort.h
        SortingAlgorythms/QuickSort.h
        SortingAlgorythms/HeapifySort.h
        SortingAlgorythms/ShellSort.h
        GraphsAlgorythms/Vertex.cpp
        GraphsAlgorythms/Vertex.h
        GraphsAlgorythms/MST.cpp
        GraphsAlgorythms/MST.h
        GraphsAlgorythms/ShortestPath.cpp
        GraphsAlgorythms/ShortestPath.h
)
