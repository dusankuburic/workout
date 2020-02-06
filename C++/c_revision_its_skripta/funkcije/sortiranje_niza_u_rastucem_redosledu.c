#include<stdio.h>


void pisiNiz(int x[], int n);
void citajNiz(int x[], int n);
void razmeni(int* a, int* b);
void sortiraj(int* a, int n);


int main()
{

	int n, x[50];
	printf("Unesite broj elemenata niza za sortiranje:\n");
	scanf_s("%d", &n);

	printf("Unesite elemente niza:\n");

	citajNiz(x,n);

	sortiraj(x, n);

	printf("Sortirani niz je:\n");
	pisiNiz(x, n);


	return 0;
}


void citajNiz(int x[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("x[%d]=", i);
		scanf_s("%d", &x[i]);
	}
}

void pisiNiz(int x[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("x[%d]=%d", i, x[i]);
		printf("\n");
	}
}


void razmeni(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sortiraj(int* a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(a + i) > *(a + j))
			{
				razmeni(a + i, a + j);
			}
		}
	}


}