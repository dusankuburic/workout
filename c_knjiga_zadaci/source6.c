#include<stdio.h>


int main()
{

	int n, m, s = 0;

	printf("Unesi n i m: ");
	scanf_s("%d%d", &n, &m);

	if (n > m) {
		printf("n mora biti manje od m");
	}
	else
	{
		while (n <= m)
		{
			if (n % 2 == 0)
				s += n * n;
			else
				s += n * n*n;

			n++;
		}
	}

	printf("Suma je: %d", s);

	return 0;
}