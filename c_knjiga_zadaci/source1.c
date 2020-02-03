#include<stdio.h>


int main()
{

	int k;
	int r = 0;
	int s = 0;
	int t = 0;

	printf("Unesite magicni broj k: ");
	scanf_s("%d", &k);

	switch (k)
	{
	case 0:
		r++;
		break;
	case 1:
		s++;
		break;
	case 2: case 3: case 4:
		t++;
		break;
	default:
		break;
	}


	printf("r = %d\n", r);
	printf("s = %d\n", s);
	printf("t = %d\n", t);

	return 0;
}