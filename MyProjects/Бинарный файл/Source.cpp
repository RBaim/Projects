#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>

struct nums
{
	int im;
}num;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, size;
	puts("Создание файла, введите количество чисел");
	std::cin >> n;
	FILE *f = fopen("1.txt", "w+b");
	for (int i = 0; i < n; i++)
	{
		num.im = rand();
		fwrite(&num, sizeof(num), 1, f);
	}
	fclose(f);
	f = fopen("1.txt", "rb");
	puts("Содержимое файла");
	while (fread(&num, sizeof(num), 1, f) != 0)
	{
		printf("%d ", num.im);
	}
	printf("\n");
	fclose(f);
	f = fopen("1.txt", "rb");
	fseek(f, 0, SEEK_END);
	FILE *g = fopen("2.txt", "w+b");
	size = ftell(f) / sizeof(num);
	n = sizeof(num);
	puts("Новый файл");
	for (int i = 1; i <= size; i++)
	{
		fseek(f, -i*n, SEEK_END);
		fread(&num, sizeof(num), 1, f);
		if (num.im % 2 == 1)
		{
			fwrite(&num, sizeof(num), 1, g);
			printf("%d ", num.im);
		}
	}
	printf("\n");
	std::cin.ignore(); std::cin.get();
}