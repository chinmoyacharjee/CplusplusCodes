#include<bits/stdc++.h>
using namespace std;

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h, int &step)
{
    cout<< " depth: " << depth << " nodeIndex: " << nodeIndex << endl;

    if (depth == h)
        return scores[nodeIndex];

    int x, y;
    if (isMax){
        
        x = minimax(depth+1, nodeIndex*2, false, scores, h, ++step);
        y = minimax(depth+1, nodeIndex*2 + 1, false, scores, h, ++step);
        cout << "Max: " << x << " " << y << " " << max(x, y) << endl; 
        return max(x, y); 
    }

    else{
        
        x = minimax(depth+1, nodeIndex*2, true, scores, h, ++step);
        y = minimax(depth+1, nodeIndex*2 + 1, true, scores, h, ++step);
        cout << "Min: " << x << " " << y << " " << min(x, y) <<  endl; 

        return min(x, y);
    }
        
}
 

int log2(int n)
{
  return (n==1)? 0 : 1 + log2(n/2);
}
 
int main()
{

    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};

    int step = 0;

    int n = sizeof(scores)/sizeof(scores[0]);
    int h = log2(n);

    int res = minimax(0, 0, true, scores, h, step);
    cout << "The optimal value is : " << res << endl;
    cout<< "Steps:" <<step<< endl;
    return 0;
}
