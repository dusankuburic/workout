#include<stdio.h>
#include<string.h>

int main()
{

	char niz1[] = "Ja sam student ITS-a, Petar Petrovic.";
	int i, duzina;
	int broj = 0;

	duzina = strlen(niz1);

	for (i = 0; i <= duzina; i++)
		if (niz1[i] == 'a')
			broj++;

	printf("Broj ponavljanja znaka 'a' u datom nizu je %d.\n", broj);


	return 0;
}