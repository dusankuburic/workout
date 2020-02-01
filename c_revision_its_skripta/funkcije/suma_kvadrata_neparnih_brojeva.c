#include<stdio.h>

void kvadrati(int k, int r);


int main()
{
	int n, m;

	printf("Unesite broj n: ");
	scanf_s("%d", &n);

	printf("Unesite broj m: ");
	scanf_s("%d", &m);

	kvadrati(n, m);

	return 0;
}


void kvadrati(int k, int r)
{
	int i;
	int suma = 0;

	if (k >= r) 
	{
		printf("Morate uneti broj m koji je veci od n\n");
		return;
	}
	i = k;

	while (i <= r)
	{
		if (i % 2 == 1)
			suma += i * i;
		i++;
	}

	printf("Suma kvadrata neparnih brojeva od %d do %d je %d\n", k, r, suma);
}