#pragma once

#include "Array.h"

class BitString : public Array {
public:
    BitString();
    BitString(int lenght);
    BitString(const BitString& p_bst);
    Array operator + (const Array& op);
    friend BitString operator & (const BitString& op1, const BitString& op2);
    friend BitString operator | (const BitString& op1, const BitString& op2);
    friend BitString operator ^ (const BitString& op1, const BitString& op2);
    friend BitString operator ~ (const BitString& op);
    void operator >> (int i);
    void operator << (int i);
};
