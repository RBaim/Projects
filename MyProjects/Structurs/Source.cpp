#include <iostream>
#include <Windows.h>

struct element
{
	char slov[25];
	element *next;
};

void prinst(struct element *p)
{
	element *y = p;
	if (y != NULL)
	{
		if (y->next != NULL)
		{
			while (y != NULL)
			{
				printf("%s\n", y->slov);
				y = y->next;
			}
			printf("\n");
		}
		else printf("%s\n", y->slov);
	}
}

void form(char *strok, element **first1)
{
	element *p1, *q1;
	char *firstslov, *endslov;
	int k = 1;
	firstslov = strok;
	while (*firstslov != '\0')
	{
		endslov = firstslov;
		while (*endslov != ' '&&*endslov != '\0')
		{
			*endslov++;
		}
		*endslov--;
		p1 = new element;
		p1->next = NULL;
		if (k == 1)
		{
			*first1 = p1;
			p1->next = NULL;
			q1 = p1;
			strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
			p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
		}
		else
		{
			q1->next = p1;
			strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov) + 1);
			p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
			q1 = q1->next;
		}
		k++;
		endslov = endslov + 2;
		firstslov = endslov;
	}
}

void delstr(struct element **q)
{
	if (*q)
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
}

void search(struct element *first)
{
	element *p = first;
	int k=0;
	puts("Найденные слова(<3):");
	while (p)
	{
		if (strlen(p->slov) < 3) {
			k++;
			printf("%s\n", p->slov);
		}
		p = p->next;
	}
}

void delem(struct element **first, struct element **detec, struct element **prev)
{
	element *p;
	if (*first == *detec)
	{
		if ((*first)->next)
		{
			*first = (*first)->next;
			delete *detec;
		
		}
		else {
			delete *detec;
			*first = NULL;
		}
	}
	else
	{
		(*prev)->next = (*detec)->next;
		delete *detec;
	}
	*detec = NULL;
}

void clearn(struct element **first, int n)
{
	bool key = true;
	element *p1 = *first, *p2 = *first;
	if (p1->next)
		p2 = p1->next;
	while (p2)
	{
		while (p1&&key)
		{
			if (p1 == *first&&strlen(p1->slov) < n)
			{
				*first = (*first)->next;
				delete p1;
				p1 = p2 = *first;
				if (p1)
				{
					if (p1->next)
						p2 = p1->next;
				}
			}
			else
				key = false;;
		}
		if (*first)
		{
			if (strlen(p2->slov) < n)
			{
				if (p1 != p2)
					delem(first, &p2, &p1);
				else
				{
					*first = (*first)->next;
					delete p1;
					p1 = p2 = *first;
				}
				if (p1->next)
					p2 = p1->next;
			}
			else
			{
				p1 = p2;
				p2 = p2->next;
			}
		}
	}
}

int main()
{
	int n;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	element *first = NULL;
	char strok[80];
	puts("Введите строку");
	gets_s(strok);
	printf("\n");
	strok[strlen(strok) + 1] = '\0';
	form(strok, &first);
	printf("Список\n");
	prinst(first);
	search(first);
	printf("Удаление слов меньше введенной длины\n");
	std::cin >> n;
	clearn(&first, n);
	printf("Готовый список\n");
	prinst(first);
	delstr(&first);
	system("pause");
}