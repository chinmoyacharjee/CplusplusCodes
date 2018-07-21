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
	for(int i=0; i<20; i++)
	{
		//if(i%2==0) arr[i] =123;
		//else 
		arr[i] =i*20;
	}
	
	//==?!
	for(int i=5; i<=8; i++)
	{
		arr[i] = 120;
	}
	//==?!
	
	int filledTo = 19;
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

int searchWhileSorted(int* arr, int filledTo, int value)
{
	int index =-1;
	
	int low=0, high=filledTo;
	
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		if(arr[mid] == value)
		{
			index = mid;
			break;
		}
		else if(arr[mid] < value)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	
	if(index !=-1)
	{
		while(arr[index-1] == arr[index] && index > 0)
		{
			index--;
		}
	}
	return index;
}

void printArray(int *arr, int size, int filledTo)
{
	for(int i=0; i<=filledTo; i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << "Size " << size << " Fill " << filledTo+1 << endl;
}



bool deleteAtIndex(int *arr, int index, int size, int &filledTo)
{
	if(index > filledTo || index < 0)
	{
		cout << "Invalid index" << endl;
		return false;
	}
	
	for(int i=index; i<filledTo; i++)
	{
		arr[i] = arr[i+1];
	}
	
	filledTo--;
	return true;
}

bool deleteLast(int *arr, int size, int &filledTo)
{
	int element = arr[filledTo];
	
	if(deleteAtIndex(arr, filledTo, size, filledTo))
	{
		cout << "Deleted element: " << element << endl; 
		return true;
	}
	else return false;
}

bool deleteFirst(int *arr, int size, int &filledTo)
{
	int element = arr[0];
	
	if(deleteAtIndex(arr, 0, size, filledTo))
	{
		cout << "Deleted element: " << element << endl; 
		return true;
	}
	else return false;
}

bool deleteElement(int *arr, int element, int size, int &filledTo)
{
	if (filledTo == -1)
	{
		cout << "The array is empty" << endl;
		return false;
	}
	
	int index = search(arr, filledTo, element);
	
	if (index == -1)
	{
		cout << "The element is not in the array" << endl;
		return false;
	}
	
	if(deleteAtIndex(arr, index, size, filledTo))
	{
		cout << "Deleted element: " << element << endl; 
	}
	
	return true;
}

bool deleteAllAppearanceOfElement(int *arr, int element, int size, int &filledTo)
{
	if (filledTo == -1)
	{
		cout << "The array is empty" << endl;
		return false;
	}
	
	bool wasDeleted = false;
	
	while(1)
	{
		int index = search(arr, filledTo, element);
		
		if (index == -1)
		{
			break;
		}
		
		if(deleteAtIndex(arr, index, size, filledTo))
		{
			wasDeleted = true; 
		}
	}
	return wasDeleted;
}

bool replace(int *arr, int elementOld, int elementNew, int size, int filledTo)
{
	bool wasReplaced = false;
	
	for(int i=0; i<=filledTo; i++)
	{
		if (arr[i] == elementOld)
		{
			arr[i] = elementNew;
			wasReplaced = true;
		}
	}
	return wasReplaced;
}

int main (void)
{
	int size =100;
	int arr[100];
	int filledTo = traversalAndInitialize(arr, size);
	
	/*
	if (deleteFirst(arr, size, filledTo)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteLast(arr, size, filledTo)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteElement(arr, 15, size, filledTo)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteAtIndex(arr, 7, size, filledTo)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteAllAppearanceOfElement(arr, 123, size, filledTo)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if(replace(arr, 12, 420, size, filledTo)) 
		cout << "Was Replaced" << endl;
	else cout << "Replace Failed. Element could not be found" << endl;
	
	int index = searchWhileSorted(arr, filledTo, 120);
	if (index !=-1) cout << "Found at index position " << index << endl;
	else cout << "Not found" << endl;
	*/
	
	
	
	
	
	cout << "Array Contains" << endl;
	printArray(arr, size, filledTo);
	
	return 0;
}
