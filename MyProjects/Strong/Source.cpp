#include <conio.h>
#include <stdio.h>
#include <cstring>
#include <locale.h>
#include <iostream>
using namespace std;
struct disp
{
	int Id, size, prior;
	char name[20];
}disp[100];

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "1.Создать файл и записать его" << endl << "2.Открыть существующий файл" << endl;
	int n;
	cin >> n;
	FILE *f;
	char namef[30];
	int v=0;
	switch (n)
	{
	case 1:
		cout << "Введите название файла" << endl;
		cin >> namef;
		f = fopen(namef, "w+b");
		cout << "Введите количество данных" << endl;
		cin >> v;
		cout << "Введите данные(Id, размер, приоритет, имя) " << endl;
		for (int i = 0; i<v; i++)
		{
			cin >> disp[i].Id;
			fflush(stdin);
			cin >> disp[i].size;
			cin>>disp[i].prior;
			fflush(stdin);
			cin>>disp[i].name;
			fflush(stdin);
			if (disp[i].prior != 1 && disp[i].prior != 2 && disp[i].prior != 3)
			{
				disp[i].prior = 1;
			}
			fwrite(&disp[i], sizeof(disp), 1, f);
		}
		n = 2; break;
	case 2:
		cout << "Введите название файла" << endl;
		cin >> namef;
		f = fopen(namef, "r+b");
		if (f != NULL)
		{
			while (fread(&disp[0], sizeof(disp), 1, f) != 0)
			{
				v++;
			}
			rewind(f);
			for (int i = 0; i<v; i++)
			{
				fread(&disp[i], sizeof(disp), 1, f);
			}
		}
		else {
			cout << "Ошибка файла" << endl;
		}
	}
	cout << "Введенные данные(Id, размер, приоритет, имя)" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << disp[i].Id << "   " << disp[i].size << "   " << disp[i].prior << "   " << disp[i].name << endl;
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = i + 1; j < v; j++)
		{
			if (disp[i].prior < disp[j].prior)
			{
				swap(disp[i], disp[j]);
			}
		}
	}
	cout << "Отсортированные данные по приоритету(Id, размер, приоритет, имя)" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << disp[i].Id << "   " << disp[i].size << "   " << disp[i].prior << "   " << disp[i].name << endl;
	}
	int k=0;
	while (disp[k].prior == 3)
	{
		k++;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (disp[i].size < disp[j].size)
			{
				swap(disp[i], disp[j]);
			}
		}
	}
	int p = k;
	while (disp[k].prior == 2)
	{
		k++;
	}
	for (int i = p; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (disp[i].size < disp[j].size)
			{
				swap(disp[i], disp[j]);
			}
		}
	}
	int c = k;
	while (disp[k].prior == 1)
	{
		k++;
	}
	for (int i = c; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (disp[i].size < disp[j].size)
			{
				swap(disp[i], disp[j]);
			}
		}
	}
	cout << "Отсортированные данные внутри приоритета(Id, размер, приоритет, имя)" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << disp[i].Id << "   " << disp[i].size << "   " << disp[i].prior << "   " << disp[i].name << endl;
	}
	cout << "Введите название нового файла(будет без максимального по приоритету и размеру элемента)" << endl;
	FILE *g = NULL;
	k = 0;
	cin >> namef;
	g = fopen(namef, "w+b");
	for (int i = 1; i < v; i++)
	{
		fwrite(&disp[i], sizeof(disp), 1, g);
	}
	v = 0;
	rewind(g);
	while (fread(&disp[0], sizeof(disp), 1, g) != 0)
	{
		v++;
	}
	rewind(g);
	for (int i = 0; i<v; i++)
	{
		fread(&disp[i], sizeof(disp), 1, g);
	}
	cout << "Новый файл" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << disp[i].Id << "   " << disp[i].size << "   " << disp[i].prior << "   " << disp[i].name << endl;
	}
	_getch();
	return 0;
}