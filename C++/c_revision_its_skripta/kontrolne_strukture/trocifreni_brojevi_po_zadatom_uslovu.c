#include<stdio.h>
#include<math.h>

#define KUB 3

/*
123 = 1^3 + 2^3 + 3^3

abc = a^3 + b^3 + c^3
*/


int main()
{
	int a, b, c, m;
	double k;
	
	printf("Trocifreni brojevi koji su jednaki zbiru kubova svojih cifara su: \n");

	for (m = 100; m < 999; m++)
	{
		a = m / 100;
		b = m % 100 / 10;
		c = m % 10;
		k = pow(a, KUB) + pow(b, KUB) + pow(c, KUB);
		
		if (m == k)
			printf("%d ", m);
	}
	printf("\n");


	return 0;
}