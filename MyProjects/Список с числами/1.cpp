#include<Windows.h>
#include<iostream>

struct element
{
	int a;
	element *prev;
	element *next;
};

void prinst1(struct element *p)
{
	element *y = p;
	if (y != NULL)
	{
		if (y->next != NULL)
		{
			while (y != NULL)
			{
				printf("%d\n", y->a);
				y = y->next;
			}
			printf("\n");
		}
		else printf("%d\n", y->a);
	}
}

void prinst2(struct element *p)
{
	while (p->next)
	{
		p = p->next;
	}
	element *y = p;
	if (y != NULL)
	{
		if (y->prev != NULL)
		{
			while (y != NULL)
			{
				printf("%d\n", y->a);
				y = y->prev;
			}
			printf("\n");
		}
		else printf("%d\n", y->a);
	}
}

void form(char *strok, element **first)
{
	element *p1, *q1;
	char *firstslov, *endslov, chisl[20];
	int k = 1, c;
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
				*first = p1;
				p1->next = NULL;
				p1->prev = NULL;
				q1 = p1;
				strncpy(chisl, firstslov, strlen(firstslov) - strlen(endslov)+1);
				c = atoi(chisl);
				ZeroMemory(chisl, 20);
				p1->a=c;
			}
			else
			{
				q1->next = p1;
				p1->prev = q1;
				strncpy(chisl, firstslov, strlen(firstslov) - strlen(endslov)+1);
				c = atoi(chisl);
				ZeroMemory(chisl, 20);
				p1->a = c;
				q1 = q1->next;
			}
		k++;
		endslov = endslov + 2;
		firstslov = endslov;
	}
}

void shet(element *first)
{
	int kol=0;
	printf("Поиск чисел от 0 до 65535\n");
	while (first)
	{
		if (first->a >= 0 && first->a <= 65535)
		{
			kol++;
			printf("%d\n", first->a);
		}
		first = first->next;
	}
	printf("Число найденных слов %d\n", kol);
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
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	element *first = NULL;
	char strok[100];
	puts("Введите строку");
	gets_s(strok);
	printf("\n");
	strok[strlen(strok) + 1] = '\0';
	form(strok, &first);
	printf("Список ->\n");
	prinst1(first);
	printf("Список <-\n");
	prinst2(first);
	shet(first);
	delstr(&first);
	system("pause");
}