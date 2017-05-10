#include "func.h"
#include <iostream>
#include <time.h>

using namespace std;

void random(Matrix &A) {
	for (int i = 0; i < A.n; i++) {
		for (int j = 0; j < A.m; j++) {
			*(*(A.mass + i) + j) = rand() % 20 - rand() % 10;
		}
	}
}

void out(Matrix &A) {
	for (int i = 0; i < A.n; i++) {
		for (int j = 0; j <A.m; j++) {
			printf("%9.3f", *(*(A.mass + i) + j));
		}
		printf("\n");
	}
}

int main() {
	system("color f0");
	setlocale(0, "russian");
	srand((unsigned)time(0));
	Matrix A;
	puts("Введите размер матрицы nxm");
	cin >> A.n >> A.m;
	A.mass = new double*[A.n];
	for (int i = 0; i < A.n; i++) {
		*(A.mass+i) = new double[A.m];
	}
	printf("Рандомная матрица\n_____________________\n_____________________\nсредние арифметические значения для столбцов\n");
	random(A);
	printf("\n");
	out(A);
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < A.m * 9; i++) {
			printf("_");
		}
		printf("\n");
	}
	for (int j = 0; j < A.m; j++) {
		printf("% 9.3f", ColumnArithmetic(A, j));
	}
    printf("\n");
	for (int i = 0; i < A.n; i++)
		delete[] * (A.mass + i);
	delete[] A.mass;
    system("pause");
	return 0;
}
