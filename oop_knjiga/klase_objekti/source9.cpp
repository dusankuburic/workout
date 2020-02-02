#include<iostream>
#include<string>

using namespace std;


class President
{
private:
	President() {};
	President(const President&);
	const President& operator=(const President&);

	string name;
public:
	static President& GetInstance()
	{
		static President onlyInstance;
		return onlyInstance;
	}

	string GetName()
	{
		return name;
	}

	void SetName(string InputName)
	{
		name = InputName;
	}
};


int main()
{
	President& onlyPresident = President::GetInstance();
	onlyPresident.SetName("Abraham Lincoln");

	cout << "The name of President is: ";
	cout << President::GetInstance().GetName() << endl;

	President& only = President::GetInstance();

	return 0;
}