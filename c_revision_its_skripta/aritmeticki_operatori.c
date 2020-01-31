#include<stdio.h>

int main()
{
	int num1, num2;

	printf("Unesite prvi broj: ");
	scanf_s("%d", &num1);

	printf("Unesite drugi broj: ");
	scanf_s("%d", &num2);

	printf("Zbir %d + %d = %d\n", num1, num2, num1 + num2);
	printf("Razlika %d - %d = %d\n", num1, num2, num1 - num2);
	printf("Proizvod %d * %d = %d\n", num1, num2, num1*num2);
	printf("Celobrojni kolicnik %d/%d = %d\n", num1, num2, num1 / num2);

	printf("Pogresan pokusaj racunanja realnog kolicnika %d/%d je : %f\n", num1, num2, num1 / num2);
	printf("Realni kolicnik %d/%d = %f\n", num1, num2, (float)num1 / (float)num2);
	printf("Ostatak pri deljenju %d/%d je %d\n", num1, num2, num1%num2);


	return 0;
}