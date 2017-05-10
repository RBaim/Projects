#include <iostream>
#include <time.h>

long Akkerman(long n, long m) {
	if (n == 0) {
		return m + 1;
	} else {
		if (m > 0) {
			return Akkerman(n - 1, Akkerman(n, m - 1));
		} else {
			return Akkerman(n - 1, 1);
		}
	}
}

int main() {
	system("chcp 1251");
	system("color f0"); 
	system("cls");
	long t = clock();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 14; j++) {
			printf("Akkerman(%d, %d) = %d\n", i, j, Akkerman(i, j));
		}
	}
	std::cout << "Runtime: " << (clock() - t)/1000.0 <<" s" << std::endl;
	system("pause");
	return 0;
}