#include<iostream>
#include<math.h>
#include<locale.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	float a[11][11], tmp;
	puts("Введите размер квадратной матрицы n(<=11)");
	int n, imax = 0, jmax = 0, imin = 0, jmin = 0;
	srand(time(NULL));
	cin >> n;
	cout << "Срандомленная матрица" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 101 - 50;
			printf(" %7.0f ", a[i][j]);
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > a[imax][jmax])
			{
				imax = i;
				jmax = j;
			}
			if (a[i][j] < a[imin][jmin])
			{
				imin = i;
				jmin = j;
			}
		}
	}
	if (imax != imin)
	{
		for (int i = 0; i < n; i++)
		{
			tmp = a[imin][i];
			a[imin][i] = a[imax][i];
			a[imax][i] = tmp;
		}
	}
	puts("Измененная матрица");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %7.0f ", a[i][j]);
		}
		cout << endl;
	}
	cout << "Максимальный элемент=" << a[imin][jmax] << " в строке " << imax + 1 << " в столбце " << jmax + 1 << endl;
	cout << "Минимальный элемент=" << a[imax][jmin] << " в строке " << imin + 1 << " в столбце " << jmin + 1 << endl;
	system("pause");
	return 0;
}