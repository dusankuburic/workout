#include<stdio.h>
#include<math.h>

double Povrsina(double a, double b, double c);
void Ispis(double p);

int main()
{
	double a, b, c, p;

	printf("Unesite stranice trougla [a,b,c]: \n");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	p = Povrsina(a, b, c);
	Ispis(p);
}


double Povrsina(double a, double b, double c)
{
	double s, pov;

	s = (a + b + c) / 2;
	pov = sqrt(s*(s - a) * (s - b)*(s - c));
	return pov;
}

void Ispis(double p)
{
	printf("\nPovrsina trougla je %.3f\n\n", p);
}
