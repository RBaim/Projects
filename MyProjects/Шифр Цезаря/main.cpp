#include <iostream>

#include <ctime>

using namespace std;

int main() {
    FILE *f;
    fopen_s(&f, "in.txt", "r+");
    rewind(f);
    FILE *g;
    fopen_s(&g, "out.txt", "w+");
    FILE *r;
    fopen_s(&r, "desh.txt", "w+");
    char ptr;
    srand(time(NULL));
    int sh = 2;
    while ((ptr = getc(f)) != EOF) {//Шифровка
        if (ptr >= 97 && ptr <= 122) {
            ptr = (ptr + sh - 'a') % 26 + 'a';
        }
        putc(ptr, g);
    }
    rewind(g);
    while ((ptr = getc(g)) != EOF) {//Расшифровка
        if (ptr >= 97 && ptr <= 122) {
            ptr = (ptr - sh + 26 - 'a') % 26 + 'a';
        }
        putc(ptr, r);
    }
    _fcloseall();
    return 0;
}
