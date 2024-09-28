cmake_minimum_required(VERSION 3.12)
project(DoublyLinkedList VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

add_library(doubly_linked_list INTERFACE)
target_include_directories(doubly_linked_list INTERFACE include)

add_executable(doubly_linked_list_test test/test.cpp)
target_link_libraries(doubly_linked_list_test PRIVATE doubly_linked_list Catch2::Catch2WithMain)

enable_testing()
add_test(NAME DoublyLinkedListTest COMMAND doubly_linked_list_test)