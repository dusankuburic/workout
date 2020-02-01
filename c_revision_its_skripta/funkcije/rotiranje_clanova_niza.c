#include<stdio.h>


void citajNiz(int niz[], int num);
void pisiNiz(int niz[], int num);
void leftOne(int a[], int num);


int main()
{
	int i, mesto, num, niz[50];

	printf("Unesite broj elemnata niza: ");
	scanf_s("%d", &num);

	printf("Unesite elemente niza: \n");
	citajNiz(niz, num);

	printf("Unesite broj mesta pomeranja niza: ");
	scanf_s("%d", &mesto);

	for (i = 0; i < mesto; i++) 
	{
		leftOne(niz, num);
	}
	printf("Rotirani niz za %d mesta izgleda:\n", mesto);
	pisiNiz(niz, num);


	return 0;
}


void leftOne(int a[], int num)
{
	int temp, i;
	temp = a[0];

	for (i = 1; i < num; i++)
	{
		a[i - 1] = a[i];
	}
	a[num - 1] = temp;
}


void citajNiz(int niz[], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("niz[%d]=", i);
		scanf_s("%d", &niz[i]);
	}
}


void pisiNiz(int niz[], int num)
{
	
	for (int i = 0; i < num; i++)
	{
		printf("niz[%d]= %d", i, niz[i]);
		printf("\n");
	}
}