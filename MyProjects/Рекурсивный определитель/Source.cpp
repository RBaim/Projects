#include<iostream>
#include<math.h>

using namespace std;

double det(double **b, int n)
{
	if (n == 1)
	{
		return b[0][0];
	}
	else
	{
		bool perep = false;
		double detr = 0;
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				double **a = new double*[n - 1];
				for (int i = 0; i < n - 1; i++)
				{
					a[i] = new double[n - 1];
				}
				for (int c = 0, l = 0; c < n; c++)
				{
					for (int d = 0, m = 0; d < n; d++)
					{
						if (c != i && d != j)
						{
							perep = true;
							a[l][m] = b[c][d];
							m++;
						}
					}
					if (perep == true)
					{
						l++;
						perep = false;
					}
				}
				detr = detr + b[i][j] * det(a, n - 1)*pow(-1, i+j+2);
				for (int i = 0; i < n - 1; i++)
				{
					delete[] a[i];
				}
				delete[] a;
			}
		}
		return detr;
	}
}

int main()
{
	int n, k;
	printf("Imput nxn razmer matrix\n");
	cin >> n;
	printf("Imput or rand?(1, luboe)\n");
	cin >> k;
	double **b = new double *[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new double[n];
	}
	if (k == 1)
	{
		printf("Imput element matrix\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cin >> b[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				b[i][j] = rand() % 11;
				printf("%5.0f", b[i][j]);
			}
			printf("\n");
		}
	}
	double D;
	D = det(b, n);
	printf("DET=%f\n", D);
	for (int i = 0; i<n; i++)
	{
		delete[] b[i];
	}
	delete[] b;
	system("pause");
	return 0;
}
