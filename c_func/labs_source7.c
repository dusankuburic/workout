/*
long int labs (long int n);
Absolute value
Returns the absolute value of parameter n ( /n/ ).

This is the long int version of abs.

*/


#include<stdio.h>  //printf
#include<stdlib.h> //labs


int main()
{
	long int n, m;
	n = labs(65537L);
	m = labs(-100000L);
	printf("n=%ld\n", n);
	printf("m=%ld\n", m);

	return 0;
}