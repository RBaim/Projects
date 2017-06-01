#pragma once

#include "fraction.h"

class Exc {
protected:
    int num_error;
    char *error_str;
public:
    virtual void Info() {
        std::cout << "Error " << num_error << std::endl << error_str << std::endl;
    }
};

class ErrorMinusFraction : public Exc {
    int f11, f12, f21, f22;
public:
    ErrorMinusFraction(int f11_p, int f12_p, int f21_p, int f22_p) {
        f11 = f11_p; f12 = f12_p; f21 = f21_p; f22 = f22_p;
        error_str = "ƒробь не может быть представлена отрицательной ";
        num_error = 101;
    }
    void Info() {
        Exc::Info();
        std::cout << f11 << '/' << f12 << " - " << f21 << '/' << f22 << " < 0" << std::endl;
    }
};

class ErrorIndexArray : public Exc {
    int error_index;
public:
    ErrorIndexArray(int i_e) {
        error_index = i_e;
        num_error = 200;
        error_str = "»ндекса не существует в данном массиве ";
    }
    void Info() {
        Exc::Info();
        std::cout << error_index << std::endl;
    }
};

class DevNilFraction : public Exc {
    int op1;
public:
    DevNilFraction(int op1_p) {
        op1 = op1_p;
        error_str = "«наменатель с нулем ";
        num_error = 311;
    }
    void Info() {
        Exc::Info();
        std::cout << op1 << '/' << 0 << std::endl;
    }
};

class ErrorSizeArray {
public:
    void ErrorInfo() {
        std::cout << "–азмер массива должен быть больше 0" << std::endl;
    }
};

class ErrorNumWrite : public std::exception {
public:
    virtual const char* what() const throw() {
        return "„исло записываемое в массив должно быть больше 0";
    }
};

class ErrorWriteBit : public Exc {
public:
    ErrorWriteBit() {
        num_error = 276;
        error_str = "ћассив бит не может содержать значени€ меньше 0 и 1";
    }
    void Info() {
        Exc::Info();
    }
};

class ErrorWriteArr : public Exc {
public:
    ErrorWriteArr() {
        num_error = 100;
        error_str = "ћассив не может содержать значени€ меньше 0 и больше 10";
    }
    void Info() {
        Exc::Info();
    }
};

class ErrorSizeLimit : public Exc {
public:
    ErrorSizeLimit() {
        num_error = 111;
        error_str = "ѕревышен максимальный размер массива";
    }
    void Info() {
        Exc::Info();
    }
};

class ErrorOperBit : public Exc {
public:
    ErrorOperBit() {
        num_error = 231;
        error_str = "Ќесовпадение количества бит";
    }
    void Info() {
        Exc::Info();
    }
};
