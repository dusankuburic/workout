//Parses the C string str, interpreting its content as a floating point number and returns its value as a double.

#include<stdio.h>  //printf, fgets
#include<stdlib.h> //atof
#include<math.h> //sin


int main()
{
	double n, m;
	double pi = 3.14159265355;
	char buffer[256];

	printf("Enter degrees: ");
	fgets(buffer, 256, stdin);

	n = atof(buffer);
	m = sin(n*pi / 180);
	printf("The sine of %f degrees in %f\n", n, m);

	return 0;
}