#include<iostream>

using namespace std;

int main()
{

	cout << "How many integers you wish to enter?";
	int numEntries = 0;
	cin >> numEntries;

	int* pointsToInts = new int[numEntries];

	cout << "Allocated for " << numEntries << " integers" << endl;
	for (int counter = 0; counter < numEntries; ++counter)
	{
		cout << "Enter number " << counter << ": ";
		cin >> *(pointsToInts + counter);
	}

	cout << "Diplaying all numbers entered: " << endl;
	for (int counter = 0; counter < numEntries; ++counter)
	{
		cout << *(pointsToInts++) << " ";
	}

	cout << endl;

	pointsToInts -= numEntries;

	delete[] pointsToInts;
	
	return 0;
}