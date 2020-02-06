#include<stdio.h>

#define N 100

int main()
{
	int i, brojClanova, niz[N];
	double prosek, suma = 0.0;

	printf("Koliko clanova zelite da unesete: ");
	scanf_s("%d", &brojClanova);

	while (brojClanova > N)
	{
		printf("Unesite broj clanova niza: ");
		scanf_s("%d", &brojClanova);
	}

	for (i = 0; i < brojClanova; i++)
	{
		printf("Unesite clan [%d]: ", i + 1);
		scanf_s("%d", &niz[i]);
		suma += niz[i];
	}

	prosek = suma / brojClanova;

	printf("Porsek je: %lf\n Manji od proseka su:\n", prosek);
	for (i = 0; i < brojClanova; i++)
	{
		if (niz[i] < prosek)
		{
			printf("%d ", niz[i]);
		}
	}

	printf("\n");

	return 0;
}