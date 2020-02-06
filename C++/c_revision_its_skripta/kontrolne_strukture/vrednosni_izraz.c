#include<stdio.h>

int main()
{
	double x, y, z, min, max;

	printf("Unesite vrednosti za x: ");
	scanf_s("%lf", &x);
	printf("Unesite vrednosti za y: ");
	scanf_s("%lf", &y);

	if (x > y)
	{
		max = x;
		min = y;
	}
	else
	{
		max = y;
		min = x;
	}

	printf("Maksimum je: %f\n", max);
	printf("Minumum je: %f\n", min);
	z = (min + 0.5) / (1 + max * max);
	printf("z= %.2f\n", z);

	return 0;
	
}