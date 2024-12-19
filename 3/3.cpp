#include <iostream>
#include <string>
using namespace std;
template <typename T>
class ScPtr {
public:
    
    explicit ScPtr(T* ptr = nullptr) : ptr_(ptr) {}

  
    ~ScPtr() {
        delete ptr_;
    }

    
    ScPtr(const ScPtr&) = delete;
    ScPtr& operator=(const ScPtr&) = delete;

    
    ScPtr(ScPtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    
    ScPtr& operator=(ScPtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    
    T* get() const {
        return ptr_;
    }

    
    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    
    void swap(ScPtr& other) noexcept {
       swap(ptr_, other.ptr_);
    }

    
    T& operator*() const {
        return *ptr_;
    }

    
    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
};

int main() {
    
    ScPtr<int> intPtr(new int(10));
   cout << "Int value: " << *intPtr <<endl;

    
    ScPtr<double> doublePtr(new double(5.5));
   cout << "Double value: " << *doublePtr <<endl;

    
    ScPtr<std::string> stringPtr(new string("Hello, World!"));
   cout << "String value: " << *stringPtr <<endl;

   
    intPtr.reset(new int(20));
   cout << "New Int value: " << *intPtr <<endl;

    ScPtr<int> anotherIntPtr(new int(30));
    intPtr.swap(anotherIntPtr);
   cout << "Swapped Int value: " << *intPtr <<endl;

    return 0;
}
