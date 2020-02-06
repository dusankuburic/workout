#include<deque>
#include<iostream>
#include<algorithm>


using namespace std;

int main() {

	deque<int> intDeque;


	intDeque.push_back(3);
	intDeque.push_back(4);
	intDeque.push_back(5);


	intDeque.push_front(2);
	intDeque.push_front(1);
	intDeque.push_front(0);

	cout << "The contenst of the deque after inserting elements ";
	cout << "at the top bottom are: " << endl;

	for (size_t count = 0; count < intDeque.size(); ++count) {
		cout << "Element[" << count << "] =";
		cout << intDeque[count] << endl;
	}

	cout << endl;

	intDeque.pop_front();

	intDeque.pop_back();

	cout << "The contents of the deque after erasing an elemnt ";
	cout << "from the top and bottom are: " << endl;


	for (auto element = intDeque.begin(); element != intDeque.end(); ++element) {
		
		size_t Offset = distance(intDeque.begin(), element);
		cout << "Element [" << Offset << "] =" << *element << endl;
	}


	return 0;
}