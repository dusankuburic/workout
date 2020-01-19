#include<iostream>

using namespace std;

enum BOOL {FALSE, TRUE};


class Mammal {
public:
	Mammal() :itsAge(1) {}
	~Mammal(){}
	virtual void Speak() const = 0;
	virtual void Move() const = 0;
protected:
	int itsAge;
};

class Dog : public Mammal {
public:
	void Speak() const { cout << "Woof!\n"; }
	void Move() const { cout << "Walking to heel...\n"; }
};


class Cat : public Mammal {
public:
	void Speak() const { cout << "Meow!\n"; }
	void Move() const { cout << "slinking...\n"; }
};


class Horse : public Mammal {
public:
	void Speak() const { cout << "Winnie!\n"; }
	void Move() const { cout << "Galloping...\n"; }
};


int main() {

	void(Mammal::*pFunc)() const = 0;
	Mammal* ptr = 0;
	int Animal;
	int Method;


	BOOL fQuit = FALSE;

	while (fQuit == FALSE) {
		cout << "(0)Quit (1)dog (2)cat (3)horse: ";
		cin >> Animal;
		switch (Animal) {
		case 1: ptr = new Dog; break;
		case 2: ptr = new Cat; break;
		case 3: ptr = new Horse; break;
		default: fQuit = TRUE; break;
		}

		if (fQuit)
			break;

		cout << "(1)Speak (2)Move: ";
		cin >> Method;
		switch (Method)
		{
		case 1: pFunc = &Mammal::Speak; break;
		default:
			pFunc = &Mammal::Move; break;
			break;
		}

		(ptr->*pFunc)();
		delete ptr;
	}

	return 0;
}