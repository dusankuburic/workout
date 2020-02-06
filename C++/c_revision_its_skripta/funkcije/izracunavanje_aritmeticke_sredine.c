#include<stdio.h>

void arSred(int n);

int main()
{
	int x;
	printf("Unesite broj do kojeg zelite aritmeticku sredinu:\n");
	scanf_s("%d", &x);
	arSred(x);
}

void arSred(int n)
{
	float zbir = 0.0;
	int i;
	
	if (n < 1)
	{
		printf("Morate uneti broj veci od 0\n");
		return;
	}
	for (i = 1; i <= n; i++)
	{
		zbir += i;
	}
	zbir = zbir / n;
	printf("Aritmeticka sredina prvih %d brojeva je %.2f\n", n, zbir);
}