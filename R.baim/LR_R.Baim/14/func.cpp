#include "func.h"

double ColumnArithmetic(Matrix &A, int num) {
	double Arith = 0;
	if (num <= A.m - 1 && num >= 0) {
		for (int i = 0; i < A.n; i++) {
			Arith += *(*(A.mass + i) + num);
		}
		return Arith / (double)A.n;
	}
	return Arith;
}
