#include<iostream>

using namespace std;


enum BOOL {FALSE, TRUE};

class Hero
{
public:
	Hero():itsAge(10){}
	~Hero(){}
	virtual void Attack() const = 0;
	virtual void Run() const = 0;
protected:
	int itsAge;
};


class FireHero : public Hero
{
public:
	void Attack() const { cout << "FireHero attacking\n"; }
	void Run() const { cout << "FireHero running\n"; }
};



class WatherHero : public Hero
{
public:
	void Attack() const { cout << "WatherHero attacking\n"; }
	void Run() const { cout << "WatherHero running\n"; }
};



int main()
{

	void(Hero::*pFunc)() const = 0;

	Hero* p_hero = nullptr;
	int chose_hero = 0;
	int method = 0;

	BOOL fQuit = FALSE;



	while (fQuit == FALSE)
	{

		cout << "(0)Quit (1)FireHero (2)WatherHero: ";
		std::cin >> chose_hero;

		switch (chose_hero)
		{
		case 1: p_hero = new FireHero();
			break;
		case 2: p_hero = new WatherHero();
			break;
		default:
			fQuit = TRUE;
			break;
		}

		if (fQuit)
			break;


		std::cout << "(1)Attack (2)Run: ";
		std::cin >> method;

		switch (method)
		{
		case 1: pFunc = &Hero::Attack;
			break;
		case 2: pFunc = &Hero::Run;
			break;
		default:
			break;
		}

		(p_hero->*pFunc)();

		delete p_hero;
	}



	return 0;
}