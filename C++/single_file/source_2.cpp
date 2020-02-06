#include<iostream>

struct Sword {

	int power;
	int price;
	Sword():power(0),price(0){}
	virtual ~Sword() {};
};

struct GoldenSword : public Sword {

	int day;
	GoldenSword():day(0){}
	GoldenSword(int, int, int);
};

GoldenSword::GoldenSword(int POWER, int PRICE, int DAY) :
	day(DAY) {
	power = POWER;
	price = PRICE;
}

struct SilverSword : public Sword {

	int year;
	SilverSword():year(0){}
	SilverSword(int, int, int);
};

SilverSword::SilverSword(int POWER, int PRICE, int YEAR) :
	year(YEAR) {
	power = POWER;
	price = PRICE;
}




struct Node {
	Sword* sword;
	Node* next;

	~Node();
};

Node::~Node() {
	delete sword;
	sword = nullptr;
	delete next;
	next = nullptr;
}




struct LinkedList {

	Node* pHead;
	int count;

	void printList();
	void pushFront(Sword* sword);
	void pushBack(Sword* sword);

	Sword* operator[](int) const;

	LinkedList():pHead(nullptr),count(0){}
}; 

void LinkedList::printList() {
	std::cout << "*** PRINTING LIST ***\n";
	Node* pNode = pHead;
	while (pNode != nullptr) {
		std::cout << pNode->sword->price << "=>";
		pNode = pNode->next;
	}
	std::cout << '\n';
}

void LinkedList::pushFront(Sword* new_sword) {

	Node* newNode = new Node();
	newNode->sword = new_sword;
	newNode->next = pHead;
	pHead = newNode;

	count++;
}

void LinkedList::pushBack(Sword* new_sword){

	if (!pHead) {
		Node* newNode = new Node();
		newNode->sword = new_sword;
		newNode->next = pHead;
		pHead = newNode;

	}else{

	Node* pNode = pHead;
	while (pNode->next != nullptr) {
		pNode = pNode->next;
	}

	Node* newNode = new Node();
	newNode->sword = new_sword;
	newNode->next = nullptr;
	pNode->next = newNode;
 }
 
	count++;
}


Sword* LinkedList::operator[](int offSet) const {
	
	Node* pNode = pHead;
	if (!pHead)
		return nullptr;
	if (offSet > count)
		return nullptr;
	for (int i = 0; i < offSet; i++)
		pNode = pNode->next;


	return pNode->sword;

}

int main() {

	LinkedList list;
	SilverSword s1(100,555,2020);
	GoldenSword s2(222,5,2019);
	GoldenSword s3(434,3434,2020);

	list.pushBack(&s1);
	list.pushFront(&s2);
	list.pushBack(&s3);


	list.printList();

	std::cout << '\n';
	std::cout << list[0]->power << '\n';

	return 0;
}