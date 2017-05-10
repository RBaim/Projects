#include <time.h>

#include <iostream>

using namespace std;

int SumPosChet(int *array, int size) {//Вычисление суммы элементов на четных позициях
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0 && *(array+i) > 0) {
            sum += *(array + i);
        }
    }
    return sum;
}

void Input(int *array, int size) {//Ввод массива
    cout << "Ввод элементов" << endl;
    for (int i = 0; i < size; i++) {
        cin >> *(array + i);
    }
}

void Out(int *array, int size) {//Вывод массива
    for (int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

void Random(int *array, int size) {//Рандом массива
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 20 - 10;
    }
}

int MinNegative(int *array, int size) {//Вычисление минимального произведения отрицательных элементов подряд идущих
    int res1 = 1, res2 = 1;
    for (int i = 0; i < size; i++) {
        if (*(array + i) < 0) {
            for (int j = i; j < size && *(array + j) < 0; j++) {
                res2 *= (*(array + j));
                i++;
            }
            if ((res2) < (res1) || res1 == 1) {
                res1 = res2;
            }
            res2 = 1;
        }
    }
    return res1;
}

int* NewArray(int *array, int size, int &sizenew) {//Создание нового массива из положительных элементов исходного массива
    int countp = 0;
    for (int i = 0; i < size; i++) {
        if (*(array + i) > 0) {
            countp++;
        }
    }
    if (countp == 0) {
        sizenew = 0;
        return nullptr;
    }
    int *neint = new int[countp];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (*(array + i) > 0) {
            *(neint + j) = *(array + i);
            j++;
        }
    }
    sizenew = countp;
    return neint;
}

int main() {
    srand(time(NULL));
    system("chcp 1251");
    system("color f0");
    system("cls");
    int *array, size;
    cout << "Введите количество элементв массива" << endl;
    cin >> size;
    array = new int[size];
    //Input(array, size); //Ввод данных
    Random(array, size);//
    cout << "Рандомный массив" << endl;
    Out(array, size);
    cout << "Сумма положительных четных(позиция) элементов " << SumPosChet(array, size) << endl;
    cout << "Минимальное произведение подряд идущих отрицательных элементов " << MinNegative(array, size) << endl;
    int sizenew;
    int *newarray = NewArray(array, size, sizenew);
    cout << "Новый массив из положительных элементов исходного массива" << endl;
    Out(newarray, sizenew);
    delete newarray;
    delete[] array;
    system("pause");
    return 0;
}