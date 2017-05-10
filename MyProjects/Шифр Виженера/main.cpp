#include <iostream>
#include <ctime>

int main() {
    FILE *f;
    fopen_s(&f, "in.txt", "r+");
    rewind(f);
    FILE *g;
    fopen_s(&g, "out.txt", "w+");
    FILE *r;
    fopen_s(&r, "desh.txt", "w+");
    char key[] = "lemon";
    char ptr;
    srand(time(NULL));
    int i = 0;
    while ((ptr = getc(f)) != EOF) {//Шифровка
        if (ptr >= 97 && ptr <= 122)
            ptr = (ptr + key[i % (strlen(key))] - 2*'a') % 26 + 'a';
        i++;
        putc(ptr, g);
    }
    rewind(g);
    i = 0;
    while ((ptr = getc(g)) != EOF) {//Расшифровка
        if (ptr >= 97 && ptr <= 122)
            ptr = (ptr - (key[i % (strlen(key))]) + 26) % 26 + 'a';
        i++;
        putc(ptr, r);
    }
    _fcloseall();
    return 0;
}
