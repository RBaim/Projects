#include<iostream>
#include<cstring>
#include <clocale>
#include<windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char a[100];
	char s[] = "АЕЁИОУЫЭЮЯаеёиоуыэюя";
	int kol = 0;
	puts("Введите строку");
	cin>>a;
	char *first = a, *end = a;
	bool flag1 = false, flag2 = false;
	printf("Найденные слова:\n");
	while (*first != '\0'&&*first!='.')
	{
		while (*first ==',' && *first != '\0')
		{
			first++;
		}
		flag1 = false; flag2 = false;
		end = first;
		while (*end !=','&&*end !='\0'&& *end!='.')
		{
			end++;
		}
		for (int i = 0; i < 20; i++)
		{
			if (*first == s[i])
			{
				flag1 = true;
			}
			if (*(end - 1) == s[i])
			{
				flag2 = true;
			}
		}
		if (flag1 == true && flag2 == true)
		{
			kol++;
			for (int i = 0; i <= strlen(first) - strlen(end - 1); i++)
			    {
				cout << a[strlen(a) - strlen(first) + i];
				}
				printf("\n");
				first = end;
		}
		else first = end;
	}
	if (kol > 0)
	{
		cout << "Количество найденых слов " << kol << endl;
	}
	if(kol<=0)
	{
		cout << "Искомых слов нет в строке" << endl;
	}
	system("pause");
}