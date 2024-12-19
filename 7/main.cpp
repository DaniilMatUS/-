#include <iostream>
#include "A.hpp"
#include "CustomException.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL,"RU");
    try {
        A<int> collection;
        collection.addNode(-5);
        collection.addNode(10);
        collection.addNode(-3);
        collection.addNode(8);
        collection.addNode(0);

        cout << "Массив:" << endl;
        collection.display();
       
        cout << "Положительные элементы:\n";
        for (auto it = collection.beginPositive(); it != collection.endPositive(); ++it) {
        cout << *it << endl;
        }

        cout << "\nОтрицательные элементы:\n";
        for (auto it = collection.beginNegative(); it != collection.endNegative(); ++it) {
        cout << *it << endl;
        }
    }
    catch (const CustomException& e) {
    cerr << "CustomException: " << e.what() << endl;
    }
    catch (const      exception& e) {
    cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
