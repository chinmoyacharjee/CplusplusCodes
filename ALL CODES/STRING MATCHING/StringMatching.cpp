#include <iostream>
#include <string>

using namespace std;

void construtFailureFunction(int *failureFunction, string pattern)
{
	failureFunction[0] = 0;
	int k = 0;
	for(int q=1; q<pattern.length(); q++)
	{
		while ((k>0) && (pattern[k] != pattern[q]))
			k = failureFunction[k];
		if(pattern[k] == pattern[q])
			k++;
		failureFunction[q] = k;
	}
}

void kmpMatch(int *failureFunction, string pattern, string text)
{
	int q = 0;
	for(int i=0; i<text.length(); i++)
	{
		cout << q << " " << i << endl;
		while((q>0)&&(pattern[q] != text[i]))
			q = failureFunction[q];
		if(pattern[q] == text[i])
			q++;
		if(q == pattern.length()) 
		{
			cout << "Match at shift " << i-pattern.length()+1 << endl;
			q--; /*boundary condition*/ 
			q = failureFunction[q];
		}
	}
}

void kmp(string text, string pattern)
{
	int *failureFunction;
	failureFunction = new int [pattern.length()];
	
	construtFailureFunction(failureFunction, pattern);
	kmpMatch(failureFunction, pattern, text);
	
	/*for (int i=0; i<pattern.length(); i++)
	{
		cout << failureFunction[i] << " ";
	}
	cout << endl;
	*/
	
	delete [] failureFunction;
}

void naiiveProcess1(string text, string pattern)
{
	bool matchFound = false;
	for(int i=0; i<(text.length()-pattern.length()+1); i++)
	{
		if(pattern.compare(text.substr(i,pattern.length())) == 0)
		{
			cout << "Found a match with shift " << i+1 << endl;	
			matchFound = true;
		}
	}
	
	if(!matchFound) cout << "No Match Found" << endl;
}

void naiiveProcess(string text, string pattern)
{
	bool matchFound = false;
	
	for(int i=0; i<(text.length()-pattern.length()+1); i++) //shift
	{
		bool matched = true;
		for(int j=0; j<pattern.length(); j++)
		{
			if(pattern[j] != text[j+i])
			{
				matched = false;
				break;
			}
		}
		if(matched)
		{
			cout << "Found a match with shift " << i+1 << endl;
			matchFound = true;
		}
	}
	
	if(!matchFound) cout << "No Match Found" << endl;
}

int main (void)
{
	string pattern, text;
	
	getline(cin, text);
	getline(cin, pattern);
	
	//naiiveProcess(text, pattern);
	//naiiveProcess1(text, pattern);
	kmp(text, pattern);
	
	return 0;
}
