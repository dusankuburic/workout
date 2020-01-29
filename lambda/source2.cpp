#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main() {

	vector<int> numsInVec{ 25,101, 2017,-50 };

	auto evenNum = find_if(numsInVec.cbegin(),
		numsInVec.cend(),
		[](const int& num) {return ((num % 2) == 0); });


	if (evenNum != numsInVec.cend()) {
		cout << "Even numer in collection is: " << *evenNum << endl;
	}

	return 0;
}