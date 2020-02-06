#include<stdio.h>

int main()
{

	int i, j, n, m, red, zbir = 0;

	int A[20][20];

	printf("Unesi broj kolona matrice A: ");
	scanf_s("%d", &n);
	printf("Unesi broj vrsta matrice A: ");
	scanf_s("%d", &m);

	printf("Unos elemenata matrice A:\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}

	printf("Unesi broj reda matrice A ciji zbir zelis: ");
	scanf_s("%d", &red);
	for (j = 0; j < n; j++)
	{
		zbir = zbir + A[red][j];
	}
	printf("Trazeni zbir reda je: %d\n", zbir);

	return 0;
}