#include <iostream>
#include <Windows.h>
#include<stdio.h>
using namespace std;
void delelem(struct element **first, int del);
struct element
{
	element *next;
	int num;
};
void prinst(struct element *p)
{
	element *y = p;
	while (y != NULL)
	{
		printf("%d\n", y->num);
		y = y->next;
	}
	printf("\n");
}
void del(element **first, int del)
{
	int kol = 0;
	element *tmp = *first;
	while (tmp != 0)
	{
		kol++;
		tmp = tmp->next;
	}
	for (int i = 0; i < kol; i++)
	{
		delelem(first, del);
	}
}
void delelem(struct element **first, int del)
{
		element *a, *b;
		a = *first;
		if (a != NULL)
		{
			if (a->next != NULL)
			{
				if (a->num == del)
				{
					*first = a->next;
					delete a;
					a = *first;
				}
				b = a->next;
				while (b != NULL)
				{
					if (b->num == del)
					{
						a->next = b->next;
						delete b;
						b = a->next;
					}
					else
					{
						a = a->next;
						b = b->next;
					}
				}
			}
			else
			{
				if (a->num == del)
				{
					*first = NULL;
					delete a;
				}
			}
		}
}
void delstr(struct element **q)
{
	element *a = *q, *b = *q;
	q = NULL;
	while (a->next != NULL)
	{
		b = a;
		a = a->next;
		delete b;
	}
	delete a;
}
int main()
{
	element *first, *q, *p;
	int delet;
	char st[25];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	puts("Введите значения");
	gets_s(st);
	if (atoi(st) != NULL)
	{
		first = new element;
		first->num = atoi(st);
		first->next = NULL;
		p = first;
		while (gets_s(st), atoi(st) != NULL)
		{
			q = new element;
			q->num = atoi(st);
			q->next = NULL;
			p->next = q;
			p = q;
		}
		printf("Введенный список\n");
		prinst(first);
		printf("Что удалить?\n");
		cin >> delet;
		del(&first, delet);
		printf("Измененный список\n");
		prinst(first);
	}
	else { puts("Введена не цифра"); }
	system("pause");
	return 0;
}