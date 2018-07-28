#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node

int N,E;

//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}


void bfs(int s, int *distance, int *visited, vector<int>edges[]){

	queue<int> nodes;
	
	
	
	nodes.push(s);
	distance[s] = 0;
	visited[s] = 1;
	
	while(!nodes.empty()){
		int node = nodes.front();

		int size = edges[node].size();
		
		for(int i=0;i<size;i++){ 
			if(visited[edges[node][i]]!=1){				
				nodes.push(edges[node][i]);
				distance[edges[node][i]] = 1 + distance[node];
				visited[edges[node][i]] = 1;
			}
			else if(visited[edges[node][i]]==1){
				int dis = distance[node];
				++dis;
				if(distance[edges[node][i]]<dis) distance[edges[node][i]] = dis;
				visited[edges[node][i]] = -1;
				bfs(node, distance, visited, edges);
				// nodes.push(node);
			}
		}
		nodes.pop();
	}
}


int main(){
	file(true);

	int t=1;
	
	while(true){
		int N, s;
		scanf("%d",&N);
		if(N==0) break;
		scanf("%d",&s);

		vector<int>edges[N+1];

		while(true){
			int x, y;
			scanf("%d%d",&x,&y);
			if(x==0 && y==0) break;
			edges[x].push_back(y);
			//edges[y].push_back(x);

		}

		int visited[N+1];
		int distance[N+1];

		memset(visited, -1, sizeof(visited));
		memset(distance, 0, sizeof(distance));

		bfs(s, distance, visited, edges);
		// printf("ok\n");
		int mx = 0, node;


		for(int i = 1; i<=N; i++){
			
			if(distance[i]>mx){
				mx = distance[i];
				node = i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t++, s, mx, node);
	
		// for(int i = 1; i<=N; i++){
			
		// 	printf("distance[%d]: %d\n", i, distance[i]);
		// }
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