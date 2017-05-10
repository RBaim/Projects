#include<math.h>
#include<iostream>
#include<time.h>
#include<stdio.h>

using namespace std;

int main()
{
	srand(time(NULL));
	double a[100][100];
	int n;
	puts("Imput n(n-nechetn)");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 201- rand() % 201;
		}
	}
	puts("Random Matrix");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%8.0f", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	puts("Spiral");
	for (int k = 0; k < n / 2 + 1; k++)
	{
		for (int i = k, j=k; j < n - k; j++)
		{
			printf("%8.0f", a[i][j]);
		}
		for (int j = n - k-1, i = k+1; i < n - k; i++)
		{
			printf("%8.0f", a[i][j]);
		}
		for (int i = n - k-1, j = n - k-2; j >=k; j--)
		{
			printf("%8.0f", a[i][j]);
		}
		for (int i = n - k-2, j = k; i >= k + 1; i--)
		{
			printf("%8.0f", a[i][j]);
		}
	}
	cout << endl;
	system("pause");
}