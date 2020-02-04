#include<iostream>

using namespace std;

class Fish
{
public:
	bool isFreshWaterFish;

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
		isFreshWaterFish = true;
	}
};

int main()
{

	Carp myLunch;
	Tuna myDiner;

	cout << "About my food: " << endl;
	cout << "Lunch: ";
	myLunch.Swim();


	cout << "Diner: ";
	myDiner.Swim();

	return 0;

}