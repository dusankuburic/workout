
//povrsina i zapremina pravilne trostrane i cetvorostrane piramide

#include<stdio.h>
#include<math.h>

#define K3 1.73

int main()
{
	double a, H, B, h, M, P, V;
	int unos;
	int izraz = 0;

	printf("########################################\n");
	printf("## Program za izracunavanje povrsine i zapremine piramide ##\n");
	printf("########################################\n");

	printf("1. Cetvorostrana pravilna piramida\n");
	printf("2. Trostrana pravilna piramida\n");
	printf("\nIzaberite vrstu piramide(1-2): ");
	scanf_s("%d", &unos);

	switch (unos)
	{
		//cetvorostrana pravilna piramida sa bazom kvadrata
	case 1:
		printf("------------------------------------\n");
		printf("|  Cetvorostrana pravilna piramida |\n");
		printf("------------------------------------\n");
		printf("Unesite duzinu osnovne ivice (a): ");
		scanf_s("%lf", &a);
		printf("Unesite duzinu visine piramide (H): ");
		scanf_s("%lf", &H);

		izraz = (a <= 0) || (H <= 0);
		if (izraz == 0)
		{
			//racunanje povrsine baze cetvorostrane piramide
			B = a * a;
			// racunanje duzine visine bocne strane
			h = sqrt(pow(H, 2) + pow(a / 2, 2));
			//racunanje povrsine omotaca cetvorostrane piramide
			M = 2 * a*h;
			//racunanje povrsine cetvorostrane piramide
			P = B + M;
			//racunanje zapremine cevorostrane piramide
			V = (B*H) / 3;

			printf("\nDuzina visine bocne strane(h) je: %.2f cm\n", h);
			printf("Povrsina omotaca (M) je: %.2f cm2\n", M);
			printf("\nPovrsina baze (B) je: %.2f cm2\n", B);
			printf("\nPovrsina piramide (P) je: %.2f cm2\n", P);
			printf("Zapremina piramide (V) je: %.2f cm3\n", V);

		}
		else
		{
			printf("\nDuzina osnove ivice ili vise ne moze biti manja ili jednaka nuli.\n");
		}
		break;
	case 2:
		printf("------------------------------------\n");
		printf("|  Trostrana pravilna piramida |\n");
		printf("------------------------------------\n");
		printf("Unesite duzinu osnovne ivice (a): ");
		scanf_s("%lf", &a);
		printf("Unesite duzinu visine piramide (H): ");
		scanf_s("%lf", &H);
		
		izraz = (a <= 0) || (H <= 0);

		if (izraz == 0)
		{
			//racunanje povrsine baze trostrane pravilne piramide
			B = ((a*a) *K3) / 4;
			//racunanje omotaca trostrane pravilne piramide
			h = sqrt(pow(H, 2) + pow((a*K3) / 6, 2));
			//racunanje omotaca trostrane pravilne piramide
			M = 3 * ((a*h) / 2);
			//racunanje povrsine trostrane pravilne piramide
			P = B + M;
			// racunanje zapremine trostrane pravilne piramide
			V = (B * H) / 3;

			printf("\nDuzina visine bocne strane(h) je: %.2f cm\n", h);
			printf("Povrsina omotaca (M) je: %.2f cm2\n", M);
			printf("\nPovrsina baze (B) je: %.2f cm2\n", B);
			printf("\nPovrsina piramide (P) je: %.2f cm2\n", P);
			printf("Zapremina piramide (V) je: %.2f cm3\n", V);

		}
		else
		{
			printf("\nDuzine osnovne ivice ili visine ne moze biti manja ili jednaka nuli.\n");
		}
		break;

	default:
		printf("Greska!\nNe mozete uneti brojeve manje od 1 ili vece od 2.\n");
		break;
	}
}
