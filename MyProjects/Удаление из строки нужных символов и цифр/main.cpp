#include <iostream>
#include <crtdbg.h>

using namespace std;

char* Del_Sumb(char *st, char *check) {
    char *new_st = new char[strlen(st)];
    char *ptr = st;
    bool write = true;
    char *writer = new_st;
    while (*ptr!='\0') {
        for (int i = 0; i < strlen(check); i++) {
            if (*ptr == *(check + i)) {
                write = false;
                break;
            }
        }
        if (write) {
            *writer = *ptr;
             writer++;
        }
        write = true;
        ptr++;
    }
    *writer = '\0';
    return new_st;
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    char *st = new char[100]; char *new_st;
    cout << "Введите строку\n";
    cin >> st;
    new_st = Del_Sumb(st, "#@*!0123456789");
    cout << "Строка без (#@*!0123456789):\n" << new_st << endl;
    delete[] st;
    delete new_st;
    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}