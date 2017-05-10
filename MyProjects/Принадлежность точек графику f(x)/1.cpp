#include <iostream>
#include <cmath>

using namespace std;

double f1(double x)
{
	return cos(x);
}

double f2(double x)
{
	return sin(x*x);
}

bool NEIBR(double x, double y, double(f)(double))
{
	if (f(x) == y) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char** argv) {
	double(*ptr)(double);
	int n;
	printf("1.y=cos(x)\n");
	printf("2.y=sin(x^2)\n1 in default\n");
	cin >> n;
	ptr = f1;
	switch (n)
	{
	case 1:ptr = f1; break;
	case 2:ptr = f2;
	}
	cout << "Kol toch\n";
	cin >> n;
	cout << "Toch\n";
	double **a;
	a = new double*[2];
	for (int i = 0; i<2; i++)
	{
		a[i] = new double[n];
	}
	for (int i = 0; i<n; i++)
	{
		cin >> a[0][i];
		cin >> a[1][i];
	}
	for (int i = 0; i<n; i++)
	{
		if (NEIBR(a[0][i], a[1][i], ptr) == true){
		cout << i + 1 << " true\n";
		}
		else {
			cout << i + 1 << " false\n";
		}
	}
	for (int i = 0; i<2; i++)
	{
		delete[] a[i];
	}
	delete a;
	return 0;
}