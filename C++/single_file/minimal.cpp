#include<iostream>



class Power{

public:
	Power();
	Power(int range);
	virtual ~Power() = default;
	int GetRange() const;
	virtual void Display() = 0;
private:
	int range_;
};

Power::Power():
	range_(0){}

Power::Power(int range):
	range_(range){}

int Power::GetRange() const {
	return range_;
}


class FirePower : public Power {

public:
	FirePower();
	FirePower(int duration, int range);
	int GetDuration() const;
	void Display() override;
private:
	int duration_;
};

FirePower::FirePower():
	duration_(0){}

FirePower::FirePower(int duration, int range):
	duration_(duration),
	Power(range){}

int FirePower::GetDuration() const {
	return duration_;
}

void FirePower::Display()
{
	std::cout << "Fire Power" << std::endl;
}


class WaterPower : public Power {

public:
	WaterPower();
	WaterPower(int endurance, int range);
	int GetEndurance() const;
	void Display() override;
private:
	int endurance_;
};


WaterPower::WaterPower():
	endurance_(0){}

WaterPower::WaterPower(int endurance, int range):
	endurance_(endurance),
	Power(range){}

int WaterPower::GetEndurance() const {
	return endurance_;
}

void WaterPower::Display()
{
	std::cout << "Water Power" << std::endl;
}


class Node {
public:
	Node(Power*);
	~Node();
	void SetNext(Node* node);
	Node* GetNext() const;
	Power* GetPower() const;
private:
	Power* power_;
	Node* next_;
};

Node::Node(Power* power):
	power_(power),
	next_(nullptr){}

Node::~Node() {
	delete power_;
	power_ = nullptr;
	delete next_;
	next_ = nullptr;
}

void Node::SetNext(Node* node) {
	next_ = node;
}

Node* Node::GetNext() const {
	return next_;
}

Power* Node::GetPower() const {
	return power_;
}




class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int GetCount() const;
	Power* GetFirst() const;
	Power* operator[](int) const;
	void print();
	void push_front(Power*);
private:
	Node* head_;
	int count_;
};

LinkedList::LinkedList():
	head_(nullptr),
	count_(0){}

LinkedList::~LinkedList() {
	delete head_;
}

int LinkedList::GetCount() const {
	return count_;
}

Power* LinkedList::GetFirst() const {
	if (head_)
		return head_->GetPower();
	else
		return nullptr;
}

Power* LinkedList::operator[](int off_set) const {

	if (!head_)
		return nullptr;
	if (off_set > count_)
		return nullptr;

	Node* p_node = head_;
	for (int i = 0; i < off_set; i++)
		p_node = p_node->GetNext();

	return p_node->GetPower();
}


void LinkedList::push_front(Power* power) {

	Node* new_node = new Node(power);
	new_node->SetNext(head_);
	head_ = new_node;
}

void LinkedList::print() {
	Node* p_node = head_;

	while (p_node != nullptr) {
		p_node->GetPower()->Display();
		p_node = p_node->GetNext();
	}
	std::cout << std::endl;
}


int main() {

	Power* w_power = new WaterPower;
	Power* f_power = new FirePower;



	LinkedList lista;

	lista.push_front(w_power);
	lista.push_front(f_power);

	lista.print();
	
	lista[0]->Display();

	
	


	return 0;
}