#ifndef A_HPP
#define A_HPP

#include <iostream>
#include <vector>
#include "Node.hpp"
#include "SmartPointer.hpp"
#include "PositiveIterator.hpp"
#include "NegativeIterator.hpp"
#include "CustomException.hpp"
using namespace std;
template <typename T>
class A {
private:
    vector<SmartPointer<Node<T>>> nodes;

public:
    A() = default;

    void addNode(T value) {
        nodes.push_back(SmartPointer<Node<T>>(new Node<T>(value)));
    }

    void display() const {
        for (const auto& node : nodes) {
            if (node) {
                cout << "Value: " << node->value << endl;
            }
        }
    }

    PositiveIterator<T> beginPositive() {
        return PositiveIterator<T>(nodes.begin(), nodes.end());
    }

    PositiveIterator<T> endPositive() {
        return PositiveIterator<T>(nodes.end(), nodes.end());
    }

    NegativeIterator<T> beginNegative() {
        return NegativeIterator<T>(nodes.begin(), nodes.end());
    }

    NegativeIterator<T> endNegative() {
        return NegativeIterator<T>(nodes.end(), nodes.end());
    }
};

#endif // A_HPP
