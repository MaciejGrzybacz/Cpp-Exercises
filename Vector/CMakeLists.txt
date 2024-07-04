cmake_minimum_required(VERSION 3.10)
project(Vector)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(VectorLibrary Vector.cpp)

add_executable(VectorTest VectorTest.cpp)

target_link_libraries(VectorTest PRIVATE VectorLibrary)
