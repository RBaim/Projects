#include<iostream>
#include<locale.h>
#define EPS 1e-7

long double det(long double a, long double b, long double c, long double d)
{
	return a*d - b*c;
}
void imput(long double **b, int n)
{
	printf("Подсказка: ввод точек %d-угольника и проверяемых точек необходимо производить последовательно, вводить координаты X,Y\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Введите %d точку %d-угольника\n", i + 1, n);
		std::cin >> b[0][i] >> b[1][i];
	}
}
void imputtoch(long double **a, int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("Введите %d проверяемую точку\n", i + 1);
		std::cin >> a[0][i] >> a[1][i];
	}
}
void outa(long double**a, int m)
{
	printf("Координаты проверемых точек ");
	std::cout << std::endl << "X ";
	for (int i = 0; i < m; i++)
	{
		printf("%7.0f", a[0][i]);
	}
	std::cout << std::endl << "Y ";
	for (int i = 0; i < m; i++)
	{
		printf("%7.0f", a[1][i]);
	}
	printf("\n");
}
void outb(long double**b, int n)
{
	printf("Координаты точек %d-угольника ",n);
	std::cout << std::endl << "X ";
	for (int i = 0; i < n; i++)
	{
		printf("%7.0f", b[0][i]);
	}
	std::cout << std::endl << "Y ";
	for (int i = 0; i < n; i++)
	{
		printf("%7.0f", b[1][i]);
	}
	printf("\n");
}
void outc(int *c, int m)
{
	printf("Принадлежность точек 0-не принадлежит, 1-принадлежит");
	std::cout << std::endl << "? ";
	for (int i = 0; i < m; i++)
	{
		printf("%7d", c[i]);
	}
	printf("\n");
}
int prinad(long double x0, long double x1, long double x01, long double y0, long double y1, long double y01, long double x11, long double y11)
{
	long double D, D1, D2;
	D = det(x11 - x01, x0 - x1, y11 - y01, y0 - y1);
	D1 = det(x0 - x01, x0 - x1, y0 - y01, y0 - y1);
	D2 = det(x11 - x01, x0 - x01, y11 - y01, y0 - y01);
	if (((D1 / D) >= 0) && ((D2 / D) >= 0) && ((D2 / D) <= 1))
	{
		return 1;
	}
	else return 0;
}
int prinluch(long double x11, long double y11, long double x01, long double y01, long double x, long double y)
{
	long double t1, t2;
	t1 = ((x - x01) / (x11 - x01));
	t2 = ((y - y01) / (y11 - y01));
	if (t1>=0&&t2>=0&&t1==t2)
	{
		return 1;
	}
	if (t1>=0 && EPS>=fabs(y01-y+t1*(y11-y01)))
	{
		return 1;
	}
	if (t2>=0 && EPS>=fabs(x01-x+t2*(x11-x01)))
	{
		return 1;
	}
	else return 0;
}
int prinstor(long double x, long double y, long double x0, long double y0, long double x1, long double y1)
{
	long double t1, t2;
	t1 = ((x - x0) / (x1 - x0));
	t2 = ((y - y0) / (y1 - y0));
	if((t1==t2)&&(t1>=0)&&(t1<=1))
	{
		return 1;
	}
	if(((t1>=0)&&(t1<=1)&&(EPS>=fabs(y0-y+t1*(y1-y0)))) || ((t2>=0)&&(t2<=1)&&(EPS>=fabs((x0-x+t2*(x1-x0))))))
	{
		return 1;
	}
	else return 0;
}
void prov(long double**b, long double**a, int *c, int m, int n)
{
	long double x11, y11;
	for (int d = 0, k = 0; d < m; d++)
	{
		bool sovpprinver = false;
		for (int i = 0; i < n; i++)
		{
			if ((a[0][d] == b[0][i]) && (a[1][d] == b[1][i]))
			{
				sovpprinver = true;
				c[d] = 1;
			}
		}
		if (sovpprinver == false)
		{
			x11 = rand() % 201 - 100;
			y11 = rand() % 201 - 100;
			for (int i = 0, pro; i < n; i++)
			{
				pro = prinluch(x11, y11, a[0][d], a[1][d], b[0][i], b[1][i]);
				if (pro == 1)
				{
					while (pro != 0)
					{
						x11 = 1.0*rand() / 201 - 100;
						y11 = 1.0*rand() / 201 - 100;
						pro = prinluch(x11, y11, a[0][d], a[1][d], b[0][i], b[1][i]);
					}
					if (pro == 1)
					{
						i = 0;
					}
				}
			}
				for (int i = 1; i <= n - 1; i++)
				{
					k = k + prinad(b[0][i - 1], b[0][i], a[0][d], b[1][i - 1], b[1][i], a[1][d], x11, y11);
				}
				k = k + prinad(b[0][0], b[0][n - 1], a[0][d], b[1][0], b[1][n - 1], a[1][d], x11, y11);
				if (k % 2 == 1)
				{
					c[d] = 1;
				}
				else { c[d] = 0; }
				k = 0;
			if (c[d] == 0)
			{
				for (int i = 1; i <= n - 1; i++)
				{
					k = k + prinstor(a[0][d], a[1][d], b[0][i - 1], b[1][i - 1], b[0][i], b[1][i]);
				}
				k = k + prinstor(a[0][d], a[1][d], b[0][0], b[1][0], b[0][n - 1], b[1][n - 1]);
				if (k == 1)
				{
					c[d] = 1;
				}
				k = 0;
			}
		}
	}
}
int main()
{
	setlocale(0, "russian");
	int m,n;
	puts("Введите количество точек m проверяемых точек");
	std::cin >> m;
	puts("Введите количество вершин n-угольника");
	std::cin >> n;
	long double **a = new long double*[2];
	for (int i = 0; i < 2; i++)
	{
		a[i] = new long double[m];
	}
	long double **b = new long double*[2];
	for (int i = 0; i < 2; i++)
	{
		b[i] = new long double[n];
	}
	int *c = new int[m];
	imput(b, n);
	imputtoch(a, m);
	prov(b, a, c, m, n);
	outb(b, n);
	outa(a, m);
	outc(c, m);
	for (int i = 0; i < 2; i++)
	{
		delete[] a[i];
	}
	delete[]a;
	for (int i = 0; i < 2; i++)
	{
		delete[] b[i];
	}
	delete[]b;
	delete[]c;
	system("pause");
}