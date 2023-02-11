#include <iostream>
#include <stdio.h>
#include <conio.h>
void main()
{
	double t, u, k = 6, r = 5e-7, x = 0.095;
	t = tan(x) + r * (1 - log(x));
	u = t / (pow(x, 3) + 1) / (1 - exp(k - 4));

	printf("t = ");
	printf("%f", t);
	printf("u = ");
	printf("%f", u);
	_getch();
}