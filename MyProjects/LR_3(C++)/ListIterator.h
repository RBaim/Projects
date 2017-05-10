#pragma once

#include "List.h"


template<typename Q>
class List;

template<typename N>
class Node;

template<typename T>
class ListIterator
{
private:

    List<T>       *ref  = nullptr;
    Node<T>       *node = nullptr;
public:
    ListIterator(List<T> &list, int index);

    ~ListIterator();

    ListIterator<T> &operator++();
    ListIterator<T> &operator++(int);

    ListIterator<T> &operator--();
    ListIterator<T> &operator--(int);

    ListIterator<T> operator+(int i)const;
    ListIterator<T> operator-(int i)const;

    T &operator*() const;

    T *operator->();

    bool operator==(const ListIterator<T> &it)const;
    bool operator!=(const ListIterator<T> &it)const;

    ListIterator<T> &operator=(const ListIterator<T> &copy);

    bool hasNext() const;
    T &next();
};

template<typename T>
ListIterator<T>::ListIterator(List<T> &list, int index) {

    if (index < 0 || index >= list.m_size) {
        throw Exc(-200, "Error construct ListIterator");
    }

    auto cur = list.head;

    int i = 0;
    while (i != index) {
        cur = cur->next;
        i++;
    }

    ref = &list;
    node = cur;
}

template<typename T>
ListIterator<T>::~ListIterator() {}

template<typename T>
ListIterator<T> ListIterator<T>::operator+(int i)const {

    ListIterator n = *this;
    for (int j = 0; j < i; ++j) {
        n++;
    }

    return n;
}
template<typename T>
ListIterator<T> ListIterator<T>::operator-(int i)const {
    ListIterator n = *this;
    for (int j = 0; j < i; ++j) {
        n--;
    }

    return n;
}

template<typename T>
ListIterator<T> &ListIterator<T>::operator++() {

    if (!node)
        throw Exc(221, "Error ++ in list");
    node = node->next;
    return *this;
}

template<typename T>
ListIterator<T> &ListIterator<T>::operator++(int) {//same
    if (!node)
        throw Exc(221, "Error ++ in list");

    node = node->next;
    return *this;
}

template<typename T>
ListIterator<T> &ListIterator<T>::operator--() {

    if (!node)
        throw Exc(221, "Error -- in list");
    node = node->prev;
    return *this;
}

template<typename T>
ListIterator<T> &ListIterator<T>::operator--(int) {//same
    if (!node)
        throw Exc(221, "Error -- in list");

    node = node->prev;
    return *this;
}

template<typename T>
T &ListIterator<T>::operator*() const {

    if (!node)
        throw Exc(311, "error operator *()");

    return node->element;
}

template<typename T>
T *ListIterator<T>::operator->() {

    if (!node)
        throw OutOfBoundsException(ref->m_size, -1);

    return &node->element;
}

template<typename T>
bool ListIterator<T>::operator==(const ListIterator<T> &it)const { //true if iterators point to the same list and the same node in that list
    return ref == it.ref && node == it.node;
}

template<typename T>
bool ListIterator<T>::operator!=(const ListIterator<T> &it)const { //true if iterators point to the same list and the same node in that list
    return ref != it.ref || node != it.node;
}

template<typename T>
ListIterator<T> &ListIterator<T>::operator=(const ListIterator<T> &copy) {
    ref = copy.ref;
    node = copy.node;

    return *this;
}

template<typename T>
bool ListIterator<T>::hasNext() const {
    return node;
}

template<typename T>
T &ListIterator<T>::next() {

    if (!node) throw Exc(333, "Error next in list");

    T& ret = node->element;

    node = node->next;

    return ret;
}
