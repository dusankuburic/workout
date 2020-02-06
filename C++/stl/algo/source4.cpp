#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;


int main() {


	vector<int> numsInVec(3);

	fill(numsInVec.begin(), numsInVec.end(), 9);
	numsInVec.resize(6);

	fill_n(numsInVec.begin() + 3, 3, -9);
	
	cout << "Contents of the vector are: " << endl;
	for (size_t index = 0; index < numsInVec.size(); ++index) {

		cout << "Element[" << index << "] = ";
		cout << numsInVec[index] << endl;
	}


	return 0;

}