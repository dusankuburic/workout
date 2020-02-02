#include<iostream>

using namespace std;


class MonsterDB
{
private:
	~MonsterDB() { };

public:
	static void DestroyInstance(MonsterDB* pInstance)
	{
		delete pInstance;
	}

	void DoSomething(){}
};

int main()
{
	MonsterDB* myDB = new MonsterDB();
	myDB->DoSomething();

	MonsterDB::DestroyInstance(myDB);

	return 0;
}