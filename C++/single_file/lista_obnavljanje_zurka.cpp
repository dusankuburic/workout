#include<iostream>
#include<string>

class Human
{
public:
	short int age_;
	std::string name;

	virtual void whoami() = 0;
};

class Hero : public Human
{
public:
	Hero(short int age, int power, int range);
	int power_;
	int range_;


	void whoami() override 
	{
		std::cout << "Hero=> age:" << age_ << " power:" << power_ << " range:" << range_ << '\n';
	}

};

Hero::Hero(short int age, int power, int range):
	power_(power), range_(range)
{
	age_ = age;
}


class Hunter : public Human
{
public:
	Hunter(short int age, int heal, int tempo);
	int heal_;
	int tempo_;

	void whoami() override
	{
		std::cout << "Hunter=> age:" << age_ << " heal:" << heal_ << " tempo:" << tempo_ << '\n';
	}
};


Hunter::Hunter(short int age, int heal, int tempo):
	heal_(heal), tempo_(tempo)
{
	age_ = age;
}





struct Node
{
	Human* human_;
	Node* next_;
};


class LinkedList
{
private:
	Node* head_ = nullptr;
public:
	~LinkedList();
	void push_front(Human* human);
	void push_back(Human* human);
	void insert_at(int position, Human* human);
	void reverse();
	void pop_front();
	void pop_back();
	void print();
};

void LinkedList::print()
{
	Node* temp = head_;
	while (temp != nullptr)
	{
		temp->human_->whoami();
		temp = temp->next_;
	}

	std::cout << '\n';
}

LinkedList::~LinkedList()
{
	Node* temp = head_;
	Node* prev = nullptr;
	while (temp != nullptr)
	{
		prev = temp;
		temp = temp->next_;
		delete prev;
	}
}



void LinkedList::push_front(Human* human)
{
	Node* new_node = new Node;
	new_node->human_ = human;
	new_node->next_ = head_;
	head_ = new_node;
}

void LinkedList::push_back(Human* human)
{
	if (head_ == nullptr)
	{
		Node* new_node = new Node;
		new_node->human_ = human;
		new_node->next_ = head_;
		head_ = new_node;
	}
	else
	{
		Node* temp = head_;

		while (temp->next_ != nullptr)
		{
			temp = temp->next_;
		}

		Node* new_node = new Node;
		new_node->human_ = human;
		new_node->next_ = nullptr;
		temp->next_ = new_node;
	}
}

void LinkedList::insert_at(int position, Human* human)
{
	if (position == 0)
	{
		Node* new_node = new Node;
		new_node->human_ = human;
		new_node->next_ = head_;
		head_ = new_node;
	}
	else
	{
		Node* temp = head_;
		Node* prev = nullptr;
		int temp_position = 0;
		while (temp != nullptr && temp_position < position)
		{
			prev = temp;
			temp = temp->next_;
			temp_position++;
		}


		if (temp != nullptr)
		{
			Node* new_node = new Node;
			new_node->human_ = human;
			new_node->next_ = head_;
			head_ = new_node;
		}
		else
		{
			std::cout << "wrong index";
		}
	}
}


void LinkedList::reverse()
{
	Node* temp = head_;
	Node* q = nullptr;
	Node* r = nullptr;

	while (temp != nullptr)
	{
		r = q;
		q = temp;
		temp = temp->next_;
		q->next_ = r;
	}
	head_ = q;
}


void LinkedList::pop_front()
{
	Node* temp = head_;
	head_ = head_->next_;
	free(temp);
}


void LinkedList::pop_back()
{
	Node* temp = head_;
	Node* prev = nullptr;

	while (temp->next_ != nullptr)
	{
		prev = temp;
		temp = temp->next_;
	}

	prev->next_ = nullptr;
	free(temp);
}


int main()
{

	LinkedList lista;
	Human* h1 = new Hero(10,201,1000);
	Human* h2 = new Hunter(20,444,232);
	Human* h3 = new Hero(44,1024,66);

	lista.push_front(h1);
	lista.push_front(h2);
	lista.push_front(h3);
	lista.print();

	std::cout << "Rev:\n";

	lista.reverse();
	lista.print();

	delete h1;
	delete h2;
	delete h3;


	return 0;
}