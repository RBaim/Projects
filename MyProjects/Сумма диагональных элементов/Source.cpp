#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	srand(time(0));
	double a[100][100], sum=0;
	int n;
	puts("Imput n matrix");
	cin >> n;
	puts("Random Matrix");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 4;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%8.0f",a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		sum += a[i][i];
	}
	printf("diagonal sum=%3.0f \n",sum);
	sum = 0;
	for (int i = n-1, j=0; i < 0, j<n; i--, j++)
	{
				sum += a[i][j];
	}
	printf("poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
				sum += a[i][j];
		}
	}
	printf("up diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = n-1; i >=1; i--)
	{
		for (int j = 0; j < i; j++)
		{
				sum += a[i][j];
		}
	}
	printf("down diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
				sum += a[i][j];
		}
	}
	printf("up poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 1; i <n; i++)
	{
		for (int j = n-i; j < n; j++)
		{
				sum += a[i][j];
		}
	}
	printf("down poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 0; i < (n-1)/2; i++)
	{
		for (int j = i+1; j <n-i-1; j++)
		{
				sum += a[i][j];
		}
	}
	printf("up diagonal and up poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = n-1; i > (n-1)/2; i--)
	{
		for (int j = i-1; j >= n-i; j--)
		{
				sum += a[i][j];
		}
	}
	printf("down diagonal and down poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 1; i<=n-2; i++)
	{
		for (int j = 0; j < (n-1)/2; j++)
		{
				sum += a[i][j];
		}
	}
	printf("down diagonal and up poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	for (int i = n - 1; i >(n - 1) / 2; i--)
	{
		for (int j = i - 1; j >= n - i; j--)
		{
			sum += a[j][i];
		}
	}
	printf("up diagonal and down poboch diagonal sum=%3.0f \n", sum);
	sum = 0;
	printf("Imput a-strok b-stolb \n");
	int b, c;
	cin >> b >> c;
	for (int i = 0; i < b-1; i++)
	{
		for (int j = 0; j < (c-1)/(i+1); j++)
		{
				sum += a[i][j];
		}
	}
	printf("a and b up sum=%3.0f \n", sum);
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j > (c - 1) / (i + 1); j--)
		{
			sum += a[i][j];
		}
	}
	printf("a and b down sum=%3.0f \n", sum);
	system("pause");
	return 0;
}