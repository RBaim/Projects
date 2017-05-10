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

void form(char *strok, element **first1, element **first2)
{
	element *p1, *q1, *p2, *q2;
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
		if (k % 2 != 0)
		{
			p1 = new element;
			p1->next = NULL;
			if (k == 1)
			{
				*first1 = p1;
				p1->next = NULL;
				q1 = p1;
				strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov)+1);
				p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
			}
			else
			{
				q1->next = p1;
				strncpy(p1->slov, firstslov, strlen(firstslov) - strlen(endslov)+1);
				p1->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
				q1 = q1->next;
			}
		}
		else
		{
			p2 = new element;
			p2->next = NULL;
			if (k == 2)
			{
				*first2 = p2;
				q2 = p2;
				strncpy(p2->slov, firstslov, strlen(firstslov) - strlen(endslov)+1);
				p2->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
			}
			else
			{
				q2->next = p2;
				strncpy(p2->slov, firstslov, strlen(firstslov) - strlen(endslov)+1);
				p2->slov[strlen(firstslov) - strlen(endslov) + 1] = '\0';
				q2 = q2->next;
			}
		}
		k++;
		endslov=endslov+2;
		firstslov = endslov;
	}
}

void schet(element *first1, element *first2)
{
	char s[] = "АЕЁИОУЫЭЮЯаеёиоуыэюя", *sravn;
	int k1=0, k2=0;
	bool flag=false;
	element *q1 = first1, *q2 = first2;
	printf("Поиск слов начинающихся на гласные буквы\n");
	printf("Слова найденные в 1 списке\n");
	while (q1 != NULL)
	{
		flag = false;
		sravn = q1->slov;
		for (int i = 0; i < 20; i++)
		{
			if (*sravn == s[i])
			{
				k1++;
				flag = true;
			}
		}
		if (flag == true)
		{
			printf("%s\n", q1->slov);
		}
		q1 = q1->next;
	}
	printf("Слова найденные во 2 списке\n");
	while (q2 != NULL)
	{
		flag = false;
		sravn = q2->slov;
		for (int i = 0; i < 20; i++)
		{
			if (*sravn == s[i])
			{
				k2++;
				flag = true;
			}
		}
		if (flag == true)
		{
			printf("%s\n", q2->slov);
		}
		q2 = q2->next;
	}
	if (k1 > k2)
	{
		printf("Победил по количеству слов начинающихся на гласные 1 список c k1=%d словами, во 2 списке k2=%d\n", k1, k2);
	}
	if (k2 > k1)
	{
		printf("Победил по количеству слов начинающихся на гласные 2 список c k2=%d словами, в 1 списке k1=%d\n", k2, k1);
	}
	if (k1 == k2)
	{
		printf("Количество слов начинающихся на гласные в списках совпадает(k1=k2=%d)\n", k1);
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
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	element *first1=NULL, *first2=NULL;
	char strok[100];
	puts("Введите строку");
	gets_s(strok);
	printf("\n");
	strok[strlen(strok)+1] = '\0';
	form(strok, &first1, &first2);
	printf("Список из нечетных слов строки\n");
	prinst(first1);
	printf("Список из четных слов строки\n");
	prinst(first2);
	schet(first1, first2);
	delstr(&first1);
	delstr(&first2);
	system("pause");
}