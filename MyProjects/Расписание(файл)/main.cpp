#include <iostream>

using namespace std;

struct Unit {
    int num;
    int kab;
    char name[30];
    char type[100];
};

struct TimeTable {
    Unit array[7];
    int count_array;
    char day[10];
} One;

int main() {
    system("color f0");
    system("chcp 1251");
    system("cls");
    FILE *f;
    int key;
    cout << "Ввод файла - 1(не ввод - любое число)" << endl;
    cin >> key;
    if (key == 1) {
        fopen_s(&f, "TimeTable.txt", "w+b");
        cout << "Введите расписание(5 дней)" << endl;
        cout << "День, номер урока, кабинет, название, тип" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "День" << endl;
            cin >> One.day;
            cout << "Введите количество уроков" << endl;
            cin >> One.count_array;
            for (int j = 0; j < One.count_array; j++)
                cin >> One.array[j].num >> One.array[j].kab >> One.array[j].name >> One.array[j].type;
            fwrite(&One, sizeof(One), 1, f);
        }
        fclose(f);
    }
    fopen_s(&f, "TimeTable.txt", "r+b");
    cout << "Расписание" << endl;
    for (int i = 0; i < 5; i++) {
        fread(&One, 1, sizeof(One), f);
        cout << One.day << endl;
        for (int j = 0; j < One.count_array; j++)
            cout << One.array[j].num << ' ' << One.array[j].kab << ' ' << One.array[j].name << ' ' << One.array[j].type << endl;
    }
    rewind(f);
    cout << endl << endl << "Поиск запросов" << endl;
    int lek = 0, lab = 0, sem = 0, lab5 = 0;
    for (int i = 0; i < 5; i++) {
        fread(&One, 1, sizeof(One), f);
        cout << One.day << endl;
        for (int j = 0; j < One.count_array; j++) {
            if (strcmp(One.array[j].type, "sem") == 0)
                sem++;
            if (strcmp(One.array[j].type, "lab") == 0)
                lab++;
            if (strcmp(One.array[j].type, "lek") == 0)
                lek++;
        }
        cout << "sem - " << sem << " lab - " << lab << " lek - " << lek << endl;
        cout << " lab на 5 этаже" << endl;
        for (int j = 0; j < One.count_array; j++) {
            if (strcmp(One.array[j].type, "lab") == 0 && One.array[j].kab / 100 == 5) {
                lab5++;
                cout << One.array[j].num << ' ' << One.array[j].kab << ' ' << One.array[j].name << ' ' << One.array[j].type << endl;
            }
        }
        cout << "Количество - " << lab5 << endl;
        lek = lab = sem = lab5 = 0;
    }
    _fcloseall();
    system("pause");
    return 0;
}