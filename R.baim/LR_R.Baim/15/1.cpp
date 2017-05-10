#include <stdio.h>
#include <iostream>
#include <Windows.h>

void FormFile(FILE *f) {
	char buf[128];
	gets_s(buf);
	while (strlen(buf) != 0) {
		fprintf(f, "%s\n", buf);
		fflush(stdin);
		gets_s(buf);
	}
}

void PrintFile(FILE *f) {
	char buf[128];
	while (fscanf(f, "%s\n", buf) != EOF) {
		printf("%s\n", buf);
	}
	rewind(f);
}

int Word6(FILE *f) {
	int n = 0;
	char buf[128];
	while (fscanf(f, "%s\n", buf) != EOF) {
		if (strlen(buf) >= 6) {
			n++;
		}
	}
	rewind(f);
	return n;
}

bool CharCheck(char *a) {
	char b[] = "AEIOUYaeiouy";
	for (int i = 0; i<12; i++) {
		if (*a == *(b + i)) {
			return true;
		}
	}
	return false;
}

void DelWordglas(FILE *f) {
	FILE *out = fopen("tmp.txt", "w+");
	char buf[128];
	while (fscanf(f, "%s\n", buf) != EOF) {
		if (!CharCheck(buf)) {
			fprintf(out, "%s\n", buf);
		}
	}
	fclose(f); fclose(out);
	remove("in.txt");
	rename("tmp.txt", "in.txt");
	f = fopen("in.txt", "r+");
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	FILE *f, *out;
	f = fopen("in.txt", "w+");
	printf("Введите слово(или enter) в файл in.txt\n");
	FormFile(f);
	fclose(f);
	f = fopen("in.txt", "r+");
	printf("Что записано в in.txt\n");
	PrintFile(f);
	printf("Количество слов больше 6 символов %d\n", Word6(f));
	DelWordglas(f);
	printf("Содержимое файла после удаления слов начинающихся на гласные\n");
	PrintFile(f);
	fclose(f);
	system("pause");
	return 0;
}