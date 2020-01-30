#include<iostream>

using namespace std;

template<typename T1=int, typename T2=double>
class HoldPair
{
private:
	T1 value1;
	T2 value2;
public:
	HoldPair(const T1& val1, const T2& val2)
		:value1(val1), value2(val2){}

	const T1& GetFirstValue() const
	{
		return value1;
	}

	const T2& GetSecondValue() const
	{
		return value2;
	}
};


int main()
{
	HoldPair<> pairIntDbl(300, 10.09);
	HoldPair<short, const char*> pairShortStr(25, "Learn templates, love C++");

	cout << "The first object contains-" << endl;
	cout << "Value 1: " << pairIntDbl.GetFirstValue() << endl;
	cout << "Value 2: " << pairIntDbl.GetSecondValue() << endl;

	cout << "The second object contains -" << endl;
	cout << "Value 1: " << pairShortStr.GetFirstValue() << endl;
	cout << "Value 2: " << pairShortStr.GetSecondValue() << endl;

	return 0;
}