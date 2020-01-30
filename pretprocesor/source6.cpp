#define DEBUG
#define SHOW_INVARIANTS
#include<iostream>
#include<string>

using namespace std;

#ifndef DEBUG
#define ASSERT(x)
#else
#define ASSERT(x) \
	if(!(x)) \
{\
cout << "ERROR!! Assert " << #x << " failed\n"; \
cout << " on line " << __LINE__ << "\n"; \
cout << " in file " << __FILE__ << "\n"; \
}
#endif

const int FALSE = 0;
const int TRUE = 1;
typedef int BOOL;



class String
{
public:
	String();
	String(const char* const);
	String(const String&);
	~String();

	char& operator[](int offset);
	char operator[](int offset) const;

	String& operator= (const String&);
	int GetLen() const { return itsLen;}
	const char* GetString() const { return itsString; }
	BOOL Invariants() const;
 private:
	String(int);
	char* itsString;
	int itsLen;
};

String::String()
{
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
	ASSERT(Invariants());
}

String::String(int len) 
{
	itsString = new char[len + 1];
	for (int i = 0; i <= len; i++)
		itsString[i] = '\0';
	itsLen = len;
	ASSERT(Invariants());
}

String::String(const char* const cString)
{
	itsLen = strlen(cString);
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());
}

String::String(const String& rhs)
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());
}

String::~String()
{
	ASSERT(Invariants());
	delete[] itsString;
	itsLen = 0;
}

String& String::operator=(const String& rhs)
{
	ASSERT(Invariants());
	if (this == &rhs)
		return *this;
	delete[] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());

	return *this;
}

char& String::operator[](int offset) 
{
	ASSERT(Invariants());
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
	ASSERT(Invariants());
}

char String::operator[](int offset) const
{
	ASSERT(Invariants());
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
	ASSERT(Invariants());
}

BOOL String::Invariants() const {
#ifdef SHOW_INVARIANTS
	cout << " String OK";
#endif
	return ((itsLen && itsString) || (!itsLen && !itsString));
}


class Animal
{
public:
	Animal():itsAge(1),itsName("John Q. Animal")
	{
		ASSERT(Invariants());
	}
	Animal(int, const String&);
	~Animal(){}
	int GetAge() { ASSERT(Invariants()); return itsAge; }
	void SetAge(int Age)
	{
		ASSERT(Invariants());
		itsAge = Age;
		ASSERT(Invariants());
	}
	String& GetName()
	{
		ASSERT(Invariants());
		return itsName;
	}
	void SetName(const String& name)
	{
		ASSERT(Invariants());
		itsName = name;
		ASSERT(Invariants());
	}
	BOOL Invariants();
private:
	int itsAge;
	String itsName;
};

Animal::Animal(int age, const String& name) :
	itsAge(age),
	itsName(name)
{
	ASSERT(Invariants());
}

BOOL Animal::Invariants()
{
#ifdef SHOW_INVARIANTS
	cout << " Animal OK";
#endif
	return (itsAge > 0 && itsName.GetLen());
}


int main()
{
	Animal sparky(5, "Sparky");
	cout << "\n" << sparky.GetName().GetString() << " is ";
	cout << sparky.GetAge() << " years old.";
	sparky.SetAge(8);
	cout << "\n" << sparky.GetName().GetString() << " is ";
	cout << sparky.GetAge() << " years old.";

	return 0;
}