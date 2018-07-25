#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node




int N,E;

//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}


map<int, int> bfs(vector<int>edges[], map<int, int> distance,int source){

	queue<int> nodes;

	nodes.push(source);

	// map<int, int> distance;

	map<int, int> visited;

	distance[source] = 0;
	visited[source] = 1;

	int dis = 0;
	while(!nodes.empty()){
		int node = nodes.front();

		int size = edges[node].size();

		for(int i=0;i<size;i++){
			if(visited.count(edges[node][i])==0){ //not visited

				nodes.push(edges[node][i]);
				distance[edges[node][i]] = 1 + distance[node];
				visited[edges[node][i]] = 1;
			}
		}
		nodes.pop();
	}
	return distance;
}


int main(){
	file(true);

	int NC;
	int test_case = 1 ;
	while(true){

		scanf("%d", &NC);
		if(NC==0) break;

		set<int> all_nodes;

		// vector <pair<int, int>> source_TTL;
		vector<int>edges[MAX];
		for(int i=0;i<NC;i++){

			int x,y;
			scanf("%d%d",&x,&y);

			all_nodes.insert(x);
			all_nodes.insert(y);

			edges[x].push_back(y);
			edges[y].push_back(x);

		}

		while(true){

			int source, TTL;
			scanf("%d%d",&source,&TTL);
			if(source==0 && TTL==0) break;

			// cout<<source<<" "<<TTL<<endl;

			map<int, int> distance;

			set<int>::iterator itt;
			for (itt = all_nodes.begin(); itt != all_nodes.end(); ++itt) {
				distance[*itt] = 10000000;
			}

			distance = bfs(edges, distance, source);

			// cout<<"size: "<<distance.size()<<endl;

			// cout<<"ok"<<endl;

			int count = 0;
			map<int, int>::iterator it;
			for(it = distance.begin(); it != distance.end(); ++it ){
			    
			    int key = it->first;
			    int value = it->second;
			    if(value>TTL) count++;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", test_case++, count, source, TTL);
			distance.clear();
			

		}

	}

	return 0;
}
