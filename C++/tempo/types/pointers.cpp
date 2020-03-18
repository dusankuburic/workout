#include<iostream>





int main(){

	int i = 20;
	int* iptr = &i;
	std::cout << iptr << std::endl;
	std::cout << *iptr << std::endl;
	i = 30;
	std::cout << *iptr << std::endl;
	*iptr = 50;
	std::cout << *iptr << std::endl;

	std::cout << std::endl;


	int intArray[] = { 15,30,45,60 };
	std::cout << intArray[2] << std::endl;
	std::cout << *(intArray + 2) << std::endl;


	std::cout << std::endl;


	float* fltPtr = new float(50.505);
	std::cout << *fltPtr << std::endl;

	int* intArray1 = new int[10];
	intArray1[0] = 20;
	std::cout << intArray1[0] << std::endl;

}