//
// Created by radmi on 02.10.2017.
//

#ifndef DZ_1_2_2_COMPONENTS_H
#define DZ_1_2_2_COMPONENTS_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

struct Product {
    int stock_num;
    int code_prod;
    char name_prod[31];
    int date;
    int valid;
    int count;
    double cost;
    friend std::ostream& operator << (std::ostream& st, const Product p) {
        st << std::setw(10)
                  << p.stock_num
                  << std::setw(10)
                  << p.code_prod
                  << std::setw(30)
                  << p.name_prod
                  << std::setw(10)
                  << p.date
                  << std::setw(10)
                  << p.valid
                  << std::setw(15)
                  << p.cost;
        return st;
    }
};

class Keys {
    int key;
public:
    Keys(int val) : key(val) {}
    Keys &operator=(const Keys& k) {
        key = k.key;
        return *this;
    }
    Keys &operator=(Keys k) {
        key = k.key;
        return *this;
    }
    friend bool operator < (const Keys& one, const Keys& two) {
        return (one.key < two.key);
    }
    friend bool operator == (const Keys& one, const Keys& two) {
        return (one.key == two.key);
    }
    friend bool operator > (const Keys& one, const Keys& two) {
        return (one.key > two.key);
    }
    friend bool operator != (const Keys& one, const Keys& two) {
        return (one.key != two.key);
    }
    friend bool operator <= (const Keys& one, const Keys& two) {
        return (one.key <= two.key);
    }
    friend bool operator >= (const Keys& one, const Keys& two) {
        return (one.key >= two.key);
    }
    void operator++(void) {
        ++key;
    }
    friend std::ostream& operator << (std::ostream& st, const Keys& k) {
        st << std::setw(5) << k.key;
        return st;
    }
};

class MapInfo {
    std::map<Keys, Product> data;
    int date_cur;
public:
    typedef std::map<Keys, Product> MyMap ;
    MapInfo(MapInfo&& c_p) = default;
    MapInfo(int p_date_cur) : date_cur(p_date_cur) {}
    void OutData(std::ostream& st);
    void LoadData(std::ifstream& st);
    void OnTxt(std::ofstream& st);
    std::vector<Product> FindNoStock(int stock);
    std::vector<Product> FindNoCod(int cod);
    std::vector<Product> Overdue(bool cond);
    void clear() { data.clear(); }
    MapInfo& operator=(std::map<Keys, Product>&& p_p) {
        data = std::move(p_p);
    }
};

void InputInfo(std::ofstream& st);

#endif //DZ_1_2_2_COMPONENTS_H
