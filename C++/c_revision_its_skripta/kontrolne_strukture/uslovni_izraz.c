#include<stdio.h>

int main()
{
	double x, y;

	printf("Unesite broj x: ");
	scanf_s("%lf", &x);

	if (x < 0)
		y = -5;
	else if (x < 1)
		y = x + 2;
	else if (x < 5)
		y = 3 * x - 1;
	else
		y = 2 * x;

	printf("Y = %.3f\n", y);

	return 0;
}