#include <iostream>
using namespace std;
int main()
{
	int a[100][100], n;
	bool flag = false;
	puts("Imput n matrix nxn");
	cin >> n;
	puts("Imput matrix");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> *(*(a + i) + j);
		}
	}
	puts("Vveden matrix");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d",*(*(a + i) + j));
		}
		printf("\n");
	}
	puts("Summs stols");
	for (int j = 0, sum=0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum += *(*(a + i) + j);
		}
		*(*(a + n) + j)=sum;
		sum = 0;
		printf("%5d", *(*(a + n) + j));
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (*(*(a + n) + j) == *(*(a + n) + i))
			{
				flag = true;
				printf("Summ slob %d and %d sovpat\n", i+1, j+1);
			}
		}
	}
	if (!flag)
	{
		printf("Sovpad summ not found\n");
	}
	cin.ignore();
	cin.get();
	return 0;
}