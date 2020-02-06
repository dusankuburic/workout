#include<iostream>

using namespace std;

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);
enum BOOL {FALSE, TRUE};



int main() {

	int valOne = 1, valTwo = 2;
	int choice;
	const int MaxArray = 5;
	void(*pFuncArray[MaxArray])(int&, int&);

	for (int i = 0; i < MaxArray; i++) {

		cout << "(1)Change Values (2)Square (3)Cube (4)Swap: ";
		cin >> choice;
		switch (choice)
		{
		case 1: pFuncArray[i] = GetVals; break;
		case 2: pFuncArray[i] = Square; break;
		case 3: pFuncArray[i] = Cube; break;
		case 4: pFuncArray[i] = Swap; break;
		default:
			pFuncArray[i] = 0;
			break;
		}
	}


	for (int i = 0; i < MaxArray; i++) {
		pFuncArray[i](valOne, valTwo);
		PrintVals(valOne, valTwo);
	}

	return 0;
}



void PrintVals(int x, int y) {

	cout << "x: " << x << "y: " << y << endl;
}

void Square(int& rX, int& rY) {
	rX *= rX;
	rY *= rY;
}

void Cube(int& rX, int& rY) {
	int tmp;

	tmp = rX;
	rX *= rX;
	rX = rX * tmp;

	tmp = rY;
	rY *= rY;
	rY = rY * tmp;
}

void Swap(int& rX, int& rY) {
	int temp;
	temp = rX;
	rX = rY;
	rY = temp;
}

void GetVals(int& rValOne, int& rValTwo) {
	cout << "New value for ValOne: ";
	cin >> rValOne;
	cout << "New value for ValTwo: ";
	cin >> rValTwo;
}

