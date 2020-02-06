#include<stdio.h>


int main()
{

	int brojac = 0;
	float suma = 0, stopcode = 0, broj;
	
	printf("Unesite niz znakova koji se zavrzava sa %d\n", stopcode);
	scanf_s("%f", &broj);

	while (broj != stopcode)
	{
		suma += broj;
		brojac++;
		scanf_s("%d", &broj);
	}


	printf("Srednja vrednost je= %f\n", suma/brojac);

	return 0;
}