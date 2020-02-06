#include<map>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContets(const T& cont) 
{
	for (auto element = cont.cbegin();
		element != cont.cend();
		++element) {
		cout << element->first << " -> " << element->second << endl;
	}
	cout << endl;
}

struct PredIgnoreCase 
{
	bool operator()(const string& str1, const string& str2) const {

		string str1NoCase(str1), str2NoCase(str2);
		transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);

		return (str1NoCase < str2NoCase);
	}
};


typedef map<string, string> DIR_WITH_CASE;
typedef map<string, string, PredIgnoreCase> DIR_NOCASE;


int main()
{
	DIR_WITH_CASE dirWithCase;

	dirWithCase.insert(make_pair("John", "2342342"));
	dirWithCase.insert(make_pair("JOHN", "2423233"));
	dirWithCase.insert(make_pair("Sara", "52342342"));
	dirWithCase.insert(make_pair("Jack", "52342342"));


	cout << "Displaying contents of the case-sensitive map: " << endl;
	DisplayContets(dirWithCase);


	DIR_NOCASE dirNoCase(dirWithCase.begin(), dirWithCase.end());

	cout << "Displaying contents of the case-insesitive map:" << endl;
	DisplayContets(dirNoCase);

	cout << "Please enter a name to search" << endl << "> ";
	string name;
	cin >> name;

	auto pairWithCase = dirWithCase.find(name);
	if (pairWithCase != dirWithCase.end())
		cout << "Num is case-sens. dir: " << pairWithCase->second << endl;
	else
		cout << "Num not found in case-sensitive dir " << endl;

	auto pairNoCase = dirNoCase.find(name);
	if (pairNoCase != dirNoCase.end())
		cout << "Num found in CI dir: " << pairNoCase->second << endl;
	else
		cout << "Num not found in the case-insensitive directory" << endl;

	return 0;
}