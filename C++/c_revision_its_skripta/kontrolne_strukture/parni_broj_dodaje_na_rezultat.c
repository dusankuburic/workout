#include<stdio.h>

int main()
{
	int broj, suma = 0;
	printf("Unesite ceo broj u opsegu od 1 do 100:\n");
	scanf_s("%d", &broj);

	while (broj >= 1 && broj <= 100)
	{
		if (broj % 2 == 0)
		{
			suma += broj;
		}
		printf("Unesite ceo broj u opsegu od 1 do 100:\n");
		scanf_s("%d", &broj);
	}
	printf("Suma svih parnih brojeva koje ste upisali,\na nalaze se u opsegu od 1 do 100 iznosi: %d.\n", suma);
}