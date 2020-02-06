#include<stdio.h>

int main()
{

	int a[100], i, k, n;
	double s;

	while (1)
	{
		printf("Unesite broj elemnata niza: ");
		scanf_s("%d", &n);


		if (n < 0 || n > 100) break;

		for (i = 0; i < n; i++)
		{
			printf("a[%d]: ", i);
			scanf_s("%d", &a[i]);
		}

		for (s = i = k = 0; i < n; i++)
		{
			if (a[i] % 3 == 0)
			{
				s += a[i];
				k++;
			}

		}



		if (k) {
			s /= k;
		}
		printf("s= %.2f\n", s);
	}

	return 0;
}