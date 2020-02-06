#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

template<typename elementType>
struct DisplayElementKeepCount
{
	int count;

	DisplayElementKeepCount(): count(0) {}

	void operator()(const elementType& element) {
		++count;
		cout << element << ' ';
	}
};


int main() {

	vector<int> numsInVec{ 22,2017, -1, 999,42, 901 };
	cout << "Displaying the vector of integers: " << endl;

	DisplayElementKeepCount<int> result;
	result = for_each(numsInVec.begin(),
				numsInVec.end(),
				DisplayElementKeepCount<int>());

	cout << endl << "Functor invoked " << result.count << " times";


	return 0;
}