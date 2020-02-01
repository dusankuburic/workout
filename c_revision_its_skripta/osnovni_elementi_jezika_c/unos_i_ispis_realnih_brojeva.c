#include<stdio.h>

int main()
{

	float number;

	printf("Unesite realan broj: ");
	scanf_s("%f", &number);


	printf("Uneli ste broj (%%f): %f\n", number);
	printf("Broj zaokruzen na dve decimale je: %.2f\n", number);
}