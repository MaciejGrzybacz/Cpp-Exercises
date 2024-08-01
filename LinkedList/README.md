# C++ Doubly Linked List Implementation

This project implements a templated Doubly Linked List class using modern C++ features, including smart pointers, move semantics, and STL-compatible iterators.

## Features

### Core Structure
- Implements a templated `Node` structure for flexible data types
- Maintains pointers to both head and tail of the list
- Tracks the list size for O(1) size queries

### Class: DoublyLinkedList<T>

#### Constructors and Destructor
- Default constructor
- Copy constructor
- Move constructor
- Destructor (implicit due to use of `unique_ptr`)

#### Operators
- Copy assignment operator
- Move assignment operator
- Subscript operator (`[]`) for element access by index
- Output stream operator (`<<`) for printing the list

#### Core Methods
- `push_front`: Add an element to the front of the list
- `push_back`: Add an element to the end of the list
- `pop_front`: Remove the first element
- `pop_back`: Remove the last element
- `front`: Access the first element
- `back`: Access the last element
- `empty`: Check if the list is empty
- `size`: Get the number of elements
- `clear`: Remove all elements
- `insert`: Insert an element at a specific position
- `erase`: Remove an element at a specific position

#### Iterators
- `begin/end`: Return iterators to the first/past-the-last element
- `cbegin/cend`: Return const iterators

### Iterator Classes
- `Iterator<T>`: Bidirectional iterator
- `ConstIterator<T>`: Const bidirectional iterator

Both iterator classes are STL-compatible and support:
- Increment/decrement (prefix and postfix)
- Dereferencing
- Member access (->)
- Equality/inequality comparison

## File Structure

- `doubly_linked_list.hpp`: Main header file with DoublyLinkedList class template
- `node.hpp`: Header file with Node structure definition
- `iterator.hpp`: Header file with Iterator and ConstIterator class templates
- `doubly_linked_list.cpp`: Implementation file (if needed for non-template functions)
- `test.cpp`: Test file with usage examples and unit tests
