#include<iostream>

using namespace std;

int main()
{
	int age = 30;
	int dogsAge = 9;

	
	cout << "Integer age = " << age << endl;
	cout << "Integer dogAge = " << dogsAge << endl;


	int* pointsToInt = &age;
	cout << "pointsToInt points to age" << endl;

	cout << "pointsToInt = 0x" << hex << pointsToInt << endl;

	cout << "*pointsToInt = " << dec << *pointsToInt << endl;

	pointsToInt = &dogsAge;
	cout << "pointsToInt points to dogsAge now" << endl;

	cout << "pointsToInt = 0x" << hex << pointsToInt << endl;
	cout << "*pointsToInt = " << dec << *pointsToInt << endl;

	return 0;
}