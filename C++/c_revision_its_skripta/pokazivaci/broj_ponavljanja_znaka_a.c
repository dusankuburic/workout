#include<stdio.h>

int brojanjeZnaka(char znak, char* s);


int main()
{
	int ukupno;
	char izraz[] = "ITS - Visoka skola strukovnih studija";
	printf("Dati string je: %s\n", izraz);

	ukupno = brojanjeZnaka('a', izraz);
	printf("Broj pojavljivanja znaka a u datom stringu: ");
	printf("%d\n", ukupno);

	return 0;
}


int brojanjeZnaka(char znak, char* s)
{
	int suma = 0;
	while (*s)
	{
		if (*s == znak)
			suma++;
		s++;
	}
	return suma;
}