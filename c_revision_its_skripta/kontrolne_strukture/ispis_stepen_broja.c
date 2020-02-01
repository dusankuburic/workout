#include<stdio.h>

int main()
{
	int stepen, granica;

	printf("Unesite granice ispisa: ");
	scanf_s("%d", &granica);
	stepen = 1;

	do {
		printf("%d\n", stepen);
		stepen *= 2;

	} while (stepen <= granica);


	return 0;
}