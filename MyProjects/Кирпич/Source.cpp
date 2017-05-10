#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>

void main() {
	setlocale(0, "russian");
	puts("Введите размеры кирпича(a,b,c) и проёма(a,b)");
	int a, b, c, m, n, k=0;
	scanf_s("%d%d%d%d%d", &a, &b, &c, &m, &n);
	printf("a=%d, b=%d, c=%d, m=%d, n=%d.\n",a, b, c, m, n);
	if (a <= m && b <= n)
	{
		puts("Лезет a <= m && b <= n");
		k = 1;
	}
	if (a <= m && c <= n)
	{
		puts("Лезет a <= m && c <= n");
		k = 1;
	}
	if (c <= m && b <= n)
	{
		puts("Лезет c <= m && b <= n");
		k = 1;
	}
	if (b <= m && a <= n)
	{
		puts("Лезет b <= m && a <= n");
		k = 1;
	}
	if (c <= m && a <= n)
	{
		puts("Лезет c <= m && a <= n");
		k = 1;
	}
	if (a <= m && b <= n)
	{
		puts("Лезет b <= m && c <= n");
		k = 1;
	}
	if (k == 0)
	{
		puts("Не лезет кирпич в проём");
	}
	system("pause");
}