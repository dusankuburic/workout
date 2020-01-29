#include<algorithm>
#include<vector>
#include<iostream>


using namespace std;

template<typename elementType>
bool IsEven(const elementType& number) {

	return ((number % 2) == 0);
}

int main()
{

	vector<int> numsInVec{ 2017, 0,-1,42,10101, 25 };

	size_t numZeros = count(numsInVec.cbegin(), numsInVec.cend(), 0);
	cout << "Number of instances of '0': " << numZeros << endl << endl;

	size_t numEvenNums = count_if(numsInVec.cbegin(), numsInVec.cend(), IsEven<int>);

	cout << "Number of even elements: " << numEvenNums << endl;
	cout << "Number of odd elements: ";
	cout << numsInVec.size() - numEvenNums << endl;

	return 0;
}