#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {
    T value;
    Node* prev;
    Node* next;

    Node(T val) : value(val), prev(nullptr), next(nullptr) {}
};

#endif // NODE_HPP
