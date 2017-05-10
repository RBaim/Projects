#include <iostream>
#include <time.h>

int main()
{
	srand(time(0));
	float a[10][10], tmp;
	int n;
	puts("Imput n matrix");
	std::cin>>n;
	puts("Randon matrix");
	for(int i=0;i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=rand()%10;
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int c=0;c<n;c++)
			{
				for(int d=0; d<n;d++)
				{
					if(a[i][j]<a[c][d])
					{
						tmp=a[i][j];
						a[i][j]=a[c][d];
						a[c][d]=tmp;
					}
				}
			}
		}
	}
	puts("Sort matrix");
		for(int i=0;i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%5.0f", a[i][j]);
		}
		printf("\n");
	}
}