#include <iostream>

using namespace std;

int main (void)
{
	
	int arr2d [5][5];
	
	int **brr2d;
	brr2d = new int*[5];
	for(int i=0;i<5;i++)
		brr2d[i] = new int [5];
	
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			arr2d[i][j] =i;
			brr2d[i][j] =j;
		}
	}
	
	cout << "a" << endl;
	
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			cout << arr2d[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "b" << endl;
	
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			cout << brr2d[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i=0;i<5;i++)
		delete [] brr2d[i];
	delete [] brr2d;
	/*
	int arr[100];
	
	int *brr;
	brr = new int [100];
	//use	
	delete [] brr;
	*/
	
	return 0;
}
