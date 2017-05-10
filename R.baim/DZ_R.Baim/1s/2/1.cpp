#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	srand((unsigned)time(NULL));
	double a[50], tmp;
	int n;
	puts("Введите количество элементов  массива(<=50)");
	cin >> n;
	puts("Рандомный массив");
	for (int i = 0; i < n; i++)
	{
		a[i]= 1.0*rand()/100-1.0*rand()/100;
		printf("%9.2lf", a[i]);
	}
	cout << endl;
	for (int i = 1,z; i < n; i++)
	{
		tmp = a[i];
		z = i - 1;
		while (z >= 0 && a[z] > tmp)
		{
			a[z + 1] = a[z];
			z--;
		}
		a[z + 1] = tmp;
	}
	puts("Массив отсортированный");
	for (int i = 0; i < n; i++)
	{
		printf("%9.2lf", a[i]);
	}
	cout << endl;
	system("pause");
}
