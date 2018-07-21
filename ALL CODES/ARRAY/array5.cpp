#include <iostream>

using namespace std;

int size;
int filledTo;
int *arr;

void traversalAndInitialize(void)
{
	//dynamically crate
	size =10;
	arr = new int[size];
	
	
	//traversal
	for(int i=0; i<size; i++)
	{
		arr[i] =i;
	}
/*	
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
*/	
	filledTo = size-1;
}

void enlargeArray(void)
{
	int sizeNew = 2*size;
	int* arrNew = new int [sizeNew];
	
	for(int i=0; i<=filledTo; i++)
		arrNew[i] = arr[i];
		
	int *arrOld = arr;
	arr = arrNew;
	delete [] arrOld;
	
	size = sizeNew;
}

void deleteArray(void)
{
	//dynamically destroy
	delete [] arr;
}

int search(int value)
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

void makeSpaceAt(int index)
{
	for(int i=filledTo+1; i>=index; i--)
	{
		arr[i]=arr[i-1];
	}
	filledTo++;
}

bool isItFull(void)
{
	if(filledTo == size-1) return true;
	else return false;
}

bool insertAfterValue(int itemToBeInserted, int afterValue)
{
	int index = search(afterValue);
	if (index == -1) 
	{
		cout << "Array does not contain " << afterValue << endl;
		return false;
	}
	
	if (isItFull()) enlargeArray();
	
	makeSpaceAt(index+1);
	arr[index+1] = itemToBeInserted;
	return true;
}

bool insertBeforeValue(int itemToBeInserted, int beforeValue)
{
	int index = search(beforeValue);
	if (index == -1) 
	{
		cout << "Array does not contain " << beforeValue << endl;
		return false;
	}
	
	if (isItFull()) enlargeArray();
	
	makeSpaceAt(index);
	arr[index] = itemToBeInserted;
	return true;
}

bool insertAtIndexPosition(int itemToBeInserted, int index)
{
	if (index<0)
	{
		cout << "Faul index des ken mama?" << endl;
		return false;
	}
	
	if (index > filledTo+1) 
	{
		cout << "Cannot be inserted here (Fokla dater case)" << endl;
		return false;
	}
	
	if (isItFull()) enlargeArray();
	
	if(index <= filledTo) 
	{
		makeSpaceAt(index);
	}
	else 	traversalAndInitialize();
	{
		filledTo++;
	}
	
	arr[index] = itemToBeInserted;
	
	return true;
}



bool insertAtEnd(int itemToBeInserted)
{
	if (isItFull()) enlargeArray();
	filledTo++;
	arr[filledTo]= itemToBeInserted;
	return true;
}

bool insertAtBeginning(int itemToBeInserted)
{	traversalAndInitialize();
	if (isItFull()) enlargeArray();
	
	makeSpaceAt(0);
		
	arr[0]= itemToBeInserted;

	return true;
}

int searchWhileSorted(int value)
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
		else if(arr[mid] < value)	//traversalAndInitialize();
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

void printArray()
{
	for(int i=0; i<=filledTo; i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << "Size " << size << " Fill " << filledTo+1 << endl;
}

void shrinkArray(void)
{
	if(size == 10) return;
	
	int sizeNew = size/2;
	int* arrNew = new int [sizeNew];
	
	for(int i=0; i<=filledTo; i++)
		arrNew[i] = arr[i];
		
	int *arrOld = arr;
	arr = arrNew;
	delete [] arrOld;
	
	size = sizeNew;
}

bool deleteAtIndex(int index)
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
	
	if(2*(filledTo+1) == size) shrinkArray();
	return true;
}

bool deleteLast(void)
{
	int element = arr[filledTo];
	
	if(deleteAtIndex(filledTo))
	{
		cout << "Deleted element: " << element << endl; 
		return true;
	}
	else return false;
}

bool deleteFirst(void)
{
	int element = arr[0];
	
	if(deleteAtIndex(0))
	{
		cout << "Deleted element: " << element << endl; 
		return true;
	}
	else return false;
}

bool deleteElement(int element)
{
	if (filledTo == -1)
	{
		cout << "The array is empty" << endl;
		return false;
	}
	
	int index = search(element);
	
	if (index == -1)
	{
		cout << "The element is not in the array" << endl;
		return false;
	}
	
	if(deleteAtIndex(index))
	{
		cout << "Deleted element: " << element << endl; 
	}
	
	return true;
}

bool deleteAllAppearanceOfElement(int element)
{
	if (filledTo == -1)
	{
		cout << "The array is empty" << endl;
		return false;
	}
	
	bool wasDeleted = false;
	
	while(1)
	{
		int index = search(element);
		
		if (index == -1)
		{
			break;
		}
		
		if(deleteAtIndex(index))
		{
			wasDeleted = true; 
		}
	}
	return wasDeleted;
}

bool replace(int elementOld, int elementNew)
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
	traversalAndInitialize();
	
	int itemToBeInserted =500;
	int indexPositionForInsert=5;
	int beforeValue = 12;
	int afterValue =13;
		
	for (int i=0;i<5;i++)
		insertAtEnd(i*20);
	
	cout << "Array Contains" << endl;
	printArray();
	
	for (int i=0;i<17;i++)
	{
		deleteLast();
		cout << "Array Contains" << endl;
		printArray();
	}
		
	
	
	deleteArray();
	
	return 0;
}

/*
	if (deleteAtIndex(7)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteLast()) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteFirst()) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteElement(5)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if (deleteAllAppearanceOfElement(120)) cout << "Deleted" << endl;
	else cout << "Not Deleted" << endl;
	
	if(replace(120, 420)) 
		cout << "Was Replaced" << endl;
	else cout << "Replace Failed. Element could not be found" << endl;
	
	int index = searchWhileSorted(120);
	if (index !=-1) cout << "Found at index position " << index << endl;
	else cout << "Not found" << endl;
*/


/*
	if (insertAtBeginning(itemToBeInserted)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAtEnd(itemToBeInserted)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAtIndexPosition(itemToBeInserted, indexPositionForInsert)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertBeforeValue(itemToBeInserted, beforeValue)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	
	if (insertAfterValue(itemToBeInserted, afterValue)) 
		cout << "inserted"<< endl;
	else cout << "not inserted" << endl;
	*/
