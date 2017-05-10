#include <iostream>

using namespace std;

int** random(int n, int m) {
	int **a;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		*(a + i) = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(a + i) + j) = rand() % 2;
		}
	}
	return a;
}

int** Input(int n, int m) {
	int **a;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		*(a + i) = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> *(*(a + i) + j);
		}
	}
	return a;
}

void del(int **a, int &n, int &m) {
	for (int i = 0; i < n; i++) {
		delete[] * (a + i);
	}
	m = n = 0;
}

bool SquareTest(int **a, int n, int ism, int jsm) {
	for (int i = 0; i < n; i++) {
		if (*(*(a + i + ism) + jsm) == 0) {
			return false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (*(*(a + n - 1 + ism) + i +jsm) == 0) {
			return false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (*(*(a + ism)+i + jsm) == 0) {
			return false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (*(*(a + i + ism)+ n - 1 + jsm) == 0) {
			return false;
		}
	}
	return true;
}

void Search(int **a, int n, int m, int &ism, int &jsm, int &nmaxl) {
	int k = 0;
	if (n >= m) {
		k = m;
	}
	else {
		k = n;
	}
	for (int i = 1; i < k + 1; i++) {
		for (int st = 0; st < n - i + 1; st++) {
			for (int sb = 0; sb < m - i + 1; sb++) {
				if (SquareTest(a, i, st, sb)) {
					ism = st;
					jsm = sb;
					nmaxl = i;
				}
			}
		}
	}
}

void Out(int **a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%6d", *(*(a + i) + j));
		}
		cout << endl;
	}
}

void OutS(int **a, int ism, int jsm, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6d", *(*(a + i + ism) + j + jsm));
		}
		cout << endl;
	}
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	int n, m, ism = 0, jsm = 0, nmax = 0;
	int **a;
	cout << "Введите размерность матрицы m*n\n";
	cin >> n >> m;
	cout << "Рандомная матрица\n";
	a = Input(n, m);
	Out(a, n, m);
	Search(a, n, m, ism, jsm, nmax);
	cout << "Найденная матрица\n";
	OutS(a, ism, jsm, nmax);
	cout << "Расположение левого верхнего угла в основной матрице " << ism + 1  << " " << jsm + 1 <<endl;
	del(a, n, m);
	system("pause");
	return 0;
}
