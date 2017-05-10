#include "vector.h"
#include "csr.h"
#include "Menu.h"
#include "Exc.h"

void MalMatrixVect() {
    CSR A(0);
    std::cout << "Введите матрицу(размерность, затем элементы)" << std::endl;
    std::cin >> A;
    std::cout << A;
    int size_m = A.GetSize();
    Vector x(size_m);
    std::cout << "Введите вектор размерностью " << size_m << std::endl << std::endl;
    std::cin >> x;
    std::cout << "Результат:" << std::endl << (A*x) << std::endl;
}

void MalVec_sh() {
    std::cout << "Введите размерность вектора" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "Введите вектор" << std::endl << std::endl;
    std::cin >> x;
    std::cout << "Введите число" << std::endl;
    double mal;
    std::cin >> mal;
    std::cout << "Результат:" << std::endl << (mal*x) << std::endl;
}

void MalVec_vs() {
    std::cout << "Введите размерность векторов" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size), y(size);
    std::cout << "Введите вектора x и y" << std::endl << std::endl;
    std::cin >> x >> y;
    std::cout << "Результат:" << std::endl << (y&x) << std::endl;
}

void MalVec_vv() {
    std::cout << "Введите размерности векторов" << std::endl;
    int size1, size2;
    std::cin >> size1 >> size2;
    Vector x(size1), y(size2);
    std::cout << "Введите вектора x и y" << std::endl << std::endl;
    std::cin >> x >> y;
    try {
        std::cout << "Результат(1 на 2):" << std::endl << (x*y) << std::endl;
    }
    catch (ErrorMalVec er) {
        std::cout << er.what() << '(' << er.errordem1 << ' ' << er.errordem2 << ')' << std::endl;
    }
}

void SumVec() {
    std::cout << "Введите размерность векторов" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size), y(size);
    std::cout << "Введите вектора" << std::endl << std::endl;
    std::cin >> x >> y;
    std::cout << "Результат:" << std::endl << (y + x) << std::endl;
}

void VecLenght() {
    std::cout << "Введите размерность вектора" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "Введите вектор" << std::endl << std::endl;
    std::cin >> x;
    std::cout << "Длина вектора:" << std::endl << x.lenght_vect_g() << std::endl;
}

void MalMatrix_ch() {
    std::ofstream fout("test.txt");
    CSR A(3, 3);
    std::cout << "Введите матрицу(размерность, затем элементы)" << std::endl;
    std::cin >> A;
    std::cout << "Введите число" << std::endl;
    double mal;
    std::cin >> mal;
    std::cout << "Результат:" << std::endl << A*mal << std::endl;
    fout << A*mal;
    fout.close();
    std::ifstream fcin("test.txt");
    fcin >> A;
    std::cout << "Введите число" << std::endl;
    std::cin >> mal;
    std::cout << "Результат:" << std::endl << A*mal << std::endl;
    fcin.close();
}

void UnaryVector() {
    std::cout << "Введите размерность вектора" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "Введите вектор" << std::endl << std::endl;
    std::cin >> x;
    char op;
    std::cout << "Введите унарную операцию" << std::endl;
    std::cin >> op;
    switch (op) {
    case '+': +x; break;
    case '-': x = -x;
    }
    std::cout << "Результат:" << std::endl << x << std::endl;
}

void ElemOperetor() {
    std::cout << "Введите размерность вектора" << std::endl;
    int size;
    std::cin >> size;
    Vector x(size);
    std::cout << "Введите вектор" << std::endl << std::endl;
    std::cin >> x;
    int in;
    std::cout << "Введите индекс" << std::endl;
    std::cin >> in;
    try {
        std::cout<< "x[" << in << "] = " << x[in] << std::endl;
    }
    catch (ErrorIndex er) {
        std::cout << er.what() << er.errorind << std::endl;
    }
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4), Vec(8), Matrix(2);
    Main.PushLine(0, "1.Векторные операции", &Vec, nullptr);
    Main.PushLine(1, "2.Матричные операции", &Matrix, nullptr);
    Main.PushLine(2, "3.Умножение мат. и век.(A*x)", nullptr, MalMatrixVect);
    Main.PushLine(3, "4.Выход", nullptr, nullptr);
    Vec.PushLine(0, "1.Умножение на число", nullptr, MalVec_sh);
    Vec.PushLine(1, "2.Скалярное умножение", nullptr, MalVec_vs);
    Vec.PushLine(2, "3.Векторное умножение", nullptr, MalVec_vv);
    Vec.PushLine(3, "4.Сложение векторов", nullptr, SumVec);
    Vec.PushLine(4, "5.Длина вектора", nullptr, VecLenght);
    Vec.PushLine(5, "6.Унарные операции", nullptr, UnaryVector);
    Vec.PushLine(6, "7.Обращение к элементу", nullptr, ElemOperetor);
    Vec.PushLine(7, "8.Назад", &Main, nullptr);
    Matrix.PushLine(0, "1.Умножение на число", nullptr, MalMatrix_ch);
    Matrix.PushLine(1, "2.Назад", &Main, nullptr);
    Main.Run();
    system("pause");
    return 0;
}
