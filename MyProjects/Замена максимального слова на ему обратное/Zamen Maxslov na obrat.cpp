#include<string.h>
#include<iostream>

int main()
{
	char a[100], *first, *end, *ptr1=a, *ptr2=a, tmp[30];
	puts("Imput strok");
	gets_s(a);
	int d = 0;
	first = a;
	end = first;
	while (*end != '\0')
	{
		end = first;
		while (*end != '\0'&&*end != ' ')
		{
			end++;
		}
		if (strlen(first) - strlen(end) > d)
		{
			d = strlen(first) - strlen(end);
			ptr1 = first;
			ptr2 = end-1;
		}
		first = end + 1;
	}
	for (int i = 0; i < d / 2; i++)
	{
		tmp[1] = a[strlen(a) - strlen(ptr1) + i];
		a[strlen(a) - strlen(ptr1) + i] = a[strlen(a) - strlen(ptr2) - i];
		a[strlen(a)-strlen(ptr2)-i] = tmp[1];
	}
	std::cout << a<< std::endl;
	system("pause");
}