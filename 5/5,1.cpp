#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

int main() {
   string input;
    double value;
    char unit;

  cout << "Введите температуру (например, 59F или 15C): ";
    cin >> value >> unit;

    if (unit == 'F' || unit == 'f') {
        double celsius = fahrenheitToCelsius(value);
        cout <<fixed << setprecision(4) << setw(10) << setfill('\\')
            << value << " F = " << setw(10) << setfill('\\') << celsius << " C" << endl;
    }
    else if (unit == 'C' || unit == 'c') {
        double fahrenheit = celsiusToFahrenheit(value);
        cout << fixed << setprecision(4) << setw(10) << setfill('\\')
            << value << " C = " << setw(10) << setfill('\\') << fahrenheit << " F" << endl;
    }
    else {
        cerr << "Неверный формат ввода. Используйте 'F' для Фаренгейта и 'C' для Цельсия." << endl;
    }

    return 0;
}
