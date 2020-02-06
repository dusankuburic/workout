#include<stdio.h>

#define PI 3.14

int main()
{
	double p, r, h, v;

	printf("Unesite visinu valjka: ");
	scanf_s("%lf", &h);

	printf("Unesite poluprecnik valjka: ");
	scanf_s("%lf", &r);

	p = 2 * r*PI*(r + h);
	v = r * r*PI*h;

	printf("Povrsina valjka je: %.4f\n", p);
	printf("Zapremina valjka je: %.4f\n", v);

	return 0;
}