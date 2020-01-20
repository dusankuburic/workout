#include<iostream>
#include<string>

class String {
public:
	String();
	String(const char* const);
	String(const String&);
	~String();

	char& operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);

	int GetLen() const { return itsLen; }
	const char* GetString() const { return itsString; }

private:
	String(int);
	char* itsString;
	unsigned short itsLen;
};

String::String() {
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
}


String::String(int len) {
	itsString = new char[len + 1];
	for (int i = 0; i <= len; i++)
		itsString[i] = '\0';
	itsLen = len;
}


String::String(const char* const cString) {
	itsLen = strlen(cString);
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
}

String::String(const String& rhs) {

	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];	
	for (int i = 0; i < itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
}

String::~String() {
	
	delete[] itsString;
	itsLen = 0;
}

String& String::operator=(const String& rhs) {
	if (this == &rhs)
		return *this;
	delete[] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	return *this;
}

char & String::operator[](int offset) {
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

char String::operator[](int offset) const {

	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

String String::operator+(const String& rhs) {

	int totalLen = itsLen + rhs.GetLen();
	String temp(totalLen);
	int i, j;
	for (i = 0; i < itsLen; i++)
		temp[i] = itsString[i];
	for (j = 0; j < rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];

	temp[totalLen] = '\0';
	return temp;
}

void String::operator+=(const String& rhs) {

	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = itsLen + rhsLen;
	String temp(totalLen);
	for (int i = 0; i < itsLen; i++) {
		temp[i] = itsString[i];
		for (int j = 0; j < rhs.GetLen(); j++, i++)
			temp[i] = rhs[i - itsLen];
	}
	temp[totalLen] = '\0';
	*this = temp;
}


class Employee {

public:
	Employee();
	Employee(const char*,const char*,const char*, long);
	~Employee();
	Employee(const Employee&);
	Employee& operator= (const Employee&);
	
	const String & GetFirstName() const {
		return itsFirstName;
	}
	const String & GetLastName() const {
		return itsLastName;
	}
	const String & GetAdress() const {
		return itsAddress;
	}
	long GetSalary() const { return itsSalary; }

	void SetFirstName(const String& fName) {
		itsFirstName = fName;
	}
	void SetLastName(const String & lName) {
		itsLastName = lName;
	}
	void SetAddress(const String& address) {
		itsAddress = address;
	}
	void SetSalary(long salary) {
		itsSalary = salary;
	}

private:
	String itsFirstName;
	String itsLastName;
	String itsAddress;
	long itsSalary;
};

Employee::Employee():
	itsFirstName(""),
	itsLastName(""),
	itsAddress(""),
	itsSalary(0)
{}

Employee::Employee(const char* firstName, const char* lastName,const char* address, long salary):
	itsFirstName(firstName),
	itsLastName(lastName),
	itsAddress(address),
	itsSalary(salary)
{}

Employee::Employee(const Employee & rhs):
	itsFirstName(rhs.GetFirstName()),
	itsLastName(rhs.GetLastName()),
	itsAddress(rhs.GetAdress()),
	itsSalary(rhs.GetSalary())
{}


Employee::~Employee(){}


Employee & Employee::operator=(const Employee& rhs) {

	if (this == &rhs)
		return *this;

	itsFirstName = rhs.GetFirstName();
	itsLastName = rhs.GetLastName();
	itsAddress = rhs.GetAdress();
	itsSalary = rhs.GetSalary();

	return *this;
}


int main() {


	Employee Edie("Jane", "Doe", "1461 Shore Parkway", 20000);
	Edie.SetSalary(50000);
	String LasName("Levine");
	Edie.SetLastName(LasName);
	Edie.SetFirstName("Edythe");

	std::cout << "Name: "; 
	std::cout << Edie.GetFirstName().GetString();
	std::cout << " " << Edie.GetLastName().GetString();
	std::cout << ".\nAddress: ";
	std::cout << Edie.GetAdress().GetString();
	std::cout << ".\nSalary: ";
	std::cout << Edie.GetSalary();

	return 0;

}