#include<iostream>

using namespace std;


int main()
{
	bool* isSunny = NULL;

	cout << "Is it sunny (y/n)?";
	char userInput = 'y';
	cin >> userInput;

	if (userInput == 'y')
	{
		isSunny = new bool;
		*isSunny = true;
	}

	cout << "Boolean flag sunny says: " << *isSunny << endl;

	delete isSunny;

	return 0;
}