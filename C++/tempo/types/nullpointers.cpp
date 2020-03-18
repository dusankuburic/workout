#include<iostream>
#include<string>




std::string overloadTest(char*) {
	return "char*";
}

std::string overloadTest(long int) {
	return "long int";
}


int main()
{
	std::cout << std::endl;

	long int* pi = nullptr;
	auto nullp = nullptr;

	bool b(nullptr);
	std::cout << std::boolalpha << "b: " << b << std::endl;
	auto val = 5;
	if (nullptr < &val)
	{
		std::cout << "nullptr < &val" << std::endl;
	}


	std::cout << "overloadTest(nullptr)= " << overloadTest(nullptr) << std::endl;

	std::cout << std::endl;
}