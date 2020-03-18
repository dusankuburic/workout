#include<iostream>
#include<string>


struct T1 {};

struct T2 {
	int mem = 0;
public:
	T2(){}
};

int n;


int main()
{
	std::cout << std::endl;

	using namespace std::string_literals;

	auto n = 0;
	auto s = ""s;
	auto t1 = T1();
	auto t2 = T2();


	std::cout << "::n " << ::n << std::endl;
	std::cout << "n: " << n << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << "T2().mem: " << T2().mem << std::endl;
}