#include <iostream>


using namespace std;

int fibonacci(int n)
{
	if (n==0)
	{
		return 0;
	}
	else if (n==1)
	{
		return 1;
	}
	else
	{
		int result = fibonacci(n-1) + fibonacci(n-2);
		return result;
	}
}

int factorial(int n)
{
	if (n==0) return 1;
	else return n*factorial(n-1);
}


int main (void)
{
	// cout << fibonacci(10) << endl;
	
	cout << factorial(10) << endl;
	return 0;
}
