// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    char data;
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(char data)
{
    TrieNode *pNode =  new TrieNode;

    pNode->data = data;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) //stored the value at the corresponding alphabet's number.. like a = 1, b = 2, m = 13 etc;
             pCrawl->children[index] = getNode(key[i]);

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void travarse(struct TrieNode *node, string str, vector<string> &arr){
    if(node==NULL)
        return;
    if(node->data!=NULL)
        str = str + (char)(node->data);
    if(node->isEndOfWord){
        arr.push_back(str);

    }
    for(int i=0;i<26;i++){
        travarse(node->children[i],str,arr);

    }

}

vector<string> travarse2(struct TrieNode *node, string str, vector<string> arr){
    if(node==NULL)
        return arr;
    if(node->data!=NULL)
        str = str + (char)(node->data);
    if(node->isEndOfWord){
        arr.push_back(str);

    }
    for(int i=0;i<26;i++){
        return travarse(node->children[i],str,arr);

    }
    //return arr;
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]); //length of key

    struct TrieNode *root = getNode(NULL);

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    /*search(root, "their")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "their")? cout << "Yes\n" :
                           cout << "No\n";
    */
    vector<string> arr=travarse2(root,"",arr);
    travarse(root,"",arr);
    for(int i=0;i<arr.size();i++){

        cout<<arr[i]<<endl;
    }
    return 0;
}
