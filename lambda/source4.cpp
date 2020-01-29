#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

	vector<int> vecMultiplicand{ 0,1,2,3,4 };
	vector<int> vecMultiplier{ 100, 101, 102, 103, 104 };
	vector<int> vecResult;


	vecResult.resize(vecMultiplier.size());

	transform(vecMultiplicand.begin(),
		vecMultiplicand.end(),
		vecMultiplier.begin(),
		vecResult.begin(),
		[](int a, int b) {return a * b; });



	cout << "The contents of the first vector are: " << endl;
	for (size_t index = 0; index < vecMultiplicand.size(); ++index)
		cout << vecMultiplicand[index] << ' ';
	cout << endl;


	cout << "The contents of the second vector are: " << endl;
	for (size_t index = 0; index < vecMultiplier.size(); ++index)
		cout << vecMultiplier[index] << ' ';
	cout << endl;


	cout << "The result of the multiplication is: " << endl;
	for (size_t index = 0; index < vecMultiplier.size(); ++index)
		cout << vecResult[index] << ' ';


	return 0;

	
}