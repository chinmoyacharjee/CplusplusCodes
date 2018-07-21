#include <iostream>

using namespace std;

int traversalAndInitialize(int *arr, int size)
{
	//traversal
	for(int i=0; i<size; i++)
	{
		arr[i] =-1;
	}
	
	//initialize
	for(int i=0; i<10; i++)
	{
		arr[i] =i*5;
	}
	int filledTo = 9;
	return filledTo;
}

int search(int* arr, int filledTo, int value)
{
	for(int i=0; i<=filledTo; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void makeSpaceAt(int *arr, int index, int &filledTo)
{
	for(int i=filledTo+1;i>=index;i--)
	{
		arr[i]=arr[i-1];
	}
	filledTo++;
}

bool isItFull(int size, int filledTo)
{
	if(filledTo == size-1) return true;
	else return false;
}

bool boundaryCheckingWithIndex(int size, int filledTo, int index)
{
	if(isItFull(size, filledTo) || (index <0)) return true;
	else return false;
}

bool insertAfterValue(int* arr, int size, int &filledTo, int itemToBeInserted, int afterValue)
{
	if (isItFull(size, filledTo)) return false;
	int index = search(arr, filledTo, afterValue);
	if (index == -1) 
	{
		cout << "Array does not contain " << afterValue << endl;
		return false;
	}
	
	makeSpaceAt(arr, index+1, filledTo);
	arr[index+1] = itemToBeInserted;
	return true;
}

bool insertBeforeValue(int* arr, int size, int &filledTo, int itemToBeInserted, int beforeValue)
{
	if (isItFull(size, filledTo)) return false;
	int index = search(arr, filledTo, beforeValue);
	if (index == -1) 
	{
		cout << "Array does not contain " << beforeValue << endl;
		return false;
	}
	
	makeSpaceAt(arr, index, filledTo);
	arr[index] = itemToBeInserted;
	return true;
}

bool insertAtIndexPosition(int* arr, int size, int &filledTo, int itemToBeInserted, int index)
{
	if (boundaryCheckingWithIndex(size, filledTo, index)) return false;
	if (index > filledTo+1) 
	{
		cout << "Cannot be inserted here" << endl;
		return false;
	}
	
	if(index <= filledTo) 
	{
		makeSpaceAt(arr, index, filledTo);
	}
	else 
	{
		filledTo++;
	}
	
	arr[index] = itemToBeInserted;
	
	return true;
}

bool insertAtEnd(int* arr, int size, int &filledTo, int itemToBeInserted)
{
	if (isItFull(size, filledTo)) return false;
	filledTo++;
	arr[filledTo]= itemToBeInserted;
	return true;
}

bool insertAtBeginning(int* arr, int size, int &filledTo, int itemToBeInserted)
{
	if (isItFull(size, filledTo)) return false;
	

	makeSpaceAt(arr, 0, filledTo);
	
	/*
	for(int i=filledTo+1;i>0;i--)
	{
		arr[i]=arr[i-1];
	}
	filledTo++;
	*/
	arr[0]= itemToBeInserted;

	return true;
}

void printArray(int *arr, int size, int filledTo)
{
	for(int i=0; i<=filledTo; i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << "Size " << size << " Fill " << filledTo+1 << endl;
}

/*
int searchWhileSorted(int* arr, int filledTo, int value)
//sort
//delete
*/

int main (void)
{
	int size =100;
	int arr[100];
	int filledTo = traversalAndInitialize(arr, size);
	
	/*
	1. at beginning
	2. at end
	3. after a value
	4. before a value
	5. at index position
	
	int itemToBeInserted = 500;
	int afterValue = 35, beforeValue = 15;
	int indexPositionForInsert =-22;
	
	if (insertAtBeginning(arr, size, filledTo, itemToBeInserted)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAtEnd(arr, size, filledTo, itemToBeInserted)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAfterValue(arr, size, filledTo, itemToBeInserted, afterValue)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertBeforeValue(arr, size, filledTo, itemToBeInserted, beforeValue)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAtIndexPosition(arr, size, filledTo, itemToBeInserted, indexPositionForInsert)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	*/
	
	
	
	
	
	cout << "Array Contains" << endl;
	printArray(arr, size, filledTo);
	
	return 0;
}
