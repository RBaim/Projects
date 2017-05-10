#include <locale.h>
#include <stdio.h>
#include <conio.h>
int nod(int x, int y)
{
	while (x!=y)
		if (x>y) x=x-y;
		else y=y-x;
		return y;
}
void main()
{
	int a,b;
setlocale (0,"russian");// подключние русского языка
puts("Введите два натуральных числа:");
scanf ("%d %d", &a,&b);
printf ("НОД %d и %d = %d.\n",a,b,nod(a,b));
puts("Нажмите любую клавишу для завершения.....");
getch();
}

