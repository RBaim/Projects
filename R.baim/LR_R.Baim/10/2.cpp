#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

long double ap, op;

template<typename T>
void ras()
{
	T x, y, y1, y2;
	int key = 1;
	while (key == 1)
	{
		printf("Введите x для выражения y = ch^2(x) – sh^2(x)\n");
		cin >> x;
		y1 = (exp(x) + exp(-x)) / 2;
		y2 = (exp(x) - exp(-x)) / 2;
		printf("y1 = %20.16f\n", y1);
		printf("y2 = %20.16f\n", y1);
		y1 *= y1;
		y2 *= y2;
		y = y1 - y2;;
		printf("y = y1^2-y2^2 = %20.16f\n", y);
		ap = fabsl(1 - y);
		op = ap / fabs(1.0);
		printf("Погрешность абсолюьная %20.16f\n", ap); 
		printf("Погрешность относительная %20.16f\n", op);
		printf("Продолжить расчеты?(1-да)\n");
		cin >> key;
	}
}

int main()
{
	setlocale(0, "rus");
	ras<long double>();
	return 0;
}