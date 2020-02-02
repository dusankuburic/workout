#include<iostream>
#include<string>

using namespace std;

class Human
{
private:
	string name;
	int age;

public:
	Human()
	{
		age = 0;
		cout << "Default constructor: name and age not set" << endl;
	}

	Human(string humansName, int humansAge)
	{
		name = humansName;
		age = humansAge;
		cout << "Overloaded constructor creates ";
		cout << name << " of " << age << " years " << endl;
	}
};

int main()
{
	Human firstMan;
	Human firstWoman("Eve", 20);

	return 0;
}