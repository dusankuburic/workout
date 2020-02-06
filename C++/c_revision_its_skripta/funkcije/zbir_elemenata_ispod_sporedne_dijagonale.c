#include<stdio.h>
#include<stdlib.h>

int main()
{
	int** matrica;
	int n, i, j, k, temp, suma = 0, x = 0;


	printf("Unesite broj vrsta i kolona kvadratne matrice:\n");
	scanf_s("%d", &n);
	if (n <= 0)
	{
		printf("Potrebno je da unesete pozitivan ceo broj.\n");
		return 1;
	}

	matrica = malloc(n * sizeof(int*));
	if (matrica == NULL)
	{
		printf("Potrebno je da unesete pozitivan ceo broj.\n");
		return 1;
	}

	for (i = 0; i < n; i++)
	{
		*(matrica + i) = malloc(n * sizeof(int));

		if (*(matrica + i) == NULL)
		{
			printf("Doslo je do greske u alokaciji memorije.\n");
			for (k = 0; k < i; k++)
				free(*(matrica + k));
			free(matrica);

			return 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("x[%d][%d] = ", i, j);
			scanf_s("%d", &temp);
			*(*(matrica + i) + j) = temp;
		}
	}

	for (i = n - 1; i >= 0; i--)
	{
		x++;
		for (j = n - 1; j >= x; j--)
		{
			temp = *(*(matrica + i) + j);
			suma += temp;
		}
	}

	printf("Zbir elemenata ispod sporedne dijagonale iznosi %d\n\n", suma);

	for (i = 0; i < n; i++)
		free(*(matrica + i));
	free(matrica);


	return 0;

}

