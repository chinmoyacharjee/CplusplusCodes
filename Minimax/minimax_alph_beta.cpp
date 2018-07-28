#include<bits/stdc++.h>
using namespace std;

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h, int &step, int &alpha, int &beta)
{
    cout<< " depth: " << depth << " nodeIndex: " << nodeIndex << endl;

    if (depth == h)
        return scores[nodeIndex];

    int x, y;
    if (isMax){
        int best = -10000;
        
        for(int i=0; i<2; i++){
            best = max(best, minimax(depth+1, nodeIndex*2 + i, false, scores, h, ++step, alpha, beta));
            alpha = max(best, alpha);
            if(beta <= alpha)
                break;
        }

        return best; 
    }

    else{
        int best = 10000;
    
        for(int i=0; i<2; i++){
            best = min(best, minimax(depth+1, nodeIndex*2 + i, true, scores, h, ++step, alpha, beta));
            beta = min(best, beta);
            if(beta >= alpha)
                break;
        }

        return best;
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
    int alpha = -10000;
    int beta = 10000;

    int n = sizeof(scores)/sizeof(scores[0]);
    int h = log2(n);

    int res = minimax(0, 0, true, scores, h, step, alpha, beta);
    cout << "The optimal value is : " << res << endl;
    cout<< "Steps:" <<step<< endl;
    return 0;
}
