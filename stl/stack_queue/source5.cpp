#include<queue>
#include<functional>


using namespace std;

int main()
{

	priority_queue<int> numsInPrioQ;

	priority_queue<double> dblsInPrioQ;

	priority_queue<int, deque<int>, greater<int>> numsInDescendingQ;

	priority_queue<int> copyQ(numsInPrioQ);


	return 0;
}