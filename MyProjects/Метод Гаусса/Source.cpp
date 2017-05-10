#include <iostream>
#include <locale.h>
#define EPS 1e-9

using namespace std;

void SLAY(double **a, int n, int m);

void gauss(double **a, int n, int m);

int main()
{
	setlocale(0, "Russian");
	double **a;
	int n, m;
	cout << "Введите размеры расширенной матрицы nxm" << endl;
	cin >> n >> m;
	a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
	}
	cout << "Введите расширенную матрицу" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "Введенная СЛАУ" << endl;
	SLAY(a, n, m);
	cout << endl;
	gauss(a, n, m);
	cout << "Преобразованная СЛАУ" << endl;
	SLAY(a, n, m);
	cin.ignore(); cin.get();
	return 0;
}

void SLAY(double **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%9.3f", a[i][j]);
		}
		cout << endl;
	}
}

void gauss(double **a, int n, int m)
{
	double max, k;
	int im = 0, j = 0, swapstolb = 0;
	for (int i = 0; i < n - 1; i++)
	{
		max = a[i][j];
		im = i;
		while (fabs(max) < EPS && im < n - 1)
		{
			im++;
			max = a[im][j];
		}
		if (im == n - 1 && j != 0)
		{
			while (fabs(a[i][j]) < EPS && j < m)
			{
				j++;
			}
		}
		if (fabs(max) < EPS)
		{
			swapstolb = j + 1;
			if (swapstolb < m)
			{
				swapstolb++;
				for (int sp = 0; sp < n; sp++)
				{
					swap(a[sp][j], a[sp][swapstolb]);
				}
				i--;
				im = 0;
			}
			else
			{
				i = n - 1;
				j = -1;
			}
		}
		else
		{
			for (int sp = 0; sp < m; sp++)
			{
				swap(a[im][sp], a[i][sp]);
			}
			SLAY(a, n, m);
			cout << endl;
			max = a[i][j];
			for (int sp = 0; sp < m; sp++)
			{
				a[i][sp] /= max;
			}
			SLAY(a, n, m);
			cout << endl;
			for (int v = i + 1; v < n; v++)
			{
				k = a[v][j];
				for (int q = 0; q < m; q++)
				{
					a[v][q] -= k * a[i][q];
				}
			}
			SLAY(a, n, m);
			cout << endl;
			j++;
		}
		for (int ix = 0; ix < n; ix++)
		{
			for (int jx = 0; jx < m; jx++)
			{
				if (fabs(a[ix][jx]) < EPS)
				{
					a[ix][jx] = 0;
				}
			}
		}
	}
	if (j != -1)
	{
		j = 0;
		for (j; j < m; j++)
		{
			if (a[n - 1][j] != 0)
			{
				break;
			}
		}
		max = a[n - 1][j];
		for (int sp = 0; sp < m && max != 0; sp++)
		{
			a[n - 1][sp] /= max;
		}
	}
	for (int ix = 0; ix < n; ix++)
	{
		for (int jx = 0; jx < m; jx++)
		{
			if (fabs(a[ix][jx]) < EPS)
			{
				a[ix][jx] = 0;
			}
		}
	}
}