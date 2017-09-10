//
// Created by radmi on 08.09.2017.
//

#ifndef LAB1_2_EXC_H
#define LAB1_2_EXC_H
#include <iostream>

class Exc {
protected:
    int num_error;
    std::string error_str;
public:
    Exc(int num, std::string err) : num_error(num), error_str(err) {}
    virtual void Info() {
        std::cout << "Error " << num_error << ": " << std::endl << error_str << std::endl;
    }
};


#endif //LAB1_2_EXC_H
