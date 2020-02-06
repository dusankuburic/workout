#include<stdio.h>

int main()
{
	int suma = 0, n, i = 1;

	printf("Unesite ceo broj n od koga zelite sumu: ");
	scanf_s("%d", &n);

	while (i <= n)
	{
		suma += i;
		i++;
	}

	printf("Suma prirodnih brojeva od 1 do %d je: %d\n", n, suma);

	return 0;
}