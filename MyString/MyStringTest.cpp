#include "MyString.h"
#include <iostream>
#include <cassert>
#include <algorithm>

void testBasicFunctionality() {
    MyString s("Hello");
    assert(s.length() == 5);
    assert(s[0] == 'H');
    assert(s[4] == 'o');
}

void testIterators() {
    MyString s("Hello");
    std::string result;
    for (char & it : s) {
        result += it;
    }
    assert(result == "Hello");
}


int main() {
    testBasicFunctionality();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
