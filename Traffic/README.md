# Advanced C++ Container: Circular Buffer

Design and implement a template class `CircularBuffer` that represents a circular buffer (also known as a ring buffer). This data structure should use templates for type flexibility and extensively utilize iterators for access and manipulation.

## Core Requirements

1. Template Design
  - The `CircularBuffer` should be a template class, allowing it to store any data type.
  - Implement a second template parameter for the buffer's capacity, which should have a default value.

2. Basic Operations
  - Constructor that initializes the buffer with a given capacity.
  - Methods to add elements to the back (`push_back`) and remove from the front (`pop_front`).
  - Access methods: `front()`, `back()`, `at(size_t)`, and `operator[]`.

3. Iterator Support
  - Implement the following iterator types:
    - `iterator` and `const_iterator`
    - `reverse_iterator` and `const_reverse_iterator`
  - Provide `begin()`, `end()`, `rbegin()`, and `rend()` methods (and their const counterparts).

4. Capacity Management
  - Methods to check if the buffer is `empty()` or `full()`.
  - A `size()` method to return the current number of elements.
  - A `capacity()` method to return the maximum number of elements.

5. Special Iterator Features
  - Implement a `circular_iterator` that wraps around to the beginning when it reaches the end.
  - Create a `window_iterator` that allows iteration over a fixed-size window within the buffer.

## Advanced Features

6. Template Specialization
  - Provide a specialization for `bool` that uses `std::vector<bool>` space optimization.

7. Iterator Traits
  - Ensure all iterators have proper iterator traits defined.

8. Const-correctness
  - Implement `const` and non-`const` versions of all relevant methods and iterators.

9. Exception Safety
  - Ensure strong exception safety for all operations.

10. Template Metaprogramming
  - Use SFINAE or concepts (if using C++20) to restrict the types that can be stored in the buffer.

## Iterator Challenges

11. Filtering Iterator
  - Create a `filtering_iterator` that skips elements based on a predicate.

12. Transforming Iterator
  - Implement a `transforming_iterator` that applies a function to elements during iteration.

13. Multi-pass Guarantee
  - Ensure forward, bidirectional, and random access iterators provide the multi-pass guarantee.

14. Iterator Arithmetic
  - Implement proper arithmetic operations for random access iterators.
