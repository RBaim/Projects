#pragma once

template<typename T>
class Sets
{
public:
    Sets();
    Sets(T *mass_new, int &lenght);
    Sets(const Sets<T> &Copy);
    Sets(int lenght);
    ~Sets();
    bool CheckAccessory(T c);
    template<typename T>
    friend Sets<T> operator&(Sets<T> &A, Sets<T> &B);
    template<typename T>
    friend Sets<T> operator|(Sets<T> &A, Sets<T> &B);
    template<typename T>
    friend Sets<T> operator/(Sets<T> &A, Sets<T> &B);
    Sets &operator=(Sets &A);
    T operator()(int i);
    void Sort();
    void DelRepiats();
    void input(T c, int i);
    int getlen();
    void NewMem(int lenght);
    void NewSize(int size);
    void Update(T *mass, int lenght);
private:
    void Clear();
    void Null();
    T *mass;
    int lenght;
};

template<typename T>
void Sets<T>::Clear() {
    if (this->lenght > 0) {
        delete[] this->mass;
        this->mass = nullptr;
        this->lenght = 0;
    }
}

int min(int &a, int &b) {
    if (a > b) {
        return b;
    }
    return a;
}

template<typename T>
Sets<T>::Sets(const Sets<T> &Copy) {
    this->NewMem(Copy.lenght);
    for (int i = 0; i < this->lenght; i++) {
        *(this->mass + i) = *(Copy.mass + i);
    }
}

template <typename T>
Sets<T>::Sets() {
    this->mass = nullptr;
    this->lenght = 0;
}

template <typename T>
void Sets<T>::Null() {
    for (int i = 0; i < this->lenght; i++) {
        *((this->mass) + i) = 0;
    }
}

template <typename T>
Sets<T>::Sets(int lenght) {
    this->mass = new T[lenght];
    this->lenght = lenght;
    this->Null();
}

template <typename T>
Sets<T>::Sets(T *mass_new, int &lenght) {
    this->lenght = lenght;
    this->mass = new T[lenght];
    for (int i = 0; i < lenght; i++) {
        *((this->mass) + i) = *(mass_new + i);
    }
}

template <typename T>
Sets<T>::~Sets() {
    if (this->lenght > 0) {
        delete[] this->mass;
        this->mass = nullptr;
        this->lenght = 0;
    }
}

template <typename T>
bool Sets<T>::CheckAccessory(T c) {
    for (int i = 0; i < this->lenght; i++) {
        if (*((this->mass) + i) == c)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
int Sets<T>::getlen() {
    return this->lenght;
}

template <typename T>
T Sets<T>:: operator()(int i) {
    return *((this->mass) + i);
}

template <typename T>
Sets<T> operator&(Sets<T> &A, Sets<T> &B) { //Пересечение
    Sets<T> *Res = new Sets<T>;
    if (B.lenght > 0 && A.lenght > 0 && A.lenght > B.lenght) {
        *Res = operator&(B, A);
    }
    if (B.lenght > 0 && A.lenght > 0 && A.lenght <= B.lenght) {
        Res->NewMem(min(B.lenght, A.lenght));
        int l = 0;
        for (int i = 0; i < min(B.lenght, A.lenght); i++) {
            if (B.CheckAccessory(*(A.mass + i)) == true) {
                Res->input(*(A.mass + i), l);
                l++;
            }
        }
        Res->NewSize(l);
        Res->Sort();
    }
    return *Res;
}

template<typename T>
void Sets<T>::NewSize(int size) {
    if (size > 0) {
        T *t = new T[size];
        for (int i = 0; i < size; i++) {
            *(t + i) = *(mass + i);
        }
        this->Clear();
        this->Update(t, size);
        delete[] t;
    }
}

template <typename T>
void Sets<T>::Update(T *mass, int lenght) {
    this->Clear();
    this->lenght = lenght;
    this->mass = new T[lenght];
    for (int i = 0; i < lenght; i++) {
        *((this->mass) + i) = *(mass + i);
    }
}

template <typename T>
void Sets<T>::DelRepiats() {
    int size = this->getlen();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(this->mass + i) == *(this->mass + j)) {
                for (int p = j; p < size; p++) {
                    *(this->mass + p) = *(this->mass + p + 1);
                }
                size--;
                j--;
            }
        }
    }
    this->lenght = size;
}

template<typename T>
void Sets<T>::input(T c, int i)
{
    if (i >= 0 && i < this->lenght) {
        *((this->mass) + i) = c;
    }
}

template <typename T>
Sets<T> operator|(Sets<T> &A, Sets<T> &B) {//Объединение
    Sets<T> *Res = new Sets<T>;;
    if (B.lenght >= 0 && A.lenght >= 0) {
        Res->NewMem(B.lenght + A.lenght);
        int l = 0;
        for (int i = 0; i < B.lenght; i++) {
            *(Res->mass + l) = *(B.mass + i);
            l++;
        }
        for (int i = 0; i < A.lenght; i++) {
            *(Res->mass + l) = *(A.mass + i);
            l++;
        }
        Res->DelRepiats();
        Res->Sort();
    }
    return *Res;
}


template <typename T>
Sets<T> operator/(Sets<T> &A, Sets<T> &B) {//Дополнение
    Sets<T> *Res = new Sets<T>;;
    if (B.lenght >= 0 && A.lenght >= 0) {
        Res->NewMem(A.lenght);
        int l = 0;
        for (int i = 0; i < A.lenght; i++) {
            if (!(B.CheckAccessory(*(A.mass + i)))) {
                *(Res->mass + l) = *(A.mass + i);
                l++;
            }
        }
        Res->NewSize(l);
        Res->Sort();
    }
    return *Res;
}

template<typename T>
void Sets<T>::NewMem(int lenght) {
    if (lenght > 0) {
        this->Clear();
        this->mass = new T[lenght];
        this->lenght = lenght;
        this->Null();
    }
}

template<typename T>
Sets<T> & Sets<T>::operator=(Sets & A) {
    if (this != &A) {
        this->NewMem(A.getlen());
        for (int i = 0; i < A.getlen(); i++) {
            *((this->mass) + i) = A(i);
        }
    }
    return *this;
}

template <typename T>
void Sets<T>::Sort() {
    T tmp;
    for (int i = 1, z; i < this->lenght; i++) {
        tmp = *((this->mass) + i);
        z = i - 1;
        while (z >= 0 && *((this->mass) + z) > tmp) {
            *((this->mass) + z + 1) = *((this->mass) + z);
            z--;
        }
        *((this->mass) + z + 1) = tmp;
    }
}
