#include<boost/lexical_cast.hpp>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>


using namespace std;
using namespace boost;

struct Journal
{
	string title;
	vector<string> entries;

	Journal(const string &title):title(title){}

	void add_entry(const string& entry)
	{
		static int count = 1;
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}


};

struct PersistenceManager
{

	static void save(const Journal& j, const string& filename)
	{
		ofstream ofs(filename);
		for (auto& e : j.entries)
			ofs << e << endl;
	}
};


int main()
{

	Journal journal{ "Dear Diary" };
	journal.add_entry("I ate a bug");
	journal.add_entry("I cried today");


	PersistenceManager pm;
	pm.save(journal,"diary.txt");

	for (auto it = journal.entries.begin(); it != journal.entries.end(); it++)
		std::cout << *it << std::endl;

	getchar();
	return 0;

}