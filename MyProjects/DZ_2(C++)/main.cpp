#include <iostream>

#include "Menu.h"
#include "Array.h"
#include "bitstring.h"
#include "fraction.h"
#include "Exc.h"

Array *arr_a, *arr_b;

int Arr_Info() {
    std::cout << "1.a" << std::endl << "2.b" << std::endl;
    int val;
    std::cin >> val;
    return val;
}

void SizeArr() {
    switch (Arr_Info()) {
    case 1:std::cout << "Размер массива " << arr_a->getlen() << std::endl; break;
    case 2:std::cout << "Размер массива " << arr_b->getlen() << std::endl; break;
    }
}

void NewSizeArr() {
    int n_size;
    switch (Arr_Info()) {
    case 1:std::cout << "Введите новый размер" << std::endl;
    x: std::cin >> n_size;
        try {
            arr_a->NewSize(n_size);
        }
        catch (ErrorSizeArray ex) {
            ex.ErrorInfo();
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "Обратитесть в поддержку" << std::endl;
        }
        break;
    case 2:std::cout << "Введите новый размер" << std::endl;
    x1: std::cin >> n_size;
        try {
            arr_b->NewSize(n_size);
        }
        catch (ErrorSizeArray ex) {
            ex.ErrorInfo();
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x1;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "Обратитесть в поддержку" << std::endl;
        }
    }
}

void InArr() {
    int num;
    switch (Arr_Info()) {
    case 1:std::cout << "Введите число" << std::endl;
    x: std::cin >> num;
        try {
            arr_a->InputVal(num);
        }
        catch (ErrorNumWrite ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x;
        }
        catch (ErrorSizeLimit ex) {
            ex.Info();
            std::cout << "Обратитесь к создателю программы" << std::endl;
        }
        break;
    case 2:std::cout << "Введите число" << std::endl;
    x1: std::cin >> num;
        try {
            arr_b->InputVal(num);
        }
        catch (ErrorNumWrite ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x1;
        }
        catch (Exc ex) {
            ex.Info();
            std::cout << "Обратитесь к создателю программы" << std::endl;
        }
    }
}

void InArrSumb() {
    switch (Arr_Info()) {
    case 1:x:std::cout << "Введите элементы(" << arr_a->getlen() << ')' << std::endl;
        try {
            std::cin >> *arr_a;
        }
        catch (Exc er) {
            er.Info();
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x;
        }
        break;
    case 2:x1:std::cout << "Введите элементы(" << arr_b->getlen() << ')' << std::endl;
        try {
            std::cin >> *arr_b; break;
        }
        catch (Exc er) {
            er.Info();
            std::cout << "Попробуйте еще раз" << std::endl;
            goto x1;
        }
    }
}

void SumArray() {
    std::cout << "a+b" << std::endl << *arr_a << std::endl << '+' << std::endl << *arr_b << std::endl << '=' << std::endl;
    try {
        std::cout << (*arr_a) + (*arr_b) << std::endl;
    }
    catch (ErrorSizeLimit er) {
        er.Info();
        std::cout << "Измените параметры и попробуйте снова" << std::endl;
    }
}

void OutArray() {
    std::cout << "a" << std::endl << *arr_a << std::endl << "b" << std::endl << *arr_b << std::endl;
}

void MakeArr() {
    if (arr_a) delete arr_a;
    arr_a = new Array(0);
    if (arr_b) delete arr_b;
    arr_b = new Array(0);
}

void MakeBit() {
    if (arr_a) delete arr_a;
    arr_a = new BitString(0);
    if (arr_b) delete arr_b;
    arr_b = new BitString(0);
}

void MakeFrac() {
    if (arr_a) delete arr_a;
    arr_a = new Fraction(0);
    if (arr_b) delete arr_b;
    arr_b = new Fraction(0);
}

void OperBit() {
    std::cout << "Введите операцию(+, |, *, ^, ~, >, <)((a operation b),(operation a))" << std::endl;
    char op;
    std::cin >> op;
    std::cout << (*arr_a) << std::endl << op << std::endl << (*arr_b) << std::endl << '=' << std::endl;;
    try {
        switch (op) {
        case '|':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) | *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '+':std::cout << (*arr_a) + (*arr_b) << std::endl; break;
        case '*':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) & *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '^':std::cout << (*(reinterpret_cast<BitString*>(arr_a)) ^ *(reinterpret_cast<BitString*>(arr_b))) << std::endl; break;
        case '~':std::cout << ~(*(reinterpret_cast<BitString*>(arr_a))) << std::endl;
        }
    }
    catch (Exc er) {
        er.Info();
        std::cout << "Измените параметры и попробуйте снова" << std::endl;
    }
    if (op == '>' || op == '<') {
        std::cout << "Введите смещение" << std::endl;
        int sh = 0;
        std::cin >> sh;
        BitString out = *(reinterpret_cast<BitString*>(arr_a));
        switch (op) {
        case '>':out >> sh; break;
        case '<':out << sh;
        }
        std::cout << out << std::endl;
    }
}

