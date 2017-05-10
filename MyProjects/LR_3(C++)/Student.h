#pragma once

#include <iostream>
#include <string.h>

class Student {
public:
    std::string name;
    int num;
    Student() {}
    Student(std::string name_p, int num_p) {
        name = name_p;
        num = num_p;
    }
    bool operator==(Student& p) {
        return (name == p.name && num == p.num);
    }
    bool operator!=(Student& p) {
        return !operator==(p);
    }
    bool operator>(Student& p) {
        return (name > p.name && num > p.num);
    }
    bool operator<(Student& p) {
        return (name < p.name && num < p.num);
    }
    void PrintStud() {
        std::cout << name.c_str() << ' ' << num << std::endl;
    }
};
