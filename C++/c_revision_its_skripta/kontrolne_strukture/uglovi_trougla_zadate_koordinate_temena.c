#include<stdio.h>
#include<math.h>
#define PI 3.141592

int main()
{
	double xa, ya;
	double xb, yb;
	double xc, yc;

	double a, b, c, alfa, beta, gama;
	int izraz = 0;
	printf("Unesite koordinate tacke A(x,y): ");
	scanf_s("%lf%lf", &xa, &ya);
	printf("Unesite koordinate takce B(x,y): ");
	scanf_s("%lf%lf", &xb, &yb);
	printf("Unesite koordinate takce C(x,y): ");
	scanf_s("%lf%lf", &xc, &yc);

	a = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
	b = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
	c = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));

	printf("Stranica a je: %f\n", a);
	printf("Stranica b je: %f\n", b);
	printf("Stranica c je: %f\n", c);


	izraz = (a >= (b + c) || (b >= (a + c)) || (c >= (a + b)));
	
	if (izraz == 0)
	{
		alfa = acos((b*b + c * c + a * a) / (2 * b*c));
		beta = acos((c*c + a * a - b * b) / (2 * c*a));
		gama = acos((a*a + b * b - c * c) / (2 * a*b));
		alfa *= 180 / PI;
		beta *= 180 / PI;
		gama *= 180 / PI;
		printf("Alfa = %.2f\nBeta = %.2f\nGama = %.2f\n", alfa, beta, gama);
	}
	else
	{
		printf("Ne moze se kreirati trougao\n");
	}

	return 0;
}