#include<iostream>

using namespace std;

class Fish
{
protected:
	bool isFreshWaterFish;

public:
	Fish(bool isFreshWater): isFreshWaterFish(isFreshWater){}

	void Swim()
	{
		if (isFreshWaterFish)
		{
			cout << "Swim in lake" << endl;
		}
		else
		{
			cout << "Swims in sea" << endl;
		}
	}
};


class Tuna : public Fish
{
public:
	Tuna():Fish(false){}
};


class Carp : public Fish
{
public:
	Carp():Fish(true){}
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