#include<iostream>

using namespace std;

int main()
{
	int myNumbers[5];

	int* pointToNums = myNumbers;

	cout << "pointToNums = 0x" << hex << pointToNums << endl;

	cout << "&myNumbers[0] = 0x" << hex << &myNumbers[0] << endl;


	return 0;
}