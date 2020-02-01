#include<stdio.h>

int provera(int x[], int i);

int main()
{
	int x[13], i, kb = 0;

	printf("\n\n >> Unesite JMBG: \n");
	for (i = 0; i < 13; i++)
	{
		scanf_s("%d", &x[i]);
	}

	kb = provera(x, i);

	if (kb == x[12])
	{
		printf("Uneti jmbg je ispravan!\n");
	}
	else
	{
		printf("Uneti jmbg nije ispravan!\n");
	}
}


int provera(int x[], int i)
{
	int m, suma = 0, kont = 0, kontrolniBroj = 0, rez = 0;

	i = 0;
	for (m = 7; m > 1; m--)
	{
		suma += m * x[i];
		i++;
	}

	i = 6;

	for (m = 7; m > 1; m--)
	{
		suma += m * x[i];
		i++;
	}

	kont = suma % 11;

	if (kont == 0 || kont == 1)
	{
		kontrolniBroj = 0;
	}
	else
	{
		kontrolniBroj = 11 - kont;
	}

	return kontrolniBroj;
}