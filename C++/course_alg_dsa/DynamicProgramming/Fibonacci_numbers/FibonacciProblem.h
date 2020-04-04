#include<vector>
using std::vector;

class FibonacciAlgorithm {

	vector<int> memorizeTable;
public:
	FibonacciAlgorithm();

	int fibonacciMemorize(int n);
	int naiveFibonacci(int n);
};