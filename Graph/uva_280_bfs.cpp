#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node
#define mem(x,y) memset(x, y, sizeof(x))


//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}


void bfs(int source, vector<int>edges[], int *visited){

	queue<int> nodes;
	
	nodes.push(source);
	visited[source] = 1;

	int dis = 0;
	while(!nodes.empty()){
		int node = nodes.front();

		int size = edges[node].size();
		
		for(int i=0;i<size;i++){ 
			if(visited[edges[node][i]]!=1){
				nodes.push(edges[node][i]);
				visited[edges[node][i]] = 1;
			}
		}
		nodes.pop();
	}
}

void print(int visited[], int N){
    
    int count = 0;

    for(int i=0;i<N;i++){
        if(visited[i]==0){
            count++;
        }
    }
    printf("%d", count);

    for(int i=0; i<N; i++){
        if(visited[i]==0){
            printf(" %d",i+1);
        }
    } 
    printf("\n");
}



int main(){

	file(false);

	while(true){
	    int N;
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
	            
	            edges[a-1].push_back(b-1);

	        }            
	    }
	    int m;
	    scanf("%d",&m);
	        
	    for(int i=0;i<m;i++){
	        int a;
	        scanf("%d",&a);

	        // cout<<"Source: "<<a<<endl;
	        
	        int visited[N];
	        mem(visited, 0);

	        bfs(a-1, edges, visited);

	        // for(int i=0; i<N; i++) printf("visited[%d]: %d\n", i, visited[i]);

	        print(visited, N);
	    }
	}
	
	

	return 0;
}
