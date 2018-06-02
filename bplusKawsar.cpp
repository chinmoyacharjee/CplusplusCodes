#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
int nVal;
int nPointer;
string search_word;
string test;
bool find_value = false;
ofstream fout, fout1;


struct node {
    bool leaf;
    bool isRoot;
    node *par;
    vector<string>value;
    vector<node*>child;

    node *last;
};

node* getTargetNode(node *tNode, string val){
    if(tNode->leaf) return tNode;
    int i;
    for(i=0;i<tNode->value.size();i++){
        if(tNode->value[i]>val) break;
    }
    return getTargetNode(tNode->child[i],val);
}

node *Root=NULL;
node* getNewNode(bool isLeaf,bool isRoot){
    node* tmp = new node;
    tmp->isRoot = isRoot;
    tmp->leaf = isLeaf;
    tmp->last = NULL;
    return tmp;
}




void insertInParentNode(node *n, string kprime, node *nprime){
    if(n->isRoot){
        Root = getNewNode(false,true);
        n->isRoot=false;

        Root->child.push_back(n);
        Root->child.push_back(nprime);
        Root->value.push_back(kprime);
        n->par = Root;
        nprime->par = Root;
    }else{
        node *p = n->par;
        int i;
        for(i=0;i<p->value.size();i++){
            if(p->value[i]>kprime) break;
        }
        string tmpK;
        node *tmpP;

        for(int j = i; j<p->value.size(); j++){
            tmpK = p->value[j];
            tmpP = p->child[j+1];

            p->value[j] = kprime;
            p->child[j+1] = nprime;

            kprime = tmpK;
            nprime = tmpP;
        }
        p->value.push_back(kprime);
        p->child.push_back(nprime);
        nprime->par = p;


        //printf("\n\np->child size: %d\n\n",p->child.size());

        if(p->child.size()>nPointer){
            node *pprime = getNewNode(false,false);
            int nbytwoceil = (nPointer+1)/2;
            string kdoubleprime = p->value[nbytwoceil];
            for(i = nbytwoceil+1; i<p->value.size();i++){
                pprime->child.push_back(p->child[i]);
                p->child[i]->par = pprime;
                pprime->value.push_back(p->value[i]);
            }
            pprime->child.push_back(p->child[i]);
            p->child[i]->par = pprime;


            p->value.erase(p->value.begin()+nbytwoceil,p->value.end());
            p->child.erase(p->child.begin()+nbytwoceil+1,p->child.end());

            insertInParentNode(p,kdoubleprime,pprime);
        }
    }

}


void insertInLeafNode(node *leafNode, string k, node *p){
    int i;
    for(i=0;i<leafNode->value.size();i++){
        if(k<leafNode->value[i]) break;
    }
    string tmpK;
    node *tmpP;

    for(int j = i; j<leafNode->value.size(); j++){
        tmpP = leafNode->child[j];
        tmpK = leafNode->value[j];

        leafNode->child[j] = p;
        leafNode->value[j] = k;

        p = tmpP;
        k = tmpK;
    }
    leafNode->child.push_back(p);
    leafNode->value.push_back(k);

}


void insert2(string k, node *p){
    node *leafNode;
    if(Root==NULL){
        Root = getNewNode(true,true);
        leafNode = Root;
    }else leafNode = getTargetNode(Root,k);

    int keyValueCount = leafNode->value.size();
    if(keyValueCount<nVal) insertInLeafNode(leafNode,k,p);
    else{
        node* leafNode2 = getNewNode(true,false);
        insertInLeafNode(leafNode,k,p);
        leafNode2->last = leafNode->last;
        leafNode->last=leafNode2;
        int nbytwoceil = (nPointer+1)/2;

        for(int i = nbytwoceil; i<nPointer ; i++){
            leafNode2->child.push_back(leafNode->child[i]);
            leafNode2->value.push_back(leafNode->value[i]);
        }
        leafNode->value.erase(leafNode->value.begin()+nbytwoceil,leafNode->value.end());
        leafNode->child.erase(leafNode->child.begin()+nbytwoceil,leafNode->child.end());

        string kprime = leafNode2->value[0];
        insertInParentNode(leafNode,kprime,leafNode2);
    }
}
void searchFunction(node* tNode){
     int i ;
     search_word="আপেল";
     for(i=0; i<tNode->value.size()-1;i++){
        test = tNode->value[i];
        //fout1 << tNode->value[i] << endl;
        if(test == search_word){
            fout1 << "found" << endl;
            break;
        }

    }

    //printf(" ");
}

void valueOfNodeInBox(node* tNode){

    fout << "[" ;
    int i ;
     for(i=0; i<tNode->value.size()-1;i++){
        fout << tNode->value[i] <<"|";

    }
    if(tNode->value.size()>0) fout << tNode->value[i] << "]";
    //printf(" ");
}

struct pNode{
    node *tNode;
    bool nl;
    pNode(node *Node, bool b){
        tNode = Node;
        nl = b;
    }
    pNode(){

    }
};

queue<pNode>q;
void bfsTraverse(node *tNode){
    cout << tNode->value.size() << endl;
    for(int k=0; k<tNode->value.size(); k++){
        cout << tNode->value[k] << endl;
    }
    q.push(pNode(tNode,true));
    while(!q.empty()){
        pNode p = q.front();
        //printf("  Got pNode ");
        node *temp = p.tNode;
        q.pop();
        valueOfNodeInBox(temp);
        searchFunction(temp);
        //printf(" printed temp ");
        if(p.nl) fout << endl;
        int i;
        if(!temp->leaf){
        for(i=0;i<temp->child.size()-1;i++){
            q.push(pNode(temp->child[i],false));
        }
        //printf(" inserted second last child  ");
        if(p.nl) q.push(pNode(temp->child[i],true));
        else q.push(pNode(temp->child[i],false));
        //printf(" inserted  last child  ");
        }

    }
}

void searchF(string s)
{
    node  *leafnode=getTargetNode(Root,s);
    int i;
    for(i=0;i<leafnode->value.size();++i)
    {
        fout1 << leafnode->value[i] << endl;
        if(leafnode->value[i]==s)
        {
            fout1 << "found" << endl;
            return;
        }
    }
    cout<<"No"<<endl;
}


int main(){
    //cout << "How many values in each node?" << endl;

    ifstream fin, fin1;
    fout.open("english_output.txt");
    fin.open("english.txt");
    fin1.open("search_english.txt");
    fout1.open("search_output.txt");
    fin1 >> search_word;
    //fin >> nPointer;
    nPointer = 4;
    nVal = nPointer-1;


    //cout << "nPointer = " << nPointer << endl;

    string k;
    while(fin>> k){
           // cout << "val: " << k << endl;

            insert2(k,NULL);
    }
    bfsTraverse(Root);
    searchF(search_word);
    /*while(true){
        //cout << "Make your choice." << endl;
        //cout << "Action:"<<endl << "press 1 to insert" << endl << "press 2 to print result in file." << endl << "press 0 for exit" << endl;

        int choice;
        cin >> choice;
        if(choice==1){
            string value;
            cin >> value;
            insert2(value,NULL);
        }else if(choice==2){
            cout << endl << endl << endl;
            bfsTraverse(Root);
            cout << endl << endl << endl;
        }else if(choice==0) break;

    }*/
    fin.close();
    return 0;
}
