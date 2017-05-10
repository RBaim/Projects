#include<iostream>
#include<math.h>

double graf(long double x)
{
	x = sqrtl(1 - (x - 1)*(x - 1));
	return x;
}

int main()
{
	long double a = 0, b = 2, c, eps, pred=1, posl=0, dlin=0, par=0;
	int k = 4;
	printf("Impyt eps tochnost \n");
std::cin >> eps;
c = (b - a) / 4;
while (fabs(pred - posl) > eps)
{
	pred = posl;
	for (int i = 1; i <= k; i++)
	{
		dlin += sqrtl(c*c + (graf(par+c)-graf(par))*(graf(par + c) - graf(par)));
		par +=c;
	}
	par = 0;
	k = k*2;
	posl = dlin;
	c = c / 2;
	dlin = 0;
}
printf("Chiclo pi=%1.20f \n", posl);
system("pause");
}