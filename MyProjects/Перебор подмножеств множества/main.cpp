#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

void rand(double *a, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 21 - 10;
	}
}

bool SearchSumm(double *a, int n, double sum) {
	double sumb = 0;
	bool key = false;
	int k = 0, komb = 1;
	for (int i = 1; i < pow(2, n); i++) {
		for (int j = 0; j < n; j++) {
			if (((1<<j)&i)!= 0) {
				sumb += *(a + j);
			}
		}
		if (sumb == sum) {
			k = i;
			key = true;
			cout << "Комбинация " << komb << endl;
			while (k) {
				cout << k % 2;
				k /= 2;
			}
			komb++;
			cout << "\n";
		}
		sumb = 0;
	}
	return key;
}

void Out(double *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%9.0f", *(a + i));
	}
	cout << endl;
}

int main() {
	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	system("color f0");
	int n;
	double *a, s;
	cout << "Введите количество элементов множества\n";
	cin >> n;
	a = new double[n];
	rand(a, n);
	cout << "Множество\n";
	Out(a, n);
	cout << "Введите искомую сумму\n";
	cin >> s;
	cout << "Проверка наличия суммы\n"<<SearchSumm(a, n, s)<<endl;
	delete[] a;
	system("pause");
	return 0;
}
