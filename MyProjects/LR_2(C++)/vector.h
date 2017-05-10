#pragma once

#include <iostream>

#include "Exc.h"

class Vector {
    double *array;
    int lenght;
    void NewMem(int lenght);
public:
    ~Vector();
    Vector(const Vector& vec);
    Vector(int lenght = 3, double start = 0);
    Vector& operator=(const Vector& vec);
    friend Vector operator+(const Vector& vec1, const Vector& vec2);
    friend Vector operator*(const Vector& vec1, const Vector& vec2);
    friend Vector operator*(const Vector& vec, double l);
    friend Vector operator*(double l, const Vector& vec);
    friend double operator&(const Vector& vec1, const Vector& vec2);
    Vector operator+();
    Vector operator-();
    double& operator[](int i);
    double lenght_vect_g() const;
    int GetSize() const;
    Vector operator+=(const Vector& vec);
    Vector operator-=(const Vector& vec);
    friend std::ostream& operator << (std::ostream &stream, const Vector &obj);
    friend std::istream& operator >> (std::istream &stream, Vector &obj);
};
