#pragma once

#include <iostream>
#define PI 3.141592

class Figure {
protected:
	double x;
	double y;
public:
	static Figure* make(int ind);
	static void Destr(Figure*& obj);
	double GetX();
	double GetY();
	virtual double Area() = 0;
	virtual void Scaling(double zoom) = 0;
	virtual void Draw() = 0;
};

class Circle : public Figure {
    double r;
public:
	Circle();
    Circle(double x, double y, double r);
	void NewParam(double x, double y, double r);
    void Draw() override;
	bool IsTouch(const Figure& check);
    double Area() override;
	void Scaling(double zoom) override;
};

class Ellipse : public Figure {
    double a;
	double b;
public:
	Ellipse();
    Ellipse(double x, double y, double a, double b);
	void NewParam(double x, double y, double a, double b);
    void Draw() override;
    double Area() override;
	void Scaling(double zoom) override;
};
