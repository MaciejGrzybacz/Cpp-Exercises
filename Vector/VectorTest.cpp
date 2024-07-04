//
// Created by 006ma on 04.07.2024.
//
#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector.h"

#define TEST(name) void name()
#define ASSERT_EQ(a, b) assert((a) == (b))
#define ASSERT_DOUBLE_EQ(a, b) assert(std::abs((a) - (b)) < 1e-6)

// Test constructor with size
TEST(ConstructorWithSize) {
    Vector<int> v(5);
    ASSERT_EQ(v.size(), 5);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i;
        ASSERT_EQ(v[i], i);
    }
}

// Test constructor with initializer list
TEST(ConstructorWithInitializerList) {
    Vector<int> v = {1, 2, 3, 4, 5};
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
    ASSERT_EQ(v[3], 4);
    ASSERT_EQ(v[4], 5);
}

// Test copy constructor
TEST(CopyConstructor) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = v1;
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[1], 2);
    ASSERT_EQ(v2[2], 3);
}

// Test move constructor
TEST(MoveConstructor) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = std::move(v1);
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[1], 2);
    ASSERT_EQ(v2[2], 3);
    ASSERT_EQ(v1.size(), 0);
}

// Test copy assignment operator
TEST(CopyAssignment) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2;
    v2 = v1;
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[1], 2);
    ASSERT_EQ(v2[2], 3);
}

// Test move assignment operator
TEST(MoveAssignment) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2;
    v2 = std::move(v1);
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], 1);
    ASSERT_EQ(v2[1], 2);
    ASSERT_EQ(v2[2], 3);
    ASSERT_EQ(v1.size(), 0);
}

// Test addition operator
TEST(AdditionOperator) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {4, 5, 6};
    Vector<int> v3 = v1 + v2;
    ASSERT_EQ(v3.size(), 3);
    ASSERT_EQ(v3[0], 5);
    ASSERT_EQ(v3[1], 7);
    ASSERT_EQ(v3[2], 9);
}

// Test subtraction operator
TEST(SubtractionOperator) {
    Vector<int> v1 = {4, 5, 6};
    Vector<int> v2 = {1, 2, 3};
    Vector<int> v3 = v1 - v2;
    ASSERT_EQ(v3.size(), 3);
    ASSERT_EQ(v3[0], 3);
    ASSERT_EQ(v3[1], 3);
    ASSERT_EQ(v3[2], 3);
}

// Test scalar multiplication operator
TEST(ScalarMultiplicationOperator) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = v1 * 2;
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], 2);
    ASSERT_EQ(v2[1], 4);
    ASSERT_EQ(v2[2], 6);
}

// Test euclidean length
TEST(EuclideanLength) {
    Vector<int> v = {3, 4};
    ASSERT_EQ(v.euclideanLength(), 5);
}

// Test dot product
TEST(DotProduct) {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {4, 5, 6};
    ASSERT_EQ(v1.dotProduct(v2), 32);
}

int main() {
    ConstructorWithSize();
    ConstructorWithInitializerList();
    CopyConstructor();
    MoveConstructor();
    CopyAssignment();
    MoveAssignment();
    AdditionOperator();
    SubtractionOperator();
    ScalarMultiplicationOperator();
    EuclideanLength();
    DotProduct();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}