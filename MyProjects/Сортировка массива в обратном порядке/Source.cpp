#include <stdio.h>
#include <time.h>
#include <iostream>
#include<locale.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	srand(time(NULL));
	int a[20], n , z, tmp, k;
	puts("Введите количество элементов массива");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 201;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	cout << endl;
	z = n / 2;
	for (int i = 0; i < z; i++)
	{
		tmp = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = tmp;
	}
	puts("Отсортированный массив");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	cout << endl;
	system("pause");
}