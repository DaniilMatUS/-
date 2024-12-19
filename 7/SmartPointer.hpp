#ifndef SMARTPOINTER_HPP
#define SMARTPOINTER_HPP
using namespace std;
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

    // Добавим конструктор копирования и оператор присваивания
    SmartPointer(const SmartPointer& other) = delete;
    SmartPointer& operator=(const SmartPointer& other) = delete;

    // Добавим конструктор перемещения и оператор перемещающего присваивания
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

#endif // SMARTPOINTER_HPP
