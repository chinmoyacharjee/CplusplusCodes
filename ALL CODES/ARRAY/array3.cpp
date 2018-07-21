#include <iostream>

using namespace std;

/*
// problem with global array
#define SIZE 4096*4096
int n=4096*4096;
int globalArray[SIZE];
*/

int *dynamicArray;

int main (void)
{
	//dynamic;
	int n = 4096*4096;
	//++;
	dynamicArray = new int [n];
	
	for(int i=0; i<n; i++)
	{
		dynamicArray[i]=123;
	}
	
	delete [] dynamicArray;
	
	/*
	// problem with global array
	for(int i=0; i<n; i++) //>>>>>>>***NEVER DO THIS***<<<<<<<<  use SIZE for n instead.
	{
		globalArray[i]=123;
	}
	*/
	
	/*
	// problem with local array
	int n = 4096*4096;
	int localArray[n]; //>>>>>>>***NEVER DO THIS***<<<<<<<<
	for(int i=0; i<100; i++)
	{
		localArray[i]=123;
	}
	*/
	return 0;
}
