#include<iostream>

using namespace std;

class Fish
{
protected:
	bool isFreshWaterFish;
public:
	void Swim()
	{
		if (isFreshWaterFish)
			cout << "Swims in lake" << endl;
		else
			cout << "Swims in sea" << endl;
	}
};


class Tuna : public Fish
{
public:
	Tuna()
	{
		isFreshWaterFish = false;
	}
};


class Carp : public Fish
{
public:
	Carp()
	{
		isFreshWaterFish = false;
	}
};


int main()
{
	Carp myLunch;
	Tuna myDinner;

	cout << "About my food" << endl;

	cout << "Lunch: ";
	myLunch.Swim();


	cout << "Dinner: ";
	myDinner.Swim();


	return 0;
}