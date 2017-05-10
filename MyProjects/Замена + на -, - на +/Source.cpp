#include <iostream>
#include <ctime>
#include <clocale>
#include<windows.h>

int *matrix(int &n)
{
	int *a;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 20 - 10;
	}
	return a;

}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int n, *a;
	puts("Введите размер массива");
	std::cin >> n;
	a = matrix(n);
	puts("Рандомный массив");
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
	puts("Измененный массив");
	for (int i = 0; i < n; i++)
	{
			a[i] = -a[i];
			printf("%5d", a[i]);
	}
	printf("\n");
	system("pause");
}