#include<iostream>
#include<string>

using namespace std;


struct Student
{
	string firstName;
	string lastName;
	int studentNum;
	double gradePointAvg;
};

void printInfo(const Student& s) {
	cout << "ID is" << s.studentNum << endl;
	cout << "Name is " << s.firstName << " " << s.lastName << endl;
	cout << "GPA is " << s.gradePointAvg << endl;
} 


int main()
{
	Student mary;
	mary.lastName = "Smith";
	mary.firstName = "Mary";
	mary.gradePointAvg = 4.0;
	mary.studentNum = 123456789;

	printInfo(mary);

}