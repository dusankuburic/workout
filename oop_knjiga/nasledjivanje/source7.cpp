#include<iostream>

using namespace std;


class FishDummyMember
{
public:
	FishDummyMember()
	{
		cout << "FishDummyMember construct" << endl;
	}
	~FishDummyMember()
	{
		cout << "FishDummyMember destructor" << endl;
	}
};


class Fish
{
protected:
	FishDummyMember dummy;
public:
	Fish()
	{
		cout << "Fish construct" << endl;
	}
	~Fish()
	{
		cout << "Fish destruct" << endl;
	}
};

class TunaDummyMember
{
public:
	TunaDummyMember()
	{
		cout << "TunaDummyMember constructor" << endl;
	}
	~TunaDummyMember()
	{
		cout << "TunaDummyMember destructor" << endl;
	}
};


class Tuna : public Fish
{
private:
	TunaDummyMember dummy;
public:
	Tuna()
	{
		cout << "Tuna constructor" << endl;
	}
	~Tuna()
	{
		cout << "Tuna destructor" << endl;
	}
};

int main()
{
	Tuna myDinner;

	return 0;
}