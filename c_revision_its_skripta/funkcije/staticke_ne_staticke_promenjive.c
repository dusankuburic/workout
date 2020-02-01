#include<stdio.h>

int a = 0;

void increase()
{
	a++;
	printf("increase::a=%d\n", a);
}

void decrease()
{
	int a = 0;
	a--;
	printf("decrease::a=%d\n", a);
}


void nestaticna()
{
	int s = 0;
	s++;
	printf("nestaticna::s=%d\n", s);
}

void staticna()
{
	static s = 0;
	s++;
	printf("staticna::s=%d\n", s);
}


int main()
{
	int i, x = 3;
	printf("main::x=%d\n", x);
	for (i = 0; i < 3; i++)
	{
		int x = 5;
		printf("for::x=%d\n", x);
	}


	printf("main::x=%d\n", x);

	increase();
	decrease();

	printf("main::a=%d\n", a);

	for (i = 0; i < 3; i++)
		nestaticna();

	for (i = 0; i < 3; i++)
		staticna();

	return 0;
}