void OperFrac() {
    std::cout << "Введите операцию(+, -, *, >, <, =)(a operation b)" << std::endl;
    char op;
    std::cin >> op;
    std::cout << *(reinterpret_cast<Fraction*>(arr_a)) << std::endl << op << std::endl << *(reinterpret_cast<Fraction*>(arr_b)) << std::endl << '=' << std::endl;;
    try {
        switch (op) {
        case '+':std::cout << (*(dynamic_cast<Fraction*>(arr_a)) + *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '-':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) - *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '*':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) * *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '/':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) == *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '>':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) > *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '<':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) < *(reinterpret_cast<Fraction*>(arr_b))) << std::endl; break;
        case '=':std::cout << (*(reinterpret_cast<Fraction*>(arr_a)) == *(reinterpret_cast<Fraction*>(arr_b))) << std::endl;
        }
    }
    catch (Exc er) {
        er.Info();
        std::cout << "Обновите исходные данные и повторите операцию" << std::endl;
    }
}

void InFrac() {
    std::cout << "Введите числители и знаменатели дробей(2)" << std::endl;
    switch (Arr_Info()) {
    case 1:x:std::cout << "Введите дробь " << std::endl;
        try {
            std::cin >> (*(reinterpret_cast<Fraction*>(arr_a)));
        }
        catch (DevNilFraction er) {
            er.Info();
            std::cout << "Попробуйте еще раз" << std::endl;
            system("pause");
            goto x;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "Обратитесь к создателю программы" << std::endl;
        }
        catch (ErrorNumWrite er) {
            std::cout << er.what() << std::endl;
            std::cout << "Попробуйте еще раз" << std::endl;
            system("pause");
            goto x;
        }
        break;
    case 2:x1:std::cout << "Введите дробь " << std::endl;
        try {
            std::cin >> (*(reinterpret_cast<Fraction*>(arr_b)));
        }
        catch (DevNilFraction er) {
            er.Info();
            std::cout << "Попробуйте еще раз" << std::endl;
            system("pause");
            goto x1;
        }
        catch (ErrorSizeLimit er) {
            er.Info();
            std::cout << "Обратитесь к создателю программы" << std::endl;
        }
        catch (ErrorNumWrite er) {
            std::cout << er.what() << std::endl;
            std::cout << "Попробуйте еще раз" << std::endl;
            system("pause");
            goto x1;
        }
    }
}

void OutielemArr() {
    int i;
    switch (Arr_Info()) {
    case 1:std::cout << "Введите индекс" << std::endl;;
        std::cin >> i;
        try {
            std::cout << "arr[" << i << "] = " << int((*arr_a)[i]) << std::endl;
        }
        catch (ErrorIndexArray er) {
            er.Info();
            std::cout << "Обновите параметры и попробуйте еще раз" << std::endl;
            system("pause");
        }
        break;
    case 2:std::cout << "Введите индекс" << std::endl;;
        std::cin >> i;
        try {
            std::cout << "arr[" << i << "] = " << int((*arr_b)[i]) << std::endl;
        }
        catch (ErrorIndexArray er) {
            er.Info();
            std::cout << "Обновите параметры и попробуйте еще раз" << std::endl;
            system("pause");
        }
    }
}

void OutFrac() {
    std::cout << "a" << std::endl << (*(reinterpret_cast<Fraction*>(arr_a))) << std::endl << "b" << std::endl << (*(reinterpret_cast<Fraction*>(arr_b))) << std::endl;
}

void Clean() {
    if (arr_a) delete arr_a;
    if (arr_b) delete arr_b;
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Menu Main(4), Array(7), BitStr(6), Frac(4);
    Main.PushLine(0, "1.Массив", &Array, MakeArr);
    Main.PushLine(1, "2.Битовые строки", &BitStr, MakeBit);
    Main.PushLine(2, "3.Рациональные дроби", &Frac, MakeFrac);
    Main.PushLine(3, "4.Выход", nullptr, nullptr);
    Array.PushLine(0, "1.Узнать размер", nullptr, SizeArr);
    Array.PushLine(1, "2.Обновить размер", nullptr, NewSizeArr);
    Array.PushLine(2, "3.Просмотреть массивы", nullptr, OutArray);
    Array.PushLine(3, "4.Ввести число в массив", nullptr, InArr);
    Array.PushLine(4, "5.Ввести массив посимвольно", nullptr, InArrSumb);
    Array.PushLine(5, "6.Сумма двух массивов", nullptr, SumArray);
    Array.PushLine(6, "7.Назад", &Main, nullptr);
    BitStr.PushLine(0, "1.Показать", nullptr, OutArray);
    BitStr.PushLine(1, "2.Показать i элемент", nullptr, OutielemArr);
    BitStr.PushLine(2, "3.Задать размеры", nullptr, NewSizeArr);
    BitStr.PushLine(3, "4.Записать", nullptr, InArrSumb);
    BitStr.PushLine(4, "5.Операции", nullptr, OperBit);
    BitStr.PushLine(5, "6.Назад", &Main, nullptr);
    Frac.PushLine(0, "1.Показать дроби", nullptr, OutFrac);
    Frac.PushLine(1, "2.Ввести дроби", nullptr, InFrac);
    Frac.PushLine(2, "3.Операции", nullptr, OperFrac);
    Frac.PushLine(3, "4.Назад", &Main, nullptr);
    Main.Run();
    Clean();
    system("pause");
    return 0;
}
