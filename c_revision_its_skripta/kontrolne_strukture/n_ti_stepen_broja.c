#include<stdio.h>

int main()
{
	int a, n, i = 1, stepen = 1;
	
	printf("Unesite broj a: ");
	scanf_s("%d", &a);

	printf("Unesite broj n: ");
	scanf_s("%d", &n);


	while (i <= n)
	{
		stepen *= a;
		i++;
	}

	printf("Broj %d na %d-ti stepen je: %d\n", a, n, stepen);

	return 0;
}