#include<iostream>
#include<vector>

using namespace std;


int main() {

	vector<int> integers(5);

	cout << "Vector of integers was instatiated with " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;


	integers.push_back(666);

	cout << "After inserting an aditional element.... " << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;

	integers.push_back(777);


	cout << "After inserting yet another element..." << endl;
	cout << "Size: " << integers.size();
	cout << ", Capacity: " << integers.capacity() << endl;



	return 0;
}