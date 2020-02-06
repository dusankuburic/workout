#include<iostream>

using namespace std;


int main()
{
	int dogsAge = 30;
	cout << "Initialized dogsAge = " << dogsAge << endl;

	int* pointsToAnAge = &dogsAge;
	cout << "pointsToAge points to dogsAge" << endl;
	
	cout << "Enter an age for your dog: ";
	cin >> *pointsToAnAge;

	cout << "Input stored at 0x" << hex << pointsToAnAge << endl;

	cout << "Integer dogsAge = " << dec << dogsAge << endl;

	return 0;
}