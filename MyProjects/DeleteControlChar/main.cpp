#include <stdio.h>

int main() {
    FILE *f = fopen("1.txt", "r");
    FILE *g = fopen("open.txt", "w+");
    char ptr;
    while ((ptr = getc(f)) != EOF)
        if (ptr != '\n' && ptr != '\t' && ptr != '\v') putc(ptr, g);
    return 0;
}