#pragma once

template<typename Iter, typename Predicate>
Iter FindIf(Iter begin, Iter end, Predicate pred) {
    for (; begin != end; ++begin)
        if (pred(*begin))
            break;
    return begin;
}

template <typename Iter>
Iter MinElement(Iter begin, Iter end) {
    Iter min = begin;
    for (; begin != end; ++begin)
        if (*min > *begin)
            min = begin;
    return min;
}

template <typename Iter>
Iter MaxElement(Iter begin, Iter end) {
    Iter max = begin;
    for (; begin != end; ++begin)
        if (*max < *begin)
            max = begin;
    return max;
}

template<typename Iter, typename func>
void forEach(Iter begin, Iter end, func& each) {
    for (; begin != end; ++begin)
        each(*begin);
}

template<typename Iter>
int Size(Iter begin, Iter end) {
    int size = 0;
    for (; begin != end; ++begin)
        size++;
    return size;
}

template<typename T>
void Swap(T &one, T &two) {
    T tmp = one;
    one = two;
    two = tmp;
}

template<typename Iter>
void Sort(Iter begin, Iter end) {
    int size = Size(begin, end);
    bool exit = false;
    while (!exit) {
        exit = true;
        for (int i = 0; i < (size - 1); i++) {
            if (*(begin + i) > *(begin + i + 1)) {
                Swap(*(begin + i), *(begin + i + 1));
                exit = false;
            }
        }
    }
}

template<typename Iter, typename Predicate>
void CopyIf(Iter begin, Iter end, Iter& n_beg, Predicate pred) {
    for (; begin != end; ++begin)
        if (pred(*begin)) {
            *n_beg = *begin;
            ++n_beg;
        }
}

template<typename Iter1, typename Iter2>
void Copy(Iter1 begin, Iter1 end, Iter2& n_beg) {
    for (; begin != end; ++begin) {
        *n_beg = *begin;
        ++n_beg;
    }
}
