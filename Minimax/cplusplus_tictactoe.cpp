#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;

class MinMax
{
public:
    char arr[9];
    char dup[9];
    int VALUE;
    int TURN;
    int DEPTH;
    MinMax()
    {
        int i;
        for(i=1;i<=9;i++)
        {
            arr[i-1]=' ';
            dup[i-1]=' ';
        }
    }
    void MaxMove();
    void MinMove();
    void display();
    char evaluate();
    void randomtoss();
    char staticevaluate(char *);
    void process();
};
void MinMax::randomtoss()  // Toss to decide which will move first
{
    int a,num;
    srand(time(NULL));
    cout << "It's the toss ! Enter 1 or 2" << endl;
    cin >> num;
    a=(rand()%2)+1;
    if(num=a)
    {
        cout << "You won the Toss ! Make your move" << endl;
        TURN=1;
    }
    else
    {
        cout << "You lose the toss ! I will move first :P" << endl;
        TURN=2;
    }
}
char MinMax::staticevaluate(char *a)  // The static evaluate function
{
    int i,VAL;
    for(i=0;i<9;i++)
    {
        if(*(a+i)=='X')
        {
            if(i==4)
            {
                VAL+=10;
            }
            if((i==0)||(i==2)||(i==6)||(i==8))
            {
                VAL+=8;
            }
            if((i==1)||(i==3)||(i==5)||(i==7))
            {
                VAL+=6;
            }
        }
        if(*(a+i)=='O')
        {
            if(i==4)
            {
                VAL-=10;
            }
            if((i==0)||(i==2)||(i==6)||(i==8))
            {
                VAL-=8;
            }
            if((i==1)||(i==3)||(i==5)||(i==7))
            {
                VAL-=6;
            }
        }
    }
    return VAL;
}
void MinMax::MaxMove()  // Player will make his move via this function
{
    int x;
    cout << " Enter your move " << endl << endl;
    cin >> x;
    x--;
    if(arr[x]!=' ')
    {
        cout << "Invalid move, Try again" << endl;
        MaxMove();
    }
    else 
       arr[x]='X';
    TURN=2;
}
void MinMax::MinMove()  // The PC will make his move via this function
{
    int i,POS;
    for(i=0;i<9;i++)
    {
        if(arr[i]==' ')
        {
            dup[i]='O';
            if(staticevaluate(dup)<VALUE)
            {
                VALUE=staticevaluate(dup);
                POS=i;
            }
            dup[i]=' ';
        }
    }
    arr[POS]='O';
    TURN=1;
}    
void MinMax::display()  // Displays the matrix
{
    int t;
    cout << endl;
    for(t=0;t<9;t++)
    {
        cout << arr[t] <<"  |" << arr[t+1] << "  |" << arr[t+2];
        t+=2;
        if(t!=8)
            cout << endl << "---|---|---" << endl;
    }
    cout << endl;
}
char MinMax::evaluate()  // Checks for a win,loss or draw
{
    int i,c=0;
    for(i=0; i<7; i++)   /* Check Rows */
    {
        if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
            return arr[i];
        i+=2;
    }
    for(i=0; i<3; i++)  /* Check Columns */
    {
        if(arr[i]==arr[i+3] && arr[i+3]==arr[i+6]) 
            return arr[i];
    }
    if(arr[0]==arr[4] && arr[4]==arr[8])  /* Test Diagonals */
         return arr[0];

    if(arr[2]==arr[4] && arr[4]==arr[6])  /* Test Diagonals */
         return arr[2];
    
    for(i=0;i<9;i++)
    {
         if(arr[i]!=' ')
             c++;
    }
    if(c==9)
        return 'D';
    return ' ';
}
void MinMax::process()
{
    char ch;
    randomtoss();
    do
    {
        if(TURN==1)
        {
            MaxMove();
            TURN=2;
        }   
        else
        {
            MinMove();
            TURN=1;
        }    
        display();
        cout << endl;
        ch=evaluate();
        if(ch=='X')
        {
            display();
            cout << endl;
            cout <<"YOU WON !!"<< endl;
            exit(0);
        }
        if(ch=='O')
        {
            display();
            cout << endl;
            cout <<"I WON !!"<< endl;
            exit(0);
        }
        if(ch=='D')
        {
            display();
            cout << endl;
            cout <<"IT'S A DRAW !!"<< endl;
            exit(0);
        }
    }
    while(ch==' ');
}
int main()
{
    MinMax play;
    play.process();
    return 0;
}