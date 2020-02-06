#include<stdio.h>


int main()
{

	int a, n, i = 1, stepen = 1;

	printf("Unesite a i n:\n");
	scanf_s("%d%d", &a, &n);

	while (i++ <= n)
		stepen *= a;


	printf("stepen=%d\n", stepen);

	return 0;
}