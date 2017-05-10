#include<iostream>
#include<cstring>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char a[256];
	cout << "¬ведите строку" << endl;
	cin >> a;
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == a[i + 1])
		{
			for (int j = i; j < 256, a[j] != '\0'; j++)
			{
				a[j] = a[j + 1];
			}
		}
		else i++;
	}
	cout << a << endl;
	system("pause");
}