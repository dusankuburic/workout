#include<iostream>


#define ELEM 10

struct Hero {
	const char* name;
	int power;
	int armor;

	Hero(const char* n, int p, int a):
		name(n),power(p),armor(a){}

};

void print_hero(Hero* h) {
	std::cout << '\n';
	std::cout << "Name:" << h->name << '\n';
	std::cout << "Power:" << h->power << '\n';
	std::cout << "Armor:" << h->armor << '\n';
}


bool compare_by_power(Hero* h1, Hero* h2) {
	return (h1->power > h2->power);
}


bool compare_by_armor(Hero* h1, Hero* h2) {
	return (h1->armor > h1->armor);
}



struct LinkedList {
private:
	struct Node {
		Hero* hero;
		Node* next;
		Node(Hero* new_hero, Node* next_node = nullptr):
			hero(new_hero),next(next_node){}
	};
	Node* head = nullptr;

public:
	void set_next(Hero* new_hero);
	void print() const;
	void sort_list();
	~LinkedList();
};
 
LinkedList::~LinkedList() {
	Node* tek = head, *old;
	while (tek) {
		old = tek;
		tek = tek->next;
		delete old;
	}
}

void LinkedList::sort_list() {
	for(Node* tek1 = head; tek1->next; tek1 = tek1->next)
		for(Node* tek2 = tek1->next; tek2; tek2 = tek2->next)
			if (compare_by_power(tek1->hero, tek2->hero)) {
				Hero* h = tek1->hero;
				tek1->hero = tek2->hero;
				tek2->hero = h;
			}
}

void LinkedList::set_next(Hero* new_hero) {
	head = new Node(new_hero, head);
}


void LinkedList::print() const {
	for (Node* tek = head; tek; tek = tek->next)
		print_hero(tek->hero);
}


int main() {

	LinkedList lista;

	lista.set_next(new Hero("dusan",100,200));
	lista.set_next(new Hero("jovan", 700, 20));
	lista.set_next(new Hero("uros", 10, 2));

	lista.sort_list();
	lista.print();
	


	return 0;
}