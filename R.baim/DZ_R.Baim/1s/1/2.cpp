#include<math.h>
#include<locale.h>
#include<iostream>

using namespace std;

int main()
{
	setlocale(0, "russian");
	puts("¬ведите X,Y,W");
	float x, y, w, z, r;
	cin >> x >> y >> w;
	z = x + y + w;
	r = x*y*w;
	if (z <= r)
	{
		printf("max^2(X*Y*Z)= %f \n", pow(r, 2));
	}
	if (r < z)
	{
		printf("max^2(X+Y+Z)= %f \n", pow(z, 2));
	}
	system("pause");
	return 0;
}