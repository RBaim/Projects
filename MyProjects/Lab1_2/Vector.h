#pragma once

#include <initializer_list>

#include "VectorIterator.h"
#include "Exc.h"
#include "Algorithm.h"

template <typename T>
class VectorIterator;

template <typename __DataType>
class Vector {
    __DataType *array;
    int size;
    int maxsize;
public:
    typedef VectorIterator<__DataType> iterator;
    typedef __DataType value_type;
    Vector(int lenght = 0);
    Vector(int lenght, __DataType start);
    Vector(std::initializer_list <__DataType> l);
    Vector(const Vector& c_vector);
    Vector(Vector&& c_vector);
    ~Vector();
    Vector& operator=(const Vector& c_vector);
    Vector& operator=(Vector&& c_vector);
    __DataType& operator[] (int i);
    iterator Begin();
    iterator End();
    iterator Insert(iterator pos, const __DataType &p_elem);
    void PushBack(__DataType elem);
    void PopBack();
    void Erase(iterator pos);
    void Reserve(int num);
    void Resize(int num);
    int Size() const;
    int Capacity() const;
    void Clear();
};

template <typename __DataType>
Vector<__DataType>::Vector(int lenght) {
    size = lenght;
    maxsize = size + 1;
    array = new __DataType[maxsize];
}

template <typename __DataType>
Vector<__DataType>::Vector(int lenght, __DataType start) {
    size = lenght;
    maxsize = size + 1;
    array = new __DataType[maxsize];
    for (int i = 0; i < maxsize; i++)
        array[i] = start;
}

template <typename __DataType>
Vector<__DataType>::Vector(std::initializer_list <__DataType> l) {
    size = l.size();
    maxsize = size + 1;
    array = new __DataType[maxsize];
    int i = 0;
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        array[i] = *(iter); 
        i++;
    }
}

template <typename __DataType>
Vector<__DataType>::~Vector() {
    Clear();
}

template <typename __DataType>
Vector<__DataType>::Vector(const Vector& c_vector) {
    size = c_vector.size;
    maxsize = c_vector.maxsize;
    array = new __DataType[maxsize];
    for (int i = 0; i < size; i++)
        array[i] = c_vector.array[i];
}

template <typename __DataType>
Vector<__DataType>::Vector(Vector&& c_vector) {
    array = c_vector.array;
    size  = c_vector.size;
    maxsize = c_vector.maxsize;
    c_vector.array = nullptr;
    c_vector.size = c_vector.maxsize = 0;
}

template <typename __DataType>
Vector<__DataType>& Vector<__DataType>::operator=(const Vector& c_vector) {
    Clear();
    size = c_vector.size;
    maxsize = c_vector.maxsize;
    array = new __DataType[maxsize];
    for (int i = 0; i < size; i++)
        array[i] = c_vector.array[i];
    return *this;
}

template <typename __DataType>
Vector<__DataType>& Vector<__DataType>::operator=(Vector&& c_vector) {
    delete[] array;
    array = c_vector.array;
    size  = c_vector.size;
    maxsize = c_vector.maxsize;
    c_vector.array = nullptr;
    c_vector.size = c_vector.maxsize = 0;
    return *this;
}

template <typename __DataType>
void Vector<__DataType>::Clear() {
    if (size)
        delete[] array;
    size = maxsize = 0;
}

template <typename __DataType>
__DataType& Vector<__DataType>::operator[](int i) {
    if(i < 0 || i >= maxsize) throw Exc(101, "error index array");
    return array[i];
}

template<typename __DataType>
VectorIterator<__DataType> Vector<__DataType>::Begin() {
    return VectorIterator<__DataType>(*this, 0);
}

template<typename __DataType>
VectorIterator<__DataType> Vector<__DataType>::End() {
    return VectorIterator<__DataType>(*this, size);
}

template<typename __DataType>
VectorIterator<__DataType> Vector<__DataType>::Insert(VectorIterator<__DataType> pos, const __DataType &p_elem) {
    Resize(size + 1);
    int pos_c = 0;
    while (&(*pos) != (array + pos_c))
        pos_c++;
    for (int i = size - 1; i > pos_c - 1; i--)
        array[i] = array[i - 1];
    *(pos) = p_elem;
    return pos;
}

template <typename __DataType>
int Vector<__DataType>::Size() const {
    return size;
}

template <typename __DataType>
int Vector<__DataType>::Capacity() const {
    return maxsize;
}

template <typename __DataType>
void Vector<__DataType>::Resize(int num) {
    if (num > size) {
        __DataType *tmp = new __DataType[size];
        for (int i = 0; i < size; i++)
            tmp[i] = array[i];
        Clear();
        size = num;
        maxsize = size + 1;
        array = new __DataType[maxsize];
        for (int i = 0; i < size; i++)
            array[i] = tmp[i];
        delete[] tmp;
    }
}

template <typename __DataType>
void Vector<__DataType>::Reserve(int num) {
    int reserv = maxsize - size;
    if (reserv < num)
        Resize(num - reserv);
}

template <typename __DataType>
void Vector<__DataType>::PopBack() {
    if (size > 0)
        size--;
}

template<typename __DataType>
void Vector<__DataType>::Erase(iterator pos) {
    for (; pos != End(); ++pos)
        *(pos - 1) = *pos;
    size--;
}

template <typename __DataType>
void Vector<__DataType>::PushBack(__DataType elem) {
    if (size >= maxsize)
        Reserve(maxsize * 2);
    array[size] = elem;
    size++;
}
