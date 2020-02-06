/*

void* realloc (void* ptr, size_t size);
Reallocate memory block
Changes the size of the memory block pointed to by ptr.

The function may move the memory block to a new location (whose address is returned by the function).

The content of the memory block is preserved up to the lesser of the new and old sizes, 
even if the block is moved to a new location. If the new size is larger, the value of the newly allocated portion is indeterminate.

In case that ptr is a null pointer, the function behaves like malloc, 
assigning a new block of size bytes and returning a pointer to its beginning.

*/


#include<stdio.h>
#include<stdlib.h>



int main()
{
	int input, n;
	int count = 0;
	int* numbers = NULL;
	int* more_numbers = NULL;


	do {
		printf("Enter an integer value (0 to end): ");
		scanf_s("%d", &input);
		count++;

		more_numbers = (int*)realloc(numbers, count * sizeof(int));
		if (more_numbers != NULL)
		{
			numbers = more_numbers;
			numbers[count - 1] = input;
		}
		else
		{
			free(numbers);
			puts("Error (re)allocating memory");
			exit(1);
		}

	} while (input != 0);

	printf("Numbers entered: ");
	for (n = 0; n < count; n++)
		printf("%d ", numbers[n]);


	free(numbers);

	return 0;
}