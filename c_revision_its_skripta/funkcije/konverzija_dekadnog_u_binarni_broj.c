#include<stdio.h>

void decBin(int dec);


int main()
{
	int number;
	printf("Unesite broj za konverziju: ");
	scanf_s("%d", &number);
	decBin(number);

	return 0;
}


void decBin(int dec)
{
	int offset = 0;

	int binaryValue[40];

	while (dec != 0)
	{
		binaryValue[offset] = dec % 2;
		dec /= 2;
		offset++;
	}
	offset--;
	for (; offset >= 0; offset--)
		printf("%1d", binaryValue[offset]);
	printf('\n');

}