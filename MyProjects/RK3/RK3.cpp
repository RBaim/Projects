#include <iostream>
#include <Windows.h>

struct element //элемент двусвязанной структуры
{
	char a;
	element *prev;
	element *next;
};

void prinst1(struct element *y) //Печать в прямом направлении списка
{
	if (y != NULL)//Проверки на пустой список
	{
		if (y->next != NULL)
		{
			while (y != NULL)
			{
				std::cout << y->a<<std::endl;
				y = y->next;
			}
			printf("\n");
		}
		else printf("%s\n", y->a);
	}
}

void prinst2(struct element *y) //Печать в обратном направлении списка
{
	while (y->next != NULL)
	{
		y = y->next;
	}
	if (y != NULL)
	{
		if (y->prev != NULL)
		{
			while (y != NULL)
			{
				std::cout << y->a<<std::endl;
				y = y->prev;
			}
			printf("\n");
		}
		else printf("%s\n", y->a);
	}
}

void form(char *strok, element **first) //Процедура по формированию списка
{
	element *p, *q, *tmp;
	char *buk=strok;
	while (*buk == '#')
	{
		buk++;
	}
	if(*buk!='\n')
	{
			p = new element;
			*first = p;
			p->a = *buk;
			p->next = p->prev = NULL;
			buk++;
			while (*buk != '\0')
			{
				if (*buk != '#')
				{
					q = new element;
					q->next = q->prev = NULL;
					q->a = *buk;
					q->prev = p;
					p->next = q;
					p = q;
				}
				else//Если натыкаемся на # Удаляем предыдущий сдвинув указатель назад
				{
					tmp = p;
					p = p->prev;
					p->next = NULL;
					delete[] tmp;
				}
				buk++;
			}
	}
}

void delstr(struct element **q)//Удаление из памяти списка
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

int main()//Основная фунция
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char strok[100];
	element *first;
	puts("Введите строку");
	gets_s(strok);
	form(strok, &first);
	puts("Сформированный двусвязанный список(без # и предыдущих символов)");
	puts("Печать в прямом направлении");
	prinst1(first);
	puts("Печать в обратном направлении");
	prinst2(first);
	delstr(&first);
	system("pause");
    return 0;
}