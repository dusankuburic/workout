// Parses the C-string str interpreting its content as an integral number, which is returned as a value of type long int.
#include<stdio.h> //printf, fgets
#include<stdlib.h> //atol


int main()
{
	long int li;
	char buffer[256];
	printf("Enter a long number: ");
	fgets(buffer, 256, stdin);
	li = atol(buffer);
	printf("The value entered is %dl. Its double is %dl\n", li, li * 2);

	return 0;
}