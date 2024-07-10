#ifndef CPPEXERCISES_MYSTRING_H
#define CPPEXERCISES_MYSTRING_H

#include <memory>
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <cstring>
#include "Iterator.h"
#include "ConstIterator.h"

class Iterator;
class ConstIterator;

class MyString {
private:
    size_t size_;
    std::unique_ptr<char[]> data_;
    friend class Iterator;
    friend class ConstIterator;

public:
    using iterator = Iterator;
    using const_iterator = ConstIterator;

    MyString();
    explicit MyString(size_t size);
    MyString(size_t size, char default_val);
    explicit MyString(std::string_view str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString() = default;

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    MyString operator*(int count) const;
    bool operator==(const char* str) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    const char& operator[](size_t index) const;
    char& operator[](size_t index);
    explicit operator std::string() const;

    [[nodiscard]] size_t length() const;
    void append(const char* str);
    void insert(char ch, size_t index);
    [[nodiscard]] MyString substr(size_t begin, size_t end) const;
    [[nodiscard]] std::unordered_map<char, int> count() const;
    [[nodiscard]] MyString unique() const;

    iterator begin();
    iterator end();
    [[nodiscard]] const_iterator cbegin() const;
    [[nodiscard]] const_iterator cend() const;
    template<typename Predicate>

    friend std::istream& operator>>(std::istream& is, MyString& str);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    [[nodiscard]] size_t size() const;
};

#endif // CPPEXERCISES_MYSTRING_H
