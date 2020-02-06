#include<stdio.h>

int main()
{
	float a, b, c, fniz[5] = { 0.01, 0.1, 0.5,1.0, 10.0 };
	float* p_fniz;
	char tekst[] = { "Ovo je znakovni niz\n" };
	char* p_tekst;
	int i;

	p_fniz = fniz;

	a = *p_fniz;

	b = *(p_fniz + 2);

	p_fniz = &fniz[2];

	c = *(p_fniz + 2);

	printf("a=%f\nb=%f\nc=%f\n", a, b, c);

	for (i = 0; tekst[i] != '\0'; i++)
		putchar(tekst[i]);

	for (p_tekst = tekst; *p_tekst != '\0'; p_tekst++)
		putchar(*p_tekst);


	return 0;
}