#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int *a;
	int n;
	cout << "Введите количество элементов массива\n";
	cin >> n;
	a = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() % 10 - rand() % 10;
	}
	cout << "Случайные элементы массива\n";
	for (int i = 0; i < n; i++)
	{
		cout<< *(a + i) <<" ";
	}
	cout << endl;
	cout << "Адреса отрицательных элементов массива\n";
	if (*a >= 0)
	{
		*a = 0;
	}
	else
	{
		cout << a << endl;
	}
	for (int i = 1; i < n; i++)
	{
		if (*(a + i) < 0)
		{
			*a += *(a + i);
			cout << a+i << endl;
		}
	}
	cout << "Сумма отрицательных элементов " << *a << endl;
	free(a);
	cin.ignore(); cin.get();
	return 0;
}
