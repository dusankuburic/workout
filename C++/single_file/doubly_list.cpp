#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<tuple>
#include<sstream>
#include<memory>



using namespace std;



struct node
{
	struct node* prev;
	int info;
	struct node* next;
}*start;


class Doublylist
{
public:
	Doublylist()
	{
		start = NULL;
	}

	void create_list();
	void insertion_at_beginning();
	void insertion_at_position();
	void deletion();
	void display();
};





int main()
{
	Doublylist obj;
	int choice;
	
	while (1)
	{
		cout << "\n***MENU***";
		cout << "\n1. Create List";
		cout << "\n2. Insertion at Beginng";
		cout << "\n3. Insertion at Specified Position";
		cout << "\n4. Deletion";
		cout << "\n5. Display";
		cout << "\n6. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			obj.create_list();
			break;
		case 2:
			obj.insertion_at_beginning();
			break;
		case 3:
			obj.insertion_at_position();
			break;
		case 4:
			obj.deletion();
			break;
		case 5:
			obj.display();
			break;
		case 6:
			exit(0);
		default:
			cout << "Wrong choice";
			break;
		}
	}
	getchar();
}


void Doublylist::create_list()
{
	int item;
	struct node *ptr, *temp;
	ptr = new (struct node);
	cout << "\nEnter the value: ";
	cin >> item;
	ptr->info = item;
	ptr->next = NULL;
	if (start == NULL)
	{
		ptr->prev = NULL;
		start = ptr;
	}
	else
	{
		temp = start;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = ptr;
		ptr->prev = ptr;
	}
	cout << "\nList created Successfully";
	getchar();
}

void Doublylist::insertion_at_beginning()
{
	if (start == NULL)
	{
		cout << "List is not created";
		return;
	}
	struct node *ptr1;
	int item;
	cout << "\nEnter value of node: ";
	cin >> item;
	ptr1 = new(struct node);

	ptr1->prev = NULL;
	ptr1->info = item;

	ptr1->next = start;
	start->prev = ptr1;
	start = ptr1;
	cout << "\nInserted Successfully at beginning!!";
	getchar();
}


void Doublylist::insertion_at_position()
{
	struct node *temp, *ps;
	int item, position, i;
	if (start == NULL)
	{
		cout << "List is not created";
		return;
	}
	cout << "\nEnter value of node: ";
	cin >> item;
	cout << "\nEnter position of node: ";
	cin >> position;
	ps = start;
	for (i = 0; i < (position - 1); i++)
	{
		ps = ps->next;
		if (ps == NULL)
		{
			cout << "Invalid Position";
			return;
		}
	}
	temp = new(struct node);
	temp->info = item;
	temp->next = temp;
	if (ps->next == NULL)
	{
		ps->next = temp;
		temp->next = NULL;
		temp->prev = ps;
	}
	else
	{
		temp->next = ps->next;
		(temp->next)->prev = temp;
		ps->next = temp;
		temp->prev = ps;
	}

	cout << "\nInserted Successfully!!";
	getchar();
}

void Doublylist::deletion()
{
	struct node *ptr1, *temp1;
	int i, item;
	cout << "\nEnter value of node to be deleted: ";
	cin >> item;
	
	if (start->info == item)
	{
		temp1 = start;
		start = start->next;
		start->prev = NULL;
		cout << "\nDeleted Successfully";
		free(temp1);
		return;
		getchar();
	}

	ptr1 = start;
	while ((ptr1->next)->next != NULL)
	{
		if ((ptr1->next)->info == item)
		{
			temp1 = ptr1->next;
		}
	}
}

void Doublylist::display()
{
	struct node* disp;
	if (start == NULL)
	{
		cout << "Empty List";
		return;
	}
	disp = start;
	cout << "\nLinked List is: ";
	while (disp != NULL)
	{
		cout << disp->info << "->";
		disp = disp->next;
	}

	cout << "NULL";
}