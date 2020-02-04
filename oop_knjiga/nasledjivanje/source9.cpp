#include<iostream>

using namespace std;

class Motor
{
public:
	void SwitchIgnition()
	{
		cout << "Ignition ON" << endl;
	}

	void PumpFuel()
	{
		cout << "Fuel in cylinder" << endl;
	}

	void FireCylinders()
	{
		cout << "Vroom" << endl;
	}
};


class Car : protected Motor
{
public:
	void Move()
	{
		SwitchIgnition();
		PumpFuel();
		FireCylinders();
	}
};

class RaceCar : protected Car
{
public:
	void Move()
	{
		SwitchIgnition();
		PumpFuel();
		FireCylinders();
		FireCylinders();
		FireCylinders();
	}
};

int main()
{
	RaceCar myDreamCar;
	myDreamCar.Move();

	return 0;
}