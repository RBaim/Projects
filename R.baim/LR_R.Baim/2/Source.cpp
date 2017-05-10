#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	double x, y, z, k, n, m;
	setlocale(0, "russian");
	puts("¬ведите x, y");
	cin >> x >> y;
	cout << "x=" << x << " " << "y=" << y << endl;
	z = (x + 1)*(x + 1) + y*y;
	k = x + 1;
	n = -x - 1;
	if (z <= 1)
	{
		if (n <= y)
		{
			if (y <= k) { puts("“очка принадлежит заданной области"); }
			else puts("“очка находитс€ в окружности, но не в заданной области");
		}
		else puts("“очка находитс€ в окружности, но не в заданной области");
	}
	else 
	{
		if (x > 0 && y > 0) { puts("“очка в первой четверти, но не в заданной области"); }
		if (x < 0 && y > 0) { puts("“очка во второй четверти, но не в заданной области"); }
		if (x < 0 && y < 0) { puts("“очка в третьей четверти, но не в заданной области"); }
		if (x > 0 && y < 0) { puts("“очка в четвертой четверти, но не в заданной области"); }
	};
	system("pause");
}
