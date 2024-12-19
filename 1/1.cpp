#include <iostream>
#include <initializer_list>
#include <stdexcept> 
using namespace std;
namespace containers {

    template <typename T>
    class DList {
    public:
        
        struct Node {
            T value;          
            Node* next;       
            Node* prev;        

           
        private:
            Node(const T& val) : value(val), next(nullptr), prev(nullptr) {}
            Node(T&& val) : value( move(val)), next(nullptr), prev(nullptr) {}

            friend class DList<T>;  
        };

       
        DList() : head(nullptr), tail(nullptr), size(0) {}

       
        DList( initializer_list<T> init) : DList() {
            for (const auto& elem : init) {
                push_back(elem);
            }
        }

       
        DList(const DList& other) : DList() {
            Node* current = other.head;
            while (current) {
                push_back(current->value);
                current = current->next;
            }
        }

        
        DList& operator=(const DList& other) {
            if (this != &other) {
                clear();
                Node* current = other.head;
                while (current) {
                    push_back(current->value);
                    current = current->next;
                }
            }
            return *this;
        }

        
        DList(DList&& other) noexcept : head(other.head), tail(other.tail), size(other.size) {
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }

       
        DList& operator=(DList&& other) noexcept {
            if (this != &other) {
                clear();
                head = other.head;
                tail = other.tail;
                size = other.size;

                other.head = nullptr;
                other.tail = nullptr;
                other.size = 0;
            }
            return *this;
        }

       
        T& operator[](size_t index) {
            return at(index);  
        }

       
        T& at(size_t index) {
            if (index >= size) {
                throw  out_of_range("Index out of range");
            }
            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }

        
        void push_back(const T& value) {
            Node* newNode = new Node(value);
            if (!tail) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            ++size;
        }

        
        void push_front(const T& value) {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            ++size;
        }

        
        void insert(size_t index, const T& value) {
            if (index == 0) {
                push_front(value);
            }
            else if (index >= size) {
                push_back(value);
            }
            else {
                Node* current = head;
                for (size_t i = 0; i < index; ++i) {
                    current = current->next;
                }
                Node* newNode = new Node(value);
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                ++size;
            }
        }

      
        void pop_back() {
            if (tail) {
                Node* temp = tail;
                if (tail->prev) {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    head = tail = nullptr;
                }
                delete temp;
                --size;
            }
        }

       
        void pop_front() {
            if (head) {
                Node* temp = head;
                if (head->next) {
                    head = head->next;
                    head->prev = nullptr;
                }
                else {
                    head = tail = nullptr;
                }
                delete temp;
                --size;
            }
        }

       
        void erase(size_t index) {
            if (index < size) {
                if (index == 0) {
                    pop_front();
                }
                else if (index == size - 1) {
                    pop_back();
                }
                else {
                    Node* current = head;
                    for (size_t i = 0; i < index; ++i) {
                        current = current->next;
                    }
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    --size;
                }
            }
        }

       
        void clear() {
            while (head) {
                pop_front();
            }
        }

        
        size_t get_size() const {
            return size;
        }

        
        T& front() {
            if (head) return head->value;
            throw  out_of_range("List is empty");
        }

        
        T& back() {
            if (tail) return tail->value;
            throw  out_of_range("List is empty");
        }

       
        ~DList() {
            clear();
        }

    private:
        Node* head;  
        Node* tail; 
        size_t size; 
    };

}

int main() {
    using namespace containers;

   
    DList<int> list1 = { 1, 2, 3, 4, 5 };
    DList<double> list2 = { 1.1, 2.2, 3.3 };
    DList< string> list3 = { "Hello", "World" };

    
     cout << "List1 (int): ";
    for (size_t i = 0; i < list1.get_size(); ++i) {
         cout << list1[i] << " ";  
    }
     cout << "\n";

    
     cout << "List2 (double): ";
    for (size_t i = 0; i < list2.get_size(); ++i) {
         cout << list2[i] << " ";
    }
     cout << "\n";

  
     cout << "List3 (string): ";
    for (size_t i = 0; i < list3.get_size(); ++i) {
         cout << list3[i] << " ";
    }
     cout << "\n";

   
    list1.push_back(6);
    list2.insert(1, 2.5);
    list3.pop_back();

     cout << "After push_back(6), list1: ";
    for (size_t i = 0; i < list1.get_size(); ++i) {
         cout << list1[i] << " ";
    }
     cout << "\n";

     cout << "After insert(1, 2.5), list2: ";
    for (size_t i = 0; i < list2.get_size(); ++i) {
         cout << list2[i] << " ";
    }
     cout << "\n";

     cout << "After pop_back(), list3: ";
    for (size_t i = 0; i < list3.get_size(); ++i) {
         cout << list3[i] << " ";
    }
     cout << "\n";

    return 0;
}
