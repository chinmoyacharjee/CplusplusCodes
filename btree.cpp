#include <bits/stdc++.h>
using namespace std;
struct BTreeNode{

    string *data;
    BTreeNode **child_ptr;
    bool leaf;
    int n;

}*root = NULL, *np = NULL, *x = NULL;


BTreeNode *init(){

    int i;
    np = new BTreeNode;
    np->data = new string[5];
    np->child_ptr = new BTreeNode *[6];
    np->leaf = true;
    np->n = 0;

    for (i = 0; i < 6; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;

}

void traverse(BTreeNode *p){

    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->data[i];
    }
    cout<<endl;

}

bool search(BTreeNode *p, string k){

	int i;
	if(p==NULL) return false;

    for (i = 0; i < (p->n); i++)
    {
    	if( k == p->data[i]) return true;
        else if ((k > p->data[i]) && (k < p->data[i + 1]))
        {
           // i++;
            break;
        }
        else if (k < p->data[0])
        {
            break;
        }
    }

    p = p->child_ptr[i];
    return search(p,k);
}


string split_child(BTreeNode *x, int i){

    int j;
    string mid;
    BTreeNode *np1, *np3, *y, *z;
    np3 = init();
    np3->leaf = true;

    if (i == -1){

        mid = x->data[2];
        x->data[2] = "";
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        for (j = 3; j < 5; j++){

            np3->data[j - 3] = x->data[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->data[j] = "";
            x->n--;

        }
        for(j = 0; j < 6; j++){

            x->child_ptr[j] = NULL;

        }
        np1->data[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else{

        y = x->child_ptr[i];
        mid = y->data[2];
        y->data[2] = "0";
        y->n--;
        for (j = 3   ; j < 5; j++){

            np3->data[j - 3] = y->data[j];
            np3->n++;
            y->data[j] = "0";
            y->n--;

        }

        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 2] = np3;
    }
    return mid;
}
void insert(string a){
    int i;
    string temp;
    x = root;
    if (root == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->leaf == true && x->n == 5)
        {
            temp = split_child(x, -1);
            x = root;
            for (i = 0; i < (x->n); i++ )
            {
                if ((a > x->data[i]) && (a < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < x->data[0])
                {
                    break;
                }
            }
            x = x->child_ptr[i];
        }
        else
        {
            while (x->leaf == false)
            {
	            for (i = 0; i < (x->n); i++)
	            {
	                if ((a > x->data[i]) && (a < x->data[i + 1]))
	                {
	                    i++;
	                    break;
	                }
	                else if (a < x->data[0])
	                {
	                    break;
	                }


	            }
                if ((x->child_ptr[i])->n == 5)
                {
                    temp = split_child(x, i);
                    x->data[x->n] = temp;
                    x->n++;
                    continue;
                }
                else
                {
                    x = x->child_ptr[i];
                }
            }
        }
    }
    x->data[x->n] = a;
    for(int i = 0; i <= x->n; i++){
        for(int j = 0; j <= x->n - 1; j++){
            if(x -> data[j] > x -> data[j + 1])
                swap(x -> data[j], x -> data[j + 1]);
        }
    }
    x->n++;

//    cout << a << " inserted" << endl;
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i, n;
    string str;
    while(cin>>str)
    {
        cout<<"Inserting "<<str<<endl;
        insert(str);
        cout<<"After inserting ::::"<<str<<endl;
        traverse(root);
    }
    //traverse(root);

   if(search(root,"অংশিত")) puts(" অংশিত Found");
    else puts("অংশিত  Not Found");

  /*  if(search(root,"অংশীদারি")) puts("অংশীদারি  Found");
    else puts("অংশীদারি  Not Found");

    if(search(root,"অংশী")) puts("অংশী  Found");
    else puts("অংশী  Not Found");
*/
}
