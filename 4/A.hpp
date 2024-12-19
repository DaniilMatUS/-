#ifndef A_HPP
#define A_HPP

#include <iostream>
#include "Node.hpp"
#include "SmartPointer.hpp"
using namespace std;
template <typename T>
class A {
private:
    SmartPointer<Node<T>> nodePtr;

public:
    A(T value) : nodePtr(new Node<T>(value)) {}

    void display() const {
        if (nodePtr) {
            cout << "Value: " << nodePtr->value << endl;
        }
        else {
            cout << "Pointer is null" << endl;
        }
    }

    // Другие методы...
};

#endif // A_HPP
