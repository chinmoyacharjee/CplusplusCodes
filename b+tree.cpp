#include<stdio.h>

#include<conio.h>

#include<iostream>

using namespace std;

struct BPlusTreeNode

{

    int *data;

    BPlusTreeNode **child_ptr;

    bool leaf;

    int n;

}*root = NULL, *np = NULL, *x = NULL;

BPlusTreeNode * init(){

    int i;

    np = new BPlusTreeNode;

    np->data = new int[5];

    np->child_ptr = new BPlusTreeNode *[6];

    np->leaf = true;

    np->n = 0;

    for (i = 0; i < 6; i++){

        np->child_ptr[i] = NULL;

    }

    return np;

}

void traverse(BPlusTreeNode *p)

{

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

    if (p->leaf == false)

    {

        traverse(p->child_ptr[i]);

    }

    cout<<endl;

}

void sort(int *p, int n)

{

    int i, j, temp;

    for (i = 0; i < n; i++)

    {

        for (j = i; j <= n; j++)

        {

            if (p[i] > p[j])

            {

                temp = p[i];

                p[i] = p[j];

                p[j] = temp;

            }

        }

    }

}

int split_child(BPlusTreeNode *x, int i)

{

    int j, mid;

    BPlusTreeNode *np1, *np3, *y;

    np3 = init();

    np3->leaf = true;

    if (i == -1)

    {

        mid = x->data[2];

        x->data[2] = 0;

        x->n--;

        np1 = init();

        np1->leaf = false;

        x->leaf = true;

        for (j = 3; j < 5; j++)

        {

            np3->data[j - 3] = x->data[j];

            np3->child_ptr[j - 3] = x->child_ptr[j];

            np3->n++;

            x->data[j] = 0;

            x->n--;

        }

        for(j = 0; j < 6; j++)

        {

            x->child_ptr[j] = NULL;

        }

        np1->data[0] = mid;

        np1->child_ptr[np1->n] = x;

        np1->child_ptr[np1->n + 1] = np3;

        np1->n++;

        root = np1;

    }

    else

    {

        y = x->child_ptr[i];

        mid = y->data[2];

        y->data[2] = 0;

        y->n--;

        for (j = 3; j < 5; j++)

        {

            np3->data[j - 3] = y->data[j];

            np3->n++;

            y->data[j] = 0;

            y->n--;

        }

        x->child_ptr[i] = y;

        x->child_ptr[i + 1] = np3;

    }

    return mid;

}

void insert(int a)

{

    int i, temp;

    x = root;

    if (x == NULL)

    {

        root = init();

        x = root;

    }

    else

    {

        if (x->leaf == true && x->n == 5)

        {
            //cout<<"First Condition"<<endl;
            temp = split_child(x, -1);

            x = root;

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

                else

                {

                    continue;

                }

            }

            x = x->child_ptr[i];

        }

        else

        {
            //cout<<"second Condition"<<endl;
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

                else

                {

                    continue;

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
    cout << x->n << endl;
    x->data[x->n] = a;

    sort(x->data, x->n);

    x->n++;

}

void file(){
    freopen("numInput.txt","r",stdin);
    freopen("numOutput.txt","w",stdout);
}


int main(){

    //file();
    int i, n, t;
    //cout<<"enter the no of elements to be inserted\n";
    //cin>>n;

    for(; ;){

        cout<<"element:";
        cin>>t;

        if(t == 0) break;
        insert(t);
        cout<<"After inserting "<< t<< endl;

        traverse(root);

    }

    //cout<<"traversal of constructed tree\n";

    getch();

}


/*
12
4
7
5
1
9
8
3
6
2
23
76



*/
