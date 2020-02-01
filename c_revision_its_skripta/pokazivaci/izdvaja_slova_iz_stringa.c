#include<stdio.h>

char* samo_slova(char* p);

int main()
{
	char* S2;
	char S1[] = "ITS, Cara Dusana 34, 11080 Zemun";
	printf("Pocetni sadrzaj niza: ");
	printf("%s\n", S1);

	S2 = samo_slova(S1);
	printf("Niz koji sadrzi samo slova: ");
	printf("%s\n", S2);

	return 0;
}

char* samo_slova(char *s1pok)
{
	static char a[80], *p;
	p = a;

	while (*s1pok)
	{
		if ((*s1pok >= 'a' && *s1pok <= 'z') || (*s1pok >= 'A' && *s1pok <= 'Z'))
		{
			*p = *s1pok;
			p++;
		}
		s1pok++;
	}
	*p = '\0';

	return a;
}