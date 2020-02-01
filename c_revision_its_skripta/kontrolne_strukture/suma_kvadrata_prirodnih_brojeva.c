#include<stdio.h>

int main()
{
	int suma = 0, n, m, i;

	printf("Unesite cele brojeve n i m:\n");
	scanf_s("%d%d", &n, &m);

	i = n;
	while (i <= m)
	{
		if (i % 2 == 0)
			suma += i * i;
		i++;
	}

	printf("Suma kvadrata parnih brojeva od %d do %d je %d\n", n, m, suma);

	return 0;
}