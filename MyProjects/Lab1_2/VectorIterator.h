#pragma once

#include "Vector.h"
#include "Exc.h"

template <typename __DataType>
class Vector;

template <typename __DataType>
class VectorIterator {
    Vector<__DataType> *vec;
    int index;
public:
    VectorIterator(Vector<__DataType> &p_vec, int p_index = 0);
    VectorIterator(const VectorIterator<__DataType> &c_iter);
    ~VectorIterator();
    VectorIterator<__DataType> operator++();
    VectorIterator<__DataType> operator--();
    VectorIterator<__DataType> operator++(int);
    VectorIterator<__DataType> operator--(int);
    VectorIterator<__DataType>& operator=(const VectorIterator<__DataType> &p_vec);
    VectorIterator<__DataType> operator-(int i);
    VectorIterator<__DataType> operator+(int i);
    bool operator==(const VectorIterator<__DataType> &p);
    bool operator!=(const VectorIterator<__DataType> &p);
    __DataType &operator*();
    operator __DataType();
    __DataType* make() const;
};

template <typename __DataType>
VectorIterator<__DataType>::VectorIterator(Vector<__DataType> &p_vec, int p_index) {
    vec = &p_vec;
    index = p_index;
}

template <typename __DataType>
VectorIterator<__DataType>::VectorIterator(const VectorIterator<__DataType> &c_iter) {
    vec = c_iter.vec;
    index = c_iter.index;
}

template <typename __DataType>
VectorIterator<__DataType>::~VectorIterator() {
    vec = nullptr;
    index = 0;
}

template <typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator++() {
    if(index > vec->Size()) throw Exc(121, "incriment ++");
    index++;
    return VectorIterator(*this);
}

template <typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator--() {
    if(index <= -1) throw Exc(131, "dicrment --");
    index--;
    return VectorIterator(*this);
}

template <typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator++(int) {
    if(index > vec->Size()) throw Exc(121, "incriment ++");
    VectorIterator tmp = *this;
    ++*this;
    return tmp;
}

template <typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator--(int) {
    if(index <= -1) throw Exc(131, "dicrment --");
    VectorIterator tmp = *this;
    --*this;
    return tmp;
}

template <typename __DataType>
VectorIterator<__DataType>& VectorIterator<__DataType>::operator=(const VectorIterator<__DataType> &p_iter) {
    vec = p_iter.vec;
    index = p_iter.index;
    return *this;
}

template<typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator+(int i) {
    VectorIterator n = *this;
    for (int j = 0; j < i; ++j)
        n++;
    return n;
}

template<typename __DataType>
VectorIterator<__DataType> VectorIterator<__DataType>::operator-(int i) {
    VectorIterator n = *this;
    for (int j = 0; j < i; ++j)
        n--;
    return n;
}

template <typename __DataType>
bool VectorIterator<__DataType>::operator==(const VectorIterator<__DataType> &p) {
    if (vec == p.vec && index == p.index)
        return true;
    return false;
}

template <typename __DataType>
bool VectorIterator<__DataType>::operator!=(const VectorIterator<__DataType> &p) {
    if (vec == p.vec && index == p.index)
        return false;
    return true;
}

template <typename __DataType>
__DataType& VectorIterator<__DataType>::operator*() {
    return vec->operator[](index);
}

template<typename __DataType>
VectorIterator<__DataType>::operator __DataType(){
    return vec->operator[](index);
}

template<typename __DataType>
__DataType* VectorIterator<__DataType>::make() const {
    return (*vec)[index];
}
