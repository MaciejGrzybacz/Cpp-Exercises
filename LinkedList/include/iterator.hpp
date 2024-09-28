#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stdexcept>
#include <iterator>

template<typename T>
class Iterator {
private:
    Node<T>* current_;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator() : current_(nullptr) {}
    explicit Iterator(Node<T>* node) : current_(node) {}

    reference operator*() const {
        if(!current_) throw std::runtime_error("Dereferencing null iterator");
        return current_->data_;
    }

    pointer operator->() const {
        if(!current_) throw std::runtime_error("Dereferencing null iterator");
        return &(current_->data_);
    }

    Iterator& operator++() {
        if(current_)
            current_ = current_->next_;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    Iterator& operator--() {
        if(current_)
            current_ = current_->prev_;
        return *this;
    }

    Iterator operator--(int) {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const Iterator& other) const {
        return this->current_ == other.current_;
    }

    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }

    Node<T>* get_node() const {
        return current_;
    }
};

template<typename T>
class ConstIterator {
private:
    const Node<T>* current_;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    ConstIterator() : current_(nullptr) {}
    explicit ConstIterator(const Node<T>* node) : current_(node) {}
    ConstIterator(const Iterator<T>& other) : current_(other.get_node()) {}

    reference operator*() const {
        if(!current_) throw std::runtime_error("Dereferencing null iterator");
        return current_->data_;
    }

    pointer operator->() const {
        if(!current_) throw std::runtime_error("Dereferencing null iterator");
        return &(current_->data_);
    }

    ConstIterator& operator++() {
        if(current_) current_ = current_->next_;
        return *this;
    }

    ConstIterator operator++(int) {
        ConstIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    ConstIterator& operator--() {
        if(current_) current_ = current_->prev_;
        return *this;
    }

    ConstIterator operator--(int) {
        ConstIterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const ConstIterator& other) const {
        return this->current_ == other.current_;
    }

    bool operator!=(const ConstIterator& other) const {
        return !(*this == other);
    }

    const Node<T>* get_node() const {
        return current_;
    }
};

#endif // ITERATOR_HPP