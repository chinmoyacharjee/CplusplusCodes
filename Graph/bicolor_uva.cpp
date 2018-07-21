#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node

//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}

int main(){
	file(true);
	
	int N,E; 
	int t = 1;
	while(true){
		scanf("%d", &N);
		if(N==0) break;
		scanf("%d", &E);

		vector<int>edges[E+5];

		int visited[N];
		int color[N];

		pair<int, int> adjs[E];
		for(int i=0; i<E; i++) adjs[i].first=0,adjs[i].second=0;

		memset(visited, -1, N*sizeof(visited[0]));
		memset(color, -1, N*sizeof(color[0]));

		int source=0;

		bool bicolorable = true;
		
		// cout<<"test case: "<<t++<<endl;
		// cout<<N<<endl<<E<<endl;
		// t++;
		for(int i=0;i<E;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			// if(i==0) source = x;
			
			// cout<<x<<" "<<y<<endl;

			source = 0;
			edges[x].push_back(y);
			edges[y].push_back(x);

			adjs[i].first = x;
			adjs[i].second = y;
		}

		queue<int> nodes;

		nodes.push(source);
		
		int c = 0;
		color[source] = c;
		visited[source] = 1;
		
		// int dis = 0;
		while(!nodes.empty()){
			
			int node = nodes.front();

			int size = edges[node].size();
			



			for(int i=0;i<size;i++){ 
				if(visited[edges[node][i]]!=1){
					
					// i = size + 5;
					nodes.push(edges[node][i]);
					if(color[node]==1) c=0;
					else if(color[node]==0) c=1;

					color[edges[node][i]] = c;
					visited[edges[node][i]] = 1;

				}
				// else{
				// 	if(color[node]!=color[edges[node][i]])
				// }

			}
			nodes.pop();
		}
		for(int i=0; i<E;i++){
			
			// cout<<color[adjs[i].first] << " " << color[adjs[i].second]<<endl;
			if(color[adjs[i].first] == color[adjs[i].second]){
				bicolorable = false;
				break;
			}
		}

		if(bicolorable) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");

		for(int i = 0; i<E+5; i++) edges[i].clear();

		
	}


	
	return 0;
}

/*

10 12
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