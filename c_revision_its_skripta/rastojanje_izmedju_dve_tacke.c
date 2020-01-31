#include<stdio.h>
#include<math.h>

int main()
{
	double x1, x2, y1, y2, z1, z2, d;

	printf("Unesite koordinate prve tacke <x1,y1,z1>:\n");
	scanf_s("%lf%lf%lf", &x1, &y1, &z1);

	printf("Unesite koordinate druge tacke <x2,y2,z2>:\n");
	scanf_s("%lf%lf%lf", &x2, &y2, &z2);

	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

	printf("d = %.2f\n", d);

	return 0;
}