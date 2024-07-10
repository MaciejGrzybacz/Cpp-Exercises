#include "Iterator.h"
#include "MyString.h"

Iterator::Iterator() noexcept : myString_(nullptr), index_(0) {}

Iterator::Iterator(MyString *myString, size_t index) : myString_(myString), index_(index) {}

char& Iterator::operator*() const {
    return myString_->data_[index_];
}

Iterator &Iterator::operator++() {
    index_++;
    return *this;
}

Iterator Iterator::operator++(int) {
    Iterator it = *this;
    index_++;
    return it;
}

Iterator &Iterator::operator--() {
    index_--;
    return *this;
}

Iterator Iterator::operator--(int) {
    Iterator it = *this;
    index_--;
    return it;
}

bool Iterator::operator==(const Iterator &other) const {
    return myString_ == other.myString_ && index_ == other.index_;
}
