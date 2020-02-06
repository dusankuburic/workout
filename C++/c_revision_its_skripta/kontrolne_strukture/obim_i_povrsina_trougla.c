#include<stdio.h>
#include<math.h>

int main()
{
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;

	double a, b, c, o, s, p;

	printf("Unesite koordinate prve tacke <x1,y1,z1>: \n");
	scanf_s("%lf%lf%lf", &x1, &y1, &z1);

	printf("\nUnesite koordinate druge tacke <x2,y2,z2>: \n");
	scanf_s("%lf%lf%lf", &x2, &y2, &z2);

	printf("\nUnesite koordinate trece tacke <x3,y3,z3>: \n");
	scanf_s("%lf%lf%lf", &x3, &y3, &z3);


	//izracunavnje stranice a
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
	//izracunavanje stranice b
	b = sqrt(pow(x1 - x3, 2) + pow(y1-y3,2) + pow(z1 - z3,2));
	//izracunavanje stranice c
	c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2) + pow(z2-z3,2));
	//ispis rastojanja izmedju tacaka
	printf("\nRastojanja izmedju tacaka:\na = %.2f, b = %.2f i c = %.2f\n\n", a, b, c);


	if (a + b == c || a + c == b || b + c == a)
	{
		printf("Unete dacke su kolinearne i ne mo gu da formiranju trougao!\n\n");
	}
	else
	{
		//izracunavanje obima trougla
		o = a + b + c;
		//izracunavanje poluobima trougla
		s = o / 2;
		//izracunavanje povrsine trougla
		p = sqrt(s* (s - a) * (s - b) * (s - c));
		printf("Obim trougla je %.2f\n\n", o);

		printf("Povrsina trougla je %.2f\n\n", p);
	}


	return 0;
}