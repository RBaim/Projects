#include<stdio.h>
#include<iostream>
struct book
{
	char name[20];
	char author[20];
	int year;
};

int main()
{
	int yearp;
	puts("INPUT BOOKS:");
	FILE *fileF = fopen("F.txt", "w+b");
	book current;
	while (scanf("%s", current.name), *(current.name)!='.')
	{
		fflush(stdin);
		scanf("%s", current.author);
		fflush(stdin);
		scanf("%d", &current.year);
		fflush(stdin);
		fwrite(&current, sizeof(book), 1, fileF);
	}
	printf("\n\n");
	rewind(fileF);
	while (fread(&current, sizeof(current), 1, fileF) != 0)
	{
		printf("%s %s %d\n", current.name, current.author, current.year);
	}
	rewind(fileF);
	puts("Imput year");
	scanf("%d", &yearp);
	FILE *fileG = fopen("G.txt", "w+b");
	while (fread(&current, sizeof(current), 1, fileF) != 0)
	{
		if (current.year == yearp)
		{
			printf("%s %s %d\n", current.name, current.author, current.year);
			fwrite(&current, sizeof(book), 1, fileG);
		}
	}
	fcloseall();
	system("pause");
}