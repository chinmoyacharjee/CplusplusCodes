#include <iostream>
#include <queue>

using namespace std;

int main (void)
{
	queue <int> mQ;
	
	mQ.push(1);
	mQ.push(2);
	mQ.push(3);
	mQ.push(4);
	mQ.push(5);
	
	cout << "size " << mQ.size() << " front " << mQ.front() << " back " << mQ.back() << endl << endl;
	
	while(!mQ.empty())
	{
		cout << mQ.front() << endl;
		mQ.pop();
	}
	
	
	return 0;
}
