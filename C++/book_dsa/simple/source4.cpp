#include<iostream>

using namespace std;


void swapWrong(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swapPtr(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapRef(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


int main()
{
	int x = 5;
	int y = 7;

	swapWrong(x, y);
	cout << "x=" << x << " y=" << y << endl;
	swapPtr(&x, &y);
	cout << "x=" << x << " y=" << y << endl;
	swapRef(x, y);
	cout << "x= " << x << " y=" << y << endl;

}