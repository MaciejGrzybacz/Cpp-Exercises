#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <cstddef>
#include <type_traits>
#include <stdexcept>


template <typename T>
concept Numerical = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Numerical T>
class Vector {
private:
    T *data_;
    size_t size_;

public:
    Vector() : data_(nullptr), size_(0) {}
    explicit Vector(size_t size) : size_(size) {
        data_ = new T[size_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = T();
        }
    }
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(T scalar) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T euclideanLength() const;
    [[nodiscard]] size_t size() const;
    T dotProduct(const Vector& other) const;
};

template<Numerical T>
Vector<T>::Vector(std::initializer_list<T> list) : size_(list.size()) {
    data_ = new T[size_];
    size_t i = 0;
    for (const auto& elem : list) {
        data_[i++] = elem;
    }
}

template<Numerical T>
Vector<T>::Vector(const Vector<T>& other) : size_(other.size_) {
    data_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<Numerical T>
Vector<T>::Vector(Vector<T>&& other) noexcept : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
}

template<Numerical T>
Vector<T>::~Vector() {
    delete[] data_;
}

template<Numerical T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<Numerical T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<Numerical T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector sizes do not match");
    }
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.data_[i] = data_[i] + other.data_[i];
    }
    return result;
}

template<Numerical T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector sizes do not match");
    }
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.data_[i] = data_[i] - other.data_[i];
    }
    return result;
}

template<Numerical T>
Vector<T> Vector<T>::operator*(T scalar) const {
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result.data_[i] = data_[i] * scalar;
    }
    return result;
}

template<Numerical T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

template<Numerical T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

template<Numerical T>
T Vector<T>::euclideanLength() const {
    T sum = 0;
    for (size_t i = 0; i < size_; ++i) {
        sum += data_[i] * data_[i];
    }
    return sqrt(sum);
}

template<Numerical T>
T Vector<T>::dotProduct(const Vector<T>& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector sizes do not match");
    }
    T result = 0;
    for (size_t i = 0; i < size_; ++i) {
        result += data_[i] * other.data_[i];
    }
    return result;
}

template<Numerical T>
size_t Vector<T>::size() const {
    return size_;
}

#endif // VECTOR_H
