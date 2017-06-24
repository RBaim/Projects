#include <ctime>
#include <clocale>
#include <iostream>
#include <typeinfo>
#include "Figures.h"

int main() {
	setlocale(0, "Russian");
	double a, b, x, y, r;
	Circle check(0, 0, 0);
	srand(time(NULL));
	Figure* ptr[3];
	for(int i = 0; i < 3; ++i) {
		if(rand() % 2) *(ptr + i) = Figure::make(1);
		else *(ptr + i) = Figure::make(2);
	}
	std::cout << "¬вод фигур(ќружность(double x, double y, double r), Ёллипс(double x, double y, double a, double b))" << std::endl;
	for(int i = 0; i < 3; ++i) {
	    std::cout << i + 1 << ": ";
		std::cout << "x, y" << std::endl;
		std::cin >> x >> y;
		if(typeid(**(ptr + i)) == typeid(Circle)) {
			std::cout << "Circle: ";
			std::cin >> r; 
			Circle *cir = dynamic_cast<Circle*>(*(ptr + i));
			cir->NewParam(x, y, r);
		} else {
			std::cout << "Ellipse: ";
			std::cin >> a >> b; 
			Ellipse *ell = dynamic_cast<Ellipse*>(*(ptr + i));
			if(ell) 
				ell->NewParam(x, y, a, b);
			else exit(1);
		}
	}
	std::cout << "Draw" << std::endl;
	for(int i = 0; i < 3; ++i) {
		 std::cout << i + 1 << ": " << std::endl;
		(*(ptr + i))->Draw();
		std::cout << "ѕлощадь: " << (*(ptr + i))->Area() << std::endl;
		if(typeid(**(ptr + i)) == typeid(Circle)) {
			std::cout << "¬ведите провер€ему другую окружность" << std::endl;
			std::cin >> x >> y >> r;
			check.NewParam(x, y, r);
			std::cout << "–езультат: " << check.IsTouch(**(ptr + i)) << std:: endl;
		}
	}
	for(int i = 0; i < 3; i++) {
		Figure::Destr(*(ptr + i));
	}
	system("pause");
    return 0;
}
