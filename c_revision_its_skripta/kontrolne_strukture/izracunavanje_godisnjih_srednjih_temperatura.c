#include<stdio.h>

int main()
{
	double mesec[12], srednjaTemp = 0;
	int i;

	printf("Unesite srednje temperature za 12 meseci.\n");
	for (i = 0; i < 12; i++)
	{
		printf("srednja temperatura za mesec %d: ", i + 1);
		scanf_s("%lf", &mesec[i]);
		srednjaTemp += mesec[i];
	}

	srednjaTemp /= 12;
	printf("Srednja temperatura za celu godinu iznosi %lf stepeni.\n", srednjaTemp);
}