#include<stdio.h>

void vraca_dve_vrednosti(int x, int y, int* kolicnik, int* ostatak)
{
	printf("Kolicnik postavljam na adresu: %p\n", kolicnik);
	printf("Ostatak postavljam na adresu: %p\n", ostatak);
	*kolicnik = x / y;
	*ostatak = x % y;
}


int main()
{
	int kolicnik, ostatak;

	printf("Adresa promenjljive kolicnik je: %p\n", &kolicnik);
	printf("Adresa promenjljive ostatak je: %p\n", &ostatak);

	vraca_dve_vrednosti(9, 2, &kolicnik, &ostatak);

	printf("Vrednost promenljive kolicnik je %d\n", kolicnik);
	printf("Vrednost promenljive ostatak je %d\n", ostatak);

	return 0;
}