#include<stdio.h>
#include<stdlib.h>


int main()
{
	int* a;
	int n, i, j, k;

	printf("Koliki je broj elemenata niza:\n");
	scanf_s("%d", &n);

	if (n <= 0)
	{
		printf("Potrebno je da unesete pozitivan ceo broj.\n");
		return 1;
	}

	a = malloc(n * sizeof(int));
	printf("Unesite clanoce niza:\n");

	for (i = 0; i < n; scanf_s("%d", &a[i++]));
	printf("Na koje mesto u nizu zelite da umetnete novi clan?\n");

	scanf_s("%d", &j);

	if (j <= 0 || j > n)
	{
		printf("Potrebno je da unesete pozitivan ceo broj koj je manji od broja %d.\n", n + 1);
		return 1;
	}

	printf("Unesite clan:\n");
	scanf_s("%d", &k);

	a = realloc(a, (n + 1) * sizeof(int));

	for (i = n; i > j - 1; i--)
	{
		a[i] = a[i - 1];
	}

	a[j - 1] = k;

	printf("Dati niz je:\n{");
	for (i = 0; i < n + 1; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("}\n");

	free(a);

	return 0;
}
