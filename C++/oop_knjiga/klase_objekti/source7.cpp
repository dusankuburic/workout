#include<iostream>
#include<string.h>

using namespace std;

class MyString
{
private:
	char* buffer;
public:
	MyString(const char* initString)
	{
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);
		}
		else
		{
			buffer = NULL;
		}
	}

	~MyString()
	{
		cout << "Invoking destructor, cleaning up " << endl;
		if (buffer != NULL)
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


int main()
{
	MyString sayHello("Hello from String Class");
	cout << " String buffer in sayHello is " << sayHello.GetLength();
	cout << " characters long " << endl;


	cout << "Buffer contains: " << sayHello.GetString() << endl;

	return 0;
}