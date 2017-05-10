#include<stdio.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(0, "russian");
	int a[100], b[100], c[100], n, z, j=0, m=0 , v=0, l=0, q=0, h;
	puts("Введите целое число");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		z = n / i;
		if (n%i == 0)
		{
			a[j] = z;
			j++;
		}
	}
	puts("Делители");
	for (int i = 0; i < j; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	if (j > 2)
	{
		for (int i = 0; i < j; i++)
		{
			for (int w = 1; w <= a[i]; w++)
			{
				if (a[i] % w == 0)
				{
					v++;
				}
			}
			if (v <= 2)
			{
				b[l] = a[i];
				l++;
			}
			v = 0;
			if (a[l] == 1)
			{
				i = 100000000000000;
			}
		}
		puts("Простые делители числа");
		for (int i = 0; i < l - 1; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
		for (int e = 0; e < l - 1; e++)
		{
			h = n;
			while (h%b[e] == 0 && h != 1)
			{
				h = h / b[e];
				m++;
			}
			c[e] = m;
			q++;
			m = 0;
		}
		puts("Степени факторизации");
		for (int i = 0; i < q; i++)
		{
			printf("%d ", c[i]);
		}
	}
	else 
	{
		puts("Введенное число простое");
	}
	_getch();
	return 0;
}