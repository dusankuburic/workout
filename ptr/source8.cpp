#include<iostream>
#include<string>

using namespace std;

int main()
{

	cout << "How many integers shall I reserve memory for?" << endl;
	int numEntries = 0;
	cin >> numEntries;


	int* myNumbers = new int[numEntries];

	cout << "Memmory allocated at: 0x" << myNumbers << hex << endl;

	delete[] myNumbers;

	return 0;
}