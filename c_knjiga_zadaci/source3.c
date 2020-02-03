#include<stdio.h>


int main()
{
	char operator;
	
	float num1 = 0, num2 = 0;

	printf("Unesite prvi broj: ");
	scanf_s("%f", &num1);

	printf("Unesite drugi broj: ");
	scanf_s("%f", &num2);

	printf("Unesite znak za zeljenu operaciju (+-*/): ");
	getchar();
	scanf_s("%c", &operator);

	switch (operator)
	{
	case '+':
		printf("%f + %f = %.2f", num1, num2, num1 + num2);
		break;
	case '-':
		printf("%f - %f = %.2f", num1, num2, num1 - num2);
		break;
	case '*':
		printf("%f * %f = %.2f", num1, num2, num1*num2);
		break;
	case '/':
		printf("%f / %f = %.2f", num1, num2, num1 / num2);
		break;
	default:
		break;
	}

	return 0;
}