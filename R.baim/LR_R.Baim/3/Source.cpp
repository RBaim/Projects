#include<iostream>
#include<math.h>
#include<locale.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	int n, x, k = 0;
	cout << "¬ведите целое число" << endl;
	cin >> n;
	while (n != 0)
	{
		x = n % 10;
		if (x % 2 == 0)
		{
			if (x != 0)
			{
				k += 1;
			}
		}
		n = n / 10;
	}
	cout << "„исло четных цифр в числе равно " << k << endl;
	system("pause");
}
