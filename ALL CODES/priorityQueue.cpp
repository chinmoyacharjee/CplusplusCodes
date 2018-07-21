#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BicchinotabadiComparison
{
	bool reverse;
	
	public:
		BicchinotabadiComparison(const bool& revparam=false)
    	{
    		reverse=revparam;
    	}
    	bool operator() (const int& lhs, const int&rhs) const
		{
			if (reverse) return (lhs>rhs);
			else return (lhs<rhs);
		}
};


int main (void)
{
	//typedef priority_queue<int, vector<int>, BicchinotabadiComparison> hydaiType;

	//hydaiType pQ(BicchinotabadiComparison(true));
	
	priority_queue <int> pQ;
	
	pQ.push(12);
	pQ.push(11);
	pQ.push(22);
	pQ.push(32);
	pQ.push(2);
	
	cout << "Size " << pQ.size() << endl;
	
	while(!pQ.empty())
	{
		cout << pQ.top() << endl;
		pQ.pop();
	}
	
	
	return 0;
}

