#include <iostream>
#include <stack>

using namespace std;

int main (void)
{
	stack <int> myStack;
	
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);
	
	cout << "Size is " << myStack.size() << endl << endl;
	
	while(!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}
	
	return 0;
}
