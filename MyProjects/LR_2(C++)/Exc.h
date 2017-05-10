#pragma once

#include <exception>

class ErrorIndex : public std::exception {
public:
    int errorind;
    ErrorIndex(int i) {
        errorind = i;
    }
    virtual const char* what() const throw() {
        return "Неверный индекс! ";
    }
};

class ErrorMalVec : public std::exception {
public:
    int errordem1, errordem2;
    ErrorMalVec(int i, int j) {
        errordem1 = i;
        errordem2 = j;
    }
    virtual const char* what() const throw() {
        return "Размерность векторов отличная от 3 ";
    }
};