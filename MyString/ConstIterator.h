#ifndef CPPEXERCISES_CONSTITERATOR_H
#define CPPEXERCISES_CONSTITERATOR_H

#include <iterator>
#include <concepts>
#include "MyString.h"

class MyString;

class ConstIterator {
public:
    using iterator_concept  = std::bidirectional_iterator_tag;
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = char;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const char*;
    using reference         = const char&;

private:
    const MyString* myString_;
    std::size_t index_;

public:
    ConstIterator() noexcept;
    ConstIterator(const MyString* myString, std::size_t index);

    reference operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    ConstIterator& operator--();
    ConstIterator operator--(int);
    bool operator==(const ConstIterator& other) const;
    auto operator<=>(const ConstIterator&) const = default;
};

static_assert(std::bidirectional_iterator<ConstIterator>);

#endif //CPPEXERCISES_CONSTITERATOR_H