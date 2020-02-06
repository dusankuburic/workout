#include<stdio.h>

void zbirKvadrata(int n);

int main()
{
	int x;
	printf("Unesite broj do kojeg zelite zbir kvadrata:\n");
	scanf_s("%d", &x);
	zbirKvadrata(x);
}


void zbirKvadrata(int n)
{
	int i, zbir = 0;

	if (n <= 1)
	{
		printf("Morate uneti broj veci od 1\n");
		return;
	}
	
	for (i = 1; i <= n; ++i)
	{
		zbir += i * i;
	}
	printf("Zbir kvadrata brojeva od 1 do %d je %d\n", n, zbir);
}