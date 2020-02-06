#include<stdio.h>

void brojevi(int a, int b);


int main()
{

	int a, b;
	printf("Unesite pozitivne cele brojeve A i B, pri cemu moda da vazi uslov A < B\n");

	printf("A= ");
	scanf_s("%d", &a);

	printf("B = ");
	scanf_s("%d", &b);


	brojevi(a, b);


	return 0;
}



void brojevi(int a, int b)
{
	int i;
	printf("Izmedju A i B naleze se seldeci parni brojevi:\n");
	for (i = a + 1; i < b; i++)
	{
		if (i % 2 == 0)
			printf("%d\n", i);
	}
}