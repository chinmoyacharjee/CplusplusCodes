#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct node
{
	node *parent;
	int data;
	int degree;
	node *left, *right;
	//node *child;
	//node *sibling;
};

node *root;

void createTree(void)
{
	root= NULL;
}

node* createNode(int input)
{
	node *temp;
	temp = new node[1];
	temp[0].parent = NULL;
	temp[0].data = input;
	temp[0].degree = 0;node *parent;
	int data;
	int degree;
	node *left, *right;
	//node *child;
	//node *sibling;
	temp[0].left = NULL;
	temp[0].right = NULL;
	//temp[0].child = NULL;
	//temp[0].sibling = NULL;
	return temp;
}

void destroyNode(node *anyNode)
{
	delete [] anyNode;
}

bool compareNodes(node *newNode, node *current)
{
	if(newNode[0].data > current[0].data) return true;
	else return false;
}

//void deleteNode(node *newNode)

void insertNode(node *newNode)
{
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	else
	{
		node * current = root;
		bool flag = false;
		
		while(1)
		{
			if(compareNodes(newNode, current))
			{
				if(current[0].right != NULL)
				{
					current = current[0].right;
				}
				else
				{
					flag = true;
					break;
				}
			}
			else
			{
				if(current[0].left != NULL)
				{
					current = current[0].left;
				}
				else
				{
					break;
				}
			}
		}
		
		if(flag)
		{
			current[0].right = newNode;
			newNode[0].parent = current;
			newNode[0].parent[0].degree++;
			//currnt[0].degree++	
		}
		else
		{
			current[0].left = newNode;
			newNode[0].parent = current;
			newNode[0].parent[0].degree++;
			//currnt[0].degree++
		}
	}
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
			
			insertNode(newNode);
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

stack <node*> qutubStack;

void fillupStack(node *ptr)
{
	while(ptr != NULL)
	{
		qutubStack.push(ptr);
		ptr = ptr[0].left;
	}
}

void traverseInOrder(void)
{
	node *ptr = root;
	
	fillupStack(ptr);
	
	while(!qutubStack.empty())
	{
		ptr = qutubStack.top();
		qutubStack.pop();
		
		cout << ptr[0].data << endl;
		
		if(ptr[0].right !=NULL)
		{
			ptr = ptr[0].right;
			fillupStack(ptr);
		}
	}
}

void traverseInOrderRecursive(node *current)
{
	if(current != NULL)
	{
		traverseInOrderRecursive(current[0].left);
		cout << current[0].data << endl;
		traverseInOrderRecursive(current[0].right);
	}
}

/*
void traversePreOrder(void);
void traversePostOrder(void);
*/

bool searchItem(int searchKey)
{node *parent;
	int data;
	int degree;
	node *left, *right;
	//node *child;
	//node *sibling;
	node *current = root;
	
	while(current != NULL)
	{
		if(current[0].data == searchKey)
		{
			return true;
		}
		else if(current[0].data < searchKey)
		{
			current = current[0].right;
		}
		else 
		{
			current = current[0].left;
		}
	}
	
	return false;
}
node *z = NULL;
bool searchItemRecursive(int searchKey, node *current)
{
	if(current == NULL) return false;
	else if(searchKey == current[0].data){z = current; return true;}
	else if(searchKey > current[0].data)
	{
		return searchItemRecursive(searchKey, current[0].right);
	}
	else 
	{
		return searchItemRecursive(searchKey, current[0].left);
	}
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int findMin(void)
{
	node *current = root;
	
	while(current[0].left != NULL)
		current = current[0].left;
	
	return current[0].data;
}

int findMax(void)
{
	node *current = root;
	
	while(current[0].right != NULL)
		current = current[0].right;
	
	return current[0].data;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
 
void deleteNode(int n)
{	
	node *y, *x, *w;
	bool flag = searchItemRecursive(n, root);

	if(z[0].left == NULL || z[0].right == NULL)
	{
		y = z;	
	}
	else
	{
		y = z[0].right;
		//w = z[0].right; 		
	}
	
	if(y[0].left != NULL)
	{
		x = y[0].left;
	}	
	else
	{
		x = y[0].right;
	}
	
	
	if(x != NULL)
	{
		x[0].parent = y[0].parent;
	}
	
	
	if(y[0].parent == NULL) 
	{
		root = x;
	}
	
	else if(y[0].parent[0].left == y) 
	{
		y[0].parent[0].left = x;
	}
	else
	{
		y[0].parent[0].right = x;
	}
	
	
	if( y != z)
	{
		z[0].data = y[0].data;
	}
	
	
	
}

int main (int argc, char *argv[])
{
	createTree();
	if(!readFromFileAndInitialize(argv[1])) return -1;
	deleteNode(97);
	traverseInOrder();
	
	//node *start = root;
	//traverseInOrderRecursive(start);
	
	//int searchKey = 15;
	
	//if(searchItem(searchKey)) cout << "ase" << endl;
	//else cout << "nai" << endl;
	
	//node *current = root;
	//if(searchItemRecursive(searchKey, current)) cout << "ase" << endl;
	//else cout << "nai" << endl;

	//cout << findMin() << endl;
	//cout << findMax() << endl;


	//destroyList();
	return 0;
}

