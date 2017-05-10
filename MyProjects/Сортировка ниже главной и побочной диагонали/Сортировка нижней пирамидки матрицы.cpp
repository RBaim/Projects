#include <iostream>
#include <time.h>

int main()
{
	srand(time(0));
	float a[10][10], tmp;
	int n;
	puts("Imput n matrix");
	std::cin >> n;
	puts("Randon matrix");
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = rand() % 10;
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	for (int i = n - 1; i >=((n - 1) / 2)-1; i--)
	{
		for (int j = i; j >=n - i-1; j--)
		{
			for (int c = n-1 ; c >=((n - 1) / 2)-1; c--)
			{
				for (int d = c; d >=n-c-1; d--)
				{
					if (a[i][j]>a[c][d])
					{
						tmp = a[i][j];
						a[i][j] = a[c][d];
						a[c][d] = tmp;
					}
				}
			}
		}
	}
	puts("Sort matrix");
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (i + j >= n-1 && j <= i)
			{
				printf("%5.0f", a[i][j]);
			}
			else { printf("%5.0s", " "); }
		}
		printf("\n");
	}
	system("pause");
	return 0;
}