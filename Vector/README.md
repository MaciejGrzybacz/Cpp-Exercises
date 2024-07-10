# Vector Template Class

The `Vector` class is a C++ template class representing a mathematical vector. It supports various data types and provides vector operations.

## Features

### Attributes
- Store elements of the vector in a dynamically allocated array
- Track the number of elements in the vector
- Allow the user to specify the data type of the vector elements

### Constructors
- Initialize a vector with a given size, default-initializing all elements
- Create a vector from an initializer list for easy predefined values
- Implement a copy constructor for deep copying
- Provide a move constructor for efficient resource transfer

### Operator Overloading
- Implement element-wise addition of two vectors
- Allow element-wise subtraction of vectors
- Enable scaling of the vector by a scalar value
- Provide a copy assignment operator for deep copying
- Include a move assignment operator for efficient content transfer
- Allow mutable access to vector elements by index
- Provide read-only access to vector elements for const contexts

### Core Methods
- Calculate and return the Euclidean length (magnitude) of the vector
- Return the number of elements in the vector
- Calculate the dot product with another vector
- Resize the vector while preserving existing elements where possible