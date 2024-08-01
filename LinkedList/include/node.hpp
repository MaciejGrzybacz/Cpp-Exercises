#include <memory>

template<typename T>
class Node {
public:
    T data_;
    Node<T>* prev_;
    Node<T>* next_;

    explicit Node(const T& data) : data_(data), prev_(nullptr), next_(nullptr) {}
    explicit Node(T&& data) : data_(std::move(data)), prev_(nullptr), next_(nullptr) {}

    Node(const T& data, Node<T>* prev, Node<T>* next)
            : data_(data), prev_(prev), next_(next) {}

    Node(T&& data, Node<T>* prev, Node<T>* next)
            : data_(std::move(data)), prev_(prev), next_(next) {}

    ~Node() = default;

    Node(const Node&) = default;
    Node& operator=(const Node&) = default;
    Node(Node&&) = default;
    Node& operator=(Node&&) = default;
};