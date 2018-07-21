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
	for(node *current = head; current != NULL; current = current[0].next)	
	{
		if(searchKey >= current[0].data) 
		{
			return current[0].previous;
		}
	}
	return NULL;
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

int main (int argc, char *argv[])
{
	createLinkList();
	if(!readFromFileAndInitialize(argv[1])) return -1;
	traverseListForward();

	/*
	insert into sorted
	insert before item
	insert after item
	
	deleteItem
	deletePrevious
	deleteNext
	deleteFirst
	deleteLast
	destroyList
	*/
/*	
	traverseListBackward();

	node *previousElement = searchForPrevious(111);
	printElement(previousElement);
	node *nextElement = searchForNext(111);
	printElement(nextElement);
*/
	destroyList();
	return 0;
}
