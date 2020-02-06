#include<stdio.h>

#define PI 3.14;

void Lopta(double r);


int main()
{

	double r;
	printf("Unesite polprecnik lopte: ");
	scanf_s("%lf", &r);

	Lopta(r);

	return 0;
}

void Lopta(double r)
{
	double p, v;
	p = 4 * r*r*PI;
	v = (4. / 3.) * r *r*r*PI;

	printf("\nLopta poluprecnika %.2f metara \n ima povrsinu %.2f\n i zapreminu %.2f!\n\n",r,p,v);

}