#include <iostream>

using namespace std;

char* EndSlovChar(char *st, char *check) {
    char *new_st = new char[strlen(st)];
    char *ptr1 = st;
    char *ptr2;
    bool write = false;
    int size = 0;
    while (*ptr1 != '\0') {
        ptr2 = ptr1;
        while (*ptr2 != '\0' && *ptr2 != ' ') {
            ptr2++;
        }
        for (int i = 0; i < strlen(check); i++) {
            if (*(ptr2 - 1) == *(check + i)) {
                write = true;
                break;
            }
        }
        if (write) {
            strncpy((new_st + size), ptr1, strlen(ptr1) - strlen(ptr2));
            size += strlen(ptr1) - strlen(ptr2);
            *(new_st + size) = ' ';
            size++;
        }
        write = false;
        ptr2++;
        ptr1 = ptr2;
    }
    *(new_st + size - 1) = '\0';
    return new_st;
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    char *st = new char[100];
    char check[] = "AEIOUYaeiouy";
    cout << "¬ведите строку\n";
    cin.getline(st, 100);
    char *st_new = EndSlovChar(st, check);
    cout << "—лова заканчивающиес€ на гласные в строке:\n" << st_new << endl;
    delete[] st;
    delete st_new;
    system("pause");
    return 0;
}
