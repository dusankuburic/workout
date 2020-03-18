#include<iostream>

void addOne(int& x)
{
	x += 1;
}

struct X {
	int data;
};



int main()
{

	std::cout << std::endl;

	int i{ 2011 };
	int* iptr = &i;

	std::cout << i << std::endl;

	std::cout << "iptr: " << iptr << std::endl;
	std::cout << "*iptr: " << *iptr << std::endl;

	std::cout << std::endl;

	int* jptr = iptr;
	*jptr = 2014;

	std::cout << "iptr: " << iptr << std::endl;
	std::cout << "*iptr: " << *iptr << std::endl;

	std::cout << "jptr: " << jptr << std::endl;
	std::cout << "*jptr: " << *jptr << std::endl;

	
	std::cout << std::endl;


	int intArray[] = { 1,2,3,4,5 };
	if (intArray[3] == *(intArray + 3)) {
		std::cout << "Pinter arithmetic works" << std::endl;
	}


	std::cout << std::endl;


	int* pi = nullptr;
	std::cout << pi << std::endl;

	bool b{ nullptr };
	std::cout << b << std::endl;


	//pointer to function

	void(*inc1)(int&) = addOne;
	auto inc2 = addOne;

	int a{ 10 };

	addOne(a);
	std::cout << "after addOne(a): " << a << std::endl;
	inc1(a);
	std::cout << "after inc1(a): " << a << std::endl;
	inc2(a);
	std::cout << "after inc2(a): " << a << std::endl;


	std::cout << std::endl;


	//pointer to meber

	std::cout << std::endl;

	int X::*p = &X::data;
	X object;
	
	object.data = 2011;
	X* objptr = new X;
	objptr->data = 2014;

	int k = object.*p;
	int l = objptr->*p;

	std::cout << "k: " << k << std::endl;
	std::cout << "l: " << l << std::endl;

	std::cout << std::endl;
}