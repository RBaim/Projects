#include <iostream>
#include <stdlib.h>

int main()
{
	int kolst, kolsim;
	puts("Imup kol strok massiv and kolsim strok");
	std::cin >> kolst>>kolsim;
	char **a = new char*[kolst];
	for (int i = 0; i < kolst; i++)
	{
		a[i] = new char[kolsim];
	}
	puts("Imput stroki");
	for (int i = 0; i < kolst; i++)
	{
		std::cout << i+1 << std::endl;
		std::cin >> a[i];
	}
	puts("Out");
	for (int i = 0; i < kolst; i++)
	{
		std::cout << i+1 << std::endl;
		std::cout << a[i];
		printf("\n");
	}
	for (int i = 0; i < kolst; i++)
	{
		delete a[i];
	}
	delete []a;
	system("pause");
}