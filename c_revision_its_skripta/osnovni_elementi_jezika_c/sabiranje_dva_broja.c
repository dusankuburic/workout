#include<stdio.h>


int main()
{
	int num1, num2, sum;

	printf("Sabiranje dva broja\n");
	printf("Unesite prvi broj:\n");
	scanf_s("%d", &num1);

	printf("Unesite drugi broj:\n");
	scanf_s("%d", &num2);

	sum = num1 + num2;

	printf("Zbir dava broja je: %d\n", sum);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);

	return 0;
}