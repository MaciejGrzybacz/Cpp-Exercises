# Custom String Class with Advanced Iterators

## Project Description

This project involves creating a custom string class (`MyString`) in C++ along with implementations of various iterator types. The project includes a standard iterator, a const iterator, and a specialized filter iterator. This exercise will deepen your understanding of string manipulation, memory management, and iterator design in C++.

## Objectives

1. Implement a `MyString` class that mimics basic functionalities of `std::string`.
2. Create a standard mutable iterator for `MyString`.
3. Implement a const iterator to allow read-only access.
4. Develop a filter iterator that can iterate over specific characters.
5. Ensure compatibility with STL algorithms and range-based for loops.

## Class Structure

### MyString
- Store characters internally (e.g., using a dynamic char array).
- Implement basic string operations like `append()`, `substr()`, `length()`, etc.
- Provide methods to get iterators: `begin()`, `end()`, `cbegin()`, `cend()`.
- Implement a method to get filter iterators.

### Iterator Classes
1. `MyString::iterator`
2. `MyString::const_iterator`

## Implementation Guidelines

1. Start with the `MyString` class, focusing on proper memory management and basic string operations.
2. Implement the `iterator` class, ensuring it provides mutable access to characters.
3. Create the `const_iterator` by modifying the `iterator` class to prevent modification.
4. Develop the `filter_iterator` that allows iteration over characters meeting specific criteria.
5. Ensure all iterators work correctly with standard algorithms and range-based for loops.
