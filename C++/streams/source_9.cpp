#include<iostream>
#include<string>

using namespace std;


int main() {

	char One[] = "One if by land";

	int fullLength = strlen(One);
	int tooShort = fullLength - 4;
	int tooLong = fullLength + 6;


	cout.write(One, fullLength) << '\n';
	cout.write(One, tooShort) << '\n';
	cout.write(One, tooLong) << '\n';

	return 0;
}