#include "ConstIterator.h"

ConstIterator::ConstIterator() noexcept : myString_(nullptr), index_(0) {}

ConstIterator::ConstIterator(const MyString *myString, std::size_t index) : myString_(myString), index_(index) {}

inline const char &ConstIterator::operator*() const {
    return myString_->data_[index_];
}

ConstIterator &ConstIterator::operator++() {
    index_++;
    return *this;
}

ConstIterator ConstIterator::operator++(int) {
    ConstIterator it = *this;
    index_++;
    return it;
}

ConstIterator &ConstIterator::operator--() {
    index_--;
    return *this;
}

ConstIterator ConstIterator::operator--(int) {
    ConstIterator it = *this;
    index_--;
    return it;
}

bool ConstIterator::operator==(const ConstIterator &other) const {
    return myString_ == other.myString_ && index_ == other.index_;
}
