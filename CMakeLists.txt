cmake_minimum_required(VERSION 3.16)
project(CppExercises)

#option(BUILD_VECTOR "Build the Vector project" OFF)

#if(BUILD_VECTOR)
#    add_subdirectory(Vector)
#endif()

option(BUILD_MY_STRING "Build the MyString project" ON)

if(BUILD_MY_STRING)
    add_subdirectory(MyString)
endif()
