#include<stdio.h>
#include<string.h>

#define DUZINA 80
#define MAX 50
#define STOP ""

void sortiraj(char* st[], int d[], int n);


int main()
{
	char str[MAX][DUZINA];
	char* pokstr[MAX];
	int duz[MAX];
	int i = 0, j;

	printf("Unesite do %d stringova za sortiranje, zatim praznu linuju pa <ENTER> za kraj: \n", MAX);

	while (gets(str[i]) != NULL && strcmp(str[i], STOP) != 0 && i < MAX)
	{
		pokstr[i] = str[i];
		duz[i] = strlen(str[i]);
		i++;
	}

	sortiraj(pokstr, duz, i);

	printf("Sortirani stringovi izgledaju:\n");
	for (j = 0; j < i; j++)
	{
		printf("String[%d]:", j);
		puts(pokstr[j]);
	}

	printf("Duzine sortiranih stringova su:\n");
	for (j = 0; j < i; j++)
	{
		printf("String[%d]:", j);
		printf("%d\n", duz[j]);
	}

	return 0;
}


void sortiraj(char* st[], int d[], int n)
{
	char* pom;
	int i, j, m;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(st[i], st[j]) > 0)
			{
				//zamena mesta
				pom = st[i];
				st[i] = st[j];
				st[j] = pom;

				//zamena duzine
				m = d[i];
				d[i] = d[j];
				d[j] = m;
			}
		}
	}
}