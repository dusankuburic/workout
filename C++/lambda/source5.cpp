#include<algorithm>
#include<string>
#include<vector>
#include<iostream>


using namespace std;

template<typename T>
void DisplayContents(const T& input) {

	for (auto element = input.cbegin();
		element != input.cend();
		++element) {
		cout << *element << endl;
	}
}

int main()
{
	vector<string> namesInVec{ "jim","Jack","Sam","Anna" };

	cout << "The names in vector in order of inertion: " << endl;
	DisplayContents(namesInVec);

	cout << "Order oafter case sensitive sort: " << endl;
	sort(namesInVec.begin(), namesInVec.end());
	DisplayContents(namesInVec);


	cout << "Order after sort ignoring case: " << endl;
	sort(namesInVec.begin(), 
		namesInVec.end(),
		[](const string& str1, const string& str2)->bool {
		
		string str1LC;
		str1LC.resize(str1.size());

		transform(str1.begin(), str1.end(), str1LC.begin(), ::tolower);

		string str2LC;
		str2LC.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LC.begin(), ::tolower);

		return (str1LC < str2LC);

	});

	DisplayContents(namesInVec);

	return 0;
}