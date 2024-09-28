#include "node.hpp"
#include "iterator.hpp"
#include <ostream>

template <typename T>
class DoublyLinkedList {
private:
    size_t size_;
    Node<T>* head_;
    Node<T>* tail_;

public:
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;

    DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
    DoublyLinkedList(const DoublyLinkedList &other);
    DoublyLinkedList(DoublyLinkedList &&other) noexcept;

    ~DoublyLinkedList();

    DoublyLinkedList& operator=(const DoublyLinkedList &other);
    DoublyLinkedList& operator=(DoublyLinkedList &&other) noexcept;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_front(const T& data);
    void push_front(T&& data);
    void push_back(const T& data);
    void push_back(T&& data);
    void pop_front();
    void pop_back();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    void clear();
    /* @brief method to find specific value in the list
     *
     * @param value - value to find
     * @return iterator to the first element with the value or end() if the value is not found
     */
    iterator find(const T& value) const;
    /* @brief method to insert element before the element at the specified position
     *
     * @param pos - iterator to the position before which the element will be inserted
     * @param data - data to insert
     * @return iterator to the inserted element
     */
    iterator insert(iterator pos, const T& data);

    /* @brief method to erase element at the specified position
     *
     * @param pos - iterator to the position of the element to erase
     * @return iterator to the element after the erased element
     */
    iterator erase(iterator pos);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list);
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other) : DoublyLinkedList() {
    for(auto it = other.cbegin(); it != other.cend(); ++it) {
        push_back(*it);
    }
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList &&other) noexcept : size_(other.size_){
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList &other) {
    DoublyLinkedList<T> tmp(other);
    std::swap(head_, tmp.head_);
    std::swap(tail_, tmp.tail_);
    std::swap(size_, tmp.size_);
    return *this;
}

template<typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(DoublyLinkedList &&other) noexcept {
    if(this != &other) {
        clear();
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<typename T>
T &DoublyLinkedList<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = head_;
    for (size_t i = 0; i < index; ++i) {
        current = current->next_;
    }
    return current->data_;
}

template<typename T>
const T &DoublyLinkedList<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = head_;
    for (size_t i = 0; i < index; ++i) {
        current = current->next_;
    }
    return current->data_;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T &data) {
    auto* new_node = new Node<T>(data, nullptr, head_);
    if(head_) {
        head_->prev_ = new_node;
    } else {
        tail_ = new_node;
    }
    head_ = new_node;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T &&data) {
    auto* new_node = new Node<T>(std::move(data), nullptr, head_);
    if(head_) {
        head_->prev_ = new_node;
    } else {
        tail_ = new_node;
    }
    head_ = new_node;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T &data) {
    auto* new_node = new Node<T>(data, tail_, nullptr);
    if(tail_) {
        tail_->next_ = new_node;
    } else {
        head_ = new_node;
    }
    tail_ = new_node;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::push_back(T &&data) {
    auto* new_node = new Node<T>(std::move(data), tail_, nullptr);
    if(tail_) {
        tail_->next_ = new_node;
    } else {
        head_ = new_node;
    }
    tail_ = new_node;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if(size_ == 0) {
        throw std::runtime_error("Pop from empty list");
    } else {
        Node<T> *to_remove = head_;
        head_ = head_->next_;
        if (head_) {
            head_->prev_ = nullptr;
        } else {
            tail_ = nullptr;
        }
        delete to_remove;
        --size_;
    }
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if(size_ == 0) {
        throw std::runtime_error("Pop from empty list");
    } else {
        Node<T> *to_remove = tail_;
        tail_ = tail_->prev_;
        if (tail_) {
            tail_->next_ = nullptr;
        } else {
            head_ = nullptr;
        }
        delete to_remove;
        --size_;
    }
}

template<typename T>
T &DoublyLinkedList<T>::front() {
    return head_->data_;
}

template<typename T>
const T &DoublyLinkedList<T>::front() const {
    return head_->data_;
}

template<typename T>
T &DoublyLinkedList<T>::back() {
    return tail_->data_;
}

template<typename T>
const T &DoublyLinkedList<T>::back() const {
    return tail_->data_;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return size_ == 0;
}

template<typename T>
size_t DoublyLinkedList<T>::size() const {
    return size_;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::find(const T& value) const {
    for(auto it = begin(); it != end(); ++it) {
        if(*it == value) {
            return iterator(it.get_node());
        }
    }
    return end();
}

template<typename T>
DoublyLinkedList<T>::iterator DoublyLinkedList<T>::insert(DoublyLinkedList::iterator pos, const T &data) {
    if(pos == begin()) {
        push_front(data);
        return begin();
    } else if(pos == end()) {
        push_back(data);
        return end();
    } else {
        Node<T>* after = pos.get_node();
        Node<T>* before = after->prev_;
        auto* new_node = new Node<T>(data, before, after);
        before->next_ = new_node;
        after->prev_ = new_node;
        ++size_;
        return iterator(new_node);
    }
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::erase(DoublyLinkedList::iterator pos) {
    if (pos == end()) {
        return end();
    }

    Node<T>* to_remove = pos.get_node();
    Node<T>* next = to_remove->next_;

    if (to_remove == head_) {
        head_ = next;
        if (head_) {
            head_->prev_ = nullptr;
        } else {
            tail_ = nullptr;
        }
    } else {
        to_remove->prev_->next_ = next;
        if (next) {
            next->prev_ = to_remove->prev_;
        } else {
            tail_ = to_remove->prev_;
        }
    }

    delete to_remove;
    --size_;

    return iterator(next);
}

template<typename T>
DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return DoublyLinkedList::iterator(head_);
}

template<typename T>
DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return DoublyLinkedList::iterator(nullptr);
}

template<typename T>
DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::cbegin() const {
    return DoublyLinkedList::const_iterator(head_);
}

template<typename T>
DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::cend() const {
    return DoublyLinkedList::const_iterator(nullptr);
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list) {
    os << "[";
    if (!list.empty()) {
        auto it = list.cbegin();
        os << *it;
        ++it;
        for (; it != list.cend(); ++it) {
            os << ", " << *it;
        }
    }
    os << "]";
    return os;
}

