#include "vector.h"

Vector::Vector(const Vector& vec) {
    if (&vec != this) {
        lenght = vec.lenght;
        array = new double[lenght];
        for (int i = 0; i < lenght; i++) {
            array[i] = vec.array[i];
        }
    }
}

Vector::Vector(int lenght, double start) {
    NewMem(lenght);
    for (int i = 0; i < lenght; i++) {
        array[i] = start;
    }
}

Vector::~Vector() {
    delete[] array;
    lenght = 0;
}

void Vector::NewMem(int lenght) {
    delete[] array;
    this->lenght = lenght;
    array = new double[lenght];
}

Vector& Vector::operator=(const Vector& vec) {
    if (this != &vec) {
        NewMem(vec.lenght);
        for (int i = 0; i < lenght; i++) {
            array[i] = vec.array[i];
        }
    }
    return *this;
}

Vector operator+(const Vector& vec1, const Vector& vec2) {
    Vector res = vec1;
    return (res += vec2);
}

Vector operator*(const Vector& vec1, const Vector& vec2) {
    if (vec1.lenght != vec2.lenght || vec1.lenght != 3) {
        throw ErrorMalVec(vec1.lenght, vec2.lenght);
    }
    Vector res;
    res.NewMem(3);
    res.array[0] = vec1.array[1] * vec2.array[2] - vec2.array[1] * vec1.array[2];
    res.array[1] = vec1.array[0] * vec2.array[2] - vec2.array[0] * vec1.array[2];
    res.array[2] = vec1.array[0] * vec2.array[1] - vec2.array[0] * vec1.array[1];
    return res;
}

Vector operator*(const Vector& vec, double l) {
    Vector res(vec);
    for (int i = 0; i < res.lenght; i++) {
        res.array[i] *= l;
    }
    return res;
}

Vector operator*(double l, const Vector& vec) {
    return operator*(vec, l);
}

double operator&(const Vector& vec1, const Vector& vec2) {
    if (vec1.lenght == vec2.lenght) {
        double res = 0;
        for (int i = 0; i < vec1.lenght; i++) {
            res += vec1.array[i] * vec2.array[i];
        }
        return res;
    }
    return 0;
}

double& Vector::operator[](int i) {
    if (i >= lenght || i < 0) {
        throw ErrorIndex(i);
    }
    return array[i];
}

Vector Vector::operator+=(const Vector& vec) {
    if (vec.lenght == lenght) {
        for (int i = 0; i < lenght; i++) {
            array[i] += vec.array[i];
        }
    }
    return *this;
}

Vector Vector::operator-=(const Vector& vec) {
    if (vec.lenght == lenght) {
        for (int i = 0; i < lenght; i++) {
            array[i] -= vec.array[i];
        }
    }
    return *this;
}

std::ostream& operator << (std::ostream &stream, const Vector &obj) {
    stream << '(';

    for (int i = 0; i < obj.lenght - 1; i++) {
        stream << obj.array[i] << ", ";
    }
    stream << obj.array[obj.lenght - 1] << ")";
    return stream;
}

std::istream& operator >> (std::istream &stream, Vector &obj) {
    std::cout << "¬ведите элементы" << std::endl;
    for (int i = 0; i < obj.lenght; i++) {
        stream >> obj.array[i];
    }
    return stream;
}

double Vector::lenght_vect_g() const {
    return sqrt((*this)&(*this));
}

int Vector::GetSize() const {
    return lenght;
}

Vector Vector::operator+() {
    return *this;
}

Vector Vector::operator-() {
    Vector res(lenght);
    for (int i = 0; i < lenght; i++)
        res.array[i] = (-1)*array[i];
    return res;
}
