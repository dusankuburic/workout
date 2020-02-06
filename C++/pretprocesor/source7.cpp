#include<iostream>
#define DEBUG

using namespace std;

#ifndef DEBUG
#define PRINT(x)
#else
#define PRINT(x) \
	cout << #x << ":\t" << x << endl;
#endif

enum BOOL {FALSE, TRUE};

int main()
{
	int x = 5;
	long y = 738981;
	PRINT(x);
	for (int i = 0; i < x; i++)
	{
		PRINT(i);
	}

	PRINT(y);
	PRINT("Hi.");
	int* px = &x;
	PRINT(px);
	PRINT(&px);

	return 0;
}