#include <iostream>
#include <time.h>

using namespace std;

void out(double **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%9.3f", *(*(a + i) + j));
		}
		printf("\n");
	}
}

void random(double **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(a + i) + j) = rand() % 20 - rand() % 10;
		}
	}
}

double sredanech(double **a, int n, int m)
{
	double sred = 0, kol = 0;;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + j % 2 == 0)
			{
				sred += *(*(a + i) + j);
				kol++;
			}
		}
	}
	sred /= kol;
	return sred;
}

void formnew(double **a, double **b, int n, int m, double zn)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(a + i) + j) >= 0)
			{
				*(*(b + i) + j) = *(*(a + i) + j);
			}
			else
			{
				*(*(b + i) + j) = zn;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	double **a, **b, n, m;
	puts("Input n, m for matrix");
	cin >> n >> m;
	a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = new double[m];
	}
	b = new double*[n];
	for (int i = 0; i < n; i++)
	{
		*(b + i) = new double[m];
	}
	random(a, n, m);
	puts("Random matrix");
	out(a, n, m);
	cout << "Srednee arifmet nechet " << sredanech(a, n, m) << endl;
	formnew(a, b, n, m, sredanech(a, n, m));
	puts("New matrix");
	out(b, n, m);
	system("pause");
	for (int i = 0; i < n; i++)
	{
		delete[] * (a + i);
	}
	delete[] a;
	for (int i = 0; i < n; i++)
	{
		delete[] * (b + i);
	}
	delete[] b;
	return 0;
}