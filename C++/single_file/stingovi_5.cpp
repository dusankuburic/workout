#include<iostream>
#include<string.h>


using namespace std;


class String {
public:
	String();
	String(const char* const);
	String(const String&);
	~String();

	//preklopljeni operatori
	char & operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	friend String operator+(const String&, const String&);
	void operator+=(const String&);
	String& operator=(const String&);

	int GetLen() const { return itsLen; }
	const char* GetString() const { return itsString; }
private:
	String(int);
	char* itsString;
	unsigned short itsLen;
};


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
	for (int i = 0; i < itsLen; i++) {
		temp[i] = itsString[i];
		for (int j = 0; j < rhs.GetLen(); j++, i++)
			temp[i] = rhs[j];
	}
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



String operator+(const String& lhs, const String& rhs)
{
	int totalLen = lhs.GetLen() + rhs.GetLen();
	String temp(totalLen);
	for (int i = 0; i < rhs.GetLen(); i++) {
		temp[i] = lhs[i];
		for (int j = 0; j < rhs.GetLen(); j++, i++)
			temp[i] = rhs[j];
	}
	temp[totalLen] = '\0';

	return temp;
}

int main() {

	String s1("String One");
	String s2("String Two");
	const char* c1 = { "C-String One" };

	String s3;
	String s4;
	String s5;

	cout << "s1: " << s1.GetString() << endl;
	cout << "s2: " << s2.GetString() << endl;
	cout << "c1:" << c1 << endl;
	s3 = s1 + s2;
	cout << "s3: " << s3.GetString() << endl;
	s4 = s1 + c1;
	cout << "s4: " << s4.GetString() << endl;
	s5 = c1 + s1;
	cout << "s5: " << s5.GetString() << endl;



	return 0;
}