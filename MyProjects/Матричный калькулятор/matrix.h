#pragma once
#include <math.h>
#include <iostream>
#define EPS 1e-6
using namespace std;
class Matrix
{
public:
	Matrix(double **a, int n, int m);
    Matrix(const Matrix &Copy);
	Matrix();
	Matrix(int n, int m);
	~Matrix();
	void null();
	void matrget();
	void matrput();
	void formelem(int i, int j, double a);
	void newmatr(int n, int m);
	void eden();
	double det();
	double operator()(int i, int j);
	Matrix obrat();
	Matrix minormat(int i, int j, int n, int m);
	Matrix minormat(int i, int j);
	Matrix &operator=(Matrix &A);
	Matrix operator*(Matrix &A);
	Matrix operator*(double A);
	Matrix operator+(Matrix &A);
	Matrix operator-(Matrix &A);
	Matrix transporn();
	int razstolb();
	int razstrok();
	int rang();
	bool cheknull();
private:
	double **matr;
	int n, m;
};
