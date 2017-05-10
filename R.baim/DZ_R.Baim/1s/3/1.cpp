#include <iostream>
#include <math.h>

using namespace std;

double f1(double x)
{
	return (x - 1) / (x + 2);
}

double f2(double x)
{
	return sin(x / 2 - 1);
}

double f3(double x)
{
	return x*x - 2*x + 3;
}

void MINMAX(double &min, double &max, double a, double b, double (f)(double))
{
	double y, EPS = 0.01, pmin, pmax,dx;
	int sh=5;
	if (b < a)
	{
		swap(a, b);
	}
	y = a; dx = (b - a) / sh;
		min = 1000;
		max = -1000;;
				
	do	{
			sh = sh * 5;
			y = a; dx = dx / 5;
			pmin = min;
			for (int i = 0; i < sh; i++)
			{
				y = y + dx;
				if (min > f(y))
				{
					min = f(y);
				}
			}
	} while (fabs(min - pmin) > EPS);
		sh = 5; dx = (b - a) / sh;
		
		do{
			sh = sh * 5; dx = dx / 5;
			y = a;
			pmax = max;
			for (int i = 0; i < sh; i++)
			{
				y = y + dx;
				if (max < f(y))
				{
					max = f(y);
				}
			}
		}while (fabs(max - pmax) > EPS);
}

int main()
{
	double(*ptr)(double);
	double min, max, a, b;
	int n;
	printf("1.y=(x - 1) / (x + 2)\n");
	printf("2.y=sin(x / 2 - 1)\n");
	printf("3.y=x^2-2x+3\n");
	printf("(1) in default\n");\
	cin >> n;
	printf("Imput a, b otrez\n");
	cin >> a >> b;
	ptr = f1;
	switch (n) {
	case 1: ptr = f1; n = 2; break;
	case 2: ptr = f2; n = 3; break;
	case 3: ptr = f3;
	}
	MINMAX(min, max, a, b, ptr);
	printf("min=%f max=%f\n", min, max);
	system("pause");
	return 0;
}