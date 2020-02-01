#include<stdio.h>


int main()
{
	int znak, br;
	int blank = 0, other = 0, malo = 0, veliko = 0;
	int digits[10];


	for (br = 0; br < 10; ++br)
	{
		digits[br] = 0;
	}

	printf("Unesite proizvoljan niz znakova:\n");

	while ((znak = getchar()) != '\n')
	{
		if (znak >= '0' && znak <= '9')
			++digits[znak - '0'];
		else if (znak == ' ' || znak == '\t')
			++blank;
		else if (znak >= 'a' && znak <= 'z')
			++malo;
		else if (znak >= 'A' && znak <= 'Z')
			++veliko;
		else
			++other;
		
	}
	for (br = 0; br < 10; ++br)
		printf("Cifra %d se pojavljuje %d puta\n", br, digits[br]);


	printf("\nBlankova ima: %d, Malih slova ima: %d\n Velikih slova ima:%d, Ostalih znakova ima: %d\n", blank, malo, veliko, other);
}