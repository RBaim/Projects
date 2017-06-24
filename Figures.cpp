#pragma once
#include "Figures.h"

Figure* Figure::make(int ind) {
    switch (ind) {
	case 1:return new Circle;
    case 2:return new Ellipse;
    }
    return nullptr;
}

void Figure::Destr(Figure*& obj) {
	delete obj;
}

Circle::Circle() {
	r = x = y = 0;
}

Ellipse::Ellipse() {
	a = b = x = y = 0;
}

Circle::Circle(double x, double y, double r) {
	this->x = x;
	this->y = y;
	this->r = r;
}

Ellipse::Ellipse(double x, double y, double a, double b) {
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

void Circle::NewParam(double x, double y, double r) {
	this->x = x;
	this->y = y;
	this->r = r;
}

void Ellipse::NewParam(double x, double y, double a, double b) {
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

void Circle::Draw() {
	std::cout << "ќкружность с радиусом " << r << std::endl;
}

void Ellipse::Draw() {
	std::cout << "Ёллипс с полуос€ми " << a << " и " << b << std::endl;
}

void Circle::Scaling(double zoom) {
	NewParam(x, y, r*zoom);
}

void Ellipse::Scaling(double zoom) {
	NewParam(x, y, a*zoom, b*zoom);
}

double Circle::Area() {
	return PI*r*r;
}

double Ellipse::Area() {
	return PI*a*b;
}

double Figure::GetX() {
	return x;
}

double Figure::GetY() {
	return y;
}

bool Circle::IsTouch(const Figure& check) {
	Circle *c = dynamic_cast<Circle*>(const_cast<Figure*>(&check));
	return (sqrt((x - c->x)*(x - c->x) + (y - c->y)*(y - c->y) <= (r + c->r)));
}
