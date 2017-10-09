//
// Created by radmi on 02.10.2017.
//
#include "Components.h"

void InputInfo(std::ofstream& st) {
    if(st.is_open()) {
        std::cout << "Input count elements: ";
        int size;
        std::cin >> size;
        Product tmp;
        for(int i = 0; i < size; ++i) {
            std::cout << i + 1 << ": stock_num, code_prod, name_prod, date(int day abs), valid, count, cost" << std::endl;
            std::cin >> tmp.stock_num >> tmp.code_prod >> tmp.name_prod >> tmp.date >> tmp.valid >> tmp.count >> tmp.cost;
            st.write((char*)&tmp, sizeof(Product));
        }
    } else throw "File not open!";
}

void MapInfo::LoadData(std::ifstream& st) {
    if(st.is_open()) {
        Product tmp;
        Keys key(0);
        while(st.read((char*)&tmp, sizeof(Product))) {
            data.insert(std::make_pair(key, tmp));
            ++key;
        }
    } else throw "File not open!";
}

void MapInfo::OutData(std::ostream& st) {
    for(auto &it : data) {
        st << it.first <<  it.second << std::endl;
    }
}

void MapInfo::OnTxt(std::ofstream& st) {
    OutData(st);
}

template <
        class InputIterator, class OutputIterator,
        class UnaryOperator, class Pred
>
OutputIterator transform_if(InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op, Pred pred) {
    while (first1 != last1) {
        if (pred(*first1)) {
            *result = op(*first1);
            ++result;
        }
        ++first1;
    }
    return result;
}

std::vector<Product> MapInfo::FindNoStock(int stock) {
    std::vector<Product> res;
    transform_if(data.begin(), data.end(), std::back_inserter(res),
                 [] (const typename MyMap::value_type& el){ return el.second;},
                 [&] (const typename MyMap::value_type& el)
                 {return (stock == el.second.stock_num) ? true : false;});
    return res;
}

std::vector<Product> MapInfo::FindNoCod(int cod) {
    std::vector<Product> res;
    transform_if(data.begin(), data.end(), std::back_inserter(res),
                 [] (const typename MyMap::value_type& el){ return el.second;},
                        [&] (const typename MyMap::value_type& el)
                        {return (cod == el.second.code_prod) ? true : false;});
    return res;
}

bool NOT(bool one, bool two) {
    return two ? one : !one;
}

std::vector<Product> MapInfo::Overdue(bool cond) {
    std::vector<Product> res;
    transform_if(data.begin(), data.end(), std::back_inserter(res),
                 [] (const typename MyMap::value_type& el){ return el.second;},
                        [&] (const typename MyMap::value_type& el)
                        {return (NOT(date_cur - el.second.date > el.second.valid, cond)) ? true : false;});
    return res;
}