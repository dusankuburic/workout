#include<stdio.h>

double skal_pro(double a[], double b[], int n);


int main()
{

	double x[100], y[100];
	int i, duzina;

	printf("Unesite duzinu vektora: ");
	scanf_s("%d", &duzina);

	printf("Unesite komponente vektora x: ");
	for (i = 0; i < duzina; i++)
		scanf_s("%lf", &x[i]);

	printf("Unesite komponente vektora y: ");
	for (i = 0; i < duzina; i++)
		scanf_s("%lf", &y[i]);

	printf("Skalarni proizvod X*Y je: %f\n", skal_pro(x, y, duzina));

	return 0;

}


double skal_pro(double a[], double b[], int n)
{
	double zbir = 0;
	int i;
	for (i = 0; i < n; i++)
		zbir += a[i] * b[i];

	return zbir;
}