#include <math.h> 
#include <stdio.h> 
#include <locale.h> 
#include <iostream> 

using namespace std;

	void main() {
		setlocale(0, "russian");
		puts("Введите координаты x,y");
		double x, y, z;
		cin >> x >> y;
		cout <<"x= "<< x <<" "<<"y= "<< y<< endl;
		z = x*x + y*y;
		if (1<=z)
		{
			if (4 >= z) 
			{
				puts("Точка принадлежит");
		}
			else puts("Точка вне окружности с радиусом 2");
		}
		else puts("Точка внутри окружности с радиусом 1");
		system("pause");
		

}