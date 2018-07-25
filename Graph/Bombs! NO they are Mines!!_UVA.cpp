#include<bits/stdc++.h>
#include <sstream>
using namespace std;

#define MAX 100000 //maximum node
#define mem(x,y) memset(x, y, sizeof(x))

#define bug printf("tested\n");


int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

// int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
// int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};


int cells[1000][1000];
int dist[1000][1000];
int visited[1000][1000];

int row, col;

void file(bool printInFile){
    freopen("../input.txt","r",stdin);
    if(printInFile)
        freopen("../output.txt","w",stdout);
}


bool valid(int tx, int ty){

	if(tx >= row || tx < 0) return false;
	if(ty >= col || ty < 0) return false;
	if(visited[tx][ty] == 1) return false;
	if(cells[tx][ty] == -1) return false;
	return true;
}


void bfs(int sx, int sy){

	queue<pair<int, int>  > nodes;

	mem(dist, 0);
	mem(visited, -1);

	//nodes.push(pair<int, int>(sx, sy));
	nodes.push(make_pair(sx, sy));

	dist[sx][sy] = 0;
	visited[sx][sy] = 1;

	int dis = 0;
	while(!nodes.empty()){
		pair<int, int> node = nodes.front();

		sx = node.first;
		sy = node.second;

		for(int i=0; i<4; i++){
			int tx = sx + fx[i];
			int ty = sy + fy[i];

			if(valid(tx, ty)){
//				cout<<sx<<sy<<"-->"<<tx<<ty<<endl;

				nodes.push(make_pair(tx, ty));
				dist[tx][ty] = 1 + dist[sx][sy];
				visited[tx][ty] = 1;
				//cout<<"";
			}
		}
		nodes.pop();
	}
}

int main(){
	file(false);

	while(true){

		scanf("%d%d",&row, &col);
		if(row == 0 && col == 0) break;
		int total_bombs_in_row;

		scanf("%d", &total_bombs_in_row);

		mem(cells, 1);

		for(int i=0; i<total_bombs_in_row; i++){

			int r;
			scanf("%d", &r);
			int bomb_in_that_r;
			scanf("%d", &bomb_in_that_r);
			while(bomb_in_that_r--){
				int c;
				scanf("%d", &c);
				cells[r][c] = -1;
			}
		}

		int sx, sy, dx, dy;
		scanf("%d%d%d%d",&sx, &sy, &dx, &dy);

		bfs(sx, sy);

		// for(int i=0; i<row; i++){
		// 	for(int j=0; j<col; j++){
		// 		//printf("dist[%d][%d]: %d, visited[%d][%d] :%d\n", i, j, dist[i][j], i, j, visited[i][j]);
		// 	}
		// }

		printf("%d\n", dist[dx][dy]);
	}

	return 0;
}
