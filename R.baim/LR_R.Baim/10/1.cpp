#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
long double y, ap, op;
int main()
{
	setlocale(0, "rus");
	y = 1;
	printf("ƒо преобразований y=%20.16f\n", y);
	y = y / 3;
	printf("представление числа 1/3 в пам€ти    y=%20.16f\n", y);
	printf("точное представление числа 1/3  =%20.16f\n", 1.0 / 3.0);
	ap = fabs((1.0 / 3) - y);    //абсолютна€ погрешность
	op = ap / fabs(1.0 / 3);  // относительна€ погрешность
	printf("јбсолютна€ погрешность предст. 1/3 ap=%20.16f\n", ap);
	printf("ќтносительна€ погрешность предст. 1/3  op=%20.16f\n", op);
	y = y / 6000;
	y = exp(y);
	y = sqrt(y); // вадратный корень
	y = y / 14;
	y = 14 * y;
	y = y*y;
	y = log(y);
	y = 6000 * y;
	y = y * 3;
	printf("ѕосле преобразований y=%20.16f\n", y);
	ap = fabs(1 - y);  //абсолютна€ погрешность
	op = ap / 1.0; // относительна€ погрешность
	printf("јбсолютна€ погрешность ap=%20.16f\n", ap);
	printf("ќтносительна€ погрешность op=%20.16f\n", op);
	system("pause");
	return 0;
}
