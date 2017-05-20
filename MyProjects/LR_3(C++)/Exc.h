#pragma once

#include <string.h>

class Exc {
protected:
    int num_error;
    char error_str[100];
public:
    Exc() {
        num_error = 0;
        error_str[0] = '\0';
    }
    Exc(int error_p, const char* message) {
        num_error = error_p;
        strcpy(error_str, message);
    }
    virtual void Info() {
        std::cout << "Error " << num_error << std::endl << error_str << std::endl;
    }
};

class ErrorIndexArray : public Exc {
    int error_index;
public:
    ErrorIndexArray(){}
    ErrorIndexArray(int i_e) {
        error_index = i_e;
        num_error = 200;
        strcpy(error_str, "Not found index ");
    }
    void Info() {
        Exc::Info();
        std::cout << error_index << std::endl;
    }
};
