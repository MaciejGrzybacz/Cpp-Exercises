cmake_minimum_required(VERSION 3.10)

project(MyString VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
        MyString.cpp
        Iterator.cpp
        ConstIterator.cpp
)

set(HEADERS
        MyString.h
        Iterator.h
        ConstIterator.h
)

add_library(MyString ${SOURCES} ${HEADERS})

target_include_directories(MyString PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MyStringTest MyStringTest.cpp)
target_link_libraries(MyStringTest MyString)

enable_testing()
add_test(NAME MyStringTest COMMAND MyStringTest)