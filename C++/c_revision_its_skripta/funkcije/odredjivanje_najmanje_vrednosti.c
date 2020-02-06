#include<stdio.h>

int ceo_br(int x, int y)
{
	int min;
	int max;

	if (x > y)
	{
		max = x;
		min = y;
	}
	else
	{
		max = y;
		min = x;
	}

	return min;
}


int main()
{

	int a, b, v, g, r1, r2, rezultat;

	printf("Unesite prvu celobrojnu vednost: ");
	scanf_s("%d", &a);
	printf("Unesite drugu celobrojnu vrednost: ");
	scanf_s("%d", &b);
	printf("Unesite trecu celobrojnu vrednost: ");
	scanf_s("%d", &v);
	printf("Unesite cetvrtu celobrojnu vrednost: ");
	scanf_s("%d", &g);


	r1 = ceo_br(a, b);

	r2 = ceo_br(v, g);

	rezultat = ceo_br(r1, r2);

	printf("Najmanje uneti ceo broj je %d\n", rezultat);

}