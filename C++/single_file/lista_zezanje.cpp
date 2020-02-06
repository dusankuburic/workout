#include<iostream>

struct Node
{
	int data;
	Node* next;
};


class LinkedList
{
	Node* head = nullptr;
public:
	
	void print();
	void push_front(int new_data);
	void push_back(int new_data);
	void reverse();
	void insert_at(int position, int new_data);
	void pop_back();
	void pop_front();
};


void LinkedList::print()
{
	Node* tek = head;
	while (tek != NULL)
	{
		std::cout <<  tek->data << "=>";
		tek = tek->next;
	}
	std::cout << '\n';
}

void LinkedList::push_front(int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

void LinkedList::push_back(int new_data)
{
	if (head == nullptr)
	{
		Node* new_node = new Node();
		new_node->data = new_data;
		new_node->next = head;
		head = new_node;
	}
	else
	{
		Node* tek = head;
		while (tek->next != nullptr)
		{
			tek = tek->next;
		}

		Node* new_node = new Node();
		new_node->data = new_data;
		new_node->next = nullptr;
		tek->next = new_node;
	}
}



void LinkedList::reverse()
{
	Node* tek = head;
	Node* q = nullptr;
	Node* r = nullptr;

	while (tek != nullptr)
	{
		r = q;
		q = tek;
		tek = tek->next;
		q->next = r;
	}
	head = q;
}


void LinkedList::insert_at(int position, int new_data)
{
	if (position == 0)
	{
		Node* new_node = new Node();
		new_node->data = new_data;
		new_node->next = head;
		head = new_node;
	}
	else
	{
		int tek_position = 0;
		Node* tek = head;
		Node* prev = nullptr;

		while (tek != nullptr && tek_position < position)
		{
			prev = tek;
			tek = tek->next;
			tek_position++;
		}

		if (tek != nullptr)
		{

			Node* new_node = new Node();
			new_node->data = new_data;
			prev->next = new_node;
			new_node->next = tek;
		}
		else
		{
			std::cout << "wrong position\n";
		}
	}
}


void LinkedList::pop_back()
{
	Node* tek = head;
	Node* prev = nullptr;

	while (tek->next != nullptr)
	{
		prev = tek;
		tek = tek->next;
	}
	prev->next = nullptr;
	free(tek);

}

void LinkedList::pop_front()
{
	Node* tek = head;

	head = tek->next;
	free(tek);
}



int main()
{

	LinkedList list;

	list.push_back(11);
	list.push_back(33);
	list.push_front(22);
	list.print();


	list.reverse();
	list.print();

	list.pop_front();
	list.print();


	return 0;
}