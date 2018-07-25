#include<bits/stdc++.h>
#include <sstream>
using namespace std;

#define MAX 100000 //maximum node
#define mem(x,y) memset(x, y, sizeof(x))
#define bug printf("tested\n");

vector<int>edges[MAX];
int N, E;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}

void dfs(int node, int *discovery, int *finish, int *dist, int *color, int &time){

	color[node] = 1;	

	int size = edges[node].size();

	for(int i=0; i<size; i++){
		int adj = edges[node][i];
		
		if(color[adj]==0){
			cout<<node<<"-->"<<adj<<endl;
			color[adj] = 1;
			dist[adj] = dist[node] + 1;
			discovery[adj] = ++time;
			dfs(adj, discovery, finish, dist, color, time);
		}
	}

	color[node] = 2;
	finish[node] = ++time;
	return;
}


int main(){
	file(false);
	scanf("%d%d",&N,&E);

	for(int i=1;i<=E;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		//dedges[y].push_back(x);
	}

	int discovery[N+1];
	int finish[N+1];
	int dist[N+1];
	int color[N+1];
	
	mem(dist, 0);
	mem(color, 0);
	mem(finish, 0);
	mem(discovery, 0);

	discovery[1] = 1;
	int time = 1;

	dfs(1, discovery, finish, dist, color, time);

	for(int i=1; i<=N; i++){
		printf("Node: %d, discovery: %d, finish: %d, color: %d, distance: %d\n", i, discovery[i]
			,finish[i], color[i], dist[i]);
	}

	/*
	0 =  white;
	1 = grey;
	2 = black;
	*/ 

	return 0;
}
