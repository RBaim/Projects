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

void sort(struct element *q)
{
	while (q->pred != NULL)
	{
		q = q->pred;
	}
	element *dop, *posl, *tmp;
	if (q->next != NULL)
	{
		bool prov = false;
		dop = q;
		posl = q->next;
		while (prov == false)
		{
			prov = true;
			while (q->pred != NULL)
			{
				q = q->pred;
			}
			dop = q;
			posl = q->next;
			while (posl != NULL)
			{
				if (strcmp(dop->name, posl->name) > 0)
				{
					prov = false;
					dop->next = posl->next;
					posl->next = dop;
					posl->pred = dop->pred;
					dop->pred = posl;
					if (posl->pred != NULL)
					{
						tmp = posl->pred;
						tmp->next = posl;
					}
					if (dop->next != NULL)
					{
						tmp = dop->next;
						tmp->pred = dop;
					}
					std::swap(dop, posl);
				}
				dop = posl;
				posl = posl->next;
			}
		}
	}
}

void udalenie(struct element **q)
{
	element *a, *l1, *l2;
	a = *q;
	while (a->pred != NULL)
	{
		a = a->pred;
	}
	int n;
	printf("Удалить кого-нибудь?(1-да, любое другое-нет)");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("Кого именно удалить?(1-да, любое другое-нет)");
		char del[25];
		std::cin >> del;
		if (a->next != NULL)
		{
			while (a->next != NULL)
			{
				if (strcmp(a->name, del) == 0)
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
			if (strcmp(a->name, del) == 0)
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
			if (strcmp(a->name, del) == 0)
			{
				*q = NULL;
				delete a;
			}
		}
	}
}

void delstr(struct element *q)
{
	element *a;
	if (q != NULL)
	{
		while (q->pred != NULL)
		{
			q = q->pred;
		}
		a = q;
		while (a->next != NULL)
		{
			q = a;
			a = q->next;
			delete q;
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char st[25];
	element *first, *q;
	puts("Введите имена участников или enter");
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
	sort(q);
	printf("                            || Отсортированный спиcок ||\n");
	print1(q);
	printf("\n");
	print2(q);
	udalenie(&q);
	printf("                            || Измененный спиcок ||\n");
	print1(q);
	printf("\n");
	print2(q);
	delstr(q);
	system("pause");
	return 0;
}