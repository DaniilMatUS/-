#ifndef NEGATIVEITERATOR_HPP
#define NEGATIVEITERATOR_HPP

#include <vector>
#include "SmartPointer.hpp"
#include "Node.hpp"
#include "CustomException.hpp"
using namespace std;
template <typename T>
class NegativeIterator {
private:
    typename vector<SmartPointer<Node<T>>>::iterator it;
    typename vector<SmartPointer<Node<T>>>::iterator end;

    void advanceToValid() {
        while (it != end && (*it)->value >= 0) {
            ++it;
        }
    }

public:
    NegativeIterator(typename vector<SmartPointer<Node<T>>>::iterator it,
        typename vector<SmartPointer<Node<T>>>::iterator end)
        : it(it), end(end) {
        advanceToValid();
    }

    NegativeIterator& operator++() {
        ++it;
        advanceToValid();
        return *this;
    }

    bool operator!=(const NegativeIterator& other) const {
        return it != other.it;
    }

    T& operator*() {
        if (it == end) throw CustomException("Out of bounds access");
        return (*it)->value;
    }
};

#endif // NEGATIVEITERATOR_HPP
