#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> numsInVec{ 25,26,27,29,30,31 };
	cout << "The vector contains: { 25,26,27,29,30,31 }";

	cout << endl << "Enter divisor (> 0): ";
	int divisor = 2;
	cin >> divisor;


	vector<int>::iterator element;
	element = find_if(numsInVec.begin(),
		numsInVec.end(),
		[divisor](int dividend) {return (dividend % divisor) == 0; });

	
	if (element != numsInVec.end()) {
		cout << "First element in vector divisible by " << divisor;
		cout << ": " << *element << endl;
	}

	return 0;
}