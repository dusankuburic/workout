#include<stdio.h>

int main() {

	printf("%s", "hello world\n");

	const char* phrase = "Hello again!\n";
	printf("%s", phrase);

	int x = 5;
	printf("%d\n", x);

	const char* phraseTwo = "Here's some values:";
	const char* phraseThree = " and also these: ";
	int y = 7, z = 35;
	long longVar = 98456;
	float floatVar = 8.8;


	printf("%s%d%d%s%ld%f\n", phraseTwo,y,z,phraseThree,longVar,floatVar);

	
	const char* phraseFour = "Formatted: ";
	printf("%s%5d%10d%10.5f\n", phraseFour, y, z, floatVar);




	return 0;
}