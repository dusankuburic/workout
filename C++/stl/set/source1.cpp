#include<set>

using namespace std;


template<typename T>
struct SortDescending
{
	bool operator()(const T& lhs, const T& rhs) const {
		return (lhs > rhs);
	}
};


int main() {

	set<int> setInts1;
	multiset<int> msetInts1;


	set<int, SortDescending<int>> setInts2;
	multiset<int, SortDescending<int>> msetInts2;


	set<int> setInts3(setInts1);
	multiset<int> msetInts3(setInts1.cbegin(), setInts1.cend());

	return 0;
}