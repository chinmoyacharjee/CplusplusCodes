#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>

using namespace std;

struct content
{
	float number;
	char symbol;
	bool flag;
};

char operators[6] = {'+','-','*','/','(',')'};

void replaceSymbols(string &numbers)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0; j<numbers.length(); j++)
		{
			if(operators[i]==numbers[j]) numbers[j] = ' ';
		}
	}
}

void makeContentWithNumber(content &node, float numberObtained)
{
	node.number = numberObtained;
	node.flag = true;
}

void makeContentWithSymbol(content &node, char symbolFromInputStringArray)
{
	node.symbol = symbolFromInputStringArray;
	node.flag = false;
}

void parsingInput(string inputString, vector <content> &infix)
{
	string numbers = inputString;
	replaceSymbols(numbers);
	
	istringstream iss(numbers);
	
	vector <float> numbersObtained;
	float temp;
	while (iss >> temp)
	{
		numbersObtained.push_back(temp);
	}
	
	
	for(int i=0; i<numbers.size(); i++)
	{
		if(numbers[i]== ' ')
		{
			if(i != 0)
			{
				if(numbers[i-1] != ' ')
				{
					content node;
					makeContentWithNumber(node, numbersObtained[0]);
					infix.push_back(node);
					numbersObtained.erase(numbersObtained.begin());
					
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
				else
				{
					content node;
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
			}
			else
			{
				//jodi amra 0 tomo jaigate space pai
				content node;
				makeContentWithSymbol(node, inputString[i]);
				infix.push_back(node);
			}
		}
	}
	
	if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumber(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	}
	
}

bool lowerPrecedence(char infixSymbol , char stackSymbol)
{
	if((infixSymbol=='*'||infixSymbol=='/')&&(stackSymbol=='+'||stackSymbol=='-')) return true;
	else return false;
}

void infixToPostfix(vector <content> infix, vector <content> &postfix)
{
	stack <content> myStack;
	
	content node;
	makeContentWithSymbol(node, '(');
	myStack.push(node);
	makeContentWithSymbol(node, ')');
	infix.push_back(node);
	
	for(int i=0; i<infix.size(); i++)
	{
		if(infix[i].flag)
		{
			postfix.push_back(infix[i]);
		}
		else
		{
			if(infix[i].symbol == '(')
			{
				myStack.push(infix[i]);
			}
			else if(infix[i].symbol == ')')
			{
				while(1)
				{
					content tempNode = myStack.top();
					if(tempNode.symbol == '(')
					{
						myStack.pop();
						break;
					}
					else
					{
						postfix.push_back(tempNode);
						myStack.pop();
					}
				}
			}
			else
			{
				while(1)
				{
					content tempNode1= myStack.top();
					if(lowerPrecedence(infix[i].symbol, tempNode1.symbol)|| tempNode1.symbol == '(') break;
					postfix.push_back(tempNode1);
					myStack.pop();
				}
				myStack.push(infix[i]);
			}
		}
	}
}

float evaluateBasicArithmetic(float a, float b, char symbol)
{
	switch(symbol)
	{
		case '+': return b+a;
		case '-': return b-a;
		case '*': return b*a;
		default: return b/a;
	}
}

float evaluatePostfix(vector <content> postfix)
{
	stack <float> myStack;
	
	for(int i=0; i<postfix.size(); i++)
	{
		if(postfix[i].flag)
		{
			myStack.push(postfix[i].number);
		}
		else
		{
			float stackTop0, stackTop1, result;
			stackTop0 = myStack.top();
			myStack.pop();
			stackTop1 = myStack.top();
			myStack.pop();
			
			result = evaluateBasicArithmetic(stackTop0, stackTop1, postfix[i].symbol);
			myStack.push(result);
		}
	}
	return myStack.top();
}

void printExpression(vector <content> expVec)
{
	for(int i=0; i<expVec.size(); i++)
	{
		if(expVec[i].flag) cout << expVec[i].number << " ";
		else cout << expVec[i].symbol << " ";
	}
	cout << endl;
}

int main (void)
{
	string inputString;
	getline(cin, inputString);
	
	vector <content> infix;
	parsingInput(inputString, infix);
	
	cout << "Infix is: ";
	printExpression(infix);
	
	vector <content> postfix;
	infixToPostfix(infix, postfix);
	
	cout << "Postfix is: ";
	printExpression(postfix);
	
	cout << "Result is: " << evaluatePostfix(postfix) << endl;
	
	return 0;
}

