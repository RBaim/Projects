#include<string.h>
#include<iostream>
#include<stdio.h>

int main()
{
	int k=0;
	char a[100], *first, *end;
	puts("Imput string");
	gets_s(a);
	int z = strlen(a);
	a[z] = ' ';
	a[z + 1] = '\0';
	for (int i = 0; i <= 5; i++)
	{
		int k = strlen(a);
		a[k] = 'r';
		a[k + 1] = '\0';

	}
	a[strlen(a)] = '\0';
	first = a;
	end = first;
	while (*end != '\0')
	{
		end = first;
		while (*end != ' ' && *end!='\0')
		{
			end++;
		}
		if ((strlen(first) - strlen(end) )<=4)
		{
			k++;
			int f=strlen(a)-strlen(first);
			int e=strlen(a)-strlen(end)+1;
			for(int i=0;i<strlen(first);i++)
			{
				a[f+i]=a[e+i];
			}
        }
		else first = end +1;
	}
	a[strlen(a) - 6] = '\0';
	printf("Resultat\n");
	std::cout << a<<std::endl;
	printf("kol del slov=%d\n", k);
	system("pause");
}