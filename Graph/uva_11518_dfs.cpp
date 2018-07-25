#include<bits/stdc++.h>
#include <sstream>
using namespace std;

#define MAX 100000 //maximum node
#define mem(x,y) memset(x, y, sizeof(x))
#define bug printf("tested\n");

// vector<int>edges[MAX];


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
            color[adj] = 1;
            dfs(adj, edges, color);
        }
    }

    color[node] = 2;
    return;
}
void print(int color[], int N){
    
    int count = 0;

    for(int i= 1;i<=N;i++){
        if(color[i]==2){
            count++;
        }
    }
    printf("%d\n", count);

}

int main(){
    file(true);

    int t;
    scanf("%d", &t);

    while(t--){
    	
    	int n, m, l;
    	scanf("%d%d%d",&n, &m, &l);

    	if(l==0){
    		printf("0\n");
    		continue;	
    	} 
    	
    	vector<int>edges[n+1];

    	for(int i=0; i<m; i++){

    		int x,y;
    		scanf("%d%d",&x,&y);
    		edges[x].push_back(y);
    		
    	}

    	int s;
    	scanf("%d", &s);
    	int color[n+1];
    	mem(color, 0);
    	dfs(s, edges, color);
    	    // cout<<"t: "<<100-t<<endl;
    	print(color, n);
    }

    return 0;
}
