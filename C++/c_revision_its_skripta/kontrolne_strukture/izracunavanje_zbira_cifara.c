#include<stdio.h>

int main()
{
	int n, zbir = 0;


	printf("Unesite ceo broj, koji je veci od 1 i manji od 1000:\n");
	scanf_s("%d", &n);

	if (n <= 1 || n >= 1000)
	{
		printf("Potrebno je da unesete broj veci od 1 i manji od 1000.\n");
		return 1;
	}

	//cifra stotica
	zbir += n / 100;
	//cifra desetica
	zbir += (n / 10) % 10;
	//cifra jedinica
	zbir += n % 10;

	printf("Zbir cifara koj broja %d iznosi %d.\n", n, zbir);

	return 0;
}