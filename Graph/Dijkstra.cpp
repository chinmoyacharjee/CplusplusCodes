#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node

vector<int>edges[MAX];
int cost[1000][1000];

int N,E;

//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}

// without priority queue
void dijkstra(int *distance, int *visited){

	queue<int> nodes;
	
	memset(visited, -1, sizeof(visited));
	memset(distance, 1000000, sizeof(distance));
	
	nodes.push(1);
	distance[1] = 0;
	visited[1] = 1;

	int dis = 0;
	while(!nodes.empty()){
		int node = nodes.front();

		int size = edges[node].size();
		
		for(int i=0;i<size;i++){ 
			int v = edges[node][i];
			if(distance[node] + cost[node][v] < distance[v]){
				
				distance[v] = distance[node] + cost[node][v];
				nodes.push(edges[node][i]);				
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
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		edges[x].push_back(y);
		// edges[y].push_back(x);

		cost[x][y] = d;
	}
	int visited[N];
	int distance[N];

	dijkstra(distance, visited);
	
	for(int i=1;i<=N;i++){
		printf("%dth distance: %d\n",i,  distance[i]);
	}

	for(int i=1;i<=N;i++){
		printf("%d\n",  visited[i]);
	}


	return 0;
}
