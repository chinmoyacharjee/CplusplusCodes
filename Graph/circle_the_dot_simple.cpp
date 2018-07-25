#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node

int N,E;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}
 

void bfs(map<string, vector<string>  > edges, string source, map<string, int> &visited, map<string, string> &par){

	queue<string> nodes;

	nodes.push(source);

	map<string, int> distance;

	distance[source] = 0;
	visited[source] = 1;
	par[source] =" ";

	int dis = 0;
	while(!nodes.empty()){
		string node = nodes.front();

		int size = edges[node].size();		

		for(int i=0;i<size;i++){
			if(visited.count(edges[node][i])==0){ 

				nodes.push(edges[node][i]);
				distance[edges[node][i]] = 1 + distance[node];
				visited[edges[node][i]] = 1;
				par[edges[node][i]] = node;

			}
		}
		nodes.pop();
	}
	
}


int main(){

	file(true);

	int E; 
	bool primera = false;	

	while(scanf("%d", &E)!=EOF){

		map<string, vector<string>  > edges;

		for(int i=0;i<E;i++){

			string x,y;
			cin>>x>>y;
	
			edges[x].push_back(y);
			edges[y].push_back(x);

		}

		string source, destination;
		cin>>source>>destination;
		
		if(primera) printf("\n");
		primera = true;

		map<string, int> visited;
		map<string, string> par;

		bfs(edges, source, visited, par);
		

		if(visited.count(destination)!=1){
			printf("No route\n");
				
		}
		else{
			
			vector<pair<string, string>  > v;			
			
			while(true){
				
				if(destination==source) break;				

				string parent = par[destination];				
				v.push_back(make_pair(parent, destination));				
				destination = parent;

			}

			for (int i=v.size()-1; i>=0; i--){
			    cout << v[i].first << " " << v[i].second << endl;
			}
			
		}
		
		// cout<<endl;	
	}

	return 0;
}
