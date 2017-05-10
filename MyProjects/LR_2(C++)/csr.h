#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

#include "vector.h"

class CSR {
    double *aelem;
    int *jptr;
    int *iptr;
    int lenght;
    int size;
    void NewMem(int a_size_not_nil, int size_matrix);
public:
    ~CSR();
    CSR(int a_size_not_nil = 3, int size_matrix = 3, double start = 1);
    CSR(const CSR& matrix);
    friend CSR operator*(const CSR& matrix, double l);
    friend CSR operator*(double l, const CSR& matrix);
    friend Vector operator*(const CSR& matrix, const Vector& vec);
    int GetSize();
    int GetLenght();
    friend std::ostream& operator << (std::ostream& stream, const CSR& obj);
    friend std::istream& operator >> (std::istream& stream, CSR& obj);
};
