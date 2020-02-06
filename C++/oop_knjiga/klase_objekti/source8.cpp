#include<iostream>
#include<string.h>


#pragma warning(disable : 4996)

using namespace std;

class MyString
{
private:
	char* buffer;
public:
	MyString(const char* initString)
	{
		buffer = NULL;
		cout << "Default constructor: creating ne MyString" << endl;
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);

			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}

	MyString(const MyString& copySource)
	{
		buffer = NULL;
		cout << "Copy constructor: copying from MyString" << endl;

		if (copySource.buffer != NULL)
		{
			buffer = new char[strlen(copySource.buffer) + 1];

			strcpy(buffer, copySource.buffer);

			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}

	~MyString()
	{
		cout << "Invoking destructor, clearing up" << endl;
		delete[] buffer;
	}

	int GetLength()
	{
		return strlen(buffer);
	}

	const char* GetString()
	{
		return buffer;
	}
};

void UseMyString(MyString str)
{
	cout << "String buffer in MyString is " << str.GetLength();
	cout << " characters long" << endl;

	cout << "Buffer contains: " << str.GetString() << endl;
	return;
}


int main()
{
	MyString sayHello("Hello from String Class");

	UseMyString(sayHello);

	return 0;
}
