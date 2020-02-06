#include<stdio.h>

int main()
{

	int n = 1;
	int i;
	double a, min, max;

	while (n > 0)
	{
		printf("Koliko brojeva zalite da unesete? n= ");
		scanf("%d", &n);

		printf("Unesite prvi realan broj:\t ");
		scanf("%lf", &a);
		min = max = a;

		for (i = 2; i <= n; i++)
		{
			printf("Unesite sledeci realan broj:\t");
			scanf("%lf", &a);
			if (a < min) min = a;
			if (a > max) max = a;
		}
		
		printf("Minimum = %f\n", min);
		printf("Maximum = %f\n", max);
		printf("Da li zelite novi unos?\n");
		printf("(unesite 0 za kraj ili pozitivan broj za nastavak)\n");
		scanf("%d", &n);
	}

	return 0;
}