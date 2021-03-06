/*
Allocate and zero-initialize array
Allocates a block of memory for an array of num elements, each of them size bytes long, and initializes all its bits to zero.

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{

	int i, n;
	int* pData;
	
	printf("Amount of numbers to be entered: ");
	scanf_s("%d", &i);
	pData = (int*)calloc(i, sizeof(int));

	if (pData == NULL)
		exit(1);

	for (n = 0; n < i; n++)
	{
		printf("Enter number #%d: ", n + 1);
		scanf_s("%d", &pData[n]);
	}

	printf("You have entered: ");
	for (n = 0; n < i; n++)
		printf("%d ", pData[n]);

	free(pData);

	return 0;
}