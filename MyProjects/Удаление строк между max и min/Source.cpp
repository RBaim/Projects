#include<iostream>
#include<time.h>

int main()
{
	float a[100][100];
	int k, n, imin, imax;
	puts("Imput n matrix");
	scanf_s("%d", &n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 21-10;
		}
	}
	imax = 0;
	imin = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	puts("Imput k stolb");
	scanf_s("%d", &k);
	for (int i = 1; i < n; i++)
	{
		if (a[i][k - 1] > a[imax][k - 1])
		{
			imax = i;
		}
		if (a[i][k - 1] < a[imin][k - 1])
		{
			imin = i;
		}
	}
	printf("\n imin=%d imax=%d \n", imin + 1, imax + 1);
	if (imax > imin)
	{
		for (int i = 0; i < imax - imin - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[imin + i + 1][j] = a[imax + i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < imin - imax - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[imax + i + 1][j] = a[imin + i][j];
			}
		}
	}
	if (abs(imax - imin-1) == 1 &&imax > imin)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[imax+i][j] = a[imax + i + 1][j];
			}
		}
	}
	if (abs(imax - imin-1) == 1 && imax < imin)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[imin+i][j] = a[imin + i + 1][j];
			}
		}
	}
	for (int i = 0; i <= n - abs(imax - imin); i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}