//
// Created by radmi on 06.09.2017.
//

#ifndef LAB1_2_UTIL_H
#define LAB1_2_UTIL_H
#include <vector>
#include "iostream"
#include "Exc.h"
#include "Vector.h"

/*template <typename T, char symb>
class type_arr {
    T* coord;
    void free() {
        if(coord != nullptr)
            delete[] coord;
    }
public:
    static int dim;
    type_arr() {
        //coord = new T[dim];
    }
    ~type_arr() {
        free();
    }
    T& operator[] (int i) {
        if(i >= dim && i < 0) throw Exc(101, "error index array");
        return coord[i];
    }
    friend std::istream& operator >> (std::istream& stream, type_arr& xi) {
        //delete[] xi.coord;
        xi.free();
        xi.coord = new T[xi.dim + 1];
        for(int i = 0; i < xi.dim; ++i) {
            stream >> xi.coord[i];
        }
        return stream;
    }
    friend std::ostream& operator << (std::ostream& stream, const type_arr& xi) {
        for(int i = 0; i < xi.dim; ++i) {
            stream << symb << i + 1 << ": " << xi.coord[i] << "   ";
        }
        stream << std::endl;
        return  stream;
    }
};

template <typename T, char c>
int type_arr<T, c>::dim = 0;//default*/

struct Node {
    int ID;
    std::vector<double> coords;
    bool apex;
};

struct Element {
    int material_ID;
    std::vector<int> ID_node;
};

struct Surface : public Element {
    int ID_surf_cond;
    int type_ID;
};

#endif //LAB1_2_UTIL_H
