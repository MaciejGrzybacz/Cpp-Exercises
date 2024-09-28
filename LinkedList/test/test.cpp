#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("DoublyLinkedList basic operations", "[doubly_linked_list]") {
DoublyLinkedList<int> list;

SECTION("List is initially empty") {
REQUIRE(list.empty());
REQUIRE(list.size() == 0);
}

SECTION("push_back and size") {
list.push_back(1);
REQUIRE(list.size() == 1);
REQUIRE_FALSE(list.empty());

list.push_back(2);
REQUIRE(list.size() == 2);
}

SECTION("push_front and front/back access") {
list.push_front(1);
REQUIRE(list.front() == 1);
REQUIRE(list.back() == 1);

list.push_front(2);
REQUIRE(list.front() == 2);
REQUIRE(list.back() == 1);
}

SECTION("pop_front and pop_back") {
list.push_back(1);
list.push_back(2);
list.push_back(3);

list.pop_front();
REQUIRE(list.front() == 2);

list.pop_back();
REQUIRE(list.back() == 2);
REQUIRE(list.size() == 1);
}
}

TEST_CASE("DoublyLinkedList iterator operations", "[doubly_linked_list]") {
DoublyLinkedList<int> list;
list.push_back(1);
list.push_back(2);
list.push_back(3);

SECTION("Forward iteration") {
auto it = list.begin();
REQUIRE(*it == 1);
++it;
REQUIRE(*it == 2);
++it;
REQUIRE(*it == 3);
++it;
REQUIRE(it == list.end());
}

SECTION("Const iteration") {
const DoublyLinkedList<int>& const_list = list;
auto it = const_list.cbegin();
REQUIRE(*it == 1);
++it;
REQUIRE(*it == 2);
++it;
REQUIRE(*it == 3);
++it;
REQUIRE(it == const_list.cend());
}
}

TEST_CASE("DoublyLinkedList advanced operations", "[doubly_linked_list]") {
DoublyLinkedList<int> list;

SECTION("Insert operation") {
list.push_back(1);
list.push_back(3);

auto it = list.begin();
++it;
list.insert(it, 2);

REQUIRE(list.size() == 3);
REQUIRE(list.front() == 1);
REQUIRE(list.back() == 3);

it = list.begin();
++it;
REQUIRE(*it == 2);
}

SECTION("Erase operation") {
list.push_back(1);
list.push_back(2);
list.push_back(3);

auto it = list.begin();
++it;
it = list.erase(it);

REQUIRE(list.size() == 2);
REQUIRE(*it == 3);
REQUIRE(list.front() == 1);
REQUIRE(list.back() == 3);
}

SECTION("Clear operation") {
list.push_back(1);
list.push_back(2);
list.clear();

REQUIRE(list.empty());
REQUIRE(list.size() == 0);
}
}

TEST_CASE("DoublyLinkedList copy and move operations", "[doubly_linked_list]") {
DoublyLinkedList<int> list;
list.push_back(1);
list.push_back(2);
list.push_back(3);

SECTION("Copy constructor") {
DoublyLinkedList<int> copy_list(list);
REQUIRE(copy_list.size() == list.size());
REQUIRE(copy_list.front() == list.front());
REQUIRE(copy_list.back() == list.back());
}

SECTION("Move constructor") {
DoublyLinkedList<int> move_list(std::move(list));
REQUIRE(move_list.size() == 3);
REQUIRE(move_list.front() == 1);
REQUIRE(move_list.back() == 3);
REQUIRE(list.empty());  // Original list should be empty after move
}

SECTION("Copy assignment operator") {
DoublyLinkedList<int> copy_list;
copy_list = list;
REQUIRE(copy_list.size() == list.size());
REQUIRE(copy_list.front() == list.front());
REQUIRE(copy_list.back() == list.back());
}

SECTION("Move assignment operator") {
DoublyLinkedList<int> move_list;
move_list = std::move(list);
REQUIRE(move_list.size() == 3);
REQUIRE(move_list.front() == 1);
REQUIRE(move_list.back() == 3);
REQUIRE(list.empty());  // Original list should be empty after move
}
}