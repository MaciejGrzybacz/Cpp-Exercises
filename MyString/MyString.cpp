#include "MyString.h"

MyString::MyString() : size_(0), data_(nullptr) {}

MyString::MyString(size_t size) : size_(size), data_(std::make_unique<char[]>(size)) {}

MyString::MyString(size_t size, char default_val) : size_(size), data_(std::make_unique<char[]>(size)) {
    std::fill_n(data_.get(), size, default_val);
}

MyString::MyString(std::string_view str) : size_(str.size()), data_(std::make_unique<char[]>(str.size())) {
    std::copy(str.begin(), str.end(), data_.get());
}

MyString::MyString(const MyString &other) : size_(other.size_), data_(std::make_unique<char[]>(other.size_)) {
    std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
}

MyString::MyString(MyString &&other) noexcept : size_(other.size_), data_(std::move(other.data_)) {
    other.size_ = 0;
}

MyString &MyString::operator=(const MyString &other) {
    size_ = other.size_;
    data_ = std::make_unique<char[]>(other.size_);
    std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
    return *this;
}

MyString &MyString::operator=(MyString &&other) noexcept {
    size_ = other.size_;
    data_ = std::make_unique<char[]>(other.size_);
    std::move(other.data_.get(), other.data_.get() + other.size_, data_.get());
    other.size_ = 0;
    return *this;
}

MyString MyString::operator+(const MyString &other) const {
    MyString result(size_ + other.size_);
    result.data_ = std::make_unique<char[]>(size_ + other.size_);
    std::copy(data_.get(), data_.get() + size_, result.data_.get());
    std::copy(other.data_.get(), other.data_.get() + other.size_, result.data_.get() + size_);
    return result;
}

MyString &MyString::operator+=(const MyString &other) {
    size_ += other.size_;
    std::unique_ptr<char[]> new_data = std::make_unique<char[]>(size_);
    std::copy(data_.get(), data_.get() + size_, new_data.get());
    std::copy(other.data_.get(), other.data_.get() + other.size_, new_data.get() + size_);
    data_ = std::move(new_data);
    return *this;
}

MyString MyString::operator*(int count) const {
    if (count < 0) {
        throw std::invalid_argument("Count should be non-negative");
    }

    MyString result(size_ * count);
    result.data_ = std::make_unique<char[]>(size_ * count);
    for (int i = 0; i < count; i++) {
        std::copy(data_.get(), data_.get() + size_, result.data_.get() + i * size_);
    }
    return result;
}

bool MyString::operator==(const char *str) const {
    return size_ == std::strlen(str) && std::equal(data_.get(), data_.get() + size_, str);
}

bool MyString::operator==(const MyString &other) const {
    return size_ == other.size_ && std::equal(data_.get(), data_.get() + size_, other.data_.get());
}

bool MyString::operator!=(const MyString &other) const {
    return !(*this == other);
}

bool MyString::operator>(const MyString &other) const {
    for(size_t i = 0; i < size_ && i < other.size_; i++) {
        if (data_[i] > other.data_[i]) {
            return true;
        }
    }
    return size_ > other.size_;
}

bool MyString::operator>=(const MyString &other) const {
    return *this == other || *this > other;
}

bool MyString::operator<(const MyString &other) const {
    for(size_t i = 0; i < size_ && i < other.size_; i++) {
        if (data_[i] < other.data_[i]) {
            return true;
        }
    }
    return size_ < other.size_;
}

bool MyString::operator<=(const MyString &other) const {
    return *this == other || *this < other;
}

const char &MyString::operator[](size_t index) const {
    if (index >= size_)
        throw std::out_of_range("Index out of range");

    return data_[index];
}

char &MyString::operator[](size_t index) {
    if (index >= size_)
        throw std::out_of_range("Index out of range");

    return data_[index];
}

MyString::operator std::string() const {
    return std::string(data_.get(), size_);
}

size_t MyString::length() const {
    return size_;
}

void MyString::append(const char *str) {
    size_t str_size = std::strlen(str);
    std::unique_ptr<char[]> new_data = std::make_unique<char[]>(size_ + str_size);
    std::copy(data_.get(), data_.get() + size_, new_data.get());
    std::copy(str, str + str_size, new_data.get() + size_);
    data_ = std::move(new_data);
    size_ += str_size;
}

void MyString::insert(char ch, size_t index) {
    if (index > size_)
        throw std::out_of_range("Index out of range");

    size_++;
    std::unique_ptr<char[]> new_data = std::make_unique<char[]>(size_);
    std::copy(data_.get(), data_.get() + index, new_data.get());
    new_data[index] = ch;
    std::copy(data_.get() + index, data_.get() + size_ - 1, new_data.get() + index + 1);
    data_ = std::move(new_data);
}

MyString MyString::substr(size_t begin, size_t end) const {
    if (begin > size_ || end > size_ || begin > end)
        throw std::out_of_range("Index out of range");

    MyString result(end - begin);
    result.data_ = std::make_unique<char[]>(end - begin);
    std::copy(data_.get() + begin, data_.get() + end, result.data_.get());
    return result;
}

std::unordered_map<char, int> MyString::count() const {
    std::unordered_map<char, int> counter;
    for (size_t i = 0; i < size_; i++) {
        counter[data_[i]]++;
    }
    return counter;
}

MyString MyString::unique() const {
    std::unordered_map<char, int> counter = count();
    MyString result(counter.size());
    result.data_ = std::make_unique<char[]>(counter.size());
    std::transform(counter.begin(), counter.end(), result.data_.get(), [](const auto &pair) { return pair.first; });
    return result;
}

MyString::iterator MyString::begin() {
    return {this, 0};
}

MyString::iterator MyString::end() {
    return {this, size_};
}

MyString::const_iterator MyString::cbegin() const {
    return {this, 0};
}

MyString::const_iterator MyString::cend() const {
    return {this, size_};
}

std::istream &operator>>(std::istream &is, MyString &str) {
    std::string temp;
    is >> temp;
    if (is) {
        str = MyString(temp);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
    for(size_t i = 0; i < str.size(); i++) {
        os << str[i];
    }
    return os;
}

size_t MyString::size() const {
    return size_;
}

