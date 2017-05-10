#include<iostream>
#include<time.h>

int main()
{
	srand(time(0));
	float a[100][100];
	int idel, jdel, n, k = 0;
	puts("Imput n matrix");
	std::cin >> n;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = rand() % 201 - 50;
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i<n - k; i++)
	{
		for (int j = 0; j<n - k; j++)
		{
			if (a[i][j]<0)
			{
				idel = i;
				jdel = j;
				for (int c = 0; c<n - idel - 1; c++)
				{
					for (int d = 0; d<n - k; d++)
					{
						a[idel + c][d] = a[idel + c + 1][d];
					}
				}
				for (int c = 0; c<n - jdel - 1; c++)
				{
					for (int d = 0; d<n - k; d++)
					{
						a[d][jdel + c] = a[d][jdel + c + 1];
					}
				}
				k++;
				puts("Redact matrix");
				for (int i = 0; i<n - k; i++)
				{
					for (int j = 0; j<n - k; j++)
					{
						printf("%5.0f", a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				i = 0;
				j = 0;
			}
		}
	}
	puts("Redact matrix");
	for (int i = 0; i<n - k; i++)
	{
		for (int j = 0; j<n - k; j++)
		{
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}