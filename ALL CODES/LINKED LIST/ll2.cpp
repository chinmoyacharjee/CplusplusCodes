#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int data;
	node *next;
	node *previous;
};

node *head, *tail;

void createLinkList(void)
{
	head= NULL;
	tail = NULL;
}

node* createNode(int input)
{
	node *temp;
	temp = new node[1];
	temp[0].data = input;
	temp[0].previous = NULL;
	temp[0].next = NULL;
	return temp;
}

void deleteNode(node *anyNode)
{
	delete [] anyNode;
}

void traverseListForward(void)
{
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		cout << current[0].data << endl;
	}
}

void traverseListBackward(void)
{
	for(node *current = tail; current != NULL; current = current[0].previous)	
	{
		cout << current[0].data << endl;
	}
}

void printElement(node *thisNode)
{
	if (thisNode == NULL) cout << "Kichhu nai" << endl;
	else cout << "Contains " << thisNode[0].data << endl;
}

void insertAtBeginning(node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode[0].next = head;
		head[0].previous = newNode;
		head = newNode;
	}
}

void insertAtEnd(node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode[0].previous = tail;
		tail[0].next = newNode;
		tail = newNode;
	}
}

void destroyList(void)
{
	while(head != tail)
	{
		node *current = head;
		head = current[0].next;
		delete [] current;
	}
	
	delete [] tail;
}
	
bool readFromFileAndInitialize(char *fileName)
{
	ifstream iFile;
	iFile.open(fileName);
	if(iFile.is_open())
	{
		int nuberOfInputs;
		iFile >> nuberOfInputs;
		for(int i=0; i<nuberOfInputs; i++)
		{
			int input;
			iFile >> input;
			
			node *newNode = createNode(input);
			
			insertAtEnd(newNode);
			//insertAtBeginning(newNode);
			//insert();
		}
		
		iFile.close();
	}
	else 
	{
		cout << "Could not open file" << endl;
		return false;
	}
	return true;
}

//node* searchForLargerGetPreviousLastToFirst(int searchKey)
node* searchForLargerGetPrevious(int searchKey)
{
	
	if(searchKey <= head[0].data) return NULL;
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		if(searchKey <= current[0].data) 
		{
			//cout << "Test " << current[0].data << endl;
			return current[0].previous;
		}
	}
	return tail;
}

void insertIntoSorted(int newItem)
{
	node *previousNode= searchForLargerGetPrevious(newItem);
	node *newNode = createNode(newItem);
	
	if(previousNode == NULL)
	{
		newNode[0].next = head;
		head[0].previous = newNode;
		head = newNode;
	}
	else if (previousNode == tail)
	{
		newNode[0].previous = tail;
		tail[0].next = newNode;
		tail = newNode;
	}
	else
	{
		newNode[0].previous = previousNode;
		newNode[0].next = previousNode[0].next;	
		previousNode[0].next[0].previous = newNode;	
		previousNode[0].next = newNode;
	}
}

//node* searchForPreviousLastToFirst(int searchKey)
node* searchForPrevious(int searchKey)
{
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		if(searchKey == current[0].data) 
		{
			return current[0].previous;
		}
	}
	return NULL;
}


//node* searchForNextLastToFirst(int searchKey)
node* searchForNext(int searchKey)
{
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		if(searchKey == current[0].data) 
		{
			return current[0].next;
		}
	}
	return NULL;
}

node* searchItem(int searchKey)
{
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		if(searchKey == current[0].data) 
		{
			return current;
		}
	}
	return NULL;
}

void insertBeforeItem(int existingItem, int newItem)
{
	node* currentItem = searchItem(existingItem);
	if (currentItem == NULL)
	{
		cout << "Next item Not found. Cannot be inserted." << endl;
		return ;
	}
	else
	{
		node *newNode = createNode(newItem);
		
		if(currentItem == head)
		{
			newNode[0].next = head;
			head[0].previous = newNode;
			head = newNode;
		}
		else
		{
			newNode[0].previous = currentItem[0].previous;
			newNode[0].next = currentItem;	
			currentItem[0].previous[0].next = newNode;	
			currentItem[0].previous = newNode;
		}
	}
}

void insertAfterItem(int existingItem, int newItem)
{
	node* currentItem = searchItem(existingItem);
	if (currentItem == NULL)
	{
		cout << "Previous item Not found. Cannot be inserted." << endl;
		return ;
	}
	else 
	{
		node *newNode = createNode(newItem);
		
		if(currentItem == tail)
		{
			newNode[0].previous = tail;
			tail[0].next = newNode;
			tail = newNode;
		}
		else
		{
			newNode[0].previous = currentItem;
			newNode[0].next = currentItem[0].next;
			currentItem[0].next[0].previous = newNode;	
			currentItem[0].next = newNode;
		}
	}
}

void deleteFirst(void)
{
	node *moraMama = head;
	head = head[0].next;
	if (head != NULL) head[0].previous = NULL;
	else tail = NULL;
	deleteNode(moraMama);
}

void deleteLast(void)
{
	node *moraMama = tail;
	tail = tail[0].previous;
	if (tail != NULL) tail[0].next = NULL;
	else head = NULL;
	deleteNode(moraMama);
}

void actualNodeDeletion(node *currentItem)
{
	if (currentItem == NULL)
	{
		cout << "Item not in the list, canot be deleted" << endl;
		return ;
	}
	else if (currentItem == head)
	{
		deleteFirst();
	}
	else if (currentItem == tail)
	{
		deleteLast();
	}
	else
	{
		currentItem[0].previous[0].next = currentItem[0].next;
		currentItem[0].next[0].previous = currentItem[0].previous;
		deleteNode(currentItem);
	}
}

void deleteItem(int item)
{
	node *currentItem = searchItem(item);
	actualNodeDeletion(currentItem);
}

void deletePrevious(int item)
{
	node *currentItem = searchItem(item);
	if(currentItem != NULL) actualNodeDeletion(currentItem[0].previous);
	else actualNodeDeletion(NULL);
}

void deleteNext(int item)
{
	node *currentItem = searchItem(item);
	if(currentItem != NULL) actualNodeDeletion(currentItem[0].next);
	else actualNodeDeletion(NULL);
}

int main (int argc, char *argv[])
{
	createLinkList();
	if(!readFromFileAndInitialize(argv[1])) return -1;
	
	traverseListForward();

/*
	insertIntoSorted(10009); //insert into sorted
	insertBeforeItem(36,99); //insert before item
	insertAfterItem(10, 13); //insert after item
	
	deleteItem(10000); //deleteItem
	deletePrevious(10000); //deletePrevious ->
	deleteNext(33); //deleteNext
	deleteFirst(); //deleteFirst
	deleteLast(); //deleteLast

	traverseListBackward();

	node *previousElement = searchForPrevious(111);
	printElement(previousElement);
	node *nextElement = searchForNext(111);
	printElement(nextElement);
*/
	destroyList();
	return 0;
}
