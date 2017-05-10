#include <math.h>
#include <iostream>
#include <stdio.h>
#include <locale.h>


using namespace std;

int main()
{
	setlocale(0, "russian");
	int n, k,c=1;
	cout << "¬ведите колличестово строк" << endl;
	cin >> n;
	cout << n<< endl;
	k = n + 1;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i <= k - 2; i++)
		{
			cout << " ";
		}
		k = k - 1;
		for (int i = 1; i <= c; i++)
		{
			cout << "^";
		}
		c = c + 2;
		cout << endl;
	}
	system("pause");
	return 0;
}