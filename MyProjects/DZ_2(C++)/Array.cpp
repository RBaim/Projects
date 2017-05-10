#include <exception>

#include "Array.h"
#include "bitstring.h"
#include "Exc.h"

int Array::maxlenght = 3;

int Array::radix = 10;

Array::Array() {
    array = new unsigned char[maxlenght];
    lenght = 0;
    Clean();
}

Array::Array(int size_arr, int start) {
    if (size_arr > maxlenght) throw ErrorSizeLimit();
    array = new unsigned char[maxlenght];
    if (size_arr < 0) throw ErrorSizeArray();
    lenght = size_arr;
    for (int i = 0; i < maxlenght; i++)
        array[i] = start;
}

Array::Array(const Array &a) {
    array = new unsigned char[maxlenght];
    lenght = a.lenght;
    for (int i = 0; i < lenght; i++)
        array[i] = a.array[i];
}

void Array::InputVal(int num) {
    if (num < 0) throw ErrorNumWrite();
    int numc = num;
    int count = 0;
    while (numc != 0) {
        count++;
        numc /= 10;
    }
    if (count > Array::maxlenght) throw ErrorSizeLimit();
        for (int i = count - 1; i >= 0; i--) {
        array[i] = num % 10;
        num /= 10;
    }
    lenght = count;
}

int Array::getlen() const {
    return lenght;
}

unsigned char& Array::operator [] (int i) const {
    if (i < 0 || i >= lenght) {
        throw ErrorIndexArray(i);
    }
    return array[i];
}

Array::~Array() {
    delete[] array;
    lenght = 0;
}

Array Array::operator + (const Array& a) {
    Array res;
    int size1 = a.lenght, size2 = this->lenght;
    int sizemax, work, raz = 0;
    if (size1 > size2) {
        sizemax = size1;
    }
    else {
        sizemax = size2;
    }
    res.lenght = sizemax;
    for (int i = size1 - 1, j = size2 - 1, k = sizemax - 1; i >= 0, j >= 0; i--, j--, k--) {
        res.array[k] = (a.array[i] + this->array[j] + raz) % (Array::radix);
        work = a.array[i] + this->array[j] + raz;
        raz = 0;
        if (work >= Array::radix) {
            if (k == 0) {
                if (res.lenght + 1 > Array::maxlenght) throw ErrorSizeLimit();
                res.operator >> (1);
                k++;
            }
            while (work >= Array::radix) {
                raz += 1;
                work -= Array::radix;
            }
        }
    }
    if (raz != 0)
        res.array[0] = raz;
    return res;
}

void Array::Clean() {
    for (int i = 0; i < lenght; i++)
        array[i] = 0;
}

void Array::operator >> (int i) {
    unsigned char *tmp = new unsigned char[lenght + i];
    for (int j = 0; j < i; j++)
        tmp[j] = 0;
    for (int j = i; j < lenght + i; j++)
        tmp[j] = (int)array[j - i];
    lenght += i;
    for (int j = 0; j < lenght; j++)
        this->operator[](j) = (int)tmp[j];
    delete[] tmp;
}

Array& Array::operator = (const Array& a) {
    if (this != &a) {
        lenght = a.lenght;
        for (int i = 0; i < lenght; i++)
            array[i] = a.array[i];
    }
    return *this;
}

std::ostream& operator << (std::ostream& stream, const Array& obj) {
    for (int i = 0; i < obj.lenght; i++)
        std::cout << (int)obj.array[i] << " ";
    return stream;
}

std::istream& operator >> (std::istream& stream, Array& obj) {
    int input;
    for (int i = 0; i < obj.lenght; i++) {
        std::cin >> input;
        obj.array[i] = input;
    }
    if (typeid(obj) == typeid(BitString)) {
        for (int i = 0; i < obj.lenght; i++)
            if (((int)obj.array[i]) >= 2 || ((int)obj.array[i]) < 0)
                throw ErrorWriteBit();
    }
    for (int i = 0; i < obj.lenght; i++)
        if (((int)obj.array[i]) >= 10 || ((int)obj.array[i]) < 0)
            throw ErrorWriteArr();
    return stream;
}

int Array::ToInt() const {
    int res = 0;
    for (int i = 0; i < lenght; i++)
        res += (int)pow(10, i) * (int)array[lenght - 1 -i];
    return res;
}

void Array::NewSize(int size_arr) {
    if (size_arr < 0) throw ErrorSizeArray();
    if(size_arr > maxlenght) throw ErrorSizeLimit();
    lenght = size_arr;
}
