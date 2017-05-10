#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;
void zap(int n);
void perepis(int n);

void main()
{
	setlocale(LC_ALL, "russian");
	int n;
	printf("Введите колличество цифр в исходном файле\nЧисла рандомятся в 1.txt, четные переписываются в 2.txt\n");
	std::cin >> n;
	setlocale(LC_ALL, "ALL");
	zap(n);
	perepis(n);
	system("pause");
}

void zap(int n)
{
	int ran;
	srand(time(0));
	setlocale(LC_ALL, "russian");
	ofstream fout("1.txt", ios::app);
	printf("То что cрандомилось(1.txt)\n");
	for (int i = 0; i < n; i++)
	{
		ran = rand();
		fout << ran << endl;
		cout << ran << endl;
	}
	fstream close();
}

void perepis(int n)
{
	int k;
	setlocale(LC_ALL, "russian");
	ifstream fin("1.txt");
	ofstream fout("2.txt", ios::app);
	printf("То что переписалось(2.txt)\n");
	for (int i = 0; i<n; i++)
	{
		fin >> k;
		if (k%2==0)
		{
			fout << k << endl;
			cout << k << endl;
		}
	}
	fstream close();
}