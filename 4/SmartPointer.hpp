#ifndef SMARTPOINTER_HPP
#define SMARTPOINTER_HPP

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    operator bool() const { return ptr != nullptr; }

    // Другие методы для управления умным указателем, если необходимо
};

#endif // SMARTPOINTER_HPP
