#pragma once

#include <iostream>

class Array {
protected:
    unsigned char *array;
    void Clean();
    int lenght;
    int ToInt() const;
    void operator >> (int i);
    static int radix;
    static int maxlenght;
public:
    Array();
    Array(int size_arr, int start = 0);
    Array(const Array& a);
    void InputVal(int num);
    void NewSize(int size_arr);
    int getlen() const;
    unsigned char& operator [] (int i) const;
    virtual ~Array();
    virtual Array operator + (const Array& a);
    virtual Array& operator = (const Array &a);
    friend std::ostream& operator << (std::ostream& stream, const Array& obj);
    friend std::istream& operator >> (std::istream& stream, Array& obj);
};
