#include <iostream>

using namespace std;

double f1(double x)
{
	return 2*x;
}

double square(double a, double b, double f(double), double eps)
{
	if (a > b)
	{
		swap(a, b);
	}
	double s1, s2, dx;
	s1 = s2 = 0;
	int step = 1000;
	do
	{
		s1 = s2;
		s2 = 0;
		dx = (b - a) / (2*step);
		for (int i = 0; i < step; i++)
		{
			s2 += fabs((f(a+i*dx*2) + f(a+(i+1)*dx*2)));
		}
		s2 *= dx;
		step *= 10;
	} while (fabs(s1 - s2) < eps);
	return s2;
}

int main()
{
	double a, b;
	cin >> a >> b;
	double(*ptr)(double) = f1;
	cout << square(a, b, f1, 0.000000001)<<endl;
	cin.ignore();
	cin.get();
}