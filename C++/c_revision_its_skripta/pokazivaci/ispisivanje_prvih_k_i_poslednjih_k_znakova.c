#include<stdio.h>
#include<string.h>

void levi(char *s, int k);
void desni(char *s, unsigned int k);

int main()
{
	char* izraz = "ITS-Visoka Skola Strukovnih Studija";
	printf("Dati string je %s\n", izraz);
	printf("Prvih 10 znakova datoh stringa je: ");
	levi(izraz, 10);
	printf("Poslednjih 7 znakova datog stringa je: ");
	desni(izraz, 7);
	return 0;
}


void levi(char* s, int k)
{
	while (k && *s)
	{
		putchar(*s);
		s++;
		k--;
	}
	putchar('\n');
}


void desni(char*s, unsigned int k)
{
	//radi provere duzia k < s
	if (strlen(s) >= k)
		puts(s + strlen(s) - k);
	else
		puts(s);
}