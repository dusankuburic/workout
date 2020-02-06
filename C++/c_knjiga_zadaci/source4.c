#include<stdio.h>


int main()
{

	int d, m, g;

	printf("Unesite dan: ");
	scanf_s("%d", &d);

	printf("Unesite mesec: ");
	scanf_s("%d", &m);

	printf("Unesite godinu: ");
	scanf_s("%d", &g);



	//sledeci dan

	//=> 30/11/1997
	//<= 1/12/1997

	/*
	SLEDECI DAN
	
	d++;
	if (d > 30)
	{
		d = 1;
		m++;

		if (m > 12) {
			g++;
		}
	}

	printf("%d/%d/%d", d, m, g);
	*/

	//PRETHODNI DAN

	d--;
	if (d == 0) {
		d = 30;
		m--;

		if (m == 0) {
			m = 12;
			g--;
		}
	}

	printf("%d/%d/%d", d, m, g);

	return 0;
}