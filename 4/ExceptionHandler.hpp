#ifndef EXCEPTIONHANDLER_HPP
#define EXCEPTIONHANDLER_HPP

#include <stdexcept>
#include <iostream>
using namespace std;
class ExceptionHandler {
public:
    static void handleException(const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
};

#endif // EXCEPTIONHANDLER_HPP
