#include<locale.h>
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	srand((unsigned)time(0));
	long double tmp;
	int n, m, k;
	puts("¬ведите размер первой матрицы nxm");
	cin >> n >> m;
	long double **a = new long double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new long double[m];
	}
	puts("¬ведите размер второй матрицы mxk(ввести только k)");
	cin >> k;
	long double **b = new long double*[m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new long double[k];
	}
	long double **c = new long double*[n];
	for (int i = 0; i < k; i++)
	{
		c[i] = new long double[k];
	}
	puts("¬вод первой матрицы");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	puts("¬вод второй матрицы");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin>>b[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			tmp = 0;
			for (int k = 0; k < m; k++)
			{
				tmp = tmp+a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
	puts("–езультат умножени€");
	for(int i=0; i<n;i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf("%5.0lf", c[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[]a;
	for (int i = 0; i < m; i++)
	{
		delete[] b[i];
	}
	delete[]b;
	for (int i = 0; i < k; i++)
	{
		delete[] c[i];
	}
	delete[]c;
	system("pause");
	}