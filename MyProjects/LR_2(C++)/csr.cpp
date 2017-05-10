#include "csr.h"

CSR::~CSR() {
    delete[] aelem;
    delete[] jptr;
    delete[] iptr;
    lenght = 0;
    size = 0;
}

CSR::CSR(const CSR& matrix) {
    lenght = matrix.lenght;
    size = matrix.size;
    aelem = new double[lenght];
    jptr = new int[lenght];
    iptr = new int[size + 1];
    for (int i = 0; i < lenght; i++) {
        aelem[i] = matrix.aelem[i];
        jptr[i] = matrix.jptr[i];
    }
    for (int i = 0; i <= size; i++) {
        iptr[i] = matrix.iptr[i];
    }
}

CSR::CSR(int a_size_not_nil, int size_matrix, double start) {
    aelem = new double[a_size_not_nil];
    jptr = new int[a_size_not_nil];
    iptr = new int[size_matrix + 1];
    lenght = a_size_not_nil;
    size = size_matrix;
    for (int i = 0; i < lenght; i++) {
        aelem[i] = start;
        jptr[i] = 0;
    }
    for (int i = 0; i <= size; i++)
        iptr[i] = 0;
}

int CSR::GetSize() {
    return size;
}

int CSR::GetLenght() {
    return lenght;
}

CSR operator*(const CSR& matrix, double l) {
    CSR res(matrix);
    for (int i = 0; i < matrix.lenght; i++)
        res.aelem[i] *= l;
    return res;
}

CSR operator*(double l, const CSR& matrix) {
    return operator*(matrix, l);
}

Vector operator*(const CSR& matrix, const Vector& vec) {
    Vector res(matrix.size);
    if (matrix.size == vec.GetSize()) {
        for (int i = 0; i < matrix.size; i++) {
            res[i] = 0;
            for (int j = matrix.iptr[i]; j < matrix.iptr[i + 1]; j++) {
                res[i] += (const_cast<Vector &>(vec))[matrix.jptr[j]] * matrix.aelem[j];
            }
        }
    }
    return res;
}

std::istream& operator >> (std::istream& stream, CSR& obj) {
    int count = 0, *t_jptr;
    double tmp, *t_aelem;
    //std::cout << "¬ведите размерность" << std::endl;
    stream >> obj.size;
    //std::cout << "¬ведите элементы" << std::endl;
    obj.NewMem(count, obj.size);
    for (int i = 0; i < obj.size; i++) {
        obj.iptr[i] = count;
        for (int j = 0; j < obj.size; j++) {
            stream >> std::setw(7) >> std::fixed >> std::setprecision(3) >> tmp;
            if (tmp != 0.) {
                t_jptr = new int[obj.lenght];
                t_aelem = new double[obj.lenght];
                for(int it = 0; it<obj.lenght; it++) {
                    t_jptr[it] = obj.jptr[it];
                    t_aelem[it] = obj.aelem[it];
                }
                delete[] obj.aelem;
                delete[] obj.jptr;
                obj.lenght++;
                obj.aelem = new double[obj.lenght];
                obj.jptr = new int[obj.lenght];
                for (int it = 0; it<obj.lenght; it++) {
                    obj.jptr[it] = t_jptr[it];
                    obj.aelem[it] = t_aelem[it];
                }
                obj.aelem[count] = tmp;
                obj.jptr[count] = j;
                delete[] t_jptr;
                delete[] t_aelem;
                count++;
            }
        }
    }
    obj.iptr[obj.size] = count;
    return stream;
}

std::ostream& operator << (std::ostream& stream, const CSR& obj) {
    stream << std::fixed << obj.size << std::endl;
    int k = 0, i = 0, j = 0;
    for (i = 0; i < obj.size; i++) {
        for (j = 0; j < obj.size; j++) {
            while (k < obj.iptr[i + 1] && j < obj.size) {
                for (int io = j; io < obj.jptr[k]; io++, j++)
                    stream << std::setw(7) << std::fixed << std::setprecision(3) << 0.;
                if (j < obj.size) {
                    stream << std::setw(7) << std::fixed << std::setprecision(3) << obj.aelem[k]; k++; j++;
                }
            }
            while (j < obj.size) {
                j++;
                stream << std::setw(7) << std::fixed << std::setprecision(3) << 0.;
            }
        }
        stream << std::endl;
    }
    return stream;
}

void CSR::NewMem(int a_size_not_nil, int size_matrix) {
    delete[] aelem;
    delete[] jptr;
    delete[] iptr;
    aelem = new double[a_size_not_nil];
    jptr = new int[a_size_not_nil];
    iptr = new int[size_matrix + 1];
    lenght = a_size_not_nil;
    size = size_matrix;
}
