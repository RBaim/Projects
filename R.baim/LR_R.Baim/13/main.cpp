#include <iostream>
#include <Windows.h>

using namespace std;

int CharCheck(char s) {
	switch (s) {
	case '(': return 1;
	case ')': return -1;
	}
	return 0;
}

bool TextChek(char **a, int n, int m) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(*(a + i)); j++) {
			count += CharCheck(*(*(a + i) + j));
			if (count < 0) {
				return false;
			}
		}
	}
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool SpecOut(char **a, int n, int m) {
	int s = 0;
	bool key = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(*(a + i)); j++) {
			if (*(*(a + i) + j) == '(') {
				s++;
			}
			if (s == 2) {
				for (int im = i; im < n; im++) {
					for (int jm = 0; jm < strlen(*(a + im)); jm++) {
						if (key && im == i) {
							jm = j;
							key = false;
						}
						if (*(*(a + im) + jm) == ')') {
							s = -1;
							key = true;
							for (int io = i; io < im + 1; io++) {
								for (int jo = 0; jo < strlen(*(a + io)) && *(*(a + io) + jo) != ')'; jo++) {
									if (key && io == i) {
										jo = j + 1;
										key = false;
										if (*(*(a + io) + jo) == '\0') {
											io++;
											jo = 0;
										}
									}
									cout << ((a + io) + jo) << endl;
								}
							}
							return true;
						}
					}
				}
				return false;
			}
		}
	}
	return false;
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	char **a;
	a = new char*[10];
	for (int i = 0; i < 10; i++) {
		*(a + i) = new char[128];
	}
	cout << "Введите текст\n";
	for (int i = 0; i < 10; i++) {
		cin.getline(*(a + i), 128);
	}
	cout << "Правильность скобок(0-ложь, 1-истина)\n" << TextChek(a, 10, 128) << endl;
	cout << "Адреса элементов между 2 открывающейся и ближайщей закрывающейся скобками\n";
	if (!SpecOut(a, 10, 128)) {
		cout << "Невозможно вывести адреса элементов между 2 открывающейся и ближайшей закрывающейся скобками\n";
	}
	for (int i = 0; i < 10; i++) {
		delete[] * (a + i);
	}
	delete[] a;
	cin.ignore(); cin.get();
	return 0;
}
