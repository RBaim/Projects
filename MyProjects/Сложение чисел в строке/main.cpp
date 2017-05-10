#include <iostream>

using namespace std;

void SumsStr(char **str) {
    char *ptr = *str;
    char *op1_1, *op1_2, *op2_1, *op2_2;
    int ch1, ch2;
    while (*ptr != '\0') {
        if (*ptr == '+') {
            if (*(ptr - 1) >= 48 && *(ptr - 1) <= 57 && *(ptr + 1) >= 48 && *(ptr + 1) <= 57) {
                op1_1 = ptr - 1;
                op1_2 = ptr - 1;
                while ((*op1_1 >= 48) && (*op1_1 <= 57)) {
                    op1_1--;
                }
                op1_1++;
                ch1 = atoi(op1_1);
                op2_1 = ptr + 1;
                op2_2 = ptr + 1;
                while (*op2_2 >= 48 && *op2_2 <= 57) {
                    op2_2++;
                }
                op2_2--;
                ch2 = atoi(op2_1);
                itoa(ch1 + ch2, op1_1, 10);
                op2_2++;
                strcat(op1_1, op2_2);
                ptr = op1_1;
            }
            else {
                ptr++;
            }
        }
        else {
            ptr++;
        }
    }
}

int main() {
    system("color f0");
    system("chcp 1251");
    system("cls");
    char *str = new char[100];
    printf("Введите строку с числами\n");
    cin.getline(str, 100);
    SumsStr(&str);
    printf("Преобразованная строка\n");
    cout << str << endl;
    delete[] str;
    system("pause");
    return 0;
}