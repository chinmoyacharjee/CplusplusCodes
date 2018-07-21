#include<bits/stdc++.h>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 100000 //maximum node
vector<int>edges[MAX];
map<int, int> m;
//vector<int>cost[MAX]; //parallel vector to store costs;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}
int main(){
	 
	 map<string, vector<string>  > m;
	 vector<string> v;
	 v.push_back("b");
	 v.push_back("baa");

	 m["a"] = v;

	 cout<<m["a"].size()<<endl;


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