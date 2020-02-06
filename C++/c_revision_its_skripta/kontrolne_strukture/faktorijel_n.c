#include<stdio.h>


int main()
{
	int i, n;
	long faktorijel = 1;

	printf("Unesite ceo broj n: ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		faktorijel = faktorijel * i;
	}

	printf("Faktorijel = %ld\n", faktorijel);

	return 0;
}