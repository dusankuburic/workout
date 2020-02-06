#include<stdio.h>

#define N 50

void zbir(int n);

int main()
{
	int n;
	
	printf("Koliko clanova niza zelite da uneste?\n");
	scanf_s("%d", &n);
	
	if (n > N)
	{
		printf("Potrebno je da uneste broj manji od %d.\n", N);
		return 1;
	}
	zbir(n);

	return 0;
}


void zbir(int n)
{

	int niz[N], parni = 0, neparni = 0;

	for (int i = 0; i < n; i++)
	{
		printf("clan[%d] = ", i);
		scanf_s("%d", &niz[i]);

		if (i % 2 == 0)
		{
			parni += niz[i];
		}
		else
		{
			neparni += niz[i];
		}
	}

	printf("Zbir clanova niza sa parnim indeksom je %d.\n", parni);
	printf("Zbri clanova niza sa neparnim indeksom je %d.\n", neparni);

	return 0;
}