#include <iostream>
#include "Sets.h"

Sets<int> A, B, C;

void sms1() {
    printf("1.Ввод множеств\n");
    printf("2.Операции с множествами\n");
    printf("3.Просмотр множеств\n");
    printf("4.Завершение программы\n");
}

void sms2() {
    printf("1.Множество А\n");
    printf("2.Множество B\n");
}

void sms3() {
    printf("1.Множество А\n");
    printf("2.Множество B\n");
    printf("3.Множество Ans\n");
}

void sms4() {
    printf("1.Пересечение &\n");
    printf("2.Объединение |\n");
    printf("3.Разность(дополнение) /\n");
    printf("4.Проверка вхождения элемента\n");
}

template <typename T>
void PrinSet(Sets<T> &Out) {
    for (int i = 0; i < Out.getlen(); i++) {
        std::cout << Out(i) << " ";
    }
    printf("\n");
}

template <typename T>
void InputSet(Sets<T> &In) {
    int s;
    printf("Введите мощность множества\n");
    scanf_s("%d", &s);
    In.NewMem(s);
    printf("Введите множество\n");
    for (int i = 0; i < In.getlen(); i++) {
        std::cin >> s;
        In.input(s, i);
    }
    In.DelRepiats();
    In.Sort();
    system("cls");
}

template<typename T>
void RecSwitch3(Sets<T> &T1, int &op, Sets<T> &T2) {
    switch (op) {
    case 1:C = T1 & T2; break;
    case 2:C = T1 | T2; break;
    case 3:C = T1 / T2;
    }
    PrinSet(T1);
    switch (op) {
    case 1:printf("&\n"); break;
    case 2:printf("|\n");; break;
    case 3:printf("/\n");;
    }
    PrinSet(T2);
    printf("=\n");
    PrinSet(C);
    std::cin.ignore(); std::cin.get();
    system("cls");
}

template<typename T>
void RecSwitch2(Sets<T> &T1, int &op, int &d) {
    switch (d) {
    case 1:RecSwitch3(T1, op, A); break;
    case 2:RecSwitch3(T1, op, B);
    }
}

void RecSwitch1(int &n, int &op, int &d) {
    switch (n)
    {
    case 1: RecSwitch2(A, op, d); break;
    case 2: RecSwitch2(B, op, d);
    }
}

template<typename T>
void CheckEl(Sets<T> &T) {
    int n;
    printf("Введите проверяемый элемент\n");
    scanf_s("%d", &n);
    printf("Множество:\n");
    PrinSet(T);
    printf("Результат проверки %d\n", T.CheckAccessory(n));
    std::cin.ignore(); std::cin.get();
    system("cls");
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    int n, op, d;
    do {
        sms1();
        scanf_s("%d", &n); system("cls");
        switch (n) {
        case 1:sms2(); scanf_s("%d", &n); system("cls");
            switch (n) {
            case 1:InputSet(A); break;
            case 2:InputSet(B);
            }
            break;
        case 2:sms2(); scanf_s("%d", &n); system("cls"); sms4(); scanf_s("%d", &op); system("cls");
            if (op != 4) {
                sms2(); scanf_s("%d", &d); system("cls");
                RecSwitch1(n, op, d);
            }
            else {
                switch (n) {
                case 1:CheckEl(A); break;
                case 2:CheckEl(B);
                }
            }
            break;
        case 3:sms3(); scanf_s("%d", &n); system("cls");
            switch (n) {
            case 1:PrinSet(A); std::cin.ignore(); std::cin.get();
                system("cls"); break;
            case 2:PrinSet(B); std::cin.ignore(); std::cin.get();
                system("cls"); break;
            case 3:PrinSet(C); std::cin.ignore(); std::cin.get();
                system("cls");
            }
        }
    } while (n != 4);
    return 0;
}