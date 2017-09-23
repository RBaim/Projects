//
// Created by radmi on 18.09.2017.
//

#ifndef DZ_1_2_PIECECOD_H
#define DZ_1_2_PIECECOD_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <functional>

void CreateData(std::ostream& stream, std::true_type);

int my_rand();

template <typename type>
void CreateData(std::ostream_iterator<type> c) {
    std::list<type> cont(100);
    std::generate(cont.begin(), cont.end(), my_rand);
    std::copy(cont.begin(), cont.end(), c);
}

template <typename Iter>
void LoadData(Iter beg, std::istream& stream, std::true_type) {
    int k;
    for(int i = 0; i < 100; ++i) {
        stream >> k; *beg = k;
    }
}

template<typename Iter1, typename type = int>
void LoadData(Iter1 cont, std::istream_iterator<type> stream_iter){
    std::copy(stream_iter, std::istream_iterator<type>(), cont);
}

template <typename Iter>
void Modify(Iter beg, Iter end) {
    int neg = *std::find_if(beg, end, [](int c) {
        if(c < 0) return true;
        return false;
    });
    int last;
    Iter cop = beg;
    while(cop != end) {
      last = *cop;
        cop++;
    }
    int del = (neg + last) / 2;
    std::for_each(beg, end, [&del](int& i) {i /= del;});
}

template <typename Cont>
void Modify(Cont& c) {
    int neg;
    for(int i = 0; i < c.size(); ++i)
        if(c[i] < 0) {neg = c[i]; break;}
    int del = (neg + c[c.size() - 1]) / 2;
    for(int i = 0; i < c.size(); ++i)
        c[i] /= del;
    int sum = 0, abssr = 0;
    for(int i = 0; i < c.size(); ++i) {
        sum += c[i];
        abssr += abs(c[i]);
    }
    abssr /= c.size();
    c.push_back(sum);
    c.push_back(abssr);
}

template <typename Iter>
void Modify(Iter beg, Iter end, std::function<void(int&)> func) {
    Modify(beg, end);
    std::for_each(beg, end, func);
}

template <typename type = int>
void Modify(std::istream_iterator<type> stream_iter_in, std::ostream_iterator<type> stream_iter_out, std::function<int(int)> func) {
    std::transform(stream_iter_in, std::istream_iterator<type>(), stream_iter_out, func);
}

template <typename Iter>
void OutputResult(Iter beg, Iter end, std::ostream& stream, std::true_type) {
    std::for_each(beg, end, [&](int el){stream << el << std::endl;});
}

template <typename Iter, typename type>
void OutputResult(Iter beg, Iter end, std::ostream_iterator<type> stream_iter) {
    std::copy(beg, end, stream_iter);
}

template <typename type = int>
int DelSearch(std::istream_iterator<type> stream_iter_in) {
    int neg = *std::find_if(stream_iter_in, std::istream_iterator<type>(), [](int c) {
        if(c < 0) return true;
        return false;
    });
    std::istream_iterator<type> it_cop(stream_iter_in);
    int last;
    while(it_cop != std::istream_iterator<type>()) {
        last = *it_cop;
        it_cop++;
    }
    return (neg + last) / 2;
}

#endif //DZ_1_2_PIECECOD_H
