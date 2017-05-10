#include<iostream>
#include<math.h>
#include<locale.h>

using namespace std;

int main()
{
	setlocale(0, "russian");
	puts("Выберите точность:");
	cout << "1-float" << endl << "2-long float" << endl << "3-double"<<endl <<"4-long double"<< endl<<"0-exit" <<endl;
	int a=-1;
	while (a != 0)
	{
		cin >> a;
		if (a == 1)
		{
			float x, z, r, y;
			puts("Введите x, z ,r");
			cin >> x >> z >> r;
			y = cos(x + 3.1*z) / tan(x / r);
			printf("y=%3.20f \n", y);
		}
		if (a == 2)
		{
			long float x, z, r, y;
			puts("Введите x, z ,r");
			cin >> x >> z >> r;
			y = cos(x + 3.1*z) / tan(x / r);
			printf("y=%3.20lf \n", y);
		}
		if (a == 3)
		{
			double x, z, r, y;
			puts("Введите x, z ,r");
			cin >> x >> z >> r;
			y = cosl(x + 3.1*z) / tan(x / r);
			printf("y=%3.20lf \n", y);
		}
		if (a == 4)
		{
			long double x, z, r, y;
			puts("Введите x, z ,r");
			cin >> x >> z >> r;
			y = cosl(x + 3.1*z) / tan(x / r);
			printf("y=%3.20lf \n", y);
		}
	}
	system("pause");
	return 0;
}