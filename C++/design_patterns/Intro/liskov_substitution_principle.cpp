#include<boost/lexical_cast.hpp>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>

//VALIDATION!!!

using namespace std;
using namespace boost;


class Rectangle
{
protected:
	int width, height;
public:
	Rectangle(int width, int height): width(width), height(height){}

	int getWidth() const {
		return width;
	}

	virtual void setWidth(int widht) {
		Rectangle::width = widht;
	}

	int getHeight() const {
		return height;
	}

	virtual void setHeight(int height) {
		Rectangle::height = height;
	}

	int area() const { return width * height; }
};


class Square: public Rectangle
{
public:
	Square(int size) :
		Rectangle(size, size) {}

	void setWidth(int width) override {
		this->width = this->height = width;
	}

	void setHeight(int height) override {
		this->width = this->height = height;
	}
};



void process(Rectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);


	cout << "expected area = " << (w * 10)
		<< ", got " << r.area() << endl;
}


int main()
{


	Rectangle r{ 3,4 };
	process(r);

	Square sq{ 5 };
	process(sq);

	getchar();
	return 0;

}