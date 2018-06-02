#include<bits/stdc++.h>

using namespace std;

int pointer;
int nValues;

struct node{
    bool leaf;
    bool isRoot;
    node *par;
    vector<int> value;
    vector<node*>child;
    node *last;
};

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


node *Root =NULL;

void insert2(int x, node *p);
void insertInParentNode(node *n,int kprime,node *nprime);
node* getNewNode(bool isLeaf,bool isRoot);
node* getTargetNode(node *tNode,int val);
void bfsTraverse(node *tNode);
void insertInLeafNode(node *leafNode, int k, node *p);
void valueOfNodeInBox(node* tNode);

int main (){
    int temp,x;
    cout << "Enter pointer N:";
    cin >> pointer;

    nValues=pointer-1;

    cout << "Enter how many numbers to input:";
    cin >> temp;
    for(int i=0;i<temp;i++){
        cin>> x;
        insert2(x,NULL);
    }
    bfsTraverse(Root);

}
void insertInParentNode(node *n,int kprime,node *nprime){
    if(n->isRoot){
        Root=getNewNode(false,true);
        n->isRoot=false;
        Root->child.push_back(n);
        Root->child.push_back(nprime);
        Root->value.push_back(kprime);
        n->par = Root;
        nprime->par = Root;
    }
    else{
        node *p = n->par;
        int i=0;
        for(i=0;i<p->value.size();i++){
            if(p->value[i]>kprime) break;
        }
        int tmpK;
        node *tmpP;

        for(int j=i;j<p->value.size();j++){
            tmpK = p->value[j];
            tmpP= p->child[j+1];

            p->value[j] = kprime;
            p->child[j+1] =nprime;

            kprime=tmpK;
            nprime = tmpP;
        }
        p->value.push_back(kprime);
        p->child.push_back(nprime);
        nprime->par = p;

        if(p->child.size()>pointer){
             node *pprime = getNewNode(false,false);
            int nbytwoceil = (pointer+1)/2;
            int kdoubleprime = p->value[nbytwoceil-1];
            for(i = nbytwoceil; i<p->value.size();i++){
                pprime->child.push_back(p->child[i]);
                p->child[i]->par = pprime;
                pprime->value.push_back(p->value[i]);
            }
            pprime->child.push_back(p->child[i]);
            p->child[i]->par = pprime;


            p->value.erase(p->value.begin()+nbytwoceil-1,p->value.end());
            p->child.erase(p->child.begin()+nbytwoceil,p->child.end());

            insertInParentNode(p,kdoubleprime,pprime);
        }

    }
}

void insert2(int x,node *p){
    node *leafNode;
    if(Root==NULL){
        Root = getNewNode(true,true);
        leafNode=Root;
    }
    else{
        leafNode = getTargetNode(Root,x);
    }

    int keyValueCount= leafNode->value.size();
    if(keyValueCount<nValues){
        insertInLeafNode(leafNode,x,p);
    }
    else{
        node* leafNode2 = getNewNode(true,false);
        insertInLeafNode(leafNode,x,p);

        leafNode2->last = leafNode->last;
        leafNode2->par = leafNode->par;

        leafNode->last = leafNode2;
        int nbytwoceil=(pointer+1)/2;

        for(int i=nbytwoceil;i<pointer;i++){
            leafNode2->child.push_back(leafNode->child[i]);
            leafNode2->value.push_back(leafNode->value[i]);
        }
        leafNode->value.erase(leafNode->value.begin()+nbytwoceil,leafNode->value.end());
        leafNode->child.erase(leafNode->child.begin()+nbytwoceil,leafNode->child.end());

        int kprime = leafNode2->value[0];
        insertInParentNode(leafNode,kprime,leafNode2);

    }

}

node* getTargetNode(node *tNode,int val){
    if(tNode->leaf) return tNode;
    int i=0;
    for(i=0;i<tNode->value.size();i++){
        if(tNode->value[i]>val){
            break;
        }
    }
    return getTargetNode(tNode->child[i],val); //WHAT HAPPENED??

}

node* getNewNode(bool isLeaf,bool isRoot){
    node *tmp =new node;
    tmp->isRoot= isRoot;
    tmp->leaf= isLeaf;
    tmp->last=NULL;
    return tmp;


}
void insertInLeafNode(node *leafNode, int k, node *p){
    int i;
    for(i=0;i<leafNode->value.size();i++){
        if(k<leafNode->value[i]) break;
    }
    int tmpK;
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
void bfsTraverse(node *tNode){

    q.push(pNode(tNode,true));
    while(!q.empty()){
        pNode p = q.front();
        //printf("  Got pNode ");
        node *temp = p.tNode;
        q.pop();
        valueOfNodeInBox(temp);
        //printf(" printed temp ");
        if(p.nl) printf("\n");
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
void valueOfNodeInBox(node* tNode){
    printf(" [");
    int i ;
     for(i=0; i<tNode->value.size()-1;i++){
        printf("%d|",tNode->value[i]);
    }
    if(tNode->value.size()>0) printf("%d]",tNode->value[i]);
    //printf(" ");
}

