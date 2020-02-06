#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

template<typename numberType>
struct IsMultiple
{
	numberType Divisor;

	IsMultiple(const numberType& divisor) {
		Divisor = divisor;
	}

	bool operator()(const numberType& element) const {
		return ((element % Divisor) == 0);
	}
};



int main() {

	vector<int> numsInVec{ 25,26,27,28,29,30,31 };
	cout << "The vector contains: 25,26,27,28,29,30,31 " << endl;

	cout << "Enter division (> 0):";
	int divisor = 2;
	cin >> divisor;

	auto element = find_if(numsInVec.begin(),
		numsInVec.end(),
		IsMultiple<int>(divisor));

	if (element != numsInVec.end())
	{
		cout << "First element in vector divisible by " << divisor;
	}

	return 0;
}