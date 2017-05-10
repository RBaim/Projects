#include<windows.h>
#include<iostream>
#include<stdio.h>
wchar_t* ctow(char *c, size_t max, int n)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int size = strlen(c);
	c[size] = ' ';
	c[size+1] = '\0';
	char str[100];
	sprintf(str, "%d", n);
	strcat(c, str);
	wchar_t* w = new wchar_t[max];
	mbstowcs(w, c, max);
	return w;
}
int main()
{
	int n;
	wchar_t *a;
	char b[100], c[100];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("¬ведите название папки\n");
	gets_s(b);
	printf("¬ведите количество папок создаваемых\n");
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		strcpy(c, b);
		a = ctow(c, 100, i+1);
		CreateDirectoryW(a, NULL);
	}
}