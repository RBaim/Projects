#include <iostream>
#include <time.h>

using namespace std;

void out(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d", *(*(a + i) + j));
		}
		printf("\n");
	}
}

void random(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(a + i) + j) = rand() % 20 - rand() % 10;
		}
	}
}

int poisk(int **a, int n, int m)
{
	int sum = 0, summax = 0, imax;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += *(*(a + i) + j);
		}
		if (summax < sum)
		{
			imax = i;
			summax = sum;
		}
	}
	return imax;
}

void deleterstr(int **a, int &n, int &m, int del)
{
	for (int i = del; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(a + i) + j) = *(*(a + i + 1) + j);
		}
	}
	n--;
	delete[] * (a + n);
}

int main()
{
	srand(time(NULL));
	int **a, n, m;
	puts("Input n, m for matrix");
	cin >> n >> m;
	a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = new int[m];
	}
	random(a, n, m);
	cout << poisk(a, n, m) + 1 << endl;
	puts("Random matrix");
	out(a, n, m);
	deleterstr(a, n, m, poisk(a, n, m));
	puts("Redact matrix");
	out(a, n, m);
	system("pause");
	for (int i = 0; i < n; i++)
	{
		delete[] * (a + i);
	}
	delete[] a;
	return 0;
}
