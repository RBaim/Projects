#include <iostream>
#include <Windows.h>
#include <stdio.h>

struct element
{
	char name[25];
	element *next;
};

void prinst(struct element *p)
{
		element *y = p;
		while (y != NULL)
		{
			printf("%s\n", y->name);
			y = y->next;
		}
		printf("\n");
}

void sort(struct element **first)
{
	element *a, *b, *c;
	a = *first;
	bool flag = false;
	if (a->next != NULL)
	{
		while (flag == false)
		{
			flag = true;
			a = *first;
			b = a->next;
			c = b->next;
			if (strcmp(a->name, b->name) > 0 && a == *first)
			{
				flag = false;
				a->next = b->next;
				b->next = a;
				std::swap(a, b);
				*first = a;
			}
			while (c != NULL)
			{
				if (strcmp(a->name, b->name) > 0 && a == *first)
				{
					flag = false;
					a->next = b->next;
					b->next = a;
					std::swap(a, b);
					*first = a;
				}
				if (strcmp(b->name, c->name) > 0)
				{
					flag = false;
					a->next = c;
					b->next = c->next;
					c->next = b;
					std::swap(b, c);
				}
				a = a->next;
				b = b->next;
				c = c->next;
			}
		}
	}
}

void delelem(struct element **first)
{
	printf("Удалить кого-нибудь?(1-да, любое другое-нет)");
	int c;
	std::cin >> c;
	if (c == 1)
	{
		element *a, *b;
		char del[25];
		printf("Кого именно удалить?\n");
		std::cin.ignore();
		gets_s(del);
		a = *first;
		if (a->next != NULL)
		{
			if (strcmp(a->name, del) == NULL)
			{
				*first = a->next;
				delete a;
				a = *first;
			}
			b = a->next;
			while (b != NULL)
			{
				if (strcmp(b->name, del) == NULL)
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
			if (strcmp(a->name, del) == 0)
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
	char st[25];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	puts("Введите имена участников");
	first = new element;
	gets_s(st);
	strcpy_s(first->name, st);
	first->next = NULL;
	p = first;
	while (gets_s(st), strlen(st) != NULL)
	{
		q = new element;
		strcpy_s(q->name, st);
		q->next = NULL;
		p->next = q;
		p = q;
	}
	p = first;
	printf("Введенный список\n");
	prinst(p);
	sort(&p);
	first = p;
	printf("Отортированный список\n");
	prinst(p);
	delelem(&p);
	first = p;
	printf("Измененный список\n");
	prinst(p);
	delstr(&first);
	system("pause");
}