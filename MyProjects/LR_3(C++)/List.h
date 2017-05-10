#pragma once

#include <iostream>

#include "ListIterator.h"

template<typename N>
class Node
{
private:

    friend class List<N>;
    friend class ListIterator<N>;

    Node<N>* prev = nullptr;
    Node<N>* next = nullptr;
    N element;

    Node(N element,  Node<N>* prev,  Node<N>* next):element(element),prev(prev), next(next){}


};

template<typename T>
class List
{
private:

    friend class ListIterator<T>;

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int m_size = 0;

    void free();

public:

    ~List();
    List() {}
    List(int size, T set);
    List(const std::initializer_list<T>& init);
    List(const List<T>& copy);

    List& operator=(const List<T>& copy);
    List& operator=(List<T>&& rvalue);

    List(List<T>&& rvalue);

    int size() const
    {
        return m_size;
    }

    int length() const
    {
        return m_size;
    }

    List<T>& pushBack(const T element);
    T popBack();
    List<T>& pushFront(const T element);
    List<T>& insert(int index, const T element);
    List<T>& erase(int index);

    T &getHead(){
        
        return head->element;
    }
    T &getTail(){
        
        return tail->element;
    }

    bool isEmpty() const
    {
        return m_size == 0;
    }

    bool nonEmpty() const
    {
        return m_size != 0;
    }

    List<T> &clear();
    T& operator[](int index);
    T const& operator[](int index) const;

    ListIterator<T> begin();
    ListIterator<T> end();

};

template<typename T>
void List<T>::free()
{
    Node<T>* cur = head;

    while (cur) {
        Node<T>* next = cur->next;
        delete cur;
        cur = next;
    }
}

template<typename T>
List<T> &List<T>::clear() {
    free();

    head = nullptr;
    tail = nullptr;
    m_size = 0;
}


template<typename T>
List<T>::~List() {
    free();
}

template<typename T>
List<T>::List(int size, T set) {
    for (int i = 0; i < size; ++i) {
        pushBack(set);
    }
}

template<typename T>
List<T>::List(const std::initializer_list<T>& init) {

    auto b = init.begin();

    while (b != init.end()) {
        pushBack(*b);
        b++;
    }
    pushBack(*init.begin());
}


template<typename T>
List<T>::List(const List<T>& copy) {
    for (int i = 0; i < copy.size(); ++i) {
        this->pushBack(copy[i]);//TODO probably not the fastest way to do this, copying Nodes should be faster
    }
}


template<typename T>
List<T>& List<T>::operator=(const List<T>& copy) {
    for (int i = 0; i < copy.size(); ++i) {
        this->pushBack(copy[i]);//TODO probably not the fastest way to do this, copying Nodes should be faster
    }

    return *this;
}



template<typename T>
List<T>& List<T>::operator=(List<T>&& rvalue) {
    //std::cout << "move assignment activated !!!" << std::endl;

    head = rvalue.head;
    m_size = rvalue.size();

    rvalue.head = nullptr;
    rvalue.m_size = 0;

    return *this;
}

template<typename T>
List<T>::List(List<T>&& rvalue) {
    //std::cout << "move constructor activated !!!" << std::endl;

    head = rvalue.head;
    m_size = rvalue.m_size;

    rvalue.head = nullptr;
    rvalue.m_size = 0;
}

template<typename T>
List<T>& List<T>::pushBack(const T element)
{

    if (!tail) { //head == nullptr
        tail = new Node<T>(element, nullptr, nullptr);
        head = tail;
    }
    else {
        tail->next = new Node<T>(element, tail, nullptr);
        tail = tail->next;
    }

    m_size++;

    return *this;
}

template<typename T>
T List<T>::popBack()
{
    if (m_size == 0) {
        throw Exc(0, "0");
    }

    T taily = tail->element;

    tail = tail->prev;

    return taily;
}

template<typename T>
List<T>& List<T>::pushFront(const T element)
{
    if (!head) {
        return pushBack(element);
    }
    else {
        auto newHead = new Node<T>(element, nullptr, head);
        head->prev = newHead;

        head = newHead;

        m_size++;
    }

    return *this;
}

template<typename T>
List<T>& List<T>::insert(int index, const T element)
{
    if (index < 0 || index > m_size) {
        throw Exc(1213, "Error insert in list");;
    }

    if (index != m_size) {


        int i = 0;
        Node<T>* atIndex = head;

        for (int j = 0; j < index; ++j) {
            atIndex = atIndex->next;
        }

        Node<T> *newcomer = new Node<T>(element, atIndex->prev, atIndex);

        if (atIndex->prev)
            atIndex->prev->next = newcomer;

        atIndex->prev = newcomer;

        if (index == 0) head = newcomer;

    }
    else {
        Node<T> *newcomer = new Node<T>(element, tail, nullptr);

        tail->next = newcomer;

        tail = newcomer;
    }

    m_size++;

    return *this;

}

template<typename T>
List<T>& List<T>::erase(int index)
{
    if (index < 0 || index > m_size) {
        throw Exc(2121, "Error erase in list");
    }

    int i = 0;
    Node<T>* atIndex = head;

    for (int j = 0; j < index; ++j) {
        atIndex = atIndex->next;
    }

    if (index == 0) {
        head = atIndex->next;

        if (m_size > 1) {
            atIndex->next->prev = nullptr;
        }

    }
    else if (index == m_size - 1) {
        tail = atIndex->prev;

        if (m_size > 1) {
            atIndex->prev->next = nullptr;
        }


    }
    else { //size >= 3
        atIndex->prev->next = atIndex->next;
        atIndex->next->prev = atIndex->prev;

    }

    delete atIndex;

    m_size--;

}

template<typename T>
T& List<T>::operator[](int index) {
    if (index >= m_size) {
        throw Exc(2111, "Error operator[]");
    }

    int i = 0;
    Node<T>* cur = head;

    for (int j = 0; j < index; ++j) {
        cur = cur->next;
    }

    return cur->element;

}

template<typename T>
T const& List<T>::operator[](int index) const {
    if (index >= m_size) {
        throw Exc(2111, "Error const operator[]");
    }

    int i = 0;
    Node<T>* cur = head;

    for (int j = 0; j < index; ++j) {
        cur = cur->next;
    }

    return cur->element;

}

template<typename T>
ListIterator<T> List<T>::begin()
{
    return ListIterator<T>(*this, 0);
}


template<typename T>
ListIterator<T> List<T>::end()
{
    ListIterator<T> res(*this, m_size - 1);
    res++;
    return res;
}
