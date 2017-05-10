#include<locale.h>
#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;

void random(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(a+i)+j) = rand() % 20 - rand() % 10;
		}
	}
}
void outspec(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(i + 5) << *(*(a + i));
		for (int j = 1; j < m; j++)
		{
			cout << setw(5) << *(*(a + i) + j);
		}
		cout << endl;
	}
}
void out(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%6d", *(*(a + i) + j));
		}
		printf("\n");
	}
}
void preobraz(int **a, int n, int &m)
{
	int jmin = 0;
	cout << "Адреса найденных мин. элементов в строках матрицы\n";
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (*(*(a + i) + jmin)>*(*(a + i) + j))
			{
				jmin = j;
			}
		}
		cout << (*(a + i) + jmin)<<endl;//Вывод адресов мин. элементов
		for (int j = jmin; j<n; j++)
		{
			*(*(a + i) + j) = *(*(a + i) + j + 1);//Цикл переписи
		}
		jmin = 0;
	}
	m--;
}

int main()
{
	system("color f0");
	setlocale(0, "russian");
	srand((unsigned)time(0));
	int n, m;
	puts("Введите размер матрицы nxn+1");
	cin >> n;
	m = n + 1;
	int **a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = new int[m];
	}
	printf("Рандомная матрица\n");
	random(a, n, m);
	out(a, n, m);
	preobraz(a, n, m);//Изменение матрицы до размеров n*n
	cout << "Преобразованная матрица путем удаления мин. элемента из каждой строки с спец. выводом в виде параллелограмма " << endl;
	outspec(a, n, m);
	for (int i = 0; i < n; i++)
		delete[] * (a + i);
	delete[] a;
	cin.ignore(); cin.get();
	return 0;
}