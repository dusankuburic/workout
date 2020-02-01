#include<stdio.h>

#define N 100

int main()
{
	int niz[N];
	int i, duzina, temp = 2, j;

	printf("Unesite duzinu niza, koja moze biti najmanje 3, a najvise %d:\n", N);
	scanf_s("%d", &duzina);

	while (duzina >= 3 && duzina <= N)
	{
		for (i = 1; i <= duzina; i++)
		{
			printf("Unesite clan niza x[%d]:", i - 1);
			scanf_s("%d", &j);
			niz[i - 1] = j;
		}

		for (i = 0; i < duzina; i++)
		{
			if (niz[i] == (niz[i - 1] + niz[i - 2]))
			{
				temp += 1;
			}
			else
			{
				printf("Dati niz brojeva ne odgovara fibonacijevom nizu.\n");
				break;
			}
		}

		if (temp == duzina)
			printf("Dati niz brojeva odgovara fibonacijevom nizu.\n");
		break;
	}

	return 0;
}