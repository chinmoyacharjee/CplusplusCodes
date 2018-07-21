#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node
vector<int>edges[MAX];
int N,E;

//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}


void bfs(int *distance, int *visited){

	queue<int> nodes;
	
	memset(visited, -1, sizeof(visited[0]));
	memset(distance, -1, sizeof(distance[0]));
	
	nodes.push(1);
	distance[1] = 0;
	visited[1] = 1;

	int dis = 0;
	while(!nodes.empty()){
		int node = nodes.front();

		int size = edges[node].size();
		
		for(int i=0;i<size;i++){ 
			if(visited[edges[node][i]]!=1){
				
				nodes.push(edges[node][i]);
				distance[edges[node][i]] = 1 + distance[node];
				visited[edges[node][i]] = 1;
			}
		}
		nodes.pop();
	}
}


int main(){
	file(false);
	
	scanf("%d%d",&N,&E);

	for(int i=1;i<=E;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		// edges[y].push_back(x);
	}
	int visited[N];
	int distance[N];

	bfs(distance, visited);
	
	for(int i=1;i<=N;i++){
		printf("%dth distance: %d\n",i,  distance[i]);
	}

	for(int i=1;i<=N;i++){
		printf("%d\n",  visited[i]);
	}


	return 0;
}

/*

10 13
1 2
1 4
1 3
2 6
4 7
3 7
3 8
6 10
7 9
7 8
8 5
10 9
10 5


*/