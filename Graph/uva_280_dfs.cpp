#include<bits/stdc++.h>
#include <sstream>
using namespace std;

#define MAX 100000 //maximum node
#define mem(x,y) memset(x, y, sizeof(x))
#define bug printf("tested\n");

// vector<int>edges[MAX];
int N, E;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}

void dfs(int node, vector<int>edges[], int *color){

    color[node] = 1;    

    int size = edges[node].size();

    for(int i=0; i<size; i++){
        int adj = edges[node][i];
        
        if(color[adj]==0){
            cout<<node<<"-->"<<adj<<endl;
            color[adj] = 1;
            dfs(adj, edges, color);
        }
    }

    color[node] = 2;
    return;
}
void print(int color[], int N){
    
    int count = 0;

    for(int i=1;i<=N;i++){
        if(color[i]==2){
            count++;
        }
    }
    printf("count: %d\n", count);

    for(int i=1; i<=N; i++){
        if(color[i]!=2){
            printf(" %d",i);
        }
    } 
    printf("\n");
}

int main(){
    file(false);

    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        vector<int>edges[N+1];
        
        while(true){
            int a;
            scanf("%d",&a);
            if(a==0) break;
            
            while(true){
                int b;
                scanf("%d",&b);
                if(b==0) break;
                
                edges[a].push_back(b);
            }            
        }
        int m;
        scanf("%d",&m);
            
        for(int i=0;i<m;i++){
            int a;
            scanf("%d",&a);

            cout<<"Source: "<<a<<endl;

            int color[N+1];
            mem(color, 0);

            dfs(a, edges, color);

            // for(int i=1; i<=N; i++) printf("color[%d]: %d\n", i, color[i]);

            // print(color, N);
        }
    }

    return 0;
}
