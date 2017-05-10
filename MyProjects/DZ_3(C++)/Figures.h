#pragma once

#include <iostream>

class Figure {
public:
    double Square_d;
    double Perimeter_d;
    Figure();
    static Figure* make(int ind);
    static void Destroy(Figure*& obj);
    virtual double Square(void) = 0;
    virtual void Out();
    virtual void Input(void) = 0;
    virtual double Perimeter(void) = 0;
};
