/*
void* malloc (size_t size);
Allocate memory block
Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.

The content of the newly allocated block of memory is not initialized, remaining with indeterminate values.

If size is zero, the return value depends on the particular library 
implementation (it may or may not be a null pointer), but the returned pointer shall not be dereferenced.
*/

#include<stdio.h>  //printf, scanf, NULL
#include<stdlib.h> // malloc, free, rand

int main()
{
	int i, n;
	char* buffer;

	printf("How long do you want the string?");
	scanf_s("%d", &i);

	buffer = (char*)malloc(i + 1);
	if (buffer == NULL)
		exit(1);

	for (n = 0; n < i; n++)
		buffer[n] = rand() % 26 + 'a';
	buffer[i] = '\0';

	printf("Random string: %s\n", buffer);
	free(buffer);

	return 0;

}