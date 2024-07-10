#ifndef CPPEXERCISES_ITERATOR_H
#define CPPEXERCISES_ITERATOR_H

#include <cstddef>
#include <iterator>
#include "ConstIterator.h"

class MyString;

class Iterator {
public:
    using iterator_concept  = std::bidirectional_iterator_tag;
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = char;
    using difference_type   = std::ptrdiff_t;
    using pointer           = char*;
    using reference         = char&;
private:
    MyString* myString_;
    size_t index_;

public:
    Iterator() noexcept;
    Iterator(MyString* myString, size_t index);

    char& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& other) const;
    auto operator<=>(const Iterator&) const = default;
};

static_assert(std::bidirectional_iterator<Iterator>);

#endif // CPPEXERCISES_ITERATOR_H
