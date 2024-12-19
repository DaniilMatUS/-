#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <stdexcept>
#include <string>
using namespace std;
class CustomException : public  runtime_error {
public:
    explicit CustomException(const  string& message) :  runtime_error(message) {}
};

#endif // CUSTOMEXCEPTION_HPP
