#include<iostream>
#include<string>

using namespace std;

#define ARRAY_LENGTH 25
#define PI 3.1416
#define MY_DOUBLE double
#define FAV_WHISKY "Jack Daniels"

int main()
{
	int numbers[ARRAY_LENGTH] = { 0 };
	cout << "Array's length:" << sizeof(numbers) / sizeof(int) << endl;

	cout << "Enter a radius: ";
	MY_DOUBLE radius = 0;
	cin >> radius;
	cout << " Area is: " << PI * radius * radius << endl;

	string favouriteWhisky(FAV_WHISKY);

	cout << "My favourite drink is: " << FAV_WHISKY << endl;
}