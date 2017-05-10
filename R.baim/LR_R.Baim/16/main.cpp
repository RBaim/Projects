#include <iostream>

bool CheckChar(char *a, char &c) {//Процедура рекурсивная для проверки одной буквы "c" исходной строки,
	//сравнение идет с массивом гласных, который надо определить в вызывающей программе
	if (c == *a) {
		return true;
	}
	if (strlen(a) == 0) {
		return false;
	}
	return CheckChar((a + 1), c);
}

void CountGlas(char *a, char *s, int &count) { //Реализация рекурсии как функции
	if (strlen(a) == 0) {
		//Выход из рекурсии
	} else {
		count += (int)CheckChar(s, *a);//Вызов рекурсивной процедуры
		CountGlas((a + 1), s, count);
	}
}

int CountClass(char *a, char *s) { //Процедурная реализация рекурсии
	if (strlen(a) == 0) {
		//Выход из рекурсии
		return 0;
	}
	return (int)CheckChar(s, *a) + CountClass(a+1, s);
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	char a[64];
	char s[] = "AEIOUYaeiouy";
	int count = 0;
	std::cout << "Введите строку" << std::endl;
	std::cin >> a;
	CountGlas(a, s, count);
	std::cout << "Количество гласных в строке " << count << std::endl;
	//std::cout << "Количество гласных в строке " << CountClass(a, s) << std::endl;
	system("pause");
	return 0;
}
