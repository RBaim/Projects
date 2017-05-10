#pragma once

#include "array.h"

class Fraction : public Array {
    unsigned char* array_f;
    int lenght_f;
    void NOD();
    int ToInt_f() const;
public:
    Fraction(int size_a = 1, int start = 1);
    Fraction(const Fraction& p_fr);
    void InputVals(int num_1, int num_2);
    Fraction operator + (const Fraction& op1);
    friend Fraction operator - (const Fraction& op1, const Fraction& op2);
    friend Fraction operator * (const Fraction& op1, const Fraction& op2);
    Fraction& operator = (const Fraction& op);
    friend bool operator > (const Fraction& op1, const Fraction& op2);
    friend bool operator < (const Fraction& op1, const Fraction& op2);
    friend bool operator == (const Fraction& op1, const Fraction& op2);
    friend bool operator >= (const Fraction& op1, const Fraction& op2);
    friend bool operator <= (const Fraction& op1, const Fraction& op2);
    friend std::ostream& operator << (std::ostream& stream, const Fraction& obj);
    friend std::istream& operator >> (std::istream& stream, Fraction& obj);
};
