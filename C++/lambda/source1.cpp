#include<algorithm>
#include<iostream>
#include<vector>
#include<list>


using namespace std;

int main() {

	vector<int> numsInVec{ 101, -4, 500, 21, 42, -1 };

	list<char> charsInList{ 'a','h','z','k','l' };
	cout << "Display elements in vector using a lambda: " << endl;

	for_each(numsInVec.cbegin(),
		numsInVec.cend(),
		[](const int& element) {cout << element << ' '; });

	cout << endl;
	cout << "Display elements in a list using a lambda: " << endl;

	for_each(charsInList.cbegin(),
		charsInList.cend(),
		[](auto& element) {cout << element << ' '; });


	return 0;
}