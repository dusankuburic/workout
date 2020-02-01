#include<stdio.h>

void Fib(int n);

int main()
{
	int x;
	printf("Unesite broj do kojeg zelite Fibonacijev niz: ");
	scanf_s("%d", &x);

	Fib(x);
}


void Fib(int n)
{
	int i, score;
	int last = 1;
	int nextToLast = 0;
	
	if (n <= 0)
	{
		printf("Morate uneti broj veci od 0\n");
		return;
	}

	printf("F[0] je: 0\n");
	printf("F[1] je: 1\n");

	for (i = 2; i < n; i++)
	{
		score = last + nextToLast;
		nextToLast = last;
		last = score;
		printf("F[%d] je : %d\n", i, last);
	}
}