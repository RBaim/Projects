#include<iostream>
#include<math.h>
#include <time.h>
#define EPS 1e-10

using namespace std;

double det(double **b, int n)
{
	if (n == 1)
	{
		return b[0][0];
	}
	double k, det = 1, tmp;
	int per = 0, g = 0;
	double **a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
	for (int c = 0; c < n - 1; c++)
	{
		for (int i = c + 1; i < n; i++)
		{
			for (int k = c; k <= n - i; k++)
			{
				if (fabs(a[c][c]) < fabs(a[c + k][c]))
				{
					g++;
					tmp = a[c + 1][c];
					per++;
					for (int t = 0; t < n; t++)
					{
						swap(a[c][t], a[c + k][t]);
					}
				}
				if (a[c][c] == 0 && g == 0)
				{
					det = 0;
				}
				g = 0;
			}
			if (det != 0)
			{
				k = a[i][c] / a[c][c];
				for (int j = 0; j < n; j++)
				{
					a[i][j] = a[i][j] - k*a[c][j];
				}
			}
			for (int ix = 0; ix < n; ix++)
			{
				for (int jx = 0; jx < n; jx++)
				{
					if (fabs(a[ix][jx]) < EPS)
					{
						a[ix][jx] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		det = det*(a[i][i]);
	}
	det = det*pow(-1, per);
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return det;
}

void obrat(double**b, double **p, int n, double D)
{
	bool perep = false;
	double **ras = new double*[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		ras[i] = new double[n - 1];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int c = 0, l=0; c < n;c++)
			{
				for (int d = 0, m=0; d < n;d++)
				{
					if (c != i && d != j)
					{
						perep = true;
						ras[l][m] = b[c][d];
						m++;
					}
				}
				if (perep == true)
				{
					l++;
					perep = false;
				}
			}
			 p[j][i]=pow(-1,i+j+2)*det(ras, n - 1) / D;
		}
	}
	puts("Obrat matrix");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%9.3f", p[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));
	int n;
	printf("Imput nxn razmer matrix\n");
	cin >> n;
	printf("Random element matrix\n");
	double **b = new double *[n];
	for (int i = 0; i<n; i++)
	{
		b[i] = new double[n];
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin>>b[i][j];
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			printf("%5.0f", b[i][j]);
		}
		printf("\n");
	}
	double D;
	D = det(b, n);
	cout << D<<endl;;
	if (D != 0)
	{
		double **obratm = new double*[n];
		for (int i = 0; i < n; i++)
		{
			obratm[i] = new double[n];
		}
		obrat(b, obratm, n, D);
	}
	else puts("Net obrat matrix");
	system("pause");
}