#include<iostream>

void xchg(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}


int main()
{
	int i = 20;
	int& iRef = i;
	
	std::cout << "i: " << i << std::endl;
	std::cout << "iRef: " << iRef << std::endl;

	std::cout << std::endl;

	iRef = 30;

	std::cout << "i: " << i << std::endl;
	std::cout << "iRef: " << iRef << std::endl;



	int a = 10;
	int b = 20;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	xchg(a, b);
	std::cout << std::endl;


	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	return 0;

}