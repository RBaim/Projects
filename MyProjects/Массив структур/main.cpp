#include <iostream>

using namespace std;

struct Citizen {
    char FIO[32];
    char city[32];
    char Country[32];
    int age;
    static int count;
    static int maxsize;
};

int Citizen::count = 0;

int Citizen::maxsize = 0;

void Print(Citizen *array) {
    for (int i = 0; i < array[0].count; i++) {
        cout << array[i].FIO << " " << array[i].city << " " << array[i].Country << " " << array[i].age << endl;
    }
}

void Input(Citizen *array) {
    int i = 0;
    do {
        cin >> array[i].FIO >> array[i].city >> array[i].Country >> array[i].age;
        i++;
        array[i].count++;
    } while (strnlen_s(array[i - 1].FIO, sizeof(array[i - 1].FIO)) > 0 && i < array[0].maxsize);
    array[i].count--;
}

void DelMillon(Citizen *array, char **millions, int n) {
    bool key;
    for (int i = 0; i < array[0].count; i++) {
        key = false;
        for (int j = 0; j < n; j++) {
            if (strcmp(array[i].city, *(millions + j)) == 0) {
                key = true;
            }
        }
        if (!key) {
            key = true;
            array[0].count--;
            for (int im = i; im < array[0].count; im++) {
                array[im] = array[im + 1];
            }
            i--;
        }
    }
}

void Sort(Citizen *array) {
    bool key = true;
    while (key) {
        key = false;
        for (int i = 0; i < array[0].count - 1; i++) {
            if (array[i].age > array[i + 1].age) {
                swap(array[i], array[i + 1]);
                key = true;
            }
        }
    }
    key = true;
    while (key) {
        key = false;
        for (int i = 0; i < array[0].count - 1; i++) {
            if (array[i].age == array[i + 1].age && strcmp(array[i].FIO, array[i + 1].FIO) > 0) {
                swap(array[i], array[i + 1]);
                key = true;
            }
        }
    }
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    Citizen *array = new Citizen[100];
    char **millions;
    millions = new char*[6];
    for (int i = 0; i < 6; i++)
        *(millions + i) = new char[32];
    strcpy(millions[0], "Moskow");
    strcpy(millions[1], "Peterburg");
    strcpy(millions[2], "Kiev");
    strcpy(millions[3], "Ufa");
    strcpy(millions[4], "Novosibirsk");
    strcpy(millions[5], "Omsk");
    array[0].maxsize = 100;
    cout << "Введите жителей или ctrl+z(ФИО||Город||Страна||Возраст)" << endl;
    Input(array);
    cout << "Введенные жители" << endl;
    Print(array);
    cout << endl;
    cout << "Список жителей без жителей мелких городов отсортированный" << endl;
    DelMillon(array, millions, 6);
    Sort(array);
    Print(array);
    for (int i = 0; i < 6; i++)
        delete[] * (millions + i);
    delete[] millions;
    delete[] array;
    system("pause");
    return 0;
}
