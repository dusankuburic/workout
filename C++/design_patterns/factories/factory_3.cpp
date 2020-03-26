#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<tuple>
#include<sstream>
#include<memory>


using namespace std;


enum class PointType
{
	cartesian,
	polar
};

class Point
{
	Point(float x, float y):x(x), y(y){}
	float x, y;
public:
	friend ostream &operator<<(ostream &os, const Point &point) {
		os << "x: " << point.x << " y: " << point.y;
		return os;
	}

private:
	class PointFactory
	{
		PointFactory(){}
	public:
		static Point NewCartesian(float x, float y) {
			return { x,y };
		}


		static Point NewPolar(float r, float theta) {
			return { r*cos(theta), r*sin(theta) };
		}
	};
public:
	static PointFactory Factory;

};




int main()
{
	

	auto p = Point::Factory.NewCartesian(3, 4);
	cout << p << endl;


	return 0;
}