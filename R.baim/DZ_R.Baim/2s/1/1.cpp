#include <iostream>
#include <time.h>

using namespace std;


struct Matrix {
	double **mass;
	int n;
	int m;
};

struct Mass {
	int *mass;
	int l;
};

void random(Matrix &A) {
	for (int i = 0; i < A.n; i++) {
		for (int j = 0; j < A.m; j++) {
			*(*(A.mass + i) + j) = rand() % 20 - rand() % 10;
		}
	}
}

void out(Matrix &A) {
	for (int i = 0; i < A.n; i++) {
		for (int j = 0; j < A.m; j++) {
			printf("%9.3f", *(*(A.mass + i) + j));
		}
		printf("\n");
	}
}

void DelStrokMass(Matrix &A, Mass &L) {
	for (int ig = 0; ig < L.l; ig++) {       //Основной алгоритм удаления
		if (*(L.mass + ig) >= 0 && *(L.mass + ig) < A.n) {//Элемент защиты от неправильного индекса
			for (int j = 0; j < A.m; j++) {
				for (int i = *(L.mass + ig); i < A.n - 1; i++) {
					*(*(A.mass + i) + j) = *(*(A.mass + i + 1) + j);
				}
			}
            A.n--;
			for (int i = 0; i < L.l; i++) {
				if (*(L.mass + i) > *(L.mass + ig)) {//Условие необходимо для правильной индексации номеров
					(*(L.mass + i))--;
				}
			} 
		}
	}
}

int main() {
	system("color f0");
	setlocale(0, "russian");
	srand((unsigned)time(0));
	Matrix A;
	Mass L;
	puts("Введите размер матрицы nxm");
	cin >> A.n >> A.m;
	A.mass = new double*[A.n];
	for (int i = 0; i < A.n; i++) {
		*(A.mass + i) = new double[A.m];
	}
	printf("Рандомная матрица\n");
	random(A);
	printf("\n");
	out(A);
	cout << "Введите количество удаляемых строк\n";
	cin >> L.l;
	L.mass = new int[L.l];
	cout << "Введите номера строк\n";
	for (int i = 0; i < L.l; i++) {
		cin >> *(L.mass + i);
		(*(L.mass + i))--;
	}
	DelStrokMass(A, L);
	printf("Преобразованная матрица\n");
	out(A);
	delete[] L.mass;
	for (int i = 0; i < A.n; i++)
		delete[] * (A.mass + i);
	delete[] A.mass;
	cin.ignore(); cin.get();
	return 0;
}
