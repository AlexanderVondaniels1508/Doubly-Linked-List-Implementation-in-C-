#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <stdexcept>

using std::exception;
using std::string;
using std::out_of_range;
using std::bad_alloc;
using std::logic_error;

class LinkedListMainError : public exception {
public:
    LinkedListMainError() = default;
    
    explicit LinkedListMainError(const string& message) 
        : message(message) 
    { }

    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class LinkedListIndexError : public out_of_range {
public:
    LinkedListIndexError() = default;

    explicit LinkedListIndexError(const string& message) 
        : out_of_range(message) 
    { }
    
};

class LinkedListMemoryError : public bad_alloc {
public:
    LinkedListMemoryError() = default;
    
    explicit LinkedListMemoryError(const string& message) 
        : bad_alloc(), message(message) 
    { }

    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class LinkedListEmptyError : public logic_error {
public:
    LinkedListEmptyError() = default;
    
    explicit LinkedListEmptyError(const string& message) 
        : logic_error(message) 
    { }
};

#endif // EXCEPTIONS_H