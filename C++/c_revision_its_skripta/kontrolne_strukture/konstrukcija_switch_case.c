#include<stdio.h>

int main()
{

	int broj;
	printf("Unesite broj 1,2,3,4 ili 5 ->");

	scanf_s("%d", &broj);

	switch (broj)
	{
	case 1:
		printf("\nUneli ste broj jedan.\n");
		break;
	case 2:
		printf("\nUneli ste broj dva.\n");
		break;
	case 3:
		printf("\nUneli ste broj tri.\n");
		break;
	case 4:
		printf("\nUneli ste broj cetiri.\n");
		break;
	case 5:
		printf("\nUneli ste broj pet.\n");
		break;
	default:
		printf("\nNiste uneli trazeni broj.\n");
		break;
	}

	
	return 0;
}