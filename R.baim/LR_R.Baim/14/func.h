#pragma once

struct Matrix {
	double **mass;
	int n;
	int m;
};

double ColumnArithmetic(Matrix &A, int num);
