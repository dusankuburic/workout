#define DemoVersion
#define DOS_VERSION 5
#include <iostream>

using namespace std;


int main()
{
	cout << "Checking on the definition of DemoVersion, DOS_VERSION_and WINDOWS_VERSION...\n";


#ifdef DemoVersion
	cout << "DemoVersion defined.\n";
#else
	cout << "DemoVerison not defined.\n";
#endif


#ifndef  DOS_VERSION
	cout << "DOS_VERSION not defined!\n";
#else
	cout << "DOS_VERSION defined as: " << DOS_VERSION << endl;
#endif // ! DOS_VERSION


#ifdef WINDOWS_VERSION
	cout << "WINDOWS_VERSION defined!\n";
#else
	cout << "WINDOWS_VERSION was not defined.\n";
#endif


#undef DOS_VERSION

#ifdef DemoVersion
	cout << "DemoVersion defined.\n";
#else
	cout << "DemoVersion not defined.\n";
#endif


#ifndef DOS_VERSION
	cout << "DOS_VERSION not defined!\n";
#else
	cout << "DOS_VERSION defined as: " << DOS_VERSION << endl;
#endif


	cout << "Done.\n";

	return 0;

}