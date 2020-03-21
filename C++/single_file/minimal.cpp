#include<iostream>



class Power{

public:
	Power();
	Power(int range);
	int GetRange() const;
private:
	int range_;
};

Power::Power():
	range_(0){}

Power::Power(int range):
	range_(range){}

int Power::GetRange() const {
	return range_;
}


class FirePower : public Power {

public:
	FirePower();
	FirePower(int duration, int range);
	int GetDuration() const;
private:
	int duration_;
};

FirePower::FirePower():
	duration_(0){}

FirePower::FirePower(int duration, int range):
	duration_(duration),
	Power(range){}

int FirePower::GetDuration() const {
	return duration_;
}


class WaterPower : public Power {

public:
	WaterPower();
	WaterPower(int endurance, int range);
	int GetEndurance() const;
private:
	int endurance_;
};


WaterPower::WaterPower():
	endurance_(0){}

WaterPower::WaterPower(int endurance, int range):
	endurance_(endurance),
	Power(range){}

int WaterPower::GetEndurance() const {
	return endurance_;
}


int main() {

}