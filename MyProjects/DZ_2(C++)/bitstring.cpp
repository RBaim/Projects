#include "bitstring.h"
#include "Exc.h"

BitString::BitString():Array() {}

BitString::BitString(int lenght) : Array(lenght) {
    if (lenght > maxlenght) throw ErrorSizeLimit();
}

BitString::BitString(const BitString& p_bst) : Array(p_bst) {}

void BitString::operator >> (int i) {//сдвиг вправо
    if (i < 0) {
        operator << (-i);
    }
    else {
        for (int c = 0; c < i; c++) {
            for (int j = getlen() - 1; j > 0; j--) {
                array[j] = (int)array[j - 1];
            }
            array[0] = 0;
        }
    }
 }

void BitString::operator << (int i) {//сдвиг влево
    if (i < 0) {
        operator >> (-i);
    }
    else {
        for (int c = 0; c < i; c++) {
            for (int j = 0; j < lenght - 1; j++) {
                array[j] = (int)array[j + 1];
            }
            array[lenght - 1] = 0;
        }
    }
}

BitString operator & (const BitString& op1, const BitString& op2) {//и
    if (op1.lenght != op2.lenght)
        throw ErrorOperBit();
    BitString res(op1.lenght);
    for (int i = 0; i < op1.lenght; i++) {
        if (op1.array[i] == 1 && op1.array[i] == op2.array[i])
            res.array[i] = 1;
    }
    return res;
}

BitString operator | (const BitString& op1, const BitString& op2) {//или
    if (op1.lenght != op2.lenght)
        throw ErrorOperBit();
    BitString res(op1.lenght);
    for (int i = 0; i < op1.lenght; i++) {
        if (op1.array[i] == 1 || op2.array[i] == 1)
            res.array[i] = 1;
    }
    return res;
}

BitString operator ^ (const BitString& op1, const BitString& op2) {//исключающее или
    if (op1.lenght != op2.lenght)
        throw ErrorOperBit();
    BitString res(op1.lenght);
    for (int i = 0; i < op1.lenght; i++) {
        if ((op1.array[i] == 1 || op2.array[i] == 1) && op1.array[i] != op2.array[i])
            res.array[i] = 1;
    }
    return res;
}

BitString operator ~ (const BitString& op) {//не
    BitString res(op.lenght);
    for (int i = 0; i < op.lenght; i++) {
        if (op.array[i] == 1) {
            res.array[i] = 0;
        } else {
           res.array[i] = 1;
        }
    }
    return res;
}

Array BitString::operator + (const Array& a) {
    BitString res;
    if (lenght != a.getlen())
        throw ErrorOperBit();
    res.lenght = lenght;
    for (int i = 0; i < lenght; i++)
        res.array[i] = (int(a[i]) + (int)array[i]) % 2;
    return res;
}
