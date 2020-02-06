#include<stdio.h>

int main()
{
	char s[] = "abcde";
	int t[] = { 1,2,3,4,5 };

	char *ps = s;
	int *pt = t;


	printf("ps = %p\n", ps);
	printf("ps+1 = %p\n", ps + 1);
	printf("ps+2 = %p\n", ps + 2);
	printf("ps-1 = %p\n", ps - 1);
	printf("ps-2 = %p\n", ps - 2);
	printf("-------------------\n");


	printf("pt = %p\n", pt);
	printf("pt+1 = %p\n", pt + 1);
	printf("pt+2 = %p\n", pt + 2);
	printf("pt-1 = %p\n", pt - 1);
	printf("pt-2 = %p\n", pt - 2);
	printf("-------------------\n");

	for (ps = s; *ps; ps++)
		putchar(*ps);
	printf("\n-------------------\n");
	

	ps = &s[3];
	printf("s = %p\n", s);
	printf("ps = %p\n", ps);
	printf("ps - s = %d\n", ps - s);
	pt = &t[3];
	printf("t = %p\n", t);
	printf("pt = %p\n", pt);
	printf("pt - t = %d\n", pt - t);


	return 0;

}