#include<math.h>
#include<locale.h>
#include<iostream>

using namespace std;

int main()
{
	setlocale(0, "russian");
	int a[100], b[100], c[100], n, k, z, j=0, l, x, q;
	puts("¬ведите пор€док группы Z");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	puts("Ёлементы группы");
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < n; i++)
	{
		k = a[i];
		z = n;
		while (k != z)
		{
			if (k > z) { k = k - z; }
			else { z = z - k; }
		}
		if (z == 1) 
		{
			b[j] = a[i];
			j++;
		}
	}
	puts("Ёлементы имеющие конечный пор€док");
	for (int i = 0; i < j; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	for (int r = 0; r < j; r++)
	{
		q = 0;
		l = 1;
		x = b[r];
		do
		{
			l = l+x;
			while (l > n)
			{
				l = l - n;
			}
			q++;
		} while (l != 1);
		c[r] = q;
	}
	puts("ѕроверка порождающих элементов");
	cout << "  ";
	for (int i = 0; i < j-1; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	system("pause");
}
