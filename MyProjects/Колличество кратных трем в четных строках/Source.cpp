#include<stdio.h>
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

int main()
{
	srand(time(0));
	double a[100][100];
	int n, m, k = 0;
	printf("Imput nxm matrix \n");
	cin >> n >> m;
	printf("Random matrix \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 21;
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	for (int i =1;i<n; i=i+2)
	{
		for (int j = 0; j < m; j++)
		{
			if (fmod(a[i][j],3) == 0 && a[i][j]!=0)
			{
				k++;
			}
		}
	}
	printf("Krat 3 v nechet %d", k);
	system("pause");
}