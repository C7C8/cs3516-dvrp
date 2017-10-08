cmake_minimum_required(VERSION 3.9)
project(Project_3___DVRP)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        node0.c
        node1.c
        node2.c
        node3.c
        project3.c
        project3.h nodeX.h nodeX.c)

add_executable(Project_3___DVRP ${SOURCE_FILES})