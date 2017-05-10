#include "Figures.h"

class Rectable : public Figure {
    double a;
    double b;
public:
    Rectable();
    Rectable(double a, double b);
    void NewParam(double a, double b);
    double Square();
    double Perimeter();
    void Out();
    void Input();
};

class Circle : public Figure {
    double r;
public:
    Circle();
    Circle(double r);
    void Out();
    void Input();
    void NewParam(double r);
    double Square();
    double Perimeter();
};

class Trapezium : public Figure {
    double a;
    double b;
    double c;
    double d;
    double h;
public:
    Trapezium();
    Trapezium(double a, double b, double c, double d, double h);
    void Out();
    void Input();
    void NewParam(double a, double b, double c, double d, double h);
    double Square();
    double Perimeter();
};


Figure::Figure() {
    Square_d = 0;
    Perimeter_d = 0;
}


Rectable::Rectable() {
    a = 0;
    b = 0;
}

Rectable::Rectable(double a, double b) {
    this->a = a;
    this->b = b;
    Square();
    Perimeter();
}

void Rectable::NewParam(double a, double b) {
    this->a = a;
    this->b = b;
    Square();
    Perimeter();
}

double Rectable::Square() {
    Square_d = a*b;
    return Square_d;
}

double Rectable::Perimeter() {
    Perimeter_d = 2 * (a + b);
    return Perimeter_d;
}

Circle::Circle() :Figure() {
    r = 0;
}

Circle::Circle(double r) {
    this->r = r;
    Square();
    Perimeter();
}

void Circle::NewParam(double r) {
    this->r = r;
    Square();
    Perimeter();
}

double Circle::Square() {
    Square_d = 3.141591653589793238*r*r;
    return Square_d;
}

double Circle::Perimeter() {
    Perimeter_d = 2 * 3.141592653589793238*r;
    return Square_d;
}

Trapezium::Trapezium() {
    a = 0;
    b = 0;
    h = 0;
}

Trapezium::Trapezium(double a, double b, double c, double d, double h) : Figure() {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->h = h;
    Square();
    Perimeter();
}

void Trapezium::NewParam(double a, double b, double c, double d, double h) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->h = h;
    Square();
    Perimeter();
}

double Trapezium::Square() {
    Square_d = h*(a + b) / 2.0;
    return Square_d;
}

double Trapezium::Perimeter() {
    Perimeter_d = a + b + c + d;
    return Perimeter_d;
}

void Figure::Out() {
    std::cout << "Периметр " << Perimeter_d << ", Площадь - " << Square_d << std::endl;
}

void Rectable::Out() {
    std::cout << "1 сторона - " << a << ", 2 сторона - " << b << ", ";
    Figure::Out();
}

void Circle::Out() {
    std::cout << "Радиус - " << r << ", ";
    Figure::Out();
}

void Trapezium::Out() {
    std::cout << "1 сторона - " << a << ", 2 сторона - " << b;
    std::cout << ", 3 сторона - " << c << ", 4 сторона - " << d;
    std::cout << ", высота - " << h << ", ";
    Figure::Out();
}

void Rectable::Input() {
    std::cout << "1 сторона" << std::endl;
    std::cin >> a;
    std::cout << "2 сторона" << std::endl;
    std::cin >> b;
    Square();
    Perimeter();
}

void Circle::Input() {
    std::cout << "Радиус" << std::endl;
    std::cin >> r;
    Square();
    Perimeter();
}

void Trapezium::Input() {
    std::cout << "1 сторона" << std::endl;
    std::cin >> a;
    std::cout << "2 сторона" << std::endl;
    std::cin >> b;
    std::cout << "3 сторона" << std::endl;
    std::cin >> c;
    std::cout << "4 сторона" << std::endl;
    std::cin >> d;
    std::cout << "высота" << std::endl;
    std::cin >> h;
    Square();
    Perimeter();
}

Figure* Figure::make(int ind) {
    switch (ind) {
    case 1:return new Rectable;
    case 2:return new Circle;
    case 3:return new Trapezium;
    }
    return nullptr;
}

void Figure::Destroy(Figure*& obj) {
    delete obj;
    obj = nullptr;
}
