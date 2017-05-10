#include<iostream>
#include<time.h>
#include<stdio.h>

using namespace std;

int main()
{
	double a[100][100], max1, maxm;
	int n,m;
	srand(time(0));
	printf("Imput nxm matrix \n");
	cin >> n>>m;
	printf("Random matrix \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 11;
			printf("%3.0f", a[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < m; j++)
	{
		max1 = a[0][j];
		for (int i = 1; i < n; i++)
		{
			if(a[i][j]>max1)
			{
				max1 = a[i][j];
			}
		}
		if(j==0)
		{
			maxm = max1;
		}
		if (maxm > max1)
		{
			maxm = max1;
		}
	}
	printf("max stolb min=%3.0f \n", maxm);
	system("pause");
}