#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	int i, r, n; FILE *f, *out;
	srand((unsigned)time(NULL));
	f = fopen("in.dat", "w+");
	out = fopen("out.dat", "w+");
	puts("Imput kol chisel");
	cin >> n;
	puts("Rand chisla");
	for (i = 0; i<n; i++) 
	{ 
		r = rand()%101; 
		fprintf(f, "%d\n", r); 
		printf("%6d", r);
	}
	printf("\n");
	rewind(f);
	puts("Perepis chisla");
	while (fscanf(f, "%d", &r) != EOF) 
	{
		if (r % 2 == 0) 
		{ 
		fprintf(out, "%d\n", r); 
		printf("%6d", r);
		}
	}
	printf("\n");
	fclose(f); fclose(out);
	system("pause");
	return 0;
}
