#include <iostream>

using namespace std;

struct numbers {
	double numd;
	int pos;
}num;

void ReadFile(FILE *f) {
	while (fread(&num, sizeof(num), 1, f) != 0)
	{
		printf("%d %f \n", num.pos, num.numd);
	}
	rewind(f);
}

void WriteFile(FILE *f) {
	int i = 0;
	char buf[128];
	gets_s(buf);
	while (strlen(buf) != 0) {
		num.pos = i;
		i++;
		num.numd = atof(buf);
		fwrite(&num, sizeof(num), 1, f);
		gets_s(buf);
	}
	rewind(f);
}

bool CheckDouble(double *a, int n, double &c) {
	for (int i = 0; i < n; i++) {
		if (*(a + i) == c) {
			return false;
		}
	}
	return true;
}

void DelComponents(FILE *f) {
	double *a = new double[3];
	FILE *g = fopen("tmp.tmp", "w+b");
	for (int i = 0; i < 3; i++) {
		fread(&num, sizeof(num), 1, f);
		fwrite(&num, sizeof(num), 1, g);
		*(a+i) = num.numd;
	}
	while (fread(&num, sizeof(num), 1, f) != 0) {
		if (CheckDouble(a, 3, num.numd)) {
			fwrite(&num, sizeof(num), 1, g);
		}
	}
	delete[] a;
	fcloseall();
	remove("1.txt");
	rename("tmp.tmp", "1.txt");
	f = fopen("1.txt", "rb");
}

int main() {
	system("chcp 1251");
	system("color f0");
	system("cls");
	puts("¬ведите вещественные числа(или enter)");
	FILE *f = fopen("1.txt", "w+b");
	WriteFile(f);
	fclose(f);
	f = fopen("1.txt", "rb");
	puts("—одержимое файла");
	ReadFile(f);
	puts("—одержимое файла после удаление повтор€ющихс€ элментов равных 1, 2, 3 компоненте");
	DelComponents(f);
	ReadFile(f);
	fclose(f);
	system("pause");
	return 0;
}
