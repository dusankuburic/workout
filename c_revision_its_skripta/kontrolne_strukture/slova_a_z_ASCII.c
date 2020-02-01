#include<stdio.h>

int main()
{
	char ch;

	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("ASCII kod za %c je %d\n", ch, ch);
	}

	return 0;
}