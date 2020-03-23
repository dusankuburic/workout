#include<boost/lexical_cast.hpp>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>


using namespace std;
using namespace boost;


enum class Relationship
{
	parent,
	child,
	sibling
};

struct Person
{
	string name;
};


struct RelationshipBrowser
{
	virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships: RelationshipBrowser// low-level modul/construct
{
	vector<tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child)
	{
		relations.push_back({ parent,Relationship::parent,child });
		relations.push_back({ child,Relationship::child,parent });
	}


	vector<Person> find_all_children_of(const string& name) override 
	{
		vector<Person> result;
		for (auto&&[first, rel, second] : relations)
		{
			if (first.name == name && rel == Relationship::parent)
			{
				result.push_back(second);
			}
		}

		return result;
	}

};


struct Resarch // high-level
{

	/*
	Resarch(Relationships& relationships)
	{
		auto& relations = relationships.relations;
		for (auto&& [first, rel, second] : relations)
		{
			if (first.name == "John" && rel == Relationship::parent)
			{
				cout << "John has a child called " << second.name << endl;
			}
		}
	}
	*/

	Resarch(RelationshipBrowser& browser)
	{
		for (auto& child : browser.find_all_children_of("John"))
		{
			cout << " John has a child called " << child.name << endl;
		}
	}
};

int main()
{

	Person parent{ "John" };
	Person child1{ "Chris" }, child2{ "Matt" };

	Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);


	Resarch _(relationships);
	
	return 0;

}