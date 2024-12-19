#include <iostream>
#include <string>
#include "A.hpp"
#include "ExceptionHandler.hpp"
using namespace std;
void displayMenu() {
    cout << "Меню:\n";
    cout << "1. Работа с int\n";
    cout << "2. Работа с double\n";
    cout << "3. Работа с string\n";
    cout << "4. Выход\n";
}

template <typename T>
void testTemplate() {
    try {
        T value;
        cout << "Введите значение: ";
        cin >> value;

        // Очистка буфера ввода для предотвращения проблем с getline
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        A<T> a(value);
        a.display();

        // Добавить тесты для всех методов класса A
    }
    catch (const exception& e) {
        ExceptionHandler::handleException(e);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            testTemplate<int>();
            break;
        case 2:
            testTemplate<double>();
            break;
        case 3:
            testTemplate<std::string>();
            break;
        case 4:
            cout << "Выход" << endl;
            break;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
    return 0;
}
