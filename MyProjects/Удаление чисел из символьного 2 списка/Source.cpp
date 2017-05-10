#include <iostream>
#include <Windows.h>
#include <clocale>

struct element
{
	char name[25];
	element *next;
	element *pred;
};
void print1(struct element *q)
{
	puts("Печать в прямом направлении");
	if (q != NULL)
	{
		while (q->pred != NULL)
		{
			q = q->pred;
		}
		while (q != NULL)
		{
			printf("%s", q->name);
			q = q->next;
			printf("\n");
		}
	}
}
void print2(struct element *q)
{
	puts("Печать в обратном направлении");
	if (q != NULL)
	{
		while (q->next != NULL)
		{
			q = q->next;
		}
		while (q != NULL)
		{
			printf("%s", q->name);
			q = q->pred;
			printf("\n");
		}
	}
}
void udalenie(struct element **q)
{
	element *a, *l1, *l2;
	a = *q;
	if (a != NULL)
		while (a->pred != NULL)
		{
			a = a->pred;
		}
	if (a->next != NULL)
	{
		while (a->next != NULL)
		{
			if (atoi(a->name) != NULL)
			{
				l1 = a->pred;
				l2 = a->next;
				if (l1 != NULL)
				{
					l1->next = a->next;
				}
				else { l2->pred = NULL; }
				l2->pred = a->pred;
				delete a;
				a = l2;
			}
			if (a->next != NULL)
			{
				a = a->next;
			}
		}
		if (atoi(a->name) != NULL)
		{
			element *g;
			*q = a->pred;
			g = *q;
			g->next = NULL;
			delete a;
		}
		else { *q = a; }
	}
	else
	{
		if (atoi(a->name) != NULL)
		{
			*q = NULL;
			delete a;
		}
	}
}
void delet(element **q)
{
	int kol = 0;
	element *a = *q;
	while (a->pred != NULL)
	{
		a = a->pred;
	}
	while (a!=NULL)
	{
		kol++;
		a = a->next;;
	}
	for (int i = 0; i < kol; i++)
	{
		udalenie(q);
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char st[25];
	element *first, *q;
	puts("Введите элементы списка или enter");
	first = new element;
	gets_s(st);
	strcpy_s(first->name, st);
	first->pred = NULL;
	first->next = NULL;
	q = first;
	while (gets_s(st), strlen(st) != 0)
	{
		q = new element;
		q->next = NULL;
		q->pred = first;
		strcpy_s(q->name, st);
		first->next = q;
		first = q;
	}
	print1(q);
	printf("\n");
	print2(q);
	printf("\n");
	delet(&q);
	printf("Измененный список(без чисел)\n");
	print1(q);
	printf("\n");
	print2(q);
	printf("\n");
	system("pause");
	return 0;
}