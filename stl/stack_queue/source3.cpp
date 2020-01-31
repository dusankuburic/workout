#include<queue>
#include<list>

using namespace std;


int main()
{

	queue<int> numsInQ;

	queue<double> dblsInQ;

	queue<double, list<double>> dblsInQInList;

	queue<int> copyQ(numsInQ);

	return 0;
}