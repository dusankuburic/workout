#include<stdio.h>
#include<stdlib.h>



/* 
 * GRESKA ISPRAVI !!!!
 * 
 */

float** unosElemenata(float** matrica, int a, int b);
void ispisMatrice(float** matrica, int a, int b);
int izracunaj(float** matrica, int a, int b);
void ispisRezultata(float** matrica, int a, int b);
void oslobadjanjeMemorije(float** matrica, int x);


int main()
{
	while (1)
	{
		float** matrica = NULL;
		int x, y;

		printf("\nUnesite broj redova (x) i broj kolona (y),\n(za kraj unesite x=0)\nx= ");
		scanf_s("%d", &x);

		if (x == 0)
			break;
		if (x < 0)
		{
			printf("Broj redova mora biti veci od 0.\n");
			break;
		}

		printf("y = ");
		scanf_s("%d", &y);
		if (y < 0)
		{
			printf("Broj kolona mora biti veci od 0.\n");
			break;
		}
		
		matrica = unosElemenata(matrica, x, y);
		if (matrica == NULL)
			break;


		ispisMatrice(matrica, x, y);

		printf("\n U datoj matrici ima ukupno %d elemenata,\n koji su jednaki aritmetickoj sredini svojih suseda.\n\n", izracunaj(matrica, x, y));
		ispisRezultata(matrica, x, y);
		oslobadjanjeMemorije(matrica, x);
	}
}

float** unosElemenata(float** matrica, int a, int b)
{
	int i, j, k;
	float temp = 0;

	matrica = malloc(a * sizeof(float*));

	if (matrica == NULL)
	{
		printf("Doslo je do greska u alokaciji memorije.\n");
		return matrica;
	}

	printf("Unesite elemente matrice:\n");
	for (i = 0; i < a; i++)
	{
		if (*(matrica + i) == NULL)
		{
			printf("Doslo je do greska u alokaciji memorije.\n");
			for (k = 0; k < i; k++)
				free(*(matrica + k));

			free(matrica);
			matrica = NULL;
			return matrica;
		}

		for (j = 0; j < b; j++)
		{
			printf("[%d, %d] = ", i + 1, j + 1);
			scanf_s("%f", &temp);
			*(*(matrica + i) + j) = temp;
		}
	}

	return matrica;
}


void ispisMatrice(float** matrica, int a, int b)
{
	int i, j;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			printf("%10.2f", *(*(matrica + i) + j));
				
		}
		printf("\n");
	}
}

int izracunaj(float** matrica, int a, int b)
{
	int i, j, temp = 0, broj = 0;

	float temp1 = 0;

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if ((i - 1) >= 0)
			{
				temp1 += *(*(matrica + (i - 1)) + j);
				broj += 1;

				if ((j - 1) >= 0)
				{
					temp1 += *(*(matrica + (i - 1)) + (j - 1));
					broj += 1;
				}

				if ((j + 1) < b)
				{
					temp1 += *(*(matrica + (i - 1)) + (j + 1));
					broj += 1;
				}
			}


			if ((i + 1) < a)
			{
				temp1 += *(*(matrica + (i + 1)) + j);
				broj += 1;
				if ((j - 1) >= 0)
				{
					temp1 += *(*(matrica + (i + 1)) + (j - 1));
					broj += 1;
				}

				if ((j + 1) < b)
				{
					temp1 += *(*(matrica + (i + 1)) + (j + 1));
					broj += 1;
				}
			}

			if ((j - 1) >= 0)
			{
				temp1 += *(*(matrica + i) + (j - 1));
				broj += 1;
			}
			if ((j + 1) < b)
			{
				temp1 += *(*(matrica + i) +(j-1));
				broj += 1;
			}
			if (broj > 0)
			{
				temp1 /= broj;
			}

			if (*(*(matrica + i) + j) == temp1)
			{
				temp += 1;
				temp1 = 0;
				broj = 0;
			}

		}

	}

	return temp;
}


void ispisRezultata(float** matrica, int a, int b)
{
	int i, j, temp = 0, broj = 0;
	float temp1 = 0;

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if ((i - 1) >= 0)
			{
				temp1 += *(*(matrica + (i - 1)) + j);
				broj += 1;
				if ((j - 1)>= b)
				{
					temp1 += *(*(matrica + (i - 1)) + (j - 1));
					broj += 1;
				}
				if ((j + 1) < b)
				{
					temp1 += *(*(matrica + (i - 1)) + (j + 1));
					broj += 1;
				}
			}

			if ((i + 1) < a)
			{
				temp1 += *(*(matrica + (i + 1)) + j);
				broj += 1;
				if ((j - 1) >= 0)
				{
					temp1 += *(*(matrica + (i + 1)) + (j - 1));
					broj += 1;
				}
				if ((j + 1) < b)
				{
					temp1 += *(*(matrica + (i+1)) + (j+1));
				}
			}


			if ((j - 1) >= 0)
			{
				temp1 += *(*(matrica + i) + (j - 1));
				broj += 1;
				if ((j + 1) < b)
				{
					temp1 += *(*(matrica + i) + (j + 1));
					broj += 1;
				}
				if (broj > 0)
				{
					temp1 /= broj;
				}

				if (*(*(matrica + i) + j) == temp1)
				{
					printf("[%d, %d]\n", i+1, j+1);

					temp1 = 0;
					broj = 0;
				}
			}

		}
	}

}


void oslobadjanjeMemorije(float** matrica, int x)
{
	int i;
	if (matrica != NULL)
	{
		for (i = 0; i < x; i++)
		{
			if (*(matrica + i) != NULL)
			{
				free(*(matrica + i));
			}
			free(matrica);
		}
	}
}


