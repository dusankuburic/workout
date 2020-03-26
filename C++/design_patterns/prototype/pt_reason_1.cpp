
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


struct Address
{
	string street, city;
	int suite;

	Address(const string &street, const string &city, int suite):
		street(street), city(city), suite(suite){}

	friend ostream &operator<<(ostream &os, const Address &address) {
		os << "street: " << address.street << "city: " << address.city << "suite: "
			<< address.suite;
		return os;
	}
};

struct Contact
{
	string name;
	Address* address;

	Contact(const string &name, Address *address):
		name(name), address(address){}

	friend ostream &operator<<(ostream &os, const Contact &contact) {
		os << "name: " << contact.name << " address: " << *contact.address;
		return os;
	}
};


int main()
{

	
	Contact john{ "John Doe",new Address{"123 East Dr","London",123}};
	//Contact jage{ "Jane Smith",Address{"123 Eest Dr","London",103}};

	Contact jane = john;
	jane.name = "Hane Smith";
	jane.address->suite = 103;

	cout << john << endl << jane << endl;
}