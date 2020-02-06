#include<stack>
#include<vector>

using namespace std;

int main()
{
	stack<int> numsInStack;

	stack<double> dblsInStack;

	stack<double, vector<double>> doublesStackedInVec;

	stack<int> numsInStackCopy(numsInStack);

}