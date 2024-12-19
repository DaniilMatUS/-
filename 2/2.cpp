#include <iostream>
#include <cmath>
#include <exception>
#include <string>
using namespace std;
class CustomException : public  exception {
public:
    CustomException(const  string& message, double value, int code)
        : message_(message), value_(value), code_(code) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    double getValue() const {
        return value_;
    }

    int getCode() const {
        return code_;
    }

private:
     string message_;
    double value_;
    int code_;
};

double calculateZ1(double m) {
    if (m < 0) {
        throw CustomException("Negative value under square root", m, 1);
    }
    return sqrt((3 * m + 2) * (3 * m + 2) - 24 * m) / (3 * sqrt(m) - 2/ sqrt(m));
}

double calculateZ2(double m) {
    if (m < 0) {
        throw CustomException("Negative value under square root", m, 1);
    }
    return -sqrt(m);
}

int main() {
    double m;
     cout << "Enter value for m: ";
     cin >> m;

    try {
        double z1 = calculateZ1(m);
        double z2 = calculateZ2(m);
         cout << "Z1 = " << z1 <<  endl;
         cout << "Z2 = " << z2 <<  endl;
    }
    catch (const CustomException& e) {
         cerr << "Error: " << e.what() <<  endl;
         cerr << "Value: " << e.getValue() <<  endl;
         cerr << "Code: " << e.getCode() <<  endl;
    }

    return 0;
}